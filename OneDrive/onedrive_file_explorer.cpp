#include "Client_Class.h" // asta ramane sus prima ca altfel nu merge !!!!!!!
#include "onedrive_file_explorer.h"
#include "DataBaseConnect.h"
#include <QMessageBox>
#include <QtWidgets/qmessagebox.h>
#include <regex>
#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>
#include <QtWidgets/qcommonstyle.h>
#include <QtWidgets/qinputdialog.h>
#include <QFileDialog>

QString filename = "SendFilesDetails.txt";

OneDriveFileExplorer::OneDriveFileExplorer(QWidget* parent)
    : QDialog(parent)
{
    ui.setupUi(this);

    QPixmap background("BackgroundLoginImg.jpg");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);

    this->setWindowIcon(QIcon("Logo.png"));//Generate window icon
    QCommonStyle style;
    ui.pushButton_LR->setIcon(style.standardIcon(QStyle::SP_ArrowRight));
    ui.pushButton_RL->setIcon(style.standardIcon(QStyle::SP_ArrowLeft));
    //this->setWindowState(Qt::WindowMinimized);
    
    QString dirPath = "C:/";
    dirmodel = new QFileSystemModel(this);
    dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files);
    dirmodel->setRootPath(dirPath);

    ui.treeViewPC->setModel(dirmodel);

    dirmodelDrive = new QFileSystemModel(this);
    dirmodelDrive->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files);
    dirmodelDrive->setRootPath(dirPath);

    ui.treeViewDrive->setModel(dirmodelDrive);

    ui.treeViewDrive->setRootIndex(dirmodelDrive->index(dirPath));
}

void OneDriveFileExplorer::on_treeViewPC_clicked(QModelIndex index) //here we send files
{
    selectedFile = dirmodel->fileInfo(index).absoluteFilePath();
}

OneDriveFileExplorer::OneDriveFileExplorer(std::string username, QWidget* parent)
    : QDialog(parent)
{
    ui.setupUi(this);

    QPixmap background("BackgroundLoginImg.jpg");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);

    this->Username = username;
    this->Path = GetUserPathToFiles(); /// aici ii dau calea din fisiere.


    this->setWindowIcon(QIcon("Logo.png"));//Generate window icon
    //this->setWindowState(Qt::WindowMinimized);
    QCommonStyle style;
    ui.pushButton_LR->setIcon(style.standardIcon(QStyle::SP_ArrowRight));
    ui.pushButton_RL->setIcon(style.standardIcon(QStyle::SP_ArrowLeft));

    QString dirPath = "C:/";
    dirmodel = new QFileSystemModel(this);
    dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files);
    dirmodel->setRootPath(dirPath);

    ui.treeViewPC->setModel(dirmodel);

    QString dirPathDrive = this->Path.c_str();
    dirmodelDrive = new QFileSystemModel(this);
    dirmodelDrive->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files);
    dirmodelDrive->setRootPath(dirPathDrive);
    ui.treeViewDrive->setModel(dirmodelDrive);

    ui.treeViewDrive->setRootIndex(dirmodelDrive->index(dirPathDrive));

    
}
std::string OneDriveFileExplorer::GetUserPathToFiles()
{
    DataBaseConnect* dbc = new DataBaseConnect();
    return dbc->GetUserPath(this->Username);
}
void OneDriveFileExplorer::sendFiles_new_method(std::string FileSourcePath, std::string Path)
{
    
    QFile file(filename);

    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);
        stream << 2 << "\n";
        stream << FileSourcePath.c_str()<<"\n";
        stream << Path.c_str()<<"\n";
    }

    /// client process should start here:)))
    QProcess process;
    QString clientPath = "..\\Client\\x64\\Release\\Client.exe";
    QFile file1 = clientPath;
    process.startDetached(file1.fileName());
    //process.waitForFinished();

}

void OneDriveFileExplorer::getFiles_new_method(std::string destinationPath)
{ 
    QFile file(filename);

    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);
        stream << 1 << "\n";
        stream << selectedFile.toStdString().c_str() << "\n";
        stream << destinationPath.c_str() << "\n";
    }
    
   QProcess process;
   QString clientPath = "..\\Client\\x64\\Release\\Client.exe";
   QFile file1 = clientPath;
    process.startDetached(file1.fileName());

}

void OneDriveFileExplorer::on_treeViewPC_doubleClicked(QModelIndex index)
{
    QDesktopServices::openUrl(QUrl::fromLocalFile(selectedFile));
}
void OneDriveFileExplorer::on_treeViewDrive_clicked(QModelIndex index)
{
    selectedFile = dirmodelDrive->fileInfo(index).absoluteFilePath();
    /// pus in fisier GEtFiles_details.txt
    /// +calea pe car eo selecteaza userul cnad apasa pe buton.
}
void OneDriveFileExplorer::on_treeViewDrive_doubleClicked(QModelIndex index)
{
    QDesktopServices::openUrl(QUrl::fromLocalFile(selectedFile));
}

void OneDriveFileExplorer::on_pushButton_LR_clicked() 
{
    QLabel* pathToFile = new QLabel(this);
    pathToFile->setText(selectedFile.toStdString().c_str());

    std::string FileSourcePath = selectedFile.toStdString();

    //sendFiles(FileSourcePath, this->Path); //-new method

    sendFiles_new_method(FileSourcePath, this->Path);
}

void OneDriveFileExplorer::on_pushButton_RL_clicked()
{

    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),"/home", QFileDialog::ShowDirsOnly|QFileDialog::DontResolveSymlinks);
    qDebug() << dir;
    getFiles_new_method(dir.toStdString());
    //get files;
    //get files method;
    // aici apare popup si ia calea in get files method;
}

void OneDriveFileExplorer::on_pushButton_delete_clicked()
{
    QFileInfo fileToDelInfo(selectedFile);
    if (fileToDelInfo.suffix() == "")
    {
        QDir dirToDel = selectedFile;
        dirToDel.removeRecursively();
    }
    else
    {
        QFile fileToDel = selectedFile;
        fileToDel.remove();
    }
}

void OneDriveFileExplorer::on_pushButton_rename_clicked()
{
    QString newName = QInputDialog::getText(this, "Rename file", "Enter a new name: ");

    QFileInfo fileToChange(selectedFile);
    QString extension = fileToChange.suffix();
    QDir currentDir(this->Path.c_str()); /// fix bug!
    currentDir.rename(fileToChange.absoluteFilePath(), newName + '.' + extension);
}

void OneDriveFileExplorer::on_pushButton_createdir_clicked()
{
    QString newName = QInputDialog::getText(this, "Create new directory", "Enter a name: ");
    QDir(this->Path.c_str()).mkdir(newName); /// fix bug!
}

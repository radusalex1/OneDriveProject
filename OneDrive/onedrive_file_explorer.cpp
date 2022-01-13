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
    m_ui.setupUi(this);

    QPixmap background("BackgroundLoginImg.jpg");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);

    this->setWindowIcon(QIcon("Logo.png"));//Generate window icon
    QCommonStyle style;
    m_ui.pushButton_LR->setIcon(style.standardIcon(QStyle::SP_ArrowRight));
    m_ui.pushButton_RL->setIcon(style.standardIcon(QStyle::SP_ArrowLeft));
    //this->setWindowState(Qt::WindowMinimized);
    
    QString dirPath = "C:/";
    m_dirmodel = new QFileSystemModel(this);
    m_dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files);
    m_dirmodel->setRootPath(dirPath);

    m_ui.treeViewPC->setModel(m_dirmodel);

    m_dirmodelDrive = new QFileSystemModel(this);
    m_dirmodelDrive->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files);
    m_dirmodelDrive->setRootPath(dirPath);

    m_ui.treeViewDrive->setModel(m_dirmodelDrive);

    m_ui.treeViewDrive->setRootIndex(m_dirmodelDrive->index(dirPath));
}

void OneDriveFileExplorer::on_treeViewPC_clicked(QModelIndex index) //here we send files
{
    m_selectedFile = m_dirmodel->fileInfo(index).absoluteFilePath();
}

OneDriveFileExplorer::OneDriveFileExplorer(std::string username, QWidget* parent)
    : QDialog(parent)
{
    m_ui.setupUi(this);

    QPixmap background("BackgroundLoginImg.jpg");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);

    this->m_Username = username;
    this->m_Path = GetUserPathToFiles(); /// aici ii dau calea din fisiere.


    this->setWindowIcon(QIcon("Logo.png"));//Generate window icon
    //this->setWindowState(Qt::WindowMinimized);
    QCommonStyle style;
    m_ui.pushButton_LR->setIcon(style.standardIcon(QStyle::SP_ArrowRight));
    m_ui.pushButton_RL->setIcon(style.standardIcon(QStyle::SP_ArrowLeft));

    QString dirPath = "C:/";
    m_dirmodel = new QFileSystemModel(this);
    m_dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files);
    m_dirmodel->setRootPath(dirPath);

    m_ui.treeViewPC->setModel(m_dirmodel);

    QString dirPathDrive = this->m_Path.c_str();
    m_dirmodelDrive = new QFileSystemModel(this);
    m_dirmodelDrive->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files);
    m_dirmodelDrive->setRootPath(dirPathDrive);
    m_ui.treeViewDrive->setModel(m_dirmodelDrive);

    m_ui.treeViewDrive->setRootIndex(m_dirmodelDrive->index(dirPathDrive));

    
}
OneDriveFileExplorer::~OneDriveFileExplorer()
{
    delete[] m_dirmodel;
    delete[] m_dirmodelDrive;
}
std::string OneDriveFileExplorer::GetUserPathToFiles()
{
    DataBaseConnect* dbc = new DataBaseConnect();
    return dbc->GetUserPath(this->m_Username);
}
void OneDriveFileExplorer::SendFilesNewMethod(std::string FileSourcePath, std::string Path)
{
    QFile file(filename);
    file.resize(0);
    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);
        stream << 2 << "\n";
        stream << FileSourcePath.c_str()<<"\n";
        stream << Path.c_str()<<"\n";
    }
    
    file.close();

    ServerProcess();

    ClientProcess();
}

void OneDriveFileExplorer::GetFilesNewMethod(std::string destinationPath)
{ 
    QFile file(filename);

    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);
        stream << 1 << "\n";
        stream << m_selectedFile.toStdString().c_str() << "\n";
        stream << destinationPath.c_str() << "\n";
    }

    ServerProcess();
    
    ClientProcess();
}

void OneDriveFileExplorer::ServerProcess()
{
    QProcess ServerProcess;
    QString serverPath = "..\\Server\\x64\\Debug\\Server.exe";
    QFile fileServer = serverPath;
    ServerProcess.startDetached(fileServer.fileName());
}

void OneDriveFileExplorer::ClientProcess()
{
    QProcess process;
    QString clientPath = "..\\Client\\x64\\Release\\Client.exe";
    QFile file1 = clientPath;
    process.startDetached(file1.fileName());
}

void OneDriveFileExplorer::on_treeViewPC_doubleClicked(QModelIndex index)
{
    QDesktopServices::openUrl(QUrl::fromLocalFile(m_selectedFile));
}
void OneDriveFileExplorer::on_treeViewDrive_clicked(QModelIndex index)
{
    m_selectedFile = m_dirmodelDrive->fileInfo(index).absoluteFilePath();

}
void OneDriveFileExplorer::on_treeViewDrive_doubleClicked(QModelIndex index)
{
    QDesktopServices::openUrl(QUrl::fromLocalFile(m_selectedFile));
}

void OneDriveFileExplorer::on_pushButton_LR_clicked() 
{
    QLabel* pathToFile = new QLabel(this);
    pathToFile->setText(m_selectedFile.toStdString().c_str());

    std::string FileSourcePath = m_selectedFile.toStdString();

    SendFilesNewMethod(FileSourcePath, this->m_Path);
}

void OneDriveFileExplorer::on_pushButton_RL_clicked()
{

    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),"/home", QFileDialog::ShowDirsOnly|QFileDialog::DontResolveSymlinks);
    qDebug() << dir;
    GetFilesNewMethod(dir.toStdString());
    
}

void OneDriveFileExplorer::on_pushButton_delete_clicked()
{
    QFileInfo fileToDelInfo(m_selectedFile);
    if (fileToDelInfo.suffix() == "")
    {
        QDir dirToDel = m_selectedFile;
        dirToDel.removeRecursively();
    }
    else
    {
        QFile fileToDel = m_selectedFile;
        fileToDel.remove();
    }
}

void OneDriveFileExplorer::on_pushButton_rename_clicked()
{
    QString newName = QInputDialog::getText(this, "Rename file", "Enter a new name: ");

    QFileInfo fileToChange(m_selectedFile);
    QString extension = fileToChange.suffix();
    QDir currentDir(fileToChange.absoluteDir());  /// fix bug! -doesnt take path.
    currentDir.rename(fileToChange.absoluteFilePath(), newName + '.' + extension);
}

void OneDriveFileExplorer::on_pushButton_createdir_clicked()
{
    QString newName = QInputDialog::getText(this, "Create new directory", "Enter a name: ");

    QFileInfo fileToChange(m_selectedFile);
    QDir currentDir(fileToChange.absoluteDir());  /// fix bug! -doesnt take path.
    QDir(currentDir).mkdir(newName); /// fix bug! - doesnt take path.
}

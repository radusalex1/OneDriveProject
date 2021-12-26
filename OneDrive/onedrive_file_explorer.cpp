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

OneDriveFileExplorer::OneDriveFileExplorer(QWidget* parent)
    : QDialog(parent)
{
    ui.setupUi(this);

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
    QString filename = "SendFilesDetails.txt";
    QFile file(filename);
    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);
        stream << 2 << "\n";
        stream << FileSourcePath.c_str()<<"\n";
        stream << Path.c_str()<<"\n";
    }

    /// client process should start here:)))
    QProcess process;
    QFile file1 = "..\\Client\\x64\\Release\\Client.exe";
    process.startDetached(file1.fileName());
    //process.waitForFinished();

}

void OneDriveFileExplorer::on_treeViewPC_doubleClicked(QModelIndex index)
{
    QDesktopServices::openUrl(QUrl::fromLocalFile(selectedFile));
}
void OneDriveFileExplorer::on_treeViewDrive_clicked(QModelIndex index)
{
    selectedFile = dirmodelDrive->fileInfo(index).absoluteFilePath();
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
    
}

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

OneDriveFileExplorer::OneDriveFileExplorer(QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    this->setWindowIcon(QIcon("Logo.png"));//Generate window icon
    this->setWindowState(Qt::WindowMinimized);
    
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
    
    QString dirPath = dirmodel->fileInfo(index).absoluteFilePath();
    selectedFile = dirPath;

    QLabel* pathToFile = new QLabel(this);
    pathToFile->setText(dirPath.toStdString().c_str());

    /*qDebug()<< dirPath.toStdString().c_str();*/
    //qDebug()<< this->Path.c_str();

    std::string FileSourcePath = dirPath.toStdString();
    //qDebug() << FileSourcePath.c_str();

    /*Client_Class client;
    client.sendFiles(FileSourcePath.c_str(), this->Path);*/ //- old method

    sendFiles(FileSourcePath, this->Path); //-new method

    //ui.listView->setRootIndex(filemodel->setRootPath(dirPath));

}

OneDriveFileExplorer::OneDriveFileExplorer(std::string username, QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    this->Username = username;
    this->Path = GetUserPathToFiles(); /// aici ii dau calea din fisiere.


    this->setWindowIcon(QIcon("Logo.png"));//Generate window icon
    this->setWindowState(Qt::WindowMinimized);

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
void OneDriveFileExplorer::SendUserOption(SOCKET sock, std::string userOptionStr)
{
    int userOption = send(sock, userOptionStr.c_str(), sizeof(int), 0);
    if (userOption == 0 || userOption == -1) {
        closesocket(sock);
        WSACleanup();
        return;
    }
}
void OneDriveFileExplorer::sendFiles(std::string SourcePathFile, std::string DestinationPath)
{
    Client_Class c;
    SOCKET sock = c.initializeSocket();
    SendUserOption(sock, "get");
    bool clientClose = false;

    const int BUFFER_SIZE = 1024;
    char bufferFile[BUFFER_SIZE];

    std::ifstream file;

    std::string fileRequested = SourcePathFile;
    std::filesystem::path p(fileRequested);
    std::string destinationPath = DestinationPath;

    
        int byRecv = send(sock, p.filename().string().c_str(), FILENAME_MAX, 0); //send filename
        send(sock, destinationPath.c_str(), FILENAME_MAX, 0); //send desti path

        qDebug() << sock;
        qDebug() << byRecv;
        qDebug() << p.filename().string().c_str();
        qDebug() << destinationPath.c_str();

        if (byRecv == 0 || byRecv == -1) {
            // error receive data - break loop
            clientClose = true;
        }
        // open file
        file.open(fileRequested, std::ios::binary);

        // get file size
        file.seekg(0, std::ios::end);
        long fileSize = file.tellg();

        qDebug() << fileSize;
        // send filesize to client
        int bySendinfo = send(sock, (char*)&fileSize, sizeof(long), 0);

        if (bySendinfo == 0 || bySendinfo == -1) {
            // error sending data - break loop
            clientClose = true;
        }
        file.seekg(0, std::ios::beg);
        // read file with do-while loop
        do {
            // read and send part file to client
            file.read(bufferFile, BUFFER_SIZE);
            qDebug() << bufferFile;
            if (file.gcount() > 0)
                bySendinfo = send(sock, bufferFile, file.gcount(), 0);

            if (bySendinfo == 0 || bySendinfo == -1) {
                // error sending data - break loop
                clientClose = true;
                break;
            }
        } while (file.gcount() > 0);
        file.close();
}
void OneDriveFileExplorer::getFiles(std::string, std::string)
{

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

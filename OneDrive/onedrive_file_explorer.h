#pragma once

#include <QtWidgets/QWidget>
#include <QtCore>
#include <QtGui>
#include "ui_onedrive_file_explorer.h"

class OneDriveFileExplorer : public QWidget
{
    Q_OBJECT

public:
    OneDriveFileExplorer(QWidget* parent = Q_NULLPTR);
    OneDriveFileExplorer(std::string username, QWidget* parent = Q_NULLPTR);
    std::string GetUserPathToFiles();

    void SendUserOption(SOCKET sock, std::string);
    void sendFiles(std::string, std::string);
    void getFiles(std::string, std::string);

private slots:
    void on_treeViewPC_clicked(QModelIndex index);
    void on_treeViewPC_doubleClicked(QModelIndex index);
    void on_treeViewDrive_clicked(QModelIndex index);
    void on_treeViewDrive_doubleClicked(QModelIndex index);
private:
    std::string Username;
    std::string Path;
    QString selectedFile;
    Ui::fileExplorerUI ui;
    QFileSystemModel* dirmodel;
    QFileSystemModel* dirmodelDrive;
};

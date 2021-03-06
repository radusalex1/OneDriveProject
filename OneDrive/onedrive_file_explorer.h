#pragma once
#include <QtWidgets/QWidget>
#include <QtCore>
#include <QtGui>
#include<QDialog>
#include "ui_onedrive_file_explorer.h"

class OneDriveFileExplorer : public QDialog
{
    Q_OBJECT

public:
    OneDriveFileExplorer(QWidget* parent = Q_NULLPTR);
    OneDriveFileExplorer(std::string username, QWidget* parent = Q_NULLPTR);
    ~OneDriveFileExplorer();
    std::string GetUserPathToFiles();
    void SendFilesNewMethod(const std::string & FileSourcePath, const std::string& Path);
    void GetFilesNewMethod(const std::string & destinationPath);
    void ServerProcess();
    void ClientProcess();

private slots:
    void on_treeViewPC_clicked(QModelIndex index);
    void on_treeViewPC_doubleClicked(QModelIndex index);
    void on_treeViewDrive_clicked(QModelIndex index);
    void on_treeViewDrive_doubleClicked(QModelIndex index);
    void on_pushButton_LR_clicked();
    void on_pushButton_RL_clicked();
    void on_pushButton_delete_clicked();
    void on_pushButton_rename_clicked();
    void on_pushButton_createdir_clicked();

private:
    std::string m_Username;
    std::string m_Path;
    QString m_selectedFile;
    Ui::fileExplorerUI m_ui;
    QFileSystemModel* m_dirmodel;
    QFileSystemModel* m_dirmodelDrive;
};

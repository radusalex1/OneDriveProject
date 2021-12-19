#pragma once

#include <QtWidgets/QWidget>
#include <QtCore>
#include <QtGui>
#include "ui_onedrive_mainwindow.h"

class OneDriveMainWindow : public QWidget
{
    Q_OBJECT
       
public:

    OneDriveMainWindow();
    OneDriveMainWindow(std::string username);

private slots:
    void on_pushButton_addfile_clicked();
    void on_pushButton_delete_clicked();
    void on_treeView_clicked(QModelIndex index);
    void on_treeView_doubleClicked(QModelIndex index);
    void on_pushButton_rename_clicked();

private:
    std::string Username;
    std::string Path;
    QString selectedFile;
    Ui::mainwindowUI ui;
    QFileSystemModel* dirmodel;
    std::string GetUserPathToFiles();

};

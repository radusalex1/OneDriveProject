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
    OneDriveMainWindow(const std::string &username);
    ~OneDriveMainWindow();

private slots:
    void on_pushButton_addfile_clicked();
    void on_pushButton_delete_clicked();
    void on_treeView_clicked(QModelIndex index);
    void on_treeView_doubleClicked(QModelIndex index);
    void on_pushButton_rename_clicked();
    void on_pushButton_createdir_clicked();

private:
    std::string m_Username;
    std::string m_Path;
    QString m_selectedFile;
    Ui::mainwindowUI m_ui;
    QFileSystemModel* m_dirmodel;
    std::string GetUserPathToFiles();

};

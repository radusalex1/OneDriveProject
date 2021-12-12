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
private slots:
    void on_treeView_clicked(QModelIndex index);
private:
    std::string Username;
    std::string Path;
    Ui::fileExplorerUI ui;
    QFileSystemModel* dirmodel;
    QFileSystemModel* dirmodelDrive;
};

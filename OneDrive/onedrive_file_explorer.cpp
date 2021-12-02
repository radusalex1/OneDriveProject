#include "onedrive_file_explorer.h"

OneDriveFileExplorer::OneDriveFileExplorer(QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    
    QString dirPath = "C:/";
    dirmodel = new QFileSystemModel(this);
    dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files);
    dirmodel->setRootPath(dirPath);

    ui.treeViewPC->setModel(dirmodel);

    /*filemodel = new QFileSystemModel(this);
    filemodel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
    filemodel->setRootPath(dirPath);

    ui.listView->setModel(filemodel);*/
}

void OneDriveFileExplorer::on_treeView_clicked(QModelIndex index)
{
    /*QString dirPath = dirmodel->fileInfo(index).absoluteFilePath();
    ui.listView->setRootIndex(filemodel->setRootPath(dirPath));*/
}
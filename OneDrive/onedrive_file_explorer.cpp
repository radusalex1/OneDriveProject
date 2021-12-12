#include "onedrive_file_explorer.h"
#include "DataBaseConnect.h"

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

void OneDriveFileExplorer::on_treeView_clicked(QModelIndex index)
{
    /*QString dirPath = dirmodel->fileInfo(index).absoluteFilePath();
    ui.listView->setRootIndex(filemodel->setRootPath(dirPath));*/
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

#include "onedrive_mainwindow.h"
#include "onedrive_file_explorer.h"
#include <string>
#include <QMessageBox>
#include <QPixmap>
#include <QLabel>
#include "DataBaseConnect.h"

OneDriveMainWindow::OneDriveMainWindow()
{
    ui.setupUi(this);

    QPixmap background("BackgroundLoginImg.jpg");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);

    this->setWindowIcon(QIcon("Logo.png"));//Generate window icon

    QString dirPath = "C:/";
    dirmodel = new QFileSystemModel(this);
    dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files);
    dirmodel->setRootPath(dirPath);

    ui.treeView->setModel(dirmodel);

}

void OneDriveMainWindow::on_pushButton_addfile_clicked()
{
    OneDriveFileExplorer* onedriveFileExplorer = new OneDriveFileExplorer(this);
    onedriveFileExplorer->setWindowTitle("OneDrive - File Explorer");
    onedriveFileExplorer->setWindowFlags(Qt::Window);
    onedriveFileExplorer->setAttribute(Qt::WA_DeleteOnClose, true);   //delete itself on closing
    QObject::connect(onedriveFileExplorer, SIGNAL(destroyed(QObject*)), this, SLOT(show()));
    onedriveFileExplorer->show();
}

OneDriveMainWindow::OneDriveMainWindow(std::string username)
{
    ui.setupUi(this);

    QPixmap background("BackgroundLoginImg.jpg");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);

    this->setWindowIcon(QIcon("Logo.png"));//Generate window icon

    QString dirPath = "C:/";
    dirmodel = new QFileSystemModel(this);
    dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files);
    dirmodel->setRootPath(dirPath);

    ui.treeView->setModel(dirmodel);

    this->Username = username;
    this->Path = GetUserPathToFiles(this->Username);
    QLabel *welcomeLabel = new QLabel(this);
    std::string WelcomeMessage ="            welcome back:" + this->Username;
    welcomeLabel->setText(WelcomeMessage.c_str());

}

std::string GetUserPathToFiles(std::string username)
{
    DataBaseConnect *dbc = new DataBaseConnect();
    return dbc->GetUserPath(username);

}

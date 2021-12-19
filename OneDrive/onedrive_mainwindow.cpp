#include "onedrive_mainwindow.h"
#include "onedrive_file_explorer.h"
#include <string>
#include <QMessageBox>
#include <QPixmap>
#include <QLabel>
#include <qinputdialog.h>
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
    OneDriveFileExplorer* onedriveFileExplorer = new OneDriveFileExplorer(this->Username, this);
    onedriveFileExplorer->setWindowTitle("OneDrive - File Explorer");
    onedriveFileExplorer->setWindowFlags(Qt::Window);
    onedriveFileExplorer->setAttribute(Qt::WA_DeleteOnClose, true);   //delete itself on closing
    QObject::connect(onedriveFileExplorer, SIGNAL(destroyed(QObject*)), this, SLOT(show()));
    onedriveFileExplorer->show();
}

OneDriveMainWindow::OneDriveMainWindow(std::string username)
{
    ui.setupUi(this);

    this->Username = username;
    this->Path = GetUserPathToFiles(); /// aici ii dau calea din fisiere. -working

    QPixmap background("BackgroundLoginImg.jpg");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);

    this->setWindowIcon(QIcon("Logo.png"));//Generate window icon

    QString dirPath = this->Path.c_str(); ///  aici ii dau calea catre directorul care trebuie afisat - working
    dirmodel = new QFileSystemModel(this);
    dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files);
    dirmodel->setRootPath(dirPath);
    ui.treeView->setModel(dirmodel);
    ui.treeView->setRootIndex(dirmodel->index(dirPath));

    QLabel *welcomeLabel = new QLabel(this);
    std::string WelcomeMessage ="            Welcome back: " + this->Username + " --- "+this->Path;
    welcomeLabel->setText(WelcomeMessage.c_str());

}

void OneDriveMainWindow::on_treeView_clicked(QModelIndex index)
{
    selectedFile = dirmodel->fileInfo(index).absoluteFilePath();
}

void OneDriveMainWindow::on_treeView_doubleClicked(QModelIndex index)
{
    QDesktopServices::openUrl(QUrl::fromLocalFile(selectedFile));
}

void OneDriveMainWindow::on_pushButton_rename_clicked()
{
    QString newName = QInputDialog::getText(this, "Rename file", "Enter a new name: ");

    QFileInfo fileToChange(selectedFile);
    QString extension = fileToChange.suffix();
    QDir currentDir(this->Path.c_str());
    currentDir.rename(fileToChange.absoluteFilePath(), newName + '.' + extension);
}

void OneDriveMainWindow::on_pushButton_delete_clicked()
{
    QFile fileToDel = selectedFile;
    fileToDel.remove();
}

std::string OneDriveMainWindow::GetUserPathToFiles()
{
    DataBaseConnect* dbc = new DataBaseConnect();
    return dbc->GetUserPath(this->Username);
}

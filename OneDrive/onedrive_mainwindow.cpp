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
    m_ui.setupUi(this);

    QPixmap background("BackgroundLoginImg.jpg");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);

    this->setWindowIcon(QIcon("Logo.png"));//Generate window icon

    QString dirPath = "C:/";
    m_dirmodel = new QFileSystemModel(this);
    m_dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files);
    m_dirmodel->setRootPath(dirPath);

    m_ui.treeView->setModel(m_dirmodel);

}

void OneDriveMainWindow::on_pushButton_addfile_clicked()
{
    OneDriveFileExplorer* onedriveFileExplorer = new OneDriveFileExplorer(this->m_Username, this);
    onedriveFileExplorer->setWindowTitle("OneDrive - File Explorer");
    onedriveFileExplorer->setWindowFlags(Qt::Window);
    onedriveFileExplorer->setAttribute(Qt::WA_DeleteOnClose, true);   //delete itself on closing
    QObject::connect(onedriveFileExplorer, SIGNAL(destroyed(QObject*)), this, SLOT(show()));
    onedriveFileExplorer->open();
}

OneDriveMainWindow::OneDriveMainWindow(std::string username)
{
    m_ui.setupUi(this);

    this->m_Username = username;
    this->m_Path = GetUserPathToFiles(); /// aici ii dau calea din fisiere. -working

    QPixmap background("BackgroundLoginImg.jpg");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);

    this->setWindowIcon(QIcon("Logo.png"));//Generate window icon

    QString dirPath = this->m_Path.c_str(); ///  aici ii dau calea catre directorul care trebuie afisat - working
    m_dirmodel = new QFileSystemModel(this);
    m_dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files);
    m_dirmodel->setRootPath(dirPath);
    m_ui.treeView->setModel(m_dirmodel);
    m_ui.treeView->setRootIndex(m_dirmodel->index(dirPath));

    QLabel *welcomeLabel = new QLabel(this);
    std::string WelcomeMessage ="            Welcome back: " + this->m_Username + " --- "+this->m_Path;
    welcomeLabel->setText(WelcomeMessage.c_str());

}

OneDriveMainWindow::~OneDriveMainWindow()
{
    delete[] m_dirmodel;
}

void OneDriveMainWindow::on_treeView_clicked(QModelIndex index)
{
    m_selectedFile = m_dirmodel->fileInfo(index).absoluteFilePath();
}

void OneDriveMainWindow::on_treeView_doubleClicked(QModelIndex index)
{
    QDesktopServices::openUrl(QUrl::fromLocalFile(m_selectedFile));
}

void OneDriveMainWindow::on_pushButton_rename_clicked()
{
    QString newName = QInputDialog::getText(this, "Rename file", "Enter a new name: ");

    QFileInfo fileToChange(m_selectedFile);
    QString extension = fileToChange.suffix();
    QDir currentDir(this->m_Path.c_str());
    currentDir.rename(fileToChange.absoluteFilePath(), newName + '.' + extension);
}

void OneDriveMainWindow::on_pushButton_createdir_clicked()
{
    QString newName = QInputDialog::getText(this, "Create new directory", "Enter a name: ");

    QDir selectedDir(m_selectedFile);
    if (selectedDir.exists())
    {
        selectedDir.mkdir(newName);
    }
    else
    {
        QDir(this->m_Path.c_str()).mkdir(newName);
    }
}

void OneDriveMainWindow::on_pushButton_delete_clicked()
{
    QFileInfo fileToDelInfo(m_selectedFile);
    if (fileToDelInfo.suffix() == "")
    {
        QDir dirToDel = m_selectedFile;
        dirToDel.removeRecursively();
    }
    else
    {
        QFile fileToDel = m_selectedFile;
        fileToDel.remove();
    }
    
}

std::string OneDriveMainWindow::GetUserPathToFiles()
{
    DataBaseConnect* dbc = new DataBaseConnect();
    return dbc->GetUserPath(this->m_Username);
}

#include "onedrive_mainwindow.h"
#include <string>
#include <QMessageBox>
#include <QPixmap>

OneDriveMainWindow::OneDriveMainWindow(QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi_mainwindowUI(this);
    QPixmap folderpic("FolderImage.jpg");
    int width = ui.label_foldericon->width();
    int height = ui.label_foldericon->height();
    ui.label_foldericon->setPixmap(folderpic.scaled(width, height, Qt::KeepAspectRatio));

    QPixmap background("BackgroundLoginImg.jpg");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);
}

void OneDriveMainWindow::on_pushButton_addfile_clicked()
{
    
}
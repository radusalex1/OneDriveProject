#include "onedrive.h"
#include <string>
#include <QMessageBox>
#include <QPixmap>
#include<QDebug>
#include "DataBaseConnect.h"
#include "onedrive_mainwindow.h"



OneDrive::OneDrive(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    QPixmap background("BackgroundLoginImg.jpg");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);

    QPixmap folderpic("Logo.png");
    int width = ui.label_picture->width();
    int height = ui.label_picture->height();
    ui.label_picture->setPixmap(folderpic.scaled(width, height, Qt::KeepAspectRatio));

    this->setWindowIcon(QIcon("Logo.png"));//Generate window icon
}   

void OneDrive::on_pushButton_login_clicked()
{
    std::string username = ui.line_username->text().toStdString();
    std::string password = ui.line_password->text().toStdString();

    /// <summary>
    /// basically check here if username and password are corect;-done
    /// </summary>
   
    DataBaseConnect *dbc = new DataBaseConnect();

    if (dbc->isUser(username,password)) 
    {
        //QMessageBox::information(this, "Login", "Username and password is correct");
        this->hide();
        OneDriveMainWindow* mainWindow = new OneDriveMainWindow(this);
        mainWindow->setWindowTitle("OneDrive - MainWindow");
        mainWindow->setWindowFlags(Qt::Window);
        mainWindow->setAttribute(Qt::WA_DeleteOnClose, true);   //delete itself on closing
        QObject::connect(mainWindow, SIGNAL(destroyed(QObject*)), this, SLOT(show()));
        mainWindow->show();
    }
    else {
        QMessageBox::warning(this, "Login", "Username and password is not correct");
    }
}

void OneDrive::on_pushButton_register_clicked()
{
    this->hide();
    onedriveRegister = new OneDriveRegister(this);
    onedriveRegister->setWindowTitle("OneDrive - Register");
    onedriveRegister->setWindowFlags(Qt::Window);
    onedriveRegister->setAttribute(Qt::WA_DeleteOnClose, true);   //delete itself on closing
    QObject::connect(onedriveRegister, SIGNAL(destroyed(QObject*)), this, SLOT(show()));
    onedriveRegister->show(); 
}

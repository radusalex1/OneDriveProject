#include "onedrive.h"
#include <string>
#include <QMessageBox>
#include <QPixmap>
#include<QDebug>
#include "DataBaseConnect.h"



OneDrive::OneDrive(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    QPixmap background("BackgroundLoginImg.jpg");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);
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
        QMessageBox::information(this, "Login", "Username and password is correct");
    }
    else {
        QMessageBox::warning(this, "Login", "Username and password is not correct");
    }
}

void OneDrive::on_pushButton_register_clicked()
{
    this->hide();
    onedriveRegister = new OneDriveRegister(this);
    onedriveRegister->setWindowTitle("Register");
    onedriveRegister->setWindowFlags(Qt::Window);
    onedriveRegister->setAttribute(Qt::WA_DeleteOnClose, true);   //delete itself on closing
    QObject::connect(onedriveRegister, SIGNAL(destroyed(QObject*)), this, SLOT(show()));
    onedriveRegister->show(); 
}

#include "onedrive.h"
#include <string>
#include <QMessageBox>
#include <QPixmap>

OneDrive::OneDrive(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    /*QPixmap background(":/OneDrive/C:/Users/Mircea/Downloads/abstract-background-with-ink.jpg");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);*/
}

void OneDrive::on_pushButton_login_clicked()
{
    QString username = ui.line_username->text();
    QString password = ui.line_password->text();

    if (username == "test" && password == "test") {
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

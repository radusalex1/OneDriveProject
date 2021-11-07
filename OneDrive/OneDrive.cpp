#include "onedrive.h"
#include <qmessagebox.h>
#include <iostream>

OneDrive::OneDrive(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
}

void OneDrive::on_pushButton_login_clicked()
{
    QString username = ui.line_username->text();
    QString password = ui.line_password->text();
 

    if (username == "test" && password == "pass")
    {
        QMessageBox::information(this, "Login", "username and password correct");
    }
    else
    {
        QMessageBox::information(this, "Login", "username and password incorrect");

    }

}

void OneDrive::on_Close_clicked()
{
    close();
}

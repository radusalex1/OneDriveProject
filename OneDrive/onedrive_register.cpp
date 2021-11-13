#include "onedrive_register.h"
#include <string>
#include <QMessageBox>
#include <QPixmap>
#include "DataBaseConnect.h"

OneDriveRegister::OneDriveRegister(QWidget* parent)
    : QWidget(parent)
{
   ui.setupUi(this);
   
    QPixmap background("BackgroundLoginImg.jpg");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);
}

void OneDriveRegister::on_pushButton_registerMethod_clicked()
{
    close();
    std::string newUserUsername = ui.line_username->text().toStdString();
    std::string newUserPassword = ui.line_password->text().toStdString();
    DataBaseConnect* dbc = new DataBaseConnect();

    dbc->newUSerRegisterCredentials(newUserUsername, newUserPassword);

}

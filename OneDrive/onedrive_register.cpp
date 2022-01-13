#include "onedrive_register.h"
#include "onedrive.h"
#include <string>
#include <QMessageBox>
#include <QPixmap>
#include "DataBaseConnect.h"

OneDriveRegister::OneDriveRegister()
{
    m_ui.setupUi(this);
   
    QPixmap background("BackgroundLoginImg.jpg");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);

    QPixmap folderpic("Logo.png");
    int width = m_ui.label_pic->width();
    int height = m_ui.label_pic->height();
    m_ui.label_pic->setPixmap(folderpic.scaled(width, height, Qt::KeepAspectRatio));

    this->setWindowIcon(QIcon("Logo.png"));//Generate window icon.
}

void OneDriveRegister::on_pushButton_registerMethod_clicked()
{
    

    std::string newUserUsername = m_ui.line_username->text().toStdString();
    std::string newUserPassword = m_ui.line_password->text().toStdString();
    DataBaseConnect* dbc = new DataBaseConnect();

    if (dbc->isUser(newUserUsername, newUserPassword))
    {
        QMessageBox::warning(this, "Register", "Username already exists!");
    }
    else
    {
        dbc->newUSerRegisterCredentials(newUserUsername, newUserPassword);
        this->hide();
        OneDrive* onedriveLogin = new OneDrive(this);
        onedriveLogin->setWindowTitle("OneDrive - Login");
        onedriveLogin->setWindowFlags(Qt::Window);
        onedriveLogin->setAttribute(Qt::WA_DeleteOnClose, true);   //delete itself on closing
        QObject::connect(onedriveLogin, SIGNAL(destroyed(QObject*)), this, SLOT(show()));
        onedriveLogin->show();
    }
   
}

void OneDriveRegister::on_pushButton_GoBack_clicked()
{
    this->hide();
    OneDrive* onedriveLogin = new OneDrive(this);
    onedriveLogin->setWindowTitle("OneDrive - Login");
    onedriveLogin->setWindowFlags(Qt::Window);
    onedriveLogin->setAttribute(Qt::WA_DeleteOnClose, true);   //delete itself on closing
    QObject::connect(onedriveLogin, SIGNAL(destroyed(QObject*)), this, SLOT(show()));
    onedriveLogin->show();
}

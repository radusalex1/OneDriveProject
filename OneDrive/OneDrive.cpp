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
    m_ui.setupUi(this);
    QPixmap background("BackgroundLoginImg.jpg");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);

    QPixmap folderpic("Logo.png");
    int width = m_ui.label_picture->width();
    int height = m_ui.label_picture->height();
    m_ui.label_picture->setPixmap(folderpic.scaled(width, height, Qt::KeepAspectRatio));

    this->setWindowIcon(QIcon("Logo.png"));//Generate window icon
    
}   

void OneDrive::on_pushButton_login_clicked()
{
    std::string username = m_ui.line_username->text().toStdString();
    std::string password = m_ui.line_password->text().toStdString();

    DataBaseConnect *dbc = new DataBaseConnect();

    if (dbc->isUser(username,password)) 
    {
        this->hide();
        OneDriveMainWindow* mainWindow = new OneDriveMainWindow(username);
        mainWindow->setWindowTitle("OneDrive - MainWindow");
        mainWindow->setWindowFlags(Qt::Window);
        mainWindow->setAttribute(Qt::WA_DeleteOnClose, true);   //delete itself on closing
        QObject::connect(mainWindow, SIGNAL(destroyed(QObject*)), this, SLOT(show()));
        mainWindow->show();
        //mainWindow->setWindowState(Qt::WindowMinimized);
    }
    else {
        QMessageBox::warning(this, "Login", "Username and password is not correct");
    }
}

OneDrive::~OneDrive()
{
    delete[] m_onedriveRegister;
}

void OneDrive::on_pushButton_register_clicked()
{
    this->hide();
    m_onedriveRegister = new OneDriveRegister();
    m_onedriveRegister->setWindowTitle("OneDrive - Register");
    m_onedriveRegister->setWindowFlags(Qt::Window);
    m_onedriveRegister->setAttribute(Qt::WA_DeleteOnClose, true);   //delete itself on closing
    QObject::connect(m_onedriveRegister, SIGNAL(destroyed(QObject*)), this, SLOT(show()));
    m_onedriveRegister->show(); 
}

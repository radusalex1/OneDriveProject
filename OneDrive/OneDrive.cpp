#include "onedrive.h"
#include <string>
#include <QMessageBox>
#include <QPixmap>
#include<QDebug>
#include <pqxx/pqxx>


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
   
    QString username = ui.line_username->text();
    QString password = ui.line_password->text();

    /// <summary>
    /// basically check here if username and password are corect;
    /// </summary>
   

    std::string connectionstring = "host=localhost port=5432 dbname=test user=postgres password =as";
    qInfo("am ajuns aici");
    try
    {
        pqxx::connection connectionobject(connectionstring.c_str());

        pqxx::work worker(connectionobject);

        pqxx::result response = worker.exec("select count(*)from users;");

        for (size_t i = 0; i < response.size(); i++)
        {
            
            //std::cout << " id: " << response[i][0] << " name: " << response[i][1] << " surname: " << response[i][2] << std::endl;
        }
    }
    catch (const std::exception& e)
    {
        //std::cerr << e.what() << std::endl;
    }
  

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

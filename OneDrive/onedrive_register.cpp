#include "onedrive_register.h"
#include <string>
#include <QMessageBox>
#include <QPixmap>

OneDriveRegister::OneDriveRegister(QWidget* parent)
    : QWidget(parent)
{
   ui.setupUi(this);
   /*
    QPixmap background(":/OneDrive/C:/Users/Mircea/Downloads/abstract-background-with-ink.jpg");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);*/
}

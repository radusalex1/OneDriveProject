#pragma once

#include <QtWidgets/QWidget>
#include "ui_onedrive_register.h"

class OneDriveRegister : public QWidget
{
    Q_OBJECT

public:
    OneDriveRegister();
private slots:
    void on_pushButton_registerMethod_clicked();
    void on_pushButton_GoBack_clicked();

private:
    Ui::registerUI m_ui;
    
    
};

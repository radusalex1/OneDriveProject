#pragma once

#include <QtWidgets/QWidget>
#include "ui_onedrive_register.h"

class OneDriveRegister : public QWidget
{
    Q_OBJECT

public:
    OneDriveRegister(QWidget* parent = Q_NULLPTR);
private slots:
    void on_pushButton_registerMethod_clicked();

private:
    Ui::registerUI ui;
    
    
};

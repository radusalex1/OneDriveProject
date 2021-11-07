#pragma once

#include <QtWidgets/QWidget>
#include "ui_onedrive.h"

class OneDrive : public QWidget
{
    Q_OBJECT

public:
    OneDrive(QWidget *parent = Q_NULLPTR);
private slots:
    void on_pushButton_login_clicked();
private:
    Ui::OneDriveClass ui;
    
};

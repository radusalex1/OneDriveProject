#pragma once

#include <QtWidgets/QWidget>
#include "ui_onedrive.h"
#include "onedrive_register.h"

class OneDrive : public QWidget
{
    Q_OBJECT

public:

    OneDrive(QWidget *parent = Q_NULLPTR);
    ~OneDrive();

private slots:

    void on_pushButton_login_clicked();
    void on_pushButton_register_clicked();

private:
    Ui::OneDriveClass m_ui;
    OneDriveRegister* m_onedriveRegister;
};

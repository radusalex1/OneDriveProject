#pragma once

#include <QtWidgets/QWidget>
#include "ui_onedrive_register.h"

class OneDriveRegister : public QWidget
{
    Q_OBJECT

public:
    OneDriveRegister(QWidget* parent = Q_NULLPTR);
    void on_pushButton_register_clicked();

private:
    Ui::Form ui;
};

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
    void on_pushButton_ChoosePath_clicked();

private:
    Ui::registerUI m_ui;
    QString m_path;
    
};

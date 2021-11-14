#pragma once

#include <QtWidgets/QWidget>
#include "ui_onedrive_mainwindow.h"

class OneDriveMainWindow : public QWidget
{
    Q_OBJECT

public:
    OneDriveMainWindow(QWidget* parent = Q_NULLPTR);
private slots:
    void on_pushButton_addfile_clicked();

private:
    Ui::Form ui;
};

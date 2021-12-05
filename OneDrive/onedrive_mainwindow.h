#pragma once

#include <QtWidgets/QWidget>
#include <QtCore>
#include <QtGui>
#include "ui_onedrive_mainwindow.h"

class OneDriveMainWindow : public QWidget
{
    Q_OBJECT

public:
    OneDriveMainWindow();
private slots:
    void on_pushButton_addfile_clicked();

private:
    Ui::mainwindowUI ui;
    QFileSystemModel* dirmodel;
};

/********************************************************************************
** Form generated from reading UI file 'onedrive_mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ONEDRIVE_MAINWINDOW_H
#define UI_ONEDRIVE_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainwindowUI
{
public:
    QPushButton *pushButton_addfile;
    QLabel *label_foldericon;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(603, 400);
        pushButton_addfile = new QPushButton(Form);
        pushButton_addfile->setObjectName(QString::fromUtf8("pushButton_addfile"));
        pushButton_addfile->setGeometry(QRect(30, 340, 91, 24));
        label_foldericon = new QLabel(Form);
        label_foldericon->setObjectName(QString::fromUtf8("label_foldericon"));
        label_foldericon->setGeometry(QRect(30, 40, 111, 121));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        pushButton_addfile->setText(QCoreApplication::translate("Form", "Add new file", nullptr));
        label_foldericon->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class mainwindowUI : public Ui_mainwindowUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONEDRIVE_MAINWINDOW_H

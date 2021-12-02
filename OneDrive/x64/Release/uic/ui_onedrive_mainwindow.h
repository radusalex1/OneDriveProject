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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_MainWindow
{
public:
    QPushButton *pushButton_addfile;
    QTreeView *treeView;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(600, 400);
        pushButton_addfile = new QPushButton(Form);
        pushButton_addfile->setObjectName(QString::fromUtf8("pushButton_addfile"));
        pushButton_addfile->setGeometry(QRect(30, 340, 91, 24));
        treeView = new QTreeView(Form);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setGeometry(QRect(30, 20, 531, 301));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        pushButton_addfile->setText(QCoreApplication::translate("Form", "Add new file", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainwindowUI: public Ui_Form_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONEDRIVE_MAINWINDOW_H

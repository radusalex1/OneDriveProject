/********************************************************************************
** Form generated from reading UI file 'onedrive_file_explorer.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ONEDRIVE_FILE_EXPLORER_H
#define UI_ONEDRIVE_FILE_EXPLORER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_FileExplorer
{
public:
    QTreeView *treeViewPC;
    QTreeView *treeViewDrive;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_delete;
    QPushButton *pushButton_rename;
    QPushButton *pushButton_createdir;
    QPushButton *pushButton__RL;
    QPushButton *pushButton_LR;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(956, 502);
        treeViewPC = new QTreeView(Form);
        treeViewPC->setObjectName(QString::fromUtf8("treeViewPC"));
        treeViewPC->setGeometry(QRect(52, 50, 331, 371));
        treeViewDrive = new QTreeView(Form);
        treeViewDrive->setObjectName(QString::fromUtf8("treeViewDrive"));
        treeViewDrive->setGeometry(QRect(570, 50, 331, 371));
        label = new QLabel(Form);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(52, 20, 71, 20));
        label_2 = new QLabel(Form);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(570, 20, 71, 16));
        pushButton_delete = new QPushButton(Form);
        pushButton_delete->setObjectName(QString::fromUtf8("pushButton_delete"));
        pushButton_delete->setGeometry(QRect(340, 450, 75, 24));
        pushButton_rename = new QPushButton(Form);
        pushButton_rename->setObjectName(QString::fromUtf8("pushButton_rename"));
        pushButton_rename->setGeometry(QRect(430, 450, 75, 24));
        pushButton_createdir = new QPushButton(Form);
        pushButton_createdir->setObjectName(QString::fromUtf8("pushButton_createdir"));
        pushButton_createdir->setGeometry(QRect(520, 450, 91, 24));
        pushButton__RL = new QPushButton(Form);
        pushButton__RL->setObjectName(QString::fromUtf8("pushButton__RL"));
        pushButton__RL->setGeometry(QRect(400, 170, 151, 24));
        pushButton_LR = new QPushButton(Form);
        pushButton_LR->setObjectName(QString::fromUtf8("pushButton_LR"));
        pushButton_LR->setGeometry(QRect(400, 250, 151, 24));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        label->setText(QCoreApplication::translate("Form", "Local drive", nullptr));
        label_2->setText(QCoreApplication::translate("Form", "Server drive", nullptr));
        pushButton_delete->setText(QCoreApplication::translate("Form", "Delete file", nullptr));
        pushButton_rename->setText(QCoreApplication::translate("Form", "Rename file", nullptr));
        pushButton_createdir->setText(QCoreApplication::translate("Form", "Create directory", nullptr));
        pushButton__RL->setText(QString());
        pushButton_LR->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class fileExplorerUI: public Ui_Form_FileExplorer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONEDRIVE_FILE_EXPLORER_H

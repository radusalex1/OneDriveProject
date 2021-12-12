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

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(602, 435);
        treeViewPC = new QTreeView(Form);
        treeViewPC->setObjectName(QString::fromUtf8("treeViewPC"));
        treeViewPC->setGeometry(QRect(10, 50, 281, 371));
        treeViewDrive = new QTreeView(Form);
        treeViewDrive->setObjectName(QString::fromUtf8("treeViewDrive"));
        treeViewDrive->setGeometry(QRect(310, 50, 281, 371));
        label = new QLabel(Form);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(18, 16, 71, 20));
        label_2 = new QLabel(Form);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(310, 20, 71, 16));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        label->setText(QCoreApplication::translate("Form", "Local drive", nullptr));
        label_2->setText(QCoreApplication::translate("Form", "Server drive", nullptr));
    } // retranslateUi

};

namespace Ui {
    class fileExplorerUI: public Ui_Form_FileExplorer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONEDRIVE_FILE_EXPLORER_H

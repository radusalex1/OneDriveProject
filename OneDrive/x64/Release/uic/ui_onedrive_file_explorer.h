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
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_FileExplorer
{
public:
    QTreeView *treeViewPC;
    QTreeView *treeViewDrive;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(603, 400);
        treeViewPC = new QTreeView(Form);
        treeViewPC->setObjectName(QString::fromUtf8("treeViewPC"));
        treeViewPC->setGeometry(QRect(10, 10, 281, 371));
        treeViewDrive = new QTreeView(Form);
        treeViewDrive->setObjectName(QString::fromUtf8("treeViewDrive"));
        treeViewDrive->setGeometry(QRect(310, 10, 281, 371));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class fileExplorerUI: public Ui_Form_FileExplorer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONEDRIVE_FILE_EXPLORER_H

/********************************************************************************
** Form generated from reading UI file 'onedrive.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ONEDRIVE_H
#define UI_ONEDRIVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OneDriveClass
{
public:
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *line_username;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *line_password;
    QPushButton *pushButton_login;
    QPushButton *pushButton_register;
    QLabel *label_picture;

    void setupUi(QWidget *OneDriveClass)
    {
        if (OneDriveClass->objectName().isEmpty())
            OneDriveClass->setObjectName(QString::fromUtf8("OneDriveClass"));
        OneDriveClass->resize(603, 400);
        OneDriveClass->setStyleSheet(QString::fromUtf8(""));
        groupBox = new QGroupBox(OneDriveClass);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(230, 70, 331, 211));
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(7, 9, 5, -1);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        line_username = new QLineEdit(groupBox);
        line_username->setObjectName(QString::fromUtf8("line_username"));

        horizontalLayout->addWidget(line_username);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        line_password = new QLineEdit(groupBox);
        line_password->setObjectName(QString::fromUtf8("line_password"));
        line_password->setEnabled(true);
        line_password->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(line_password);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        pushButton_login = new QPushButton(groupBox);
        pushButton_login->setObjectName(QString::fromUtf8("pushButton_login"));

        verticalLayout_2->addWidget(pushButton_login);

        pushButton_register = new QPushButton(groupBox);
        pushButton_register->setObjectName(QString::fromUtf8("pushButton_register"));

        verticalLayout_2->addWidget(pushButton_register);

        label_picture = new QLabel(OneDriveClass);
        label_picture->setObjectName(QString::fromUtf8("label_picture"));
        label_picture->setGeometry(QRect(30, 80, 181, 201));
        label_picture->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(OneDriveClass);

        QMetaObject::connectSlotsByName(OneDriveClass);
    } // setupUi

    void retranslateUi(QWidget *OneDriveClass)
    {
        OneDriveClass->setWindowTitle(QCoreApplication::translate("OneDriveClass", "OneDrive", nullptr));
        groupBox->setTitle(QCoreApplication::translate("OneDriveClass", "SingIn", nullptr));
        label->setText(QCoreApplication::translate("OneDriveClass", "Username", nullptr));
        label_2->setText(QCoreApplication::translate("OneDriveClass", "Password", nullptr));
        pushButton_login->setText(QCoreApplication::translate("OneDriveClass", "Login", nullptr));
        pushButton_register->setText(QCoreApplication::translate("OneDriveClass", "Register", nullptr));
        label_picture->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class OneDriveClass: public Ui_OneDriveClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONEDRIVE_H

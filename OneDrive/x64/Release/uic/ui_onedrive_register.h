/********************************************************************************
** Form generated from reading UI file 'onedrive_register.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ONEDRIVE_REGISTER_H
#define UI_ONEDRIVE_REGISTER_H

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

class Ui_Form_Register
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
    QPushButton *pushButton_ChoosePath;
    QPushButton *pushButton_registerMethod;
    QPushButton *pushButton_GoBack;
    QLabel *label_pic;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(600, 400);
        groupBox = new QGroupBox(Form);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(230, 70, 311, 211));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        line_username = new QLineEdit(groupBox);
        line_username->setObjectName(QString::fromUtf8("line_username"));

        horizontalLayout->addWidget(line_username);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        line_password = new QLineEdit(groupBox);
        line_password->setObjectName(QString::fromUtf8("line_password"));
        line_password->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(line_password);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        pushButton_ChoosePath = new QPushButton(groupBox);
        pushButton_ChoosePath->setObjectName(QString::fromUtf8("pushButton_ChoosePath"));

        verticalLayout_2->addWidget(pushButton_ChoosePath);

        pushButton_registerMethod = new QPushButton(groupBox);
        pushButton_registerMethod->setObjectName(QString::fromUtf8("pushButton_registerMethod"));

        verticalLayout_2->addWidget(pushButton_registerMethod);

        pushButton_GoBack = new QPushButton(groupBox);
        pushButton_GoBack->setObjectName(QString::fromUtf8("pushButton_GoBack"));

        verticalLayout_2->addWidget(pushButton_GoBack);

        label_pic = new QLabel(Form);
        label_pic->setObjectName(QString::fromUtf8("label_pic"));
        label_pic->setGeometry(QRect(28, 75, 181, 201));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Form", "Register", nullptr));
        label->setText(QCoreApplication::translate("Form", "Username", nullptr));
        label_2->setText(QCoreApplication::translate("Form", "Password", nullptr));
        pushButton_ChoosePath->setText(QCoreApplication::translate("Form", "Choose path", nullptr));
        pushButton_registerMethod->setText(QCoreApplication::translate("Form", "Register", nullptr));
        pushButton_GoBack->setText(QCoreApplication::translate("Form", "Return to login", nullptr));
        label_pic->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class registerUI: public Ui_Form_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONEDRIVE_REGISTER_H

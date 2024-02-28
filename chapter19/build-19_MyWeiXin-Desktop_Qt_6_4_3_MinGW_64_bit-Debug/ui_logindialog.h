/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QLabel *label;
    QLineEdit *userLineEdit;
    QLineEdit *pwdLineEdit;
    QPushButton *loginPushButton;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName("LoginDialog");
        LoginDialog->resize(369, 423);
        label = new QLabel(LoginDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 361, 411));
        label->setFrameShape(QFrame::NoFrame);
        label->setFrameShadow(QFrame::Sunken);
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/login.jpg")));
        userLineEdit = new QLineEdit(LoginDialog);
        userLineEdit->setObjectName("userLineEdit");
        userLineEdit->setGeometry(QRect(110, 230, 141, 31));
        QFont font;
        font.setPointSize(10);
        userLineEdit->setFont(font);
        userLineEdit->setAlignment(Qt::AlignCenter);
        pwdLineEdit = new QLineEdit(LoginDialog);
        pwdLineEdit->setObjectName("pwdLineEdit");
        pwdLineEdit->setGeometry(QRect(110, 260, 141, 31));
        pwdLineEdit->setEchoMode(QLineEdit::Password);
        pwdLineEdit->setAlignment(Qt::AlignCenter);
        loginPushButton = new QPushButton(LoginDialog);
        loginPushButton->setObjectName("loginPushButton");
        loginPushButton->setGeometry(QRect(50, 290, 251, 41));
        loginPushButton->setFont(font);
        loginPushButton->setFlat(true);

        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "Dialog", nullptr));
        label->setText(QString());
        loginPushButton->setText(QCoreApplication::translate("LoginDialog", "\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H

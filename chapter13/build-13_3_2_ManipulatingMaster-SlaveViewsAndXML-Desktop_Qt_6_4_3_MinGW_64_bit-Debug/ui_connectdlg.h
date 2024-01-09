/********************************************************************************
** Form generated from reading UI file 'connectdlg.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTDLG_H
#define UI_CONNECTDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_QSqlConnectionDialogUi
{
public:
    QGroupBox *connGroupBox;
    QLabel *textLabel2;
    QLabel *textLabel3;
    QLabel *textLabel4;
    QLabel *textLabel4_2;
    QLabel *textLabel5;
    QLabel *textLabrl5_2;
    QComboBox *comboDriver;
    QLineEdit *editDatabase;
    QLineEdit *editUsername;
    QLineEdit *editPassword;
    QLineEdit *editHostname;
    QSpinBox *portSpinBox;
    QLabel *status_label;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *QSqlConnectionDialogUi)
    {
        if (QSqlConnectionDialogUi->objectName().isEmpty())
            QSqlConnectionDialogUi->setObjectName("QSqlConnectionDialogUi");
        QSqlConnectionDialogUi->resize(396, 449);
        connGroupBox = new QGroupBox(QSqlConnectionDialogUi);
        connGroupBox->setObjectName("connGroupBox");
        connGroupBox->setGeometry(QRect(20, 20, 351, 301));
        textLabel2 = new QLabel(connGroupBox);
        textLabel2->setObjectName("textLabel2");
        textLabel2->setGeometry(QRect(20, 40, 62, 18));
        textLabel3 = new QLabel(connGroupBox);
        textLabel3->setObjectName("textLabel3");
        textLabel3->setGeometry(QRect(20, 80, 62, 18));
        textLabel4 = new QLabel(connGroupBox);
        textLabel4->setObjectName("textLabel4");
        textLabel4->setGeometry(QRect(20, 130, 62, 18));
        textLabel4_2 = new QLabel(connGroupBox);
        textLabel4_2->setObjectName("textLabel4_2");
        textLabel4_2->setGeometry(QRect(20, 170, 62, 18));
        textLabel5 = new QLabel(connGroupBox);
        textLabel5->setObjectName("textLabel5");
        textLabel5->setGeometry(QRect(20, 210, 62, 18));
        textLabrl5_2 = new QLabel(connGroupBox);
        textLabrl5_2->setObjectName("textLabrl5_2");
        textLabrl5_2->setGeometry(QRect(20, 250, 62, 18));
        comboDriver = new QComboBox(connGroupBox);
        comboDriver->setObjectName("comboDriver");
        comboDriver->setGeometry(QRect(100, 40, 221, 26));
        editDatabase = new QLineEdit(connGroupBox);
        editDatabase->setObjectName("editDatabase");
        editDatabase->setGeometry(QRect(100, 80, 221, 26));
        editUsername = new QLineEdit(connGroupBox);
        editUsername->setObjectName("editUsername");
        editUsername->setGeometry(QRect(100, 130, 221, 26));
        editPassword = new QLineEdit(connGroupBox);
        editPassword->setObjectName("editPassword");
        editPassword->setGeometry(QRect(100, 170, 221, 26));
        editHostname = new QLineEdit(connGroupBox);
        editHostname->setObjectName("editHostname");
        editHostname->setGeometry(QRect(100, 210, 221, 26));
        portSpinBox = new QSpinBox(connGroupBox);
        portSpinBox->setObjectName("portSpinBox");
        portSpinBox->setGeometry(QRect(100, 250, 221, 27));
        status_label = new QLabel(QSqlConnectionDialogUi);
        status_label->setObjectName("status_label");
        status_label->setGeometry(QRect(20, 330, 351, 31));
        okButton = new QPushButton(QSqlConnectionDialogUi);
        okButton->setObjectName("okButton");
        okButton->setGeometry(QRect(180, 390, 88, 27));
        cancelButton = new QPushButton(QSqlConnectionDialogUi);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setGeometry(QRect(280, 390, 88, 27));

        retranslateUi(QSqlConnectionDialogUi);

        QMetaObject::connectSlotsByName(QSqlConnectionDialogUi);
    } // setupUi

    void retranslateUi(QDialog *QSqlConnectionDialogUi)
    {
        QSqlConnectionDialogUi->setWindowTitle(QCoreApplication::translate("QSqlConnectionDialogUi", "Dialog", nullptr));
        connGroupBox->setTitle(QCoreApplication::translate("QSqlConnectionDialogUi", "\346\225\260\346\215\256\345\272\223\350\277\236\346\216\245\350\256\276\347\275\256", nullptr));
        textLabel2->setText(QCoreApplication::translate("QSqlConnectionDialogUi", "\351\251\261\345\212\250\357\274\232", nullptr));
        textLabel3->setText(QCoreApplication::translate("QSqlConnectionDialogUi", "\346\225\260\346\215\256\345\272\223\345\220\215\357\274\232", nullptr));
        textLabel4->setText(QCoreApplication::translate("QSqlConnectionDialogUi", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        textLabel4_2->setText(QCoreApplication::translate("QSqlConnectionDialogUi", "\345\257\206\347\240\201\357\274\232", nullptr));
        textLabel5->setText(QCoreApplication::translate("QSqlConnectionDialogUi", "\344\270\273\346\234\272\345\220\215\357\274\232", nullptr));
        textLabrl5_2->setText(QCoreApplication::translate("QSqlConnectionDialogUi", "\347\253\257\345\217\243\357\274\232", nullptr));
        status_label->setText(QCoreApplication::translate("QSqlConnectionDialogUi", "\347\212\266\346\200\201\357\274\232", nullptr));
        okButton->setText(QCoreApplication::translate("QSqlConnectionDialogUi", "\350\277\236\346\216\245", nullptr));
        cancelButton->setText(QCoreApplication::translate("QSqlConnectionDialogUi", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QSqlConnectionDialogUi: public Ui_QSqlConnectionDialogUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTDLG_H

/********************************************************************************
** Form generated from reading UI file 'filesrvdlg.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILESRVDLG_H
#define UI_FILESRVDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_FileSrvDlg
{
public:
    QLabel *label;
    QLineEdit *sfileNameLineEdit;
    QPushButton *openFilePushButton;
    QPushButton *sendFilePushButton;
    QLineEdit *sfileSizeLineEdit;
    QLineEdit *sendSizeLineEdit;
    QProgressBar *sendProgressBar;
    QPushButton *srvClosePushButton;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *FileSrvDlg)
    {
        if (FileSrvDlg->objectName().isEmpty())
            FileSrvDlg->setObjectName("FileSrvDlg");
        FileSrvDlg->resize(491, 300);
        label = new QLabel(FileSrvDlg);
        label->setObjectName("label");
        label->setGeometry(QRect(210, 10, 91, 31));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        sfileNameLineEdit = new QLineEdit(FileSrvDlg);
        sfileNameLineEdit->setObjectName("sfileNameLineEdit");
        sfileNameLineEdit->setEnabled(false);
        sfileNameLineEdit->setGeometry(QRect(90, 60, 211, 31));
        QFont font1;
        font1.setPointSize(10);
        sfileNameLineEdit->setFont(font1);
        sfileNameLineEdit->setAlignment(Qt::AlignCenter);
        sfileNameLineEdit->setReadOnly(true);
        openFilePushButton = new QPushButton(FileSrvDlg);
        openFilePushButton->setObjectName("openFilePushButton");
        openFilePushButton->setGeometry(QRect(300, 60, 31, 31));
        openFilePushButton->setFont(font1);
        sendFilePushButton = new QPushButton(FileSrvDlg);
        sendFilePushButton->setObjectName("sendFilePushButton");
        sendFilePushButton->setGeometry(QRect(340, 60, 92, 28));
        sendFilePushButton->setFont(font1);
        sfileSizeLineEdit = new QLineEdit(FileSrvDlg);
        sfileSizeLineEdit->setObjectName("sfileSizeLineEdit");
        sfileSizeLineEdit->setEnabled(false);
        sfileSizeLineEdit->setGeometry(QRect(140, 110, 71, 31));
        sfileSizeLineEdit->setFont(font1);
        sfileSizeLineEdit->setAlignment(Qt::AlignCenter);
        sfileSizeLineEdit->setReadOnly(true);
        sendSizeLineEdit = new QLineEdit(FileSrvDlg);
        sendSizeLineEdit->setObjectName("sendSizeLineEdit");
        sendSizeLineEdit->setEnabled(false);
        sendSizeLineEdit->setGeometry(QRect(290, 110, 71, 31));
        sendSizeLineEdit->setFont(font1);
        sendSizeLineEdit->setAlignment(Qt::AlignCenter);
        sendSizeLineEdit->setReadOnly(true);
        sendProgressBar = new QProgressBar(FileSrvDlg);
        sendProgressBar->setObjectName("sendProgressBar");
        sendProgressBar->setGeometry(QRect(130, 150, 191, 31));
        sendProgressBar->setValue(0);
        srvClosePushButton = new QPushButton(FileSrvDlg);
        srvClosePushButton->setObjectName("srvClosePushButton");
        srvClosePushButton->setGeometry(QRect(340, 160, 92, 28));
        srvClosePushButton->setFont(font1);
        label_2 = new QLabel(FileSrvDlg);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 120, 41, 19));
        label_3 = new QLabel(FileSrvDlg);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(230, 120, 51, 19));
        label_4 = new QLabel(FileSrvDlg);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(90, 160, 41, 19));

        retranslateUi(FileSrvDlg);

        QMetaObject::connectSlotsByName(FileSrvDlg);
    } // setupUi

    void retranslateUi(QDialog *FileSrvDlg)
    {
        FileSrvDlg->setWindowTitle(QCoreApplication::translate("FileSrvDlg", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("FileSrvDlg", "\346\226\207\344\273\266\345\217\221\351\200\201", nullptr));
        openFilePushButton->setText(QCoreApplication::translate("FileSrvDlg", "...", nullptr));
        sendFilePushButton->setText(QCoreApplication::translate("FileSrvDlg", "\345\217\221\351\200\201", nullptr));
        srvClosePushButton->setText(QCoreApplication::translate("FileSrvDlg", "\345\201\234\346\255\242", nullptr));
        label_2->setText(QCoreApplication::translate("FileSrvDlg", "\345\244\247\345\260\217\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("FileSrvDlg", "\345\267\262\345\217\221\351\200\201\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("FileSrvDlg", "\350\277\233\345\272\246\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileSrvDlg: public Ui_FileSrvDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILESRVDLG_H

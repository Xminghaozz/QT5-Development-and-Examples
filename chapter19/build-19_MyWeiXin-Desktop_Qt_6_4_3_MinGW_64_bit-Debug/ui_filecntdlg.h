/********************************************************************************
** Form generated from reading UI file 'filecntdlg.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILECNTDLG_H
#define UI_FILECNTDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_FileCntDlg
{
public:
    QPushButton *openFilePushButton;
    QLineEdit *recvSizeLineEdit;
    QLabel *label_4;
    QLineEdit *rfileNameLineEdit;
    QProgressBar *recvProgressBar;
    QPushButton *cntClosePushButton;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_2;
    QLineEdit *rfileSizeLineEdit;
    QLabel *rateLabel;

    void setupUi(QDialog *FileCntDlg)
    {
        if (FileCntDlg->objectName().isEmpty())
            FileCntDlg->setObjectName("FileCntDlg");
        FileCntDlg->resize(561, 249);
        openFilePushButton = new QPushButton(FileCntDlg);
        openFilePushButton->setObjectName("openFilePushButton");
        openFilePushButton->setGeometry(QRect(300, 70, 31, 31));
        QFont font;
        font.setPointSize(10);
        openFilePushButton->setFont(font);
        recvSizeLineEdit = new QLineEdit(FileCntDlg);
        recvSizeLineEdit->setObjectName("recvSizeLineEdit");
        recvSizeLineEdit->setEnabled(false);
        recvSizeLineEdit->setGeometry(QRect(290, 120, 71, 31));
        recvSizeLineEdit->setFont(font);
        recvSizeLineEdit->setAlignment(Qt::AlignCenter);
        recvSizeLineEdit->setReadOnly(true);
        label_4 = new QLabel(FileCntDlg);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(90, 170, 41, 19));
        rfileNameLineEdit = new QLineEdit(FileCntDlg);
        rfileNameLineEdit->setObjectName("rfileNameLineEdit");
        rfileNameLineEdit->setEnabled(false);
        rfileNameLineEdit->setGeometry(QRect(90, 70, 211, 31));
        rfileNameLineEdit->setFont(font);
        rfileNameLineEdit->setAlignment(Qt::AlignCenter);
        rfileNameLineEdit->setReadOnly(true);
        recvProgressBar = new QProgressBar(FileCntDlg);
        recvProgressBar->setObjectName("recvProgressBar");
        recvProgressBar->setGeometry(QRect(130, 160, 191, 31));
        recvProgressBar->setValue(0);
        cntClosePushButton = new QPushButton(FileCntDlg);
        cntClosePushButton->setObjectName("cntClosePushButton");
        cntClosePushButton->setGeometry(QRect(340, 70, 92, 28));
        cntClosePushButton->setFont(font);
        label = new QLabel(FileCntDlg);
        label->setObjectName("label");
        label->setGeometry(QRect(210, 20, 91, 31));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(FileCntDlg);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(230, 130, 51, 19));
        label_2 = new QLabel(FileCntDlg);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 130, 41, 19));
        rfileSizeLineEdit = new QLineEdit(FileCntDlg);
        rfileSizeLineEdit->setObjectName("rfileSizeLineEdit");
        rfileSizeLineEdit->setEnabled(false);
        rfileSizeLineEdit->setGeometry(QRect(140, 120, 71, 31));
        rfileSizeLineEdit->setFont(font);
        rfileSizeLineEdit->setAlignment(Qt::AlignCenter);
        rfileSizeLineEdit->setReadOnly(true);
        rateLabel = new QLabel(FileCntDlg);
        rateLabel->setObjectName("rateLabel");
        rateLabel->setGeometry(QRect(340, 170, 61, 19));
        rateLabel->setFont(font);

        retranslateUi(FileCntDlg);

        QMetaObject::connectSlotsByName(FileCntDlg);
    } // setupUi

    void retranslateUi(QDialog *FileCntDlg)
    {
        FileCntDlg->setWindowTitle(QCoreApplication::translate("FileCntDlg", "Dialog", nullptr));
        openFilePushButton->setText(QCoreApplication::translate("FileCntDlg", "...", nullptr));
        label_4->setText(QCoreApplication::translate("FileCntDlg", "\350\277\233\345\272\246\357\274\232", nullptr));
        cntClosePushButton->setText(QCoreApplication::translate("FileCntDlg", "\345\201\234\346\255\242", nullptr));
        label->setText(QCoreApplication::translate("FileCntDlg", "\346\226\207\344\273\266\346\216\245\346\224\266", nullptr));
        label_3->setText(QCoreApplication::translate("FileCntDlg", "\345\267\262\346\216\245\346\224\266\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("FileCntDlg", "\345\244\247\345\260\217\357\274\232", nullptr));
        rateLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FileCntDlg: public Ui_FileCntDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILECNTDLG_H

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QPushButton *searchPushButton;
    QTableWidget *userListTableWidget;
    QLabel *userLabel;
    QLabel *label_3;
    QTextBrowser *chatTextBrowser;
    QPushButton *transPushButton;
    QLabel *label_5;
    QTextEdit *chatTextEdit;
    QPushButton *sendPushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 60, 500));
        label->setFrameShape(QFrame::Box);
        label->setFrameShadow(QFrame::Sunken);
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/bar.jpg")));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 10, 250, 65));
        label_2->setFrameShape(QFrame::Box);
        label_2->setFrameShadow(QFrame::Sunken);
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/img/search.jpg")));
        searchPushButton = new QPushButton(centralwidget);
        searchPushButton->setObjectName("searchPushButton");
        searchPushButton->setGeometry(QRect(100, 30, 191, 26));
        searchPushButton->setFlat(true);
        userListTableWidget = new QTableWidget(centralwidget);
        if (userListTableWidget->columnCount() < 1)
            userListTableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        userListTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        userListTableWidget->setObjectName("userListTableWidget");
        userListTableWidget->setEnabled(true);
        userListTableWidget->setGeometry(QRect(60, 70, 250, 435));
        QFont font;
        font.setPointSize(14);
        userListTableWidget->setFont(font);
        userListTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        userListTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        userListTableWidget->setShowGrid(false);
        userListTableWidget->horizontalHeader()->setVisible(false);
        userListTableWidget->horizontalHeader()->setDefaultSectionSize(250);
        userListTableWidget->verticalHeader()->setVisible(false);
        userLabel = new QLabel(centralwidget);
        userLabel->setObjectName("userLabel");
        userLabel->setGeometry(QRect(311, 1, 121, 62));
        QFont font1;
        font1.setPointSize(15);
        userLabel->setFont(font1);
        userLabel->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(310, 0, 432, 65));
        label_3->setFrameShape(QFrame::Box);
        label_3->setFrameShadow(QFrame::Sunken);
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/img/title.jpg")));
        chatTextBrowser = new QTextBrowser(centralwidget);
        chatTextBrowser->setObjectName("chatTextBrowser");
        chatTextBrowser->setGeometry(QRect(310, 65, 431, 300));
        transPushButton = new QPushButton(centralwidget);
        transPushButton->setObjectName("transPushButton");
        transPushButton->setGeometry(QRect(370, 370, 31, 23));
        transPushButton->setFlat(true);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(310, 360, 432, 40));
        label_5->setFrameShape(QFrame::Box);
        label_5->setFrameShadow(QFrame::Sunken);
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/img/tool.jpg")));
        chatTextEdit = new QTextEdit(centralwidget);
        chatTextEdit->setObjectName("chatTextEdit");
        chatTextEdit->setGeometry(QRect(310, 400, 432, 97));
        sendPushButton = new QPushButton(centralwidget);
        sendPushButton->setObjectName("sendPushButton");
        sendPushButton->setGeometry(QRect(660, 470, 75, 25));
        QFont font2;
        font2.setPointSize(10);
        sendPushButton->setFont(font2);
        MainWindow->setCentralWidget(centralwidget);
        label_2->raise();
        label_3->raise();
        label_5->raise();
        label->raise();
        chatTextBrowser->raise();
        transPushButton->raise();
        chatTextEdit->raise();
        sendPushButton->raise();
        userLabel->raise();
        searchPushButton->raise();
        userListTableWidget->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        searchPushButton->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = userListTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\345\210\227", nullptr));
        userLabel->setText(QString());
        label_3->setText(QString());
        transPushButton->setText(QString());
        label_5->setText(QString());
        sendPushButton->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

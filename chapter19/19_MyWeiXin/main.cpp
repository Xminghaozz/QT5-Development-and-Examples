#include "mainwindow.h"

#include "logindialog.h"
#include <QApplication>
#include <QCoreApplication>
#include <QNetworkInterface>

int main( int argc, char *argv[] )
{
    QApplication a( argc, argv );
    LoginDialog  logindlg;
    logindlg.show();

    // MainWindow w;
    // w.show();
    return a.exec();
}

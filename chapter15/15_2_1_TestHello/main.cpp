#include "mainwindow.h"

#include <QApplication>
#include <QTranslator>
int main( int argc, char *argv[] )
{
    QApplication a( argc, argv );
    QTranslator *translator = new QTranslator;
    translator->load(
        "D:/QTWorkSpace/QT5 Development and Examples/chapter15/15_2_1_TestHello/TestHello.qm" );
    a.installTranslator( translator );
    MainWindow w;
    w.show();
    return a.exec();
}

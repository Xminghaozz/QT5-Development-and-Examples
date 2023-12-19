#include "mainwindow.h"

#include <QApplication>

int main( int argc, char *argv[] )
{
    QApplication a( argc, argv );
    QFont        font( "ZYSongl8030", 12 );
    a.setFont( font );
    MainWindow w;
    w.show();
    return a.exec();
}

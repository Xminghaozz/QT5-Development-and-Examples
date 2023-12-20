#include "mainwindow.h"
#include "mapwidget.h"
#include <QApplication>

int main( int argc, char *argv[] )
{
    QApplication a( argc, argv );
    QFont        font( "ARPL KaitiM GB", 12 );
    font.setBold( true );
    a.setFont( font );
    MapWidget mapWidget;
    mapWidget.show();
    return a.exec();
}

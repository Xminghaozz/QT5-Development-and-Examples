#include "modelex.h"

#include <QApplication>
#include <QTableView>

int main( int argc, char *argv[] )
{
    QApplication a( argc, argv );
    ModelEx      modelEx;
    QTableView   view;
    view.setModel( &modelEx );
    view.setWindowTitle( QObject::tr( "modelEx" ) );
    view.resize( 400, 400 );
    view.show();
    return a.exec();
}

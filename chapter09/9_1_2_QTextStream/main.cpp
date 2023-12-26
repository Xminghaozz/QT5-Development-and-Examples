#include <QCoreApplication>
#include <QFile>
#include <QTextStream>

int main( int argc, char *argv[] )
{
    QCoreApplication a( argc, argv );
    QFile            data( "data.text" );
    if ( data.open( QFile::WriteOnly | QFile::Truncate ) )
    {
        QTextStream out( &data );
        out << QObject::tr( "source:" ) << qSetFieldWidth( 10 ) << Qt::left << 90 << Qt::endl;
    }
    return a.exec();
}

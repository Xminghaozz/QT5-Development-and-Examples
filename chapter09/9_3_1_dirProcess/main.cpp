#include <QCoreApplication>
#include <QDir>
#include <QStringList>
#include <QtDebug>

qint64 du( const QString &path )
{
    QDir   dir( path );
    qint64 size = 0;
    foreach ( QFileInfo fileInfo, dir.entryInfoList( QDir::Files ) )
    {
        size = size + fileInfo.size();
    }

    foreach ( QString subDir, dir.entryList( QDir::Dirs | QDir::NoDotAndDotDot ) )
    {
        size = size + du( path + QDir::separator() + subDir );
    }

    char   unit    = 'B';
    qint64 curSize = size;
    if ( curSize > 1024 )
    {
        curSize = curSize / 1024;
        unit    = 'K';
        if ( curSize > 1024 )
        {
            curSize = curSize / 1024;
            unit    = 'M';
            if ( curSize > 1024 )
            {
                curSize = curSize / 1024;
                unit    = 'G';
            }
        }
    }
    qDebug() << curSize << unit << "\t" << qPrintable( path ) << Qt::endl;

    return size;
}
int main( int argc, char *argv[] )
{
    QCoreApplication a( argc, argv );
    QStringList      args = a.arguments();
    QString          path;

    if ( args.count() > 1 )
    {
        path = args[ 1 ];
    }
    else
    {
        path = QDir::currentPath();
    }

    qDebug() << path << Qt::endl;
    du( path );
    return a.exec();
}

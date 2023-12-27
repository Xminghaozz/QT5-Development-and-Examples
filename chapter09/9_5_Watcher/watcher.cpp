#include "watcher.h"

#include <QApplication>
#include <QDir>
#include <QMessageBox>
#include <QVBoxLayout>

Watcher::Watcher( QWidget *parent )
    : QWidget( parent )
{
    QStringList args = qApp->arguments();
    QString     path;
    if ( args.count() > 1 )
    {
        path = args[ 1 ];
    }
    else
    {
        path = QDir::currentPath();
    }

    pathLabel = new QLabel;
    pathLabel->setText( tr( "监视的目录：" ) + path );
    QVBoxLayout *mainLayout = new QVBoxLayout( this );
    mainLayout->addWidget( pathLabel );
    fsWatcher.addPath( path );

    connect( &fsWatcher, &QFileSystemWatcher::fileChanged, this, &Watcher::directoryChanged );
}

Watcher::~Watcher() {}

void Watcher::directoryChanged( QString path )
{
    QMessageBox::information( nullptr, tr( " 目录发生变化 " ), path );
}

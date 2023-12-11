#include "mainwindow.h"

#include <QApplication>
#include <QPixmap>
#include <QSplashScreen >

int main( int argc, char *argv[] )
{
    QApplication  a( argc, argv );
    QPixmap       pixmap( ":/Img/Qt.png" );
    QSplashScreen splash( pixmap );
    splash.show(); // 显示启动图片
    a.processEvents();
    MainWindow w;
    w.show();
    splash.finish( &w );
    return a.exec();
}

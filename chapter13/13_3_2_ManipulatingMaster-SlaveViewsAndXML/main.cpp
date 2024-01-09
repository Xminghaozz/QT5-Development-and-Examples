#include "connectdlg.h"
#include "mainwindow.h"
#include <QApplication>
#include <QDialog>

int main( int argc, char *argv[] )
{
    QApplication a( argc, argv );
    ConnDlg      dialog;
    if ( dialog.exec() != QDialog::Accepted )
        return -1;
    QFile     *carDetails = new QFile( ":/res/attribs.xml" );
    MainWindow window( "factory", "cars", carDetails );
    window.show();
    return a.exec();
}

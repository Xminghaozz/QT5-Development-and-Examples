#include "mainwindow.h"
#include <QTextEdit>
#include <windows.h>

MainWindow::MainWindow( QWidget *parent )
    : QMainWindow( parent )
{
    this->setWindowTitle( tr( "Splash Example" ) );
    QTextEdit *edit = new QTextEdit;
    edit->setText( "Splash Example!" );
    this->setCentralWidget( edit );
    this->resize( 600, 450 );
    Sleep( 1000 );
}

MainWindow::~MainWindow() {}

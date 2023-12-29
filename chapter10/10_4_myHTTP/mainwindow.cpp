#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow( QWidget *parent )
    : QMainWindow( parent )
    , ui( new Ui::MainWindow )
{
    ui->setupUi( this );
    manager = new QNetworkAccessManager( this );
    connect( manager, &QNetworkAccessManager::finished, this, &MainWindow::replyFinished );
    // manager->get( QNetworkRequest( QUrl( "http://www.baidu.com" ) ) );
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::startRequest( QUrl url )
{
    reply = manager->get( QNetworkRequest( url ) );
    connect( reply, &QNetworkReply::readyRead, this, &MainWindow::httpReadyRead );
    connect( reply, &QNetworkReply::downloadProgress, this, &MainWindow::updateDataReadProgress );
    connect( reply, &QNetworkReply::finished, this, &MainWindow::httpFinished );
}

void MainWindow::replyFinished( QNetworkReply *reply )
{
    QString all = reply->readAll();
    ui->textBrowser->setText( all );
    reply->deleteLater();
    ui->progressBar->hide();
}

void MainWindow::httpFinished()
{
    ui->progressBar->hide();
    file->flush();
    file->close();
    reply->deleteLater();
    reply = 0;
    delete file;
    file = 0;
}

void MainWindow::httpReadyRead()
{
    if ( file )
        file->write( reply->readAll() );
}

void MainWindow::updateDataReadProgress( qint64 bytesRead, qint64 totalBytes )
{
    ui->progressBar->setMaximum( totalBytes );
    ui->progressBar->setValue( bytesRead );
}

void MainWindow::on_pushButton_clicked()
{
    url = ui->lineEdit->text();
    QFileInfo info( url.path() );
    QString   fileName( info.fileName() );
    file = new QFile( fileName );
    if ( !file->open( QIODevice::WriteOnly ) )
    {
        qDebug() << "file open error";
        delete file;
        file = 0;
        return;
    }
    startRequest( url );
    ui->progressBar->setValue( 0 );
    ui->progressBar->show();
}

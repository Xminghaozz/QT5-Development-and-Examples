#include "dialog.h"
#include "timeserver.h"
#include <QHBoxLayout>
#include <QMessageBox>
#include <QVBoxLayout>

Dialog::Dialog( QWidget *parent )
    : QDialog( parent )
{
    this->setWindowTitle( tr( "多线程时间服务器" ) );
    label1  = new QLabel( tr( "服务器端口" ) );
    label2  = new QLabel;
    quitBtn = new QPushButton( tr( "退出" ) );

    QHBoxLayout *btnLayout = new QHBoxLayout;
    btnLayout->addStretch( 1 );
    btnLayout->addWidget( quitBtn );
    btnLayout->addStretch( 1 );

    QVBoxLayout *mainLayout = new QVBoxLayout( this );
    mainLayout->addWidget( label1 );
    mainLayout->addWidget( label2 );
    mainLayout->addLayout( btnLayout );

    connect( quitBtn, &QPushButton::clicked, this, &Dialog::close );

    count      = 0;
    timeserver = new TimeServer( this );
    if ( !timeserver->listen() )
    {
        QMessageBox::critical( this, tr( "多线程时间服务器" ),
                               tr( "无法启动服务器:%1" ).arg( timeserver->errorString() ) );
        close();
        return;
    }
    label1->setText( tr( "服务器端口:%1" ).arg( timeserver->serverPort() ) );
}

Dialog::~Dialog() {}

void Dialog::slotShow() { label2->setText( tr( " 第 %1 次请求完毕。" ).arg( ++count ) ); }

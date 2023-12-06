#include "progressdlg.h"
#include <QFont>
#include <QProgressDialog>

ProgressDlg::ProgressDlg( QWidget *parent )
    : QDialog( parent )
{
    QFont font( "ZYSong18030", 12 );
    this->setFont( font );
    this->setWindowTitle( tr( "Progress" ) );

    fileNum = new QLabel;
    fileNum->setText( tr( "文件数目：" ) );
    fileNumLineEdit = new QLineEdit;
    fileNumLineEdit->setText( tr( "100000" ) );
    progressType = new QLabel;
    progressType->setText( tr( " 显示类型：" ) );
    comboBox = new QComboBox;
    comboBox->addItem( tr( "progressBar" ) );
    comboBox->addItem( tr( "progressDialog" ) );
    progressBar = new QProgressBar;
    starBtn     = new QPushButton;
    starBtn->setText( tr( "开始" ) );

    mainLayout = new QGridLayout( this );
    mainLayout->addWidget( fileNum, 0, 0 );
    mainLayout->addWidget( fileNumLineEdit, 0, 1 );
    mainLayout->addWidget( progressType, 1, 0 );
    mainLayout->addWidget( comboBox, 1, 1 );
    mainLayout->addWidget( progressBar, 2, 0, 1, 2 );
    mainLayout->addWidget( starBtn, 3, 1 );
    mainLayout->setContentsMargins( 15, 15, 15, 15 );
    mainLayout->setSpacing( 10 );

    connect( starBtn, &QPushButton::clicked, this, &ProgressDlg::startProgress );
}

ProgressDlg::~ProgressDlg() {}

void ProgressDlg::startProgress()
{
    bool ok;
    int  num = fileNumLineEdit->text().toInt( &ok );
    if ( comboBox->currentIndex() == 0 ) // 采用进度条的方式显示进度
    {
        progressBar->setRange( 0, num );
        for ( int i = 0; i < num + 1; i++ )
        {
            progressBar->setValue( i );
        }
    }
    else if ( comboBox->currentIndex() == 1 ) // 采用进度对话框显示进度
    {
        // 创建一个进度对话框
        QProgressDialog *progressDialog = new QProgressDialog( this );
        QFont            font( "ZYSong18030", 12 );
        progressDialog->setFont( font );
        progressDialog->setWindowModality( Qt::WindowModal );
        progressDialog->setMinimumDuration( 5 );
        progressDialog->setWindowTitle( tr( "Please Wait" ) );
        progressDialog->setLabelText( tr( "Copying..." ) );
        progressDialog->setCancelButtonText( tr( "Cancel" ) );
        progressDialog->setRange( 0, num ); // 设置进度对话框的步进范围
        for ( int i = 0; i < num + 1; i++ )
        {
            progressDialog->setValue( i );
            if ( progressDialog->wasCanceled() )
            {
                return;
            }
        }
    }
}

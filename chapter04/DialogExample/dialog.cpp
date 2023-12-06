#include "dialog.h"

Dialog::Dialog( QWidget *parent )
    : QDialog( parent )
{
    this->setWindowTitle( tr( "各种标准对话框的实例" ) );
    /*各个控件对象的初始化 文件对话框*/
    fileBtn = new QPushButton;
    fileBtn->setText( tr( "文件标准对话框实例" ) );
    fileLineEdit = new QLineEdit; // 用来显示选择的文件名

    // 添加布局管理
    mainLayout = new QGridLayout( this ); // 布局设计
    mainLayout->addWidget( fileBtn, 0, 0 );
    mainLayout->addWidget( fileLineEdit, 0, 1 );

    // 事件关联
    connect( fileBtn, &QPushButton::clicked, this, &Dialog::showFile );

    /*颜色对话框*/
    colorBtn = new QPushButton;
    colorBtn->setText( tr( "颜色标准对话框" ) );
    colorFrame = new QFrame;
    colorFrame->setFrameShape( QFrame::Box );
    colorFrame->setAutoFillBackground( true );

    mainLayout->addWidget( colorBtn, 1, 0 ); // 布局设计
    mainLayout->addWidget( colorFrame, 1, 1 );

    // 事件关联
    connect( colorBtn, &QPushButton::clicked, this, &Dialog::showColor );

    /*字体对话框*/
    fontBtn = new QPushButton;
    fontBtn->setText( tr( "字体标准对话框实例" ) );
    fontLineEdit = new QLineEdit; // 显示更改的字符串
    fontLineEdit->setText( tr( "Welcome!" ) );

    mainLayout->addWidget( fontBtn, 2, 0 ); // 布局设计
    mainLayout->addWidget( fontLineEdit, 2, 1 );

    // 事件关联
    connect( fontBtn, &QPushButton::clicked, this, &Dialog::showFont );

    /*输入对话框*/
    inputBtn = new QPushButton;
    inputBtn->setText( tr( "标准输入对话框实例" ) );

    mainLayout->addWidget( inputBtn );
    connect( inputBtn, &QPushButton::clicked, this, &Dialog::showInputDlg );

    /*标准消息对话框*/
    msgBtn = new QPushButton;
    msgBtn->setText( tr( "标准消息对话框实例" ) );

    mainLayout->addWidget( msgBtn, 3, 1 );
    connect( msgBtn, &QPushButton::clicked, this, &Dialog::showMsgDlg );
}

Dialog::~Dialog() {}

void Dialog::showFile()
{
    QString s = QFileDialog::getOpenFileName( this, "open file dialog", "/",
                                              "C++ files(*.cpp);;C files(*.c);;Head files(*.h" );
    fileLineEdit->setText( s );
}

void Dialog::showColor()
{
    QColor c = QColorDialog::getColor( Qt::blue );
    if ( c.isValid() )
    {
        colorFrame->setPalette( QPalette( c ) );
    }
}

void Dialog::showFont()
{
    bool  ok;
    QFont f = QFontDialog::getFont( &ok );
    if ( ok )
    {
        fontLineEdit->setFont( f );
    }
}

void Dialog::showInputDlg()
{
    inputDlg = new InputDlg( this );
    inputDlg->show();
}

void Dialog::showMsgDlg()
{
    msgDlg = new MsgBoxDlg( this );
    msgDlg->show();
}

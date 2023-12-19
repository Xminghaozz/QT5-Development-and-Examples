#include "mainwindow.h"
#include <QColorDialog>

MainWindow::MainWindow( QWidget *parent )
    : QMainWindow( parent )
{
    drawWidget = new DrawWidget;          // 新建一个 DrawWidget 对象
    this->setCentralWidget( drawWidget ); // 新建的 DrawWidget 对象作为主窗口的中央窗体
    createToolBar();                      // 实现一个工具栏
    this->setMinimumSize( 600, 400 );     // 实现一个工具栏
    showStyle(); // 初始化线型，设置控件中的当前值作为初始值
    drawWidget->setWidth( widthSpinBox->value() ); // 初始化线宽
    drawWidget->setColor( Qt::black );             // 初始化颜色
}

MainWindow::~MainWindow() {}

void MainWindow::createToolBar()
{
    QToolBar *toolBar = addToolBar( "Tool" );           // 为主窗口新建一个工具栏对象
    styleLabel        = new QLabel( tr( "线型风格" ) ); // 创建线型风格选择控件
    styleComboBox     = new QComboBox;
    styleComboBox->addItem( tr( "SolidLine" ), static_cast<int>( Qt::SolidLine ) );
    styleComboBox->addItem( tr( "DashLine" ), static_cast<int>( Qt::DashLine ) );
    styleComboBox->addItem( tr( "DotLine" ), static_cast<int>( Qt::DotLine ) );
    styleComboBox->addItem( tr( "DashDotLine" ), static_cast<int>( Qt::DashDotLine ) );
    styleComboBox->addItem( tr( "DashDotDotLine" ), static_cast<int>( Qt::DashDotDotLine ) );

    connect( styleComboBox, &QComboBox::activated, this,
             &MainWindow::showStyle );          // 关联相应的槽函数
    widthLabel   = new QLabel( tr( "线宽:" ) ); // 创建线宽选择控件
    widthSpinBox = new QSpinBox;
    connect( widthSpinBox, &QSpinBox::valueChanged, drawWidget, &DrawWidget::setWidth );

    colorBtn = new QToolButton;
    QPixmap pixmap( 20, 20 );
    pixmap.fill( Qt::black );

    colorBtn->setIcon( QIcon( pixmap ) );
    connect( colorBtn, &QPushButton::clicked, this, &MainWindow::showColor );
    clearBtn = new QToolButton();
    clearBtn->setText( tr( " 清除" ) );
    connect( clearBtn, &QPushButton::clicked, drawWidget, &DrawWidget::clear );

    toolBar->addWidget( styleLabel );
    toolBar->addWidget( styleComboBox );
    toolBar->addWidget( widthLabel );
    toolBar->addWidget( widthSpinBox );
    toolBar->addWidget( colorBtn );
    toolBar->addWidget( clearBtn );
}

void MainWindow::showStyle()
{
    drawWidget->setStyle(
        styleComboBox->itemData( styleComboBox->currentIndex(), Qt::UserRole ).toInt() );
}

void MainWindow::showColor()
{
    QColor color = QColorDialog::getColor( static_cast<int>( Qt::black ),
                                           this ); // 使用标准颜色对话框 QColorDialog 获得一个颜色值
    if ( color.isValid() )
    {
        // 将新选择的颜色传给绘制区，用千改变画笔的颜色值
        drawWidget->setColor( color );
        QPixmap p( 20, 20 );
        p.fill( color );
        colorBtn->setIcon( QIcon( p ) ); // 更新颜色选择按钮上的颜色显示
    }
}

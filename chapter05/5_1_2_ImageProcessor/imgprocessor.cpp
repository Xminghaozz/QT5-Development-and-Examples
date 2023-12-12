#include "imgprocessor.h"

#include <QFile>
#include <QFileDialog>
#include <QPainter>
#include <QPrintDialog>
#include <QPrinter>
#include <QTextStream>
#include <QTransform>

ImgProcessor::ImgProcessor( QWidget *parent )
    : QMainWindow( parent )
{
    this->setWindowTitle( tr( "Easy Word" ) );
    showWidget = new ShowWidget( this );
    this->setCentralWidget( showWidget );
    /*创建动作、菜单、工具栏的函数*/
    createActions();
    createMenus();
    createToolBars();
    if ( img.load( ":/Img/image.png" ) )
    {
        // 在imageLabel对象中放置图片
        showWidget->imageLabel->setPixmap( QPixmap::fromImage( img ) );
    }
}

ImgProcessor::~ImgProcessor() {}

void ImgProcessor::createActions()
{
    //"打开"动作
    openFileAction = new QAction( QIcon( ":/Img/open.png" ), tr( "打开" ), this );
    openFileAction->setShortcut( tr( "Ctrl+O" ) );
    openFileAction->setStatusTip( tr( "打开一个文件" ) );
    connect( openFileAction, &QAction::triggered, this, &ImgProcessor::showOpenFile );
    //"新建"动作
    NewFileAction = new QAction( QIcon( ":/Img/new.png" ), tr( "新建" ), this );
    NewFileAction->setShortcut( tr( "Ctrl+N" ) );
    NewFileAction->setStatusTip( tr( "新建一个文件" ) );
    connect( NewFileAction, &QAction::triggered, this, &ImgProcessor::showNewFile );
    //"退出"动作
    exitAction = new QAction( tr( "退出" ), this );
    exitAction->setShortcut( tr( "Ctrl+Q" ) );
    exitAction->setStatusTip( tr( " 退出程序" ) );
    connect( exitAction, &QAction::triggered, this, &ImgProcessor::close );
    //"复制"动作
    copyAction = new QAction( QIcon( ":/Img/copy.png" ), tr( "复制" ), this );
    copyAction->setShortcut( tr( "Ctrl+C" ) );
    copyAction->setStatusTip( tr( "复制文件" ) );
    connect( copyAction, &QAction::triggered, showWidget->text, &QTextEdit::copy );
    //"剪切"动作
    cutAction = new QAction( QIcon( ":/Img/cut.png" ), tr( "剪切" ), this );
    cutAction->setShortcut( tr( "Ctrl+X" ) );
    cutAction->setStatusTip( tr( "剪切文件" ) );
    connect( cutAction, &QAction::triggered, showWidget->text, &QTextEdit::cut );
    //"粘贴"动作
    pasteAction = new QAction( QIcon( ":/Img/copy.png" ), tr( "粘贴" ), this );
    pasteAction->setShortcut( tr( "Ctrl+V" ) );
    pasteAction->setStatusTip( tr( "粘贴文件" ) );
    connect( pasteAction, &QAction::triggered, showWidget->text, &QTextEdit::paste );
    //"关于“动作
    aboutAction = new QAction( tr( "关于" ), this );
    connect( aboutAction, &QAction::triggered, this, &QApplication::aboutQt );

    //"打印文本"动作
    PrintTextAction = new QAction( QIcon( ":/Img/printText.png" ), tr( "打印文本" ), this );
    PrintTextAction->setStatusTip( tr( "打印一个文本" ) );
    connect( PrintTextAction, &QAction::triggered, this, &ImgProcessor::showPrintText );
    //"打印图片"动作
    PrintImageAction = new QAction( QIcon( ":/Img/printImage.png" ), tr( "打印图片" ), this );
    PrintImageAction->setStatusTip( tr( "打印一张图片" ) );
    connect( PrintImageAction, &QAction::triggered, this, &ImgProcessor::showPrintImage );
    //"放大"动作
    zoomInAction = new QAction( QIcon( ":/Img/zoomin.png" ), tr( "放大" ), this );
    zoomInAction->setStatusTip( tr( "放大一张图片" ) );
    connect( zoomInAction, &QAction::triggered, this, &ImgProcessor::showZoomIn );
    //"缩小"动作
    zoomOutAction = new QAction( QIcon( ":/Img/zoomout.png" ), tr( "缩小" ), this );
    zoomOutAction->setStatusTip( tr( "缩小一张图片" ) );
    connect( zoomOutAction, &QAction::triggered, this, &ImgProcessor::showZoomOut );
    // 实现图片旋转的动作(Action)
    // 旋转90°
    rotate90Action = new QAction( QIcon( ":/Img/rotate90.png" ), tr( "旋转90°" ), this );
    rotate90Action->setStatusTip( tr( "将一张图片旋转90°" ) );
    connect( rotate90Action, &QAction::triggered, this, &ImgProcessor::showRotate90 );
    // 旋转180°
    rotate180Action = new QAction( QIcon( ":/Img/rotate180.png" ), tr( "旋转180°" ), this );
    rotate180Action->setStatusTip( tr( "将一张图片旋转180°" ) );
    connect( rotate180Action, &QAction::triggered, this, &ImgProcessor::showRotate180 );

    // 旋转270°
    rotate270Action = new QAction( QIcon( ":/Img/rotate270.png" ), tr( "旋转270°" ), this );
    rotate270Action->setStatusTip( tr( "将一张图片旋转270°" ) );
    connect( rotate270Action, &QAction::triggered, this, &ImgProcessor::showRotate270 );

    // 实现图片镜像的动作(Action)
    //  获取指定大小的图标
    QIcon verticalIcon   = QIcon( ":/Img/mirrorVertical.png" );
    QIcon horizontalIcon = QIcon( ":/Img/mirrorHorizontal.png" );

    // 指定图标大小
    int iconSize = 25; // 设置所需的图标大小
    // 获取指定大小的图标
    QPixmap verticalPixmap   = verticalIcon.pixmap( iconSize, iconSize );
    QPixmap horizontalPixmap = horizontalIcon.pixmap( iconSize, iconSize );
    // 纵向镜像
    mirrorVerticalAction = new QAction( verticalPixmap, tr( "纵向镜像" ), this );
    mirrorVerticalAction->setStatusTip( tr( "对一张图片做纵向镜像" ) );
    connect( mirrorVerticalAction, &QAction::triggered, this, &ImgProcessor::showMirrorVertical );
    // 横向镜像
    mirrorHorizontalAction = new QAction( horizontalPixmap, tr( "横向镜像" ), this );
    mirrorHorizontalAction->setStatusTip( tr( "对一张图片做横向镜像" ) );
    connect( mirrorHorizontalAction, &QAction::triggered, this,
             &ImgProcessor::showMirrorHorizontal );
    // 实现撤销和重做的动作
    // 撤销和重做
    undoAction = new QAction( QIcon( ":/Img/undo.png" ), "撤销", this );
    connect( undoAction, &QAction::triggered, showWidget->text, &QTextEdit::undo );
    redoAction = new QAction( QIcon( ":/Img/redo.png" ), "重做", this );
    connect( redoAction, &QAction::triggered, showWidget->text, &QTextEdit::redo );
}

void ImgProcessor::createMenus()
{
    // 文件菜单
    fileMenu = menuBar()->addMenu( tr( "文件" ) );
    fileMenu->addAction( openFileAction );
    fileMenu->addAction( NewFileAction );
    fileMenu->addAction( PrintTextAction );
    fileMenu->addAction( PrintImageAction );
    fileMenu->addSeparator();
    fileMenu->addAction( exitAction );
    // 缩放菜单
    zoomMenu = menuBar()->addMenu( tr( "编辑" ) );
    zoomMenu->addAction( copyAction );
    zoomMenu->addAction( cutAction );
    zoomMenu->addAction( pasteAction );
    zoomMenu->addAction( aboutAction );
    zoomMenu->addSeparator();
    zoomMenu->addAction( zoomInAction );
    zoomMenu->addAction( zoomOutAction );
    // 旋转菜单
    rotateMenu = menuBar()->addMenu( tr( "旋转" ) );
    rotateMenu->addAction( rotate90Action );
    rotateMenu->addAction( rotate180Action );
    rotateMenu->addAction( rotate270Action );
    // 镜像菜单
    mirrorMenu = menuBar()->addMenu( tr( "镜像" ) );
    mirrorMenu->addAction( mirrorVerticalAction );
    mirrorMenu->addAction( mirrorHorizontalAction );
}

void ImgProcessor::createToolBars()
{
    // 文件工具条
    fileTool = addToolBar( "File" );
    fileTool->addAction( openFileAction );
    fileTool->addAction( NewFileAction );
    fileTool->addAction( PrintTextAction );
    fileTool->addAction( PrintImageAction );
    // 编辑工具条
    zoomTool = addToolBar( "Edit" );
    zoomTool->addAction( copyAction );
    zoomTool->addAction( cutAction );
    zoomTool->addAction( pasteAction );
    zoomTool->addSeparator();
    zoomTool->addAction( zoomInAction );
    zoomTool->addAction( zoomOutAction );
    // 旋转工具条
    rotateTool = addToolBar( "Rotate" );
    rotateTool->addAction( rotate90Action );
    rotateTool->addAction( rotate180Action );
    rotateTool->addAction( rotate270Action );
    // 撤销和重做工具条
    doToolBar = addToolBar( "DoEdit" );
    doToolBar->addAction( undoAction );
    doToolBar->addAction( redoAction );

    fileTool->setAllowedAreas(
        Qt::TopToolBarArea |
        Qt::LeftToolBarArea ); // 工具条是一个可移动的窗口，它可停靠的区域由QToolBar的allowAreas决定
    fileTool->setMovable( false );
}

void ImgProcessor::loadFile( QString fileName )
{
    printf( "file name:%s\n", fileName.data() );
    QFile file( fileName );
    if ( file.open( QIODevice::ReadOnly | QIODevice::Text ) )
    {
        QTextStream textStream( &file );
        while ( !textStream.atEnd() )
        {
            showWidget->text->append( textStream.readLine() );
            printf( "readLine\n" );
        }
        printf( "end\n" );
    }
}

void ImgProcessor::mergeFormat( QTextCharFormat ) {}

void ImgProcessor::showNewFile()
{
    ImgProcessor *newImgProcessor = new ImgProcessor;
    newImgProcessor->show();
}

void ImgProcessor::showOpenFile()
{
    fileName = QFileDialog::getOpenFileName( this );
    if ( !fileName.isEmpty() )
    {
        if ( showWidget->text->document()->isEmpty() )
        {
            loadFile( fileName );
        }
        else
        {
            ImgProcessor *newImgProcessor = new ImgProcessor;
            newImgProcessor->show();
            newImgProcessor->loadFile( fileName );
        }
    }
}

void ImgProcessor::showPrintText()
{
    QPrinter     printer; // 新建一个QPrinter对象
    QPrintDialog printDialog( &printer, this );
    if ( printDialog.exec() )
    {
        // 获得QTextEdit对象的文档
        QTextDocument *doc = showWidget->text->document();
        doc->print( &printer );
    }
}

void ImgProcessor::showPrintImage()
{
    QPrinter     printer;
    QPrintDialog printDialog( &printer, this );
    if ( printDialog.exec() )
    {
        QPainter painter( &printer );
        QRect    rect = painter.viewport(); // 获得QPainter对象的视图矩形区域
        QSize    size = img.size();         // 获得图像的大小
        /*按照图形比例大小重新设置视图矩形区域*/
        size.scale( rect.size(), Qt::KeepAspectRatio );
        painter.setViewport( rect.x(), rect.y(), size.width(), size.height() );
        painter.setWindow( img.rect() ); // 设置QPainter窗口大小为图像的大小
        painter.drawImage( 0, 0, img );  // 打印图像
    }
}

void ImgProcessor::showZoomIn()
{
    if ( img.isNull() ) // 有效性判断
        return;
    QTransform transform; // 声明一个 QTransform 类的实例 在 Qt6 中，QMatrix 被替换为
                          // QTransform，并且变换函数的用法也略有不同。
    transform.scale( 2, 2 );
    img = img.transformed( transform );
    // 重新设置显示图形
    showWidget->imageLabel->setPixmap( QPixmap::fromImage( img ) );
}

void ImgProcessor::showZoomOut()
{
    if ( img.isNull() )
        return;
    QTransform transform;
    transform.scale( 0.5, 0.5 );
    img = img.transformed( transform );

    showWidget->imageLabel->setPixmap( QPixmap::fromImage( img ) );
}

void ImgProcessor::showRotate90()
{
    if ( img.isNull() )
        return;
    QTransform transform;
    transform.rotate( 90 );
    img = img.transformed( transform );
    showWidget->imageLabel->setPixmap( QPixmap::fromImage( img ) );
}

void ImgProcessor::showRotate180()
{
    if ( img.isNull() )
        return;
    QTransform transform;
    transform.rotate( 180 );
    img = img.transformed( transform );
    showWidget->imageLabel->setPixmap( QPixmap::fromImage( img ) );
}

void ImgProcessor::showRotate270()
{
    if ( img.isNull() )
        return;
    QTransform transform;
    transform.rotate( 270 );
    img = img.transformed( transform );
    showWidget->imageLabel->setPixmap( QPixmap::fromImage( img ) );
}

void ImgProcessor::showMirrorVertical()
{
    if ( img.isNull() )
        return;
    img = img.mirrored( false, true );
    showWidget->imageLabel->setPixmap( QPixmap::fromImage( img ) );
}

void ImgProcessor::showMirrorHorizontal()
{
    if ( img.isNull() )
        return;
    img = img.mirrored( true, false );
    showWidget->imageLabel->setPixmap( QPixmap::fromImage( img ) );
}

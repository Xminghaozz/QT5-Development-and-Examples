#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow( QWidget *parent )
    : QMainWindow( parent )
    , ui( new Ui::MainWindow )
{
    ui->setupUi( this );
    this->initMainWindow(); // 执行初始化方法
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::initMainWindow()
{
    // 用初始化方法对系统主窗体进行初始化
    ui->stackedWidget->setCurrentIndex( 1 );                    // 置于商品管理主页
    ui->toolBox->setCurrentIndex( 0 );                          // 新品入库显示页在前面
    QSqlQueryModel *categoryModel = new QSqlQueryModel( this ); // 商品类别模型数据
    categoryModel->setQuery( "select Name from category" );
    ui->newCategoryComboBox->setModel( categoryModel ); // 商品类别列表加载(新品入库页)

    commodity_model = new QSqlTableModel( this ); // 商品信息视图
    commodity_model->setTable( "commodity_inf" );
    commodity_model->select();
    ui->commodityTableView->setModel(
        commodity_model ); // 库存商品记录数据网格信息加载("新品入库“页）

    ui->preCategoryComboBox->setModel( categoryModel ); // 商品类别列表加载("预售订单”页）

    loadPreCommodity(); // 在“预售订单”页加载商品信息
    myMemberID = "00000001";
    myOrdered  = false; // 尚未有人购物
    myOrderID  = 0;
    myPaySum   = 0; // 当前订单累计付款金额

    QListWidgetItem *title = new QListWidgetItem;
    title->setText( QString( "当前订单[编号%1]" ).arg( myOrderID ) );
    title->setTextAlignment( Qt::AlignCenter );
}

void MainWindow::onTableSelectChange( int row )
{
    // 当用户变更选择商品信息数据网格中的条目时执行对应的表单更新
    int r = 1;
    if ( row != 0 )
        r = ui->commodityTableView->currentIndex().row();
    QModelIndex index;
    index = commodity_model->index( r, 0 ); // 名称
    ui->newNameLineEdit->setText( commodity_model->data( index ).toString() );
    index = commodity_model->index( r, 1 ); // 进价
    ui->newInputPriceLineEdit->setText( commodity_model->data( index ).toString() );
    index = commodity_model->index( r, 2 );
    ui->newOutputPriceLineEdit->setText( commodity_model->data( index ).toString() );
    showCommodityPhoto();
    QSqlQuery query;

    query.exec( QString( "select Namefrom category where CategoryID= (selectCategoryID from "
                         "commodity where Name='%1') " )
                    .arg( ui->newNameLineEdit->text() ) );
    query.next();
    ui->newCategoryComboBox->setCurrentText( query.value( 0 ).toString() );
}

void MainWindow::showCommodityPhoto()
{
    // 显示商品样照
    QPixmap         photo;
    QModelIndex     index;
    QSqlQueryModel *pictureModel = new QSqlQueryModel( this );
    QString         name         = ui->newNameLineEdit->text();
    pictureModel->setQuery( "select Picture from commodity where Name='" + name + "' " );
    index = pictureModel->index( 0, 0 );
    photo.loadFromData( pictureModel->data( index ).toByteArray(), "JPG" );
    ui->newPictureLabel->setPixmap( photo );
}

void MainWindow::loadPreCommodity()
{
    // 预售订单页加载显示商品信息
    QSqlQueryModel *commodityNameModel = new QSqlQueryModel( this ); // 商品名称数据模型
    commodityNameModel->setQuery( QString( "select Name from commodity where CategoryID = (select "
                                           "CategoryID from category where Name ='%1')" )
                                      .arg( ui->preCategoryComboBox->currentText() ) );
    ui->preNameComboBox->setModel( commodityNameModel );
    onPreNameComboBoxChange();
}

void MainWindow::onPreNameComboBoxChange()
{
    // 在“预售订单”页改选商品名称时联动显示该商品的各信息项
    QSqlQueryModel *preCommodityModel = new QSqlQueryModel( this ); // 商品表数据模型
    QString         name = ui->preNameComboBox->currentText();      // 当前选中的商品名
    preCommodityModel->setQuery(
        "select OutputPrice, Amount, Picture from commodity where Name ='" + name +
        "'" ); // 从数据库中查出单价、库存、照片等信息

    QModelIndex index;
    index = preCommodityModel->index( 0, 0 ); // 单价
    ui->preOutputPriceLabel->setText( preCommodityModel->data( index ).toString() );
    index = preCommodityModel->index( 0, 1 ); // 库存
    ui->preAmountLabel->setText( preCommodityModel->data( index ).toString() );
    ui->preCountSpinBox->setMaximum( ui->preAmountLabel->text().toInt() );

    // 下面开始获取和展示图片
    QPixmap photo;
    index = preCommodityModel->index( 0, 2 );
    photo.loadFromData( preCommodityModel->data( index ).toByteArray(), "JPG" );
    ui->prePictureLabellabel->setPixmap( photo );

    // 计算总价
    ui->preTotalLabel->setText( QString::number( ui->preOutputPriceLabel->text().toFloat() *
                                                 ui->preCountSpinBox->value() ) );
}

void MainWindow::on_commodityTableView_clicked( const QModelIndex &index )
{
    onTableSelectChange( 1 ); // 在选择数据网格中不同的商品条目时执行
}

void MainWindow::on_preCategoryComboBox_currentIndexChanged( int index )
{
    loadPreCommodity(); // 下拉列表改变类别时加载对应类下的商品
}

void MainWindow::on_preNameComboBox_currentIndexChanged( int index )
{
    onPreNameComboBoxChange(); // 选择不同商品名联动显示该商品各信息项
}

void MainWindow::on_preCountSpinBox_valueChanged( int arg1 )
{
    // 修改出售商品数量时对应计算总价
    ui->preTotalLabel->setText(
        QString::number( ui->preOutputPriceLabel->text().toFloat() * arg1 ) );
}

void MainWindow::on_preSellPushButton_clicked()
{
    // “出售”按钮单击事件过程代码
}

void MainWindow::on_prePlaceOrderPushButton_clicked()
{
    // “下单”按钮单击事件过程代码
}

void MainWindow::on_newUploadPushButton_clicked()
{
    // “上传”按钮单击事件过程代码
    QString pictureName =
        QFileDialog::getOpenFileName( this, "选择商品图片", ".", "Image File(*.png *.jpg)" );
    if ( pictureName.isEmpty() )
    {
        return;
    }
    myPicImg.load( pictureName );
    ui->newPictureLabel->setPixmap( QPixmap::fromImage( myPicImg ) );
}

void MainWindow::on_newPutinStorePushButton_clicked()
{
    // “入库”按钮单击事件过程代码
    QSqlQuery query;
    query.exec( QString( "select CategoryID from category where Name = '%1'" )
                    .arg( ui->newCategoryComboBox->currentText() ) );
    query.next();
    int     categoryid  = query.value( 0 ).toInt();    // 将要入库的商品类别
    QString name        = ui->newNameLineEdit->text(); // 商品名称
    float   inputprice  = ui->newInputPriceLineEdit->text().toFloat();
    float   outputprice = ui->newOutputPriceLineEdit->text().toFloat();
    int     count       = ui->newCountSpinBox->value(); // 入库量

    // 插入商品信息
    query.exec( QString( "insert into commodity(CategoryID, Name, Picture, InputPrice,OutputPrice, "
                         "Amount) values (%1,'%2', NULL,%3,%4,%5)" )
                    .arg( categoryid )
                    .arg( name )
                    .arg( inputprice )
                    .arg( outputprice )
                    .arg( count ) );

    // 插入照片
    QByteArray picdata;
    QBuffer    buffer( &picdata );
    buffer.open( QIODevice::WriteOnly );
    myPicImg.save( &buffer, "JPG" );
    QVariant var( picdata );

    QString sqlstr = "update commodity set Picture=? where Name ='" + name + "'";
    query.prepare( sqlstr );
    query.addBindValue( var );
    if ( !query.exec() )
    {
        QMessageBox::information( 0, QObject::tr( "提示" ), "照片写入失败" );
    }

    // 刷新网格信息
    commodity_model->setTable( "commodity_inf" );
    commodity_model->select();
    ui->commodityTableView->setModel( commodity_model );
}

void MainWindow::on_newClearancePushButton_clicked()
{
    // “清仓”按钮单击事件过程代码
}

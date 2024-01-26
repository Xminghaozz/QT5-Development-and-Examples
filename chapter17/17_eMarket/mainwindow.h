#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QBuffer>
#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
// #include "opencv2/opencv.hpp"
#include <QPixmap>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QTime>

// using namespace cv;
QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    MainWindow( QWidget *parent = nullptr );
    ~MainWindow();

    void initMainWindow();               // 界面初始化方法
    void onTableSelectChange( int row ); // 商品信息数据网格与表单联动
    void showCommodityPhoto();           // 显示商品样照
    void loadPreCommodity();             // 加载"预售订单"页商品名称列表
    void onPreNameComboBoxChange();      //"预售订单"页商品名与表单联动

  private slots:
    void on_commodityTableView_clicked( const QModelIndex &index ); // 商品信息数据网格单击事件槽
    void on_preCategoryComboBox_currentIndexChanged( int index ); // 类别与商品名列表联动信息槽
    void on_preNameComboBox_currentIndexChanged( int index ); // 改选商品名信息槽
    void on_preCountSpinBox_valueChanged( int arg1 );         // 售出商品数改变信息槽
    void on_preSellPushButton_clicked();                      // 出售按钮单击事件
    void on_prePlaceOrderPushButton_clicked();                // 下单按钮单击事件
    void on_newUploadPushButton_clicked();                    // 上传按钮单击事件
    void on_newPutinStorePushButton_clicked();                // 入库按钮单击事件
    void on_newClearancePushButton_clicked();                 // 清仓按钮单击事件

  private:
    Ui::MainWindow *ui;
    QImage          myPicImg;        // 保存商品样照
    QSqlTableModel *commodity_model; // 访问数据库商品信息视图的模型
    QString         myMemberID;      // 会员账号
    bool            myOrdered;       // 是否正在购买(订单已写入数据库)
    int             myOrderID;       // 订单编号
    float           myPaySum;        // 当前订单累计需要付款的总金额
};

/*访问数据库的静态方法*/
static bool createMySqlConn()
{
    QSqlDatabase sqldb = QSqlDatabase::addDatabase( "QMYSQL" );
    sqldb.setDatabaseName( "emarket" );
    sqldb.setHostName( "localhost" );
    sqldb.setPort( 3306 );
    sqldb.setUserName( "root" );
    sqldb.setPassword( "001127" );

    if ( !sqldb.open() )
    {
        QMessageBox::critical( 0, QObject::tr( "后台数据库连接失败！" ), "无法创建连接",
                               QMessageBox::Cancel );
        return false;
    }
    return true;
}
#endif // MAINWINDOW_H

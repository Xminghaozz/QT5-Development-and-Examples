#include "area.h"
#include <QString>
#include <QtTest>
// add necessary includes here

class TestArea : public QObject
{
    Q_OBJECT

  public:
    TestArea();
    ~TestArea();

  private slots:
    void toArea();      // 测试函数名toArea()
    void toArea_data(); // 初始化测试数据
};

TestArea::TestArea() {}

TestArea::~TestArea() {}

void TestArea::toArea()
{
    // 获取测试数据
    QFETCH( Area, area );
    QFETCH( double, r );
    QVERIFY( qAbs( area.CountArea() - r ) < 0.0000001 );
    QVERIFY2( true, "Failure" );
}

void TestArea::toArea_data()
{
    // 定义测试数据列
    QTest::addColumn<Area>( "area" );
    QTest::addColumn<double>( "r" );
    // 建立测试数据
    QTest::newRow( "1" ) << Area( 1 ) << 3.14;
    QTest::newRow( "2" ) << Area( 2 ) << 12.56;
    QTest::newRow( "3" ) << Area( 3 ) << 28.26;
}

QTEST_APPLESS_MAIN( TestArea ) // 该宏将 Area 定义为元类型，这样所有基于模板的函数都可以使用 Area。

#include "tst_testarea.moc"

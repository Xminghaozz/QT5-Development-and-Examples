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
    void test_case1();
};

TestArea::TestArea() {}

TestArea::~TestArea() {}

void TestArea::test_case1()
{
    Area area( 1 );
    QVERIFY( qAbs( area.CountArea() - 3.14 ) < 0.0000001 );
    QVERIFY2( true, "Failure" );
}

QTEST_APPLESS_MAIN( TestArea )

#include "tst_testarea.moc"

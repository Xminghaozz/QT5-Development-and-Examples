#include <QString>
#include <QtTest>
// add necessary includes here

class TestQString2 : public QObject
{
    Q_OBJECT

  public:
    TestQString2();
    ~TestQString2();

  private slots:
    void testBenchMark();
};

TestQString2::TestQString2() {}

TestQString2::~TestQString2() {}

void TestQString2::testBenchMark()
{
    QString str( "hello" );
    // 用于测试性能的代码
    QBENCHMARK { str.toLower(); }

    QVERIFY2( true, "Failure" );
}

QTEST_APPLESS_MAIN( TestQString2 )

#include "tst_testqstring2.moc"

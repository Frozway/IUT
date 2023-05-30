#include <QtTest>
#include "../App/merchandise.h"
#include "qtestcase.h"

// add necessary includes here

class merchandiseTest : public QObject
{
    Q_OBJECT

public:
    merchandiseTest();
    ~merchandiseTest();
    Merchandise * a ;
    Merchandise * b ;
    Merchandise * c ;

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_operator();
    void test_operator2();

};

merchandiseTest::merchandiseTest()
{

}

merchandiseTest::~merchandiseTest()
{

}

void merchandiseTest::initTestCase()
{
    a = new Merchandise(100, 300);
    b = new Merchandise(100, 300);
    c = new Merchandise(100, 500);

}

void merchandiseTest::cleanupTestCase()
{
    delete a ;
    delete b ;
    delete c ;
}

void merchandiseTest::test_operator()
{
    QCOMPARE(*a==*b, true);
    QCOMPARE(*a==*c, false);
}

void merchandiseTest::test_operator2()
{
    QCOMPARE(*a==*b, true);
    QCOMPARE(*a==*c, false);
}

QTEST_APPLESS_MAIN(merchandiseTest)

#include "tst_merchandisetest.moc"

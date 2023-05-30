#include <QtTest>

// add necessary includes here

class PersonUnitTests : public QObject
{
    Q_OBJECT

public:
    PersonUnitTests();
    ~PersonUnitTests();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void getterAndSetter();

};

PersonUnitTests::PersonUnitTests()
{

}

PersonUnitTests::~PersonUnitTests()
{

}

void PersonUnitTests::initTestCase()
{

}

void PersonUnitTests::cleanupTestCase()
{

}

void PersonUnitTests::getterAndSetter()
{

}

QTEST_APPLESS_MAIN(PersonUnitTests)

#include "tst_personunittests.moc"

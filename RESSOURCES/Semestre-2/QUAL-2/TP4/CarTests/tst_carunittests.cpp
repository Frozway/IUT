#include <QtTest>

// add necessary includes here
#include "../App-CAR/car.h"
#include "../App-CAR/person.h"

class CarUnitTests : public QObject
{
    Q_OBJECT

public:
    CarUnitTests();
    ~CarUnitTests();
    Person* person1;
    Person* person2;
    Person* person3;
    Car* car;

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testGetter();
    void testAdd();

};

CarUnitTests::CarUnitTests()
{
}

CarUnitTests::~CarUnitTests()
{


}

void CarUnitTests::initTestCase()
{
    car= new Car("Toyota", "Corolla", "ABC123", 5, 1000);
    person1 = new Person("John", 70);
    person2 = new Person("Alice", 65);
    person3 = new Person("Bob", 80);

}

void CarUnitTests::cleanupTestCase()
{
    delete car ;
    delete person1;
    delete person2;
    delete person3;
}

void CarUnitTests::testAdd()

{
    QCOMPARE(car->getItsDriver(), nullptr);
    car->addDriver(person1);
    QCOMPARE(car->getItsDriver(), person1);
}

void CarUnitTests::testGetter()
{

}



QTEST_APPLESS_MAIN(CarUnitTests)

#include "tst_carunittests.moc"

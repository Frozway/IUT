#include "person.h"
#include <iostream>

Person::Person(string name, int weight): itsName(name), itsWeigth(weight)
{

}

int Person::getItsWeigth() const
{
    return itsWeigth;
}

void Person::setItsWeigth(int value)
{
    itsWeigth = value;
}

string Person::getItsName() const
{
    return itsName;
}

void Person::setItsName(const string &value)
{
    itsName = value;
}

void Person::display()
{
    cout << itsName << " (" << itsWeigth << " kg)";
}

bool Person::operator==(const Person & person) const {
    return (itsName == person.getItsName()) && (itsWeigth == person.getItsWeigth());
}

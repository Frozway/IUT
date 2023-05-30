#include "address.h"

int Address::getItsNo() const
{
    return itsNo;
}

string Address::getItsStreetName() const
{
    return itsStreetName;
}

int Address::getItsPostalCode() const
{
    return itsPostalCode;
}

string Address::getItsCity() const
{
    return itsCity;
}

void Address::setItsNo(int newItsNo)
{
    itsNo = newItsNo;
}

void Address::setItsStreetName(const string &newItsStreetName)
{
    itsStreetName = newItsStreetName;
}

void Address::setItsPostalCode(int newItsPostalCode)
{
    itsPostalCode = newItsPostalCode;
}

void Address::setItsCity(const string &newItsCity)
{
    itsCity = newItsCity;
}

Address::Address()
{

}

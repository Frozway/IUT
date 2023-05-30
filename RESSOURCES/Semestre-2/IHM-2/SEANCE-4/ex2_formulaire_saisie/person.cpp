#include "person.h"

void Person::setName(const QString &aName)
{
    itsName = aName;
}

void Person::setFirstname(const QString &aFirstname)
{
    itsFirstname = aFirstname;
}

void Person::setDate(const QDate &aDate)
{
    itsDate = aDate;
}

QString Person::getItsName() const
{
    return itsName;
}

QString Person::getItsFirstname() const
{
    return itsFirstname;
}

QDate Person::getItsDate() const
{
    return itsDate;
}

Person::Person()
{

}

#include "person.h"

Person::Person()
{

}

QString Person::transformName(QString aFirstname)
{
    return aFirstname.toUpper();
}

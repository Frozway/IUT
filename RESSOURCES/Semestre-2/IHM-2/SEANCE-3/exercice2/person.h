#ifndef PERSON_H
#define PERSON_H

#include "qdatetime.h"
#include <QWidget>

class Person
{
private:
    QString itsName ;
    QString itsFirsName ;
    QDate itsDate ;
public:
    Person();
};

#endif // PERSON_H

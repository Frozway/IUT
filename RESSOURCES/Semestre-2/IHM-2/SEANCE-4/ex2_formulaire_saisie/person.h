#ifndef PERSON_H
#define PERSON_H

#include "QtCore/qdatetime.h"
#include <QWidget>

class Person
{
private:
    QString itsName;
    QString itsFirstname;
    QDate itsDate;
public:
    Person();
    void setName(const QString &aName);
    void setFirstname(const QString &aFirstname);
    void setDate(const QDate &aDate);
    QString getItsName() const;
    QString getItsFirstname() const;
    QDate getItsDate() const;
};

#endif // PERSON_H

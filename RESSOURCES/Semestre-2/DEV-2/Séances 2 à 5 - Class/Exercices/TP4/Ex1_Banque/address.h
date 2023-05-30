#ifndef ADDRESS_H
#define ADDRESS_H
#include <iostream>

using namespace std ;

class Address
{
private :
    int itsNo ;
    string itsStreetName ;
    int itsPostalCode ;
    string itsCity ;

public:
    Address();
    int getItsNo() const;
    string getItsStreetName() const;
    int getItsPostalCode() const;
    string getItsCity() const;
    void setItsNo(int newItsNo);
    void setItsStreetName(const string &newItsStreetName);
    void setItsPostalCode(int newItsPostalCode);
    void setItsCity(const string &newItsCity);
};

#endif // ADDRESS_H

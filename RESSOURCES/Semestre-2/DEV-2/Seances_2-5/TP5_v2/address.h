#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>

using namespace std ;

class Address
{
private:
    int itsNo ;
    string itsStreetName ;
    int itsPostalCode ;
    string itsCity ;
public:
    Address(int no, string streetName, int postalCode, string  city);
    void display();
};

#endif // ADDRESS_H

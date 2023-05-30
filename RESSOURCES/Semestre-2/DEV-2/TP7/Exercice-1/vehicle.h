#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>

using namespace std ;

class Vehicle
{
protected:
    string itsBrand ;
    string itsModel ;
    string itsRegistrationPlate ;
    int itsConstructionYear ;
    int itsHP;
public:
    Vehicle(string brand, string model, string registrationPlate, int constructionYear, int hp);
    virtual void display() = 0 ;
};

#endif // VEHICLE_H

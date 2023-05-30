#ifndef LORRY_H
#define LORRY_H
#include "vehicle.h"
#include <iostream>

using namespace std ;

class Lorry : public Vehicle
{
private:
    int itsAutoriseLoad ;
public:
    Lorry(string brand, string model, string registrationPlate, int constructionYear, int hp, int autorisedLoad);
    void display();
};

#endif // LORRY_H

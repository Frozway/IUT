#ifndef CAR_H
#define CAR_H
#include "vehicle.h"
#include <iostream>

class Car : public Vehicle
{
private:
    int itsNbSeats ;
public:
    Car(string brand, string model, string registrationPlate, int constructionYear, int hp, int nbSeats);
    void display();
};

#endif // CAR_H

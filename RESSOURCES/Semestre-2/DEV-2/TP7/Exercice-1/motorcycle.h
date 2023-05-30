#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H
#include "vehicle.h"
#include <iostream>

using namespace std ;

class MotorCycle : public Vehicle
{
private:
    int itsCapacity ;
public:
    MotorCycle(string brand, string model, string registrationPlate, int constructionYear, int hp, int capacity);
    void display();
};

#endif // MOTORCYCLE_H

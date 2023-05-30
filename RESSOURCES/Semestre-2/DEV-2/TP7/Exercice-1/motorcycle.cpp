#include "motorcycle.h"

MotorCycle::MotorCycle(string brand, string model, string registrationPlate, int constructionYear, int hp, int capacity)
    :Vehicle(brand, model, registrationPlate, constructionYear, hp), itsCapacity(capacity)
{

}

void MotorCycle::display() {
    cout << "Brand: " << itsBrand << endl;
    cout << "Model: " << itsModel  << endl;
    cout << "License Plate: " << itsRegistrationPlate << endl;
    cout << "Year of Construction: " << itsConstructionYear << endl;
    cout << "Horsepower: " << itsHP << endl;
    cout << "Capacity : " << itsCapacity << endl;
}

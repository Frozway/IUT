#include "car.h"

Car::Car(string brand, string model, string registrationPlate, int constructionYear, int hp, int nbSeats)
    :Vehicle(brand, model, registrationPlate, constructionYear, hp), itsNbSeats(nbSeats)
{
}


void Car::display() {
    cout << endl << "   Brand: " << itsBrand << endl;
    cout << "   Model: " << itsModel  << endl;
    cout << "   License Plate: " << itsRegistrationPlate << endl;
    cout << "   Year of Construction: " << itsConstructionYear << endl;
    cout << "   Horsepower: " << itsHP << endl;
    cout << "   Number of Seats: " << itsNbSeats << endl;
}



#include "lorry.h"

Lorry::Lorry(string brand, string model, string registrationPlate, int constructionYear, int hp, int autorisedLoad)
    :Vehicle(brand, model, registrationPlate, constructionYear, hp), itsAutoriseLoad(autorisedLoad)
{
}

void Lorry::display() {
    cout << "Brand: " << itsBrand << endl;
    cout << "Model: " << itsModel  << endl;
    cout << "License Plate: " << itsRegistrationPlate << endl;
    cout << "Year of Construction: " << itsConstructionYear << endl;
    cout << "Horsepower: " << itsHP << endl;
    cout << "Autorise Load : " << itsAutoriseLoad << endl;
}

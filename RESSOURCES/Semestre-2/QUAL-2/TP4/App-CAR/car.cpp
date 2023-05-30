#include "car.h"
#include <algorithm>
#include <iostream>

int Car::getItsLoad() const
{
    return itsLoad;
}

int Car::getItsSpeed() const
{
    return itsSpeed;
}

int Car::getItsKm() const
{
    return itsKm;
}

Person * Car::getItsDriver() const
{
    return itsDriver;
}

State Car::getItsState() const
{
    return itsState;
}

Car::Car(string brand, string model, string registrationPlate, int noMaxPassengers, int maxLoad)
    : itsBrand(brand),itsModel(model),itsRegistrationPlate(registrationPlate), itsNoMaxPassengers(noMaxPassengers),
      itsMaxLoad(maxLoad)
{
    itsState = STARTED;
    itsSpeed = 0;
    itsKm = 0;
    itsLoad = 0;
    itsPassengers = new vector<Person *>();
    itsDriver = nullptr;
}

int Car::getNoPassengers()
{
    return itsPassengers->size();
}

void Car::addDriver(Person * driver)
{
    if (itsState == STARTED)
        throw string("Impossible de monter le conducteur lorsque la voiture n'est pas arretee !");
    if (itsDriver != nullptr)
       itsLoad -= itsDriver->getItsWeigth();
    itsDriver = driver;
}

void Car::start()
{
    if (itsState != STOPPED)
        throw string("La voiture est deja demarree !");
    if (itsDriver == nullptr)
        throw string("Impossible de demarrer sans conducteur !");
    itsState = STARTED;
}

void Car::stop()
{
    if (itsState == STOPPED)
        throw string("La voiture est deja arretee !");
    itsState = STOPPED;
    itsLoad -= itsDriver->getItsWeigth();
    itsDriver = nullptr;
}

void Car::accelerate()
{
    if (itsState != STARTED)
        throw string("La voiture n'est pas demaree !");
    if (itsSpeed + 10 > MAX_SPEED)
    {
        itsSpeed = MAX_SPEED;
        throw string("Vitesse minimale atteinte !");
    }
    itsSpeed += 10;
}

void Car::slowdown()
{
    if (itsState != STARTED)
        throw string("La voiture n'est pas demaree !");
    if (itsSpeed < MIN_SPEED)
    {
        itsSpeed = MIN_SPEED;
        throw string("Vitesse minimale atteinte !");
    }
    itsSpeed -= 10;
}

void Car::drive(int hours)
{
    if (itsState != STARTED)
        throw string("La voiture est arretee !");
    itsKm += itsSpeed * hours;
}

bool Car::isPassenger(Person *person)
{
    vector<Person *>::iterator it = find(itsPassengers->begin(), itsPassengers->end(), person);
    return (it != itsPassengers->end());
}

bool Car::isDriver(Person *person)
{
    if (itsDriver == nullptr)
        return false;
    return *itsDriver == *person;
}

void Car::addPassenger(Person *person)
{
    if (itsState != STOPPED)
        throw string("La voiture n'est pas arretee !");
    else if (getNoPassengers() == itsNoMaxPassengers)
        throw string("Plus de place !");
    else if (itsLoad + person->getItsWeigth() > itsMaxLoad)
        throw string("Passager trop lourd !");
    else if (isPassenger(person))
        throw string(person->getItsName() + " est déjà passager");
    else if (isDriver(person))
         throw string(person->getItsName() + " est déjà conducteur");
    else
    {
        itsLoad += person->getItsWeigth();
    }
}

void Car::removePassenger(Person *person)
{
    if (itsState != STOPPED)
        throw string("La voiture n'est pas arretee !");
    else if (itsPassengers->empty())
        throw string("Il n'y a plus de passager !");
    else
    {
         vector<Person *>::iterator it = find(itsPassengers->begin(), itsPassengers->end(), person);
         if (it != itsPassengers->end())
         {
             itsLoad -= person->getItsWeigth();
             itsPassengers->erase(it);
         }
    }
}

void Car::displayPersons()
{
    cout << "Driver: ";
    itsDriver->display();
    cout << endl;

    if (! itsPassengers->empty())
    {
        cout << "Passengers: ";
        for (Person * p : *itsPassengers)
        {
            p->display();
            cout << " ";
        }
        cout << endl;
    }
}

void Car::displayState()
{
    string state = (itsState==STOPPED) ? "stopped" : "started";
    cout << "State: " << state << " speed: " << itsSpeed << " km: " << itsKm
         << " load: " << itsLoad << endl;
}

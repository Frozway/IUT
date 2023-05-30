#ifndef CAR_H
#define CAR_H

#include <string>
#include "person.h"
#include <vector>
using namespace std;

enum State{STARTED, STOPPED};

class Car
{
private:
    string itsBrand;
    string itsModel;
    string itsRegistrationPlate;
    int itsNoMaxPassengers;
    int itsMaxLoad;

    int itsSpeed;
    int itsKm;
    State itsState;
    Person * itsDriver;
    int itsLoad;
    vector<Person *> * itsPassengers;

public:
    static const int MAX_SPEED = 180;
    static const int MIN_SPEED = 0;
    Car(string brand, string model, string registrationPlate, int noMaxPassengers, int maxLoad);
    int getNoPassengers();
    void addDriver(Person * driver);
    void start();
    void stop();
    void accelerate();
    void slowdown();
    void drive(int hours);
    bool isPassenger(Person * person);
    bool isDriver(Person * person);
    void addPassenger(Person * person);
    void removePassenger(Person * person);
    void displayPersons();
    void displayState();
    int getItsLoad() const;
    int getItsSpeed() const;
    int getItsKm() const;
    Person *getItsDriver() const;
    State getItsState() const;
};

#endif // CAR_H

#ifndef INSURANCE_H
#define INSURANCE_H
#include "client.h"
#include "vehicle.h"
#include <iostream>
#include <map>
#include <vector>

using namespace std;


class Insurance
{
private:
    string itsName;
    map<Client *, vector<Vehicle*>> * itsVehicleContracts ;
public:
    Insurance(string name);
    ~Insurance();
    void addContract(Client *client, Vehicle *vehicle);
    void removeContract(Client *client, Vehicle *vehicle);
    void displayContracts();
    void displayContractsClient(Client *client);
};

#endif // INSURANCE_H

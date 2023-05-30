#ifndef CLIENT_H
#define CLIENT_H

#include <vector>
#include "address.h"
#include "order.h"
#include <string>

using namespace std ;

class Client
{
private:
    string itsForename ;
    string itsLastName ;
    Address * itsAddress ;
    vector<Order*>* itsOrders ;

public:
    Client(string forename, string lastname, Address * address);
    ~Client();
    void addOrder(Order * order);
    void display();
};

#endif // CLIENT_H

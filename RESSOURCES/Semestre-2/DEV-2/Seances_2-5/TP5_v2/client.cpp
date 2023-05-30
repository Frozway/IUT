#include "client.h"

Client::Client(string forename, string lastname, Address *address)
{
    itsForename = forename ;
    itsLastName = lastname ;
    itsAddress = address ;
    itsOrders = new vector<Order*> ;
}

Client::~Client()
{
    for(vector<Order*>::iterator it = itsOrders->begin() ; it != itsOrders->end() ; it++)
    {
        delete * it ;
    }
}

void Client::addOrder(Order * order)
{
    itsOrders->push_back(order);
}

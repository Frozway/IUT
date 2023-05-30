#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>

using namespace std ;

class Client
{
private:
    string itsForename ;
    string itsLastName ;
    string itsAddress ;
public:
    Client(string forename, string lastName, string address);
    void display() ;
    string getItsLastName() const;
};

#endif // CLIENT_H

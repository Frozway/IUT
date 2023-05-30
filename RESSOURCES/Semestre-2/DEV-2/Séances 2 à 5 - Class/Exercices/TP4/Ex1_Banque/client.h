#ifndef CLIENT_H
#define CLIENT_H
#include "address.h"

class Client
{
private:
    Address itsAddress ;
    string itsForename ;
    string itsLastname ;
public:
    Client();
    Address getItsAddress() const;
    string getItsForename() const;
    string getItsLastname() const;
    void setItsAddress(const Address &newItsAddress);
    void setItsForename(const string &newItsForename);
    void setItsLastname(const string &newItsLastname);
};

#endif // CLIENT_H

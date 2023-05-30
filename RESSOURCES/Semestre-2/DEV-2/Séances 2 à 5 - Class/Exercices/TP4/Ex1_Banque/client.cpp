#include "client.h"

Address Client::getItsAddress() const
{
    return itsAddress;
}

string Client::getItsForename() const
{
    return itsForename;
}

string Client::getItsLastname() const
{
    return itsLastname;
}

void Client::setItsAddress(const Address &newItsAddress)
{
    itsAddress = newItsAddress;
}

void Client::setItsForename(const string &newItsForename)
{
    itsForename = newItsForename;
}

void Client::setItsLastname(const string &newItsLastname)
{
    itsLastname = newItsLastname;
}

Client::Client()
{

}

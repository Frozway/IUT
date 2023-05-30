#include "client.h"

string Client::getItsLastName() const
{
    return itsLastName;
}

Client::Client(string forename, string lastName, string address)
{
    itsForename = forename ;
    itsLastName = lastName ;
    itsAddress = address ;
}

//affiche le prénom, nom et adresse sur la sortie standard

void Client::display()
{
    cout << "Forename : " << itsForename << endl ;
    cout << "Last Name : " << itsLastName << endl ;
    cout << "Address : " << itsAddress << endl ;
}

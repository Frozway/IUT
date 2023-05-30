#include "account.h"

Client Account::getItsOwner() const
{
    return itsOwner;
}

CreditCard Account::getItsCreditCard() const
{
    return itsCreditCard;
}

long Account::getItsAcoutNo() const
{
    return itsAcoutNo;
}

float Account::getItsBalance() const
{
    return itsBalance;
}

void Account::setItsOwner(const Client &newItsOwner)
{
    itsOwner = newItsOwner;
}

void Account::setItsCreditCard(const CreditCard &newItsCreditCard)
{
    itsCreditCard = newItsCreditCard;
}

void Account::setItsAcoutNo(long newItsAcoutNo)
{
    itsAcoutNo = newItsAcoutNo;
}

void Account::setItsBalance(float newItsBalance)
{
    itsBalance = newItsBalance;
}

Account::Account(){

}


void Account::displayAccount()
{
    cout << "Numéro de compte : " << itsAcoutNo << endl;
    cout << "Solde : " << itsBalance << endl;
    cout << "Nom du titulaire : " << itsOwner.getItsLastname() << endl;
    cout << "Prénom du titulaire : " << itsOwner.getItsForename() << endl;
    cout << "Adresse du titulaire : " << itsOwner.getItsAddress().getItsNo() << " "
         << itsOwner.getItsAddress().getItsStreetName() << ", "
         << itsOwner.getItsAddress().getItsPostalCode() << " "
         << itsOwner.getItsAddress().getItsCity() << endl;

    if (itsCreditCard.getItsCardNo() != 0)
    {
        cout << "Numéro de carte : " << itsCreditCard.getItsCardNo() << endl;
        cout << "Type de carte : " << itsCreditCard.getItsCreditCardType() << endl;
        cout << "Date d'expiration : " << itsCreditCard.getItsExpirationDate() << endl;
    }
}


#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "client.h"
#include "creditcard.h"


class Account
{
private:
    Client itsOwner ;
    CreditCard itsCreditCard ;
    long itsAcoutNo ;
    float itsBalance ;
public:
    Account();
    void displayAccount();
    Client getItsOwner() const;
    CreditCard getItsCreditCard() const;
    long getItsAcoutNo() const;
    float getItsBalance() const;
    void setItsOwner(const Client &newItsOwner);
    void setItsCreditCard(const CreditCard &newItsCreditCard);
    void setItsAcoutNo(long newItsAcoutNo);
    void setItsBalance(float newItsBalance);
};

#endif // ACCOUNT_H

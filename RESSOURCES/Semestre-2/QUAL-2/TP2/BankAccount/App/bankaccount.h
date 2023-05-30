#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
using namespace std;

enum Currency{
    DOLLARS,
    EUROS
};

static const char * stringCurrency[]={"$","€"};

class BankAccount
{
private:
    int itsNb;
    float itsBalance;
    float itsAllowedCredit;
    Currency itsCurrency;
public:
    BankAccount(int nb,  Currency itsCurrency);
    void setItsAllowedCredit(float newItsAllowedCredit);
    void deposit(float ammout);
    void retreat(float ammount);
    void display();
};

#endif // BANKACCOUNT_H

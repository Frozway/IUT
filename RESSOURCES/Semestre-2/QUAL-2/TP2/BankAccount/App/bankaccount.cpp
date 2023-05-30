#include "bankaccount.h"
#include "myexception.h"

void BankAccount::setItsAllowedCredit(float newItsAllowedCredit)
{
    itsAllowedCredit = newItsAllowedCredit;
}

BankAccount::BankAccount(int nb, Currency currency)
{
    itsNb=nb;
    itsCurrency=currency;
    itsAllowedCredit=0.;
    itsBalance=0.;
}

void BankAccount::deposit(float ammout){
    itsBalance+=ammout;
}
void BankAccount::retreat(float ammount){
    if(itsBalance - ammount  < -itsAllowedCredit)
        throw MyException("Retrait invalide");
    itsBalance-=ammount;
}
void BankAccount::display(){
    cout<<"The account number "<<itsNb<<" balance is "<< itsBalance << stringCurrency[itsCurrency];
}

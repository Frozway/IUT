#ifndef CREDITCARD_H
#define CREDITCARD_H
#include <iostream>

using namespace std ;

enum CreditCardType{
    CB,
    VISA,
    MASTERCARD
};

class CreditCard
{
private:
    CreditCardType itsCreditCardType ;
    long itsCardNo ;
    string itsExpirationDate ;
public:
    CreditCard();
    CreditCardType getItsCreditCardType() const;
    long getItsCardNo() const;
    string getItsExpirationDate() const;
    void setItsCreditCardType(CreditCardType newItsCreditCardType);
    void setItsCardNo(long newItsCardNo);
    void setItsExpirationDate(const string &newItsExpirationDate);
};

#endif // CREDITCARD_H

#include "creditcard.h"

CreditCardType CreditCard::getItsCreditCardType() const
{
    return itsCreditCardType;
}

long CreditCard::getItsCardNo() const
{
    return itsCardNo;
}

string CreditCard::getItsExpirationDate() const
{
    return itsExpirationDate;
}

void CreditCard::setItsCreditCardType(CreditCardType newItsCreditCardType)
{
    itsCreditCardType = newItsCreditCardType;
}

void CreditCard::setItsCardNo(long newItsCardNo)
{
    itsCardNo = newItsCardNo;
}

void CreditCard::setItsExpirationDate(const string &newItsExpirationDate)
{
    itsExpirationDate = newItsExpirationDate;
}

CreditCard::CreditCard()
{

}

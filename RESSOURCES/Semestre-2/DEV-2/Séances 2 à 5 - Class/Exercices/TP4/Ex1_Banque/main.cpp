#include "account.h"
#include <iostream>

using namespace std;

int main()
{
    // Créer une instance de Address
    Address myAddress;
    myAddress.setItsNo(123);
    myAddress.setItsStreetName("Rue du Faubourg");
    myAddress.setItsPostalCode(75001);
    myAddress.setItsCity("Paris");

    // Créer une instance de Client
    Client myClient;
    myClient.setItsForename("Jean");
    myClient.setItsLastname("Dupont");
    myClient.setItsAddress(myAddress);

    // Créer une instance de CreditCard
    CreditCard myCreditCard;
    myCreditCard.setItsCreditCardType(VISA);
    myCreditCard.setItsCardNo(1234567890123456);
    myCreditCard.setItsExpirationDate("12/24");

    // Créer une instance de Account
    Account myAccount;
    myAccount.setItsOwner(myClient);
    myAccount.setItsCreditCard(myCreditCard);
    myAccount.setItsAcoutNo(123456789);
    myAccount.setItsBalance(5000.0);

    // Créer une nouvelle instance de CreditCard
    CreditCard mySecondCreditCard;
    mySecondCreditCard.setItsCreditCardType(MASTERCARD);
    mySecondCreditCard.setItsCardNo(9876543210123456);
    mySecondCreditCard.setItsExpirationDate("12/26");

    // Ajouter la deuxième carte au compte
    myAccount.setItsCreditCard(mySecondCreditCard);


    myAccount.displayAccount();

}

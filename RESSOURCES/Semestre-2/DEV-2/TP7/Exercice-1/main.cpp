#include "car.h"
#include "client.h"
#include "insurance.h"
#include "motorcycle.h"
#include "vehicle.h"
#include <iostream>

using namespace std;

int main()
{
    //--------------------Test de addContract-----------------------\\

    //Client 1

    // Création d'un véhicule
    Vehicle* myCar = new Car("Renault", "Clio", "AB-123-CD", 2015, 75, 5);

    Shape* myRect = new Rectangle

    // Création d'un client
    Client* myClient = new Client("John", "Doe", "123 Main St.");

    // Création d'une assurance
    Insurance* myInsurance = new Insurance("Assurance Car.");

    // Ajout d'un contrat d'assurance pour le client et le véhicule donnés
    myInsurance->addContract(myClient, myCar);


    //Client 2

    Vehicle* myMotorCycle = new MotorCycle("Honda", "CBR600RR", "AB-456-EF", 2020, 120, 2);

    Client* myClient2 = new Client("Thibaut", "LEFRANCOIS", "123 Main St.");

    Insurance* myInsurance2 = new Insurance("Assurance Motor.");

    myInsurance2->addContract(myClient2, myMotorCycle);

    //--------------------Test de displayContractsClient---------------------\\

    cout << endl ;

    myInsurance->displayContractsClient(myClient);
    myInsurance2->displayContracts();

    //-------------------Test de removeContract----------------------\\

    // suppression du contrat
    myInsurance->removeContract(myClient, myCar);

    myInsurance2->removeContract(myClient2, myMotorCycle);

    // affichage des contrats après suppression

    cout << "Liste des contrats apres suppression: " << endl;

    myInsurance->displayContracts();
    myInsurance2->displayContracts();

    cout << endl << "Fin" << endl << endl ;

    delete myInsurance ;
    delete myInsurance2;

    return 0;
}

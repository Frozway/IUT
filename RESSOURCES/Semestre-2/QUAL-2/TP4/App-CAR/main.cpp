#include <iostream>
#include "car.h"
#include "person.h"

using namespace std;

int main()
{
    // Création de quelques objets Person
        Person* person1 = new Person("John", 70);
        Person* person2 = new Person("Alice", 65);
        Person* person3 = new Person("Bob", 80);

        // Création d'un objet Car
        Car myCar("Toyota", "Corolla", "ABC123", 5, 1000);

        // Ajout du conducteur à la voiture
        myCar.addDriver(person1);

        // Ajout de passagers à la voiture
        myCar.addPassenger(person2);
        myCar.addPassenger(person3);

        // Affichage des personnes présentes dans la voiture
        myCar.displayPersons();

        // Démarrage de la voiture
        myCar.start();

        // Accélération de la voiture
        myCar.accelerate();

        // Conduite pendant 2 heures
        myCar.drive(2);

        // Affichage de l'état de la voiture
        myCar.displayState();

        // Arrêt de la voiture
        myCar.stop();

        // Suppression d'un passager de la voiture
        myCar.removePassenger(person2);

        // Affichage du chargement de la voiture
        cout << "Load: " << myCar.getItsLoad() << endl;

        // Libération de la mémoire des objets Person
        delete person1;
        delete person2;
        delete person3;

        return 0;
}

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string name, firstname, birthdate;
    string filepath = "C:/Users/tibol/Documents/IUT/RESSOURCES/DEV-1/Séance 8 - Les fichiers/TP/adhesion.txt" ;

    cout << "Quel est votre nom : "  ;
    cin >> name ;
    cout << endl << "Quel est votre prénom : " ;
    cin >> firstname ;
    cout << endl << "Quel est votre date anniv : " ;
    cin >> birthdate ;

    ofstream outputFile("adhesion.txt") ;

    outputFile << name << endl << firstname << endl << birthdate ;

}

#include <iostream>

using namespace std;

//Fonction qui à pour but de déterminer et d'afficher les années bisextiles sur une plage donnée
//La fonction ne renvoit pas de valeur, mais a pour paramètre la plage donnée
void bisex(int year1, int year2)
{
    for (int year = year1 ; year <= year2 ; year ++)
    {
        if ((!(year % 4) and (year % 100)) or ! (year % 400))
        {
            cout << year << endl ;
        }
    }
}

int main()
{
    unsigned short int year1, year2 ;

    cout << "Entrez l'année de départ : " ;
    cin >> year1 ;
    cout << "Entrez l'année de fin : " ;
    cin >> year2 ;

    //Exécuter la fonction avec les paramètres définis par l'utilisateur
    bisex(year1, year2) ;

}

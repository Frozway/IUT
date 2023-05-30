#include <iostream>
using namespace std;

int PGCD(int a, int b)
{
    int reste = 0 ;

    do
    {
        reste = a%b ;

        if (reste == 0)
        {
            return b ;
        }

        else
        {
            a = b ;
            b = reste;
        }
    }

    while (reste != 0) ;




} ;

int main()
{
    int num1, num2 ;
    cout << "Entrez un nombre a : " ;
    cin >> num1 ;
    cout << endl << "Etnrez un nombre b : " ;
    cin >> num2 ;
    if (num1 > num2)
    {
        cout << endl << "Le PGCD est : " << PGCD(num1, num2) << endl ; ;
    }

    else
    {
        do
        {
            cout << "Votre nombre a doit etre plus grand b" << endl << endl ;
            cout << "Entrez un nombre a : " ;
            cin >> num1 ;
            cout << endl << "Entrez un nombre b : " ;
            cin >> num2 ;
        }

        while (num1 < num2) ;
    }


} ;

#include <iostream>

using namespace std;

//Déclaration : fonction qui utilise une formule pour calculer la factorielle d'un nb donné (pour nb qui vaut 0 on à 1, informations de la doc)
//Problème : ne marche plus après 13
unsigned long long facto(int nb)
{
    unsigned long long result = 1 ; //mettre l'expression du résultat en long long pour avoir la capcité d
    if (nb==0)
    {
        return 1 ; //Pour éviter le problème du (si nb = 0, facto = 0)
    }

    else
    {
        for (int i = 1 ; i <= nb ; i++)
        {
            result = result * i ;
        }

        return result ;
    }
}



int main()
{

unsigned short int nb ;
cout << "Entrez un nombre pour avoir sa factorielle : " ;
cin >> nb ;
cout << facto(nb) << endl ;


}

#include <iostream>

using namespace std;

int triangular(int nb)
{
//    if (nb <= 1)
//    {
//        return nb - 1;
//    }
//    else
//    {
//        return (nb-1) + triangular(nb-1) ;
//    }

    //ne marche pas
    int result = 1 ;

    if (nb == 0)
    {
        return 1 ;
    }
    else
    {
        for (int i = 1 ; i <= nb ; i++)
        {
            result = result + nb ;
        }

        return result ;
    }


}

int main()
{
    int nb ;

    cout << "Entrez un nombre : " ;
    cin >> nb ;
    cout << endl << triangular(nb) << " est son nombre triangulaire" ;

}

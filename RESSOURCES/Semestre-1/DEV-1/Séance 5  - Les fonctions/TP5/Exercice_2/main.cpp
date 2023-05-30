#include <iostream>

using namespace std;

int fibo(int nb)
{
    if (nb==0)
    {
        return 0 ;
    }
    else if (nb==1)
    {
        return 1 ;
    }
    else
    {
        return fibo(nb-2) + fibo(nb-1) ;
    }
}



int main()
{
    unsigned short int nb ;
    cout << "Entrez un nombre pour avoir la somme des deux termes qui le précèdent : " ;
    cin >> nb ;
    cout << fibo(nb) << endl ;
}

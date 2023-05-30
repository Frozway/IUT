#include <iostream>

using namespace std;

void swap2 (int* p1, int* p2)
{
    int tempPoint = *p1 ;
    *p1 = *p2 ;
    *p2 = tempPoint ;
}




int main()
{

    int nb1 = 1 ;
    int nb2 = 2 ;
    cout << nb1 << nb2 << endl ;
    int *pointeur1 = &nb1 ;
    int *pointeur2 = &nb2 ;
    swap2(pointeur1, pointeur2) ;
    cout << nb1 << nb2 << endl ;

}

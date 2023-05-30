#include "pgcd.h"
#include <iostream>

using namespace std ;

int PGCD::getItsA() const
{
    return itsA;
}

void PGCD::setItsA(int newItsA)
{
    itsA = newItsA;
}

int PGCD::getItsB() const
{
    return itsB;
}

void PGCD::setItsB(int newItsB)
{
    itsB = newItsB;
}

int PGCD::getItsPGCD() const
{
    return itsPGCD;
}

PGCD::PGCD(int a, int b)
{
    if(a<0)
    {
        a = -a ;
    }

    if(b<0)
    {
        b = -b ;
    }

    if(a<b)
    {
        int temp = a ;
        a = b ;
        b = temp ;
    }

    itsA = a ;
    itsB = b ;
}

void PGCD::compute()
{
    int a = itsA ;
    int b = itsB ;
    int r ;

    while(b != 0)
    {
      r = a%b;
      a = b;
      b = r;
    }
    itsPGCD = a ;
}

void PGCD::display()
{
    cout << "PGCD(" << itsA << ", " << itsB << ") = " << itsPGCD << "\n\n" ;
}

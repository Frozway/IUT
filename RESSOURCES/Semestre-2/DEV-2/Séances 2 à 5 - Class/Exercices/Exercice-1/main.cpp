#include <iostream>
#include "pgcd.h"

using namespace std;

int main()
{
    PGCD x (30, 21);
    x.compute();
    x.display();

    x.setItsB(17);
    x.compute();
    x.display();
}

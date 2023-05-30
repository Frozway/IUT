#include <iostream>

#include "bankaccount.h"
#include "myexception.h"
using namespace std;

int main()
{
    BankAccount *Pierre = new BankAccount(123456,EUROS);

    try
    {Pierre->retreat(10);}
    catch(MyException &e){
        cout<<e.what()<<endl;
    }

    Pierre->display();
};

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "dico.h"
//#include "typeDef.h"

using namespace std;

int main()
{



//Dice d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15, d16 ;

srand(time(NULL));
//
string diceList[16] ; //créer un tableau qui se complétera quand un dé sera tiré, comp
//
//for (int iCol = 0 ; iCol < SIZE ; iCol ++)
//{
//    for (int iRow = 0 ; iRow < SIZE ; iRow ++)
//    {
//        //choisir un dès 16 dé
//        int numDice = rand()%16 + 1;
//        //vérifier que ce dé n'est pas utilisé
//        while(diceList[numDice] == "used")
//        {
//            numDice = rand()%16 + 1 ;
//        }
//        diceList[numDice] ="used" ; //une fois qu'un dès 16 dé à été choisi, le marqué comme utiliser
//        cout << numDice << endl ;
//
//
//    }
//} ;

//
for (int iRow = 0 ; iRow <= 16 ; iRow ++)
{
    //choisir un dès 16 dé
    int numDice = rand()%16;
    //vérifier que ce dé n'est pas utilisé
    while(diceList[numDice] == "used")
    {
        numDice = rand()%16  ;
    }
    diceList[numDice] ="used" ; //une fois qu'un dès 16 dé à été choisi, le marqué comme utiliser
    cout << numDice << endl ;


};



}

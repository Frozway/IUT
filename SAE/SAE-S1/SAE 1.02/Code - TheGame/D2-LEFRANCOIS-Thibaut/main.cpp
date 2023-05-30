#include <iostream>
#include "color.h"
#include "typeDef.h"
#include "tests.h"
#include "functions.h"

using namespace std;

int main()
{
    /*
    test_push() ;
    test_top() ;
    test_pop() ;
    test_insert() ;
    test_displayList();
    test_remove() ;
    test_min() ;
    test_putACard() ;
    test_shuffle() ;
    test_moveUp() ;
    test_moveDown();
    test_play() ;
    test_isValid();
    */

//******************** Boucle de jeu **************************//

    int choice ;

    clearScreen();

    cout << R"(
            //==========================================================\\

                          /-----------------------------\
                          |       TheGame - Menu        |
                          |-----------------------------|
                          |                             |
                          | [1] : Solo Mode             |
                          |                             |
                          | [2] : Multijoueur           |
                          |                             |
                          | [3] : Tests du code         |
                          |                             |
                          | [4] : Regles du jeu         |
                          |                             |
                          | [5] : Quitter le jeu        |
                          |                             |
                          \-----------------------------/

            \\==========================================================//

                            Quel est votre choix : )";

    //cout << BLUE_TEXT << "Quel est votre choix : " << COLOR_RESET ;
    while(true)
    {
        cin >> choice;
        if(cin.fail() || choice < 1 || choice > 6 )
        {
            cout << endl << RED_TEXT << "               " << "Votre choix n'est pas possible, veuillez recommencer : " << COLOR_RESET;
            cin.clear(); //Réinitialiser l'entrée si une erreur à été produite pour pouvoir de nouveau entrée une valeur
            cin.ignore(10,'\n'); //Ignore un certains nombre de caractères pour ne pas prendre en compte l'entrée comme plusieurs entrée et cela à partir la fin de ligne
        }
        else
            break;
    }
    cout << endl ;


    switch(choice)
    {
        case 1 : soloMode();
        break;

        case 2 : multiMode();
        break;

        case 3 : launchTest();
        break;

        case 4 : launchRules();

        case 5 : break ;

        break;
    }

    return 0;
}

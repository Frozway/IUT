#ifndef TYPEDEF_H
#define TYPEDEF_H
#include <iostream>

using namespace std ;

const int MAX_LENGTH = 3; // longueur maximale de toutes les valeurs de la liste

/*
 * Element of a list
 */
struct Element
{
    int value = 0;
    Element * next = nullptr;
};

/*
 * Definition of a list
 */
struct List
{
    int size = 0;
    Element * first = nullptr;
};

struct Player
{
    string name ;
    int score ;
    List *hand ;
    Player * nextPlayer = nullptr ;
    bool canPlay = true ; // : passera en false quand un des joueurs ne pourra plus jouer -> sauter son tour
};

struct ListPlayers
{
    int nbPlayers = 0;
    Player * firstPlayer = nullptr ;
};

#endif // TYPEDEF_H

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using namespace std;


class Player
{
private:
    string itsName ;
    int itsPlayTime ;
    int itsPoints ;
public:
    Player(string name);
    string getItsName() const;
    void addStatistics(int points, int playTime);
    void display();
    friend ostream& operator<<(ostream& os, const Player& player);
};

#endif // PLAYER_H

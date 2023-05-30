#ifndef TEAM_H
#define TEAM_H

#include "player.h"
#include <iostream>
#include <map>
using namespace std ;

enum Position{
    CENTER,
    POWER_FORWARD,
    SMALL_FORWARD,
    SHOOTING_GUARD,
    POINT_GUARD
};

class Team
{
private:
    string itsTeamName ;
    map<Position, Player *> *itsPlayers ;
public:
    Team(string teamName);
    ~Team();
    void addPlayer(Position position, Player *player);
    void addStatistics(string name, int points, int playTime);
    void display();
    bool save();
    string getItsTeamName() const;
};

#endif // TEAM_H

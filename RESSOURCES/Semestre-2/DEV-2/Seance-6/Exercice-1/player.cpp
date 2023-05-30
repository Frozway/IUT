#include "player.h"

Player::Player(string name)
{
    itsName = name ;
    itsPlayTime = 0 ;
    itsPoints = 0 ;
}


string Player::getItsName() const
{
    return itsName;
}

void Player::addStatistics(int points, int playTime)
{
    itsPoints += points;
    itsPlayTime += playTime;
}

void Player::display()
{
    cout << itsName << ": " << itsPoints << " / " << itsPlayTime << endl;
}

ostream& operator<<(ostream& os, const Player& player)
{
    os << player.getItsName() << " : " << player.itsPoints << " / " << player.itsPlayTime;
    return os;
}


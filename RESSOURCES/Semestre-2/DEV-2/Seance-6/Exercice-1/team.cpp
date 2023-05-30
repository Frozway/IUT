#include "team.h"
#include <fstream>

string Team::getItsTeamName() const
{
    return itsTeamName;
}

Team::Team(string teamName)
{
    itsPlayers = new map<Position, Player*>;
    itsTeamName = teamName ;
}

Team::~Team()
{
    for (auto it = itsPlayers->begin(); it != itsPlayers->end(); ++it)
    {
        delete it->second;
    }
    delete itsPlayers;
}

void Team::addPlayer(Position position, Player *player)
{
    itsPlayers->insert(make_pair(position, player));
}

void Team::addStatistics(string name, int points, int playTime)
{
    for (auto it = itsPlayers->begin(); it != itsPlayers->end(); ++it)
    {
        if (it->second->getItsName() == name)
        {
            it->second->addStatistics(points, playTime);
            break;
        }
    }
}

void Team::display()
{
    cout << itsTeamName << endl;
    for (auto it = itsPlayers->begin(); it != itsPlayers->end(); ++it)
    {
        cout << it->first << ": ";
        it->second->display();
    }
}

bool Team::save()
{
    ofstream teamFile(itsTeamName + ".team");
    if (!teamFile.is_open()) {
        return false; // Impossible d'ouvrir le fichier
    }

    for (auto it = itsPlayers->begin(); it != itsPlayers->end(); ++it) {
        Position pos = it->first;
        Player* player = it->second;

        teamFile << pos << " - " << *player << endl;
    }

    teamFile.close();
    return true;
}

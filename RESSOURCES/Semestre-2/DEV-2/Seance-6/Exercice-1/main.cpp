#include "team.h"
#include <fstream>

#include <iostream>

using namespace std;

int main()
{
    // Création des joueurs
    Player* parker = new Player("Parker");
    Player* james = new Player("James");
    Player* durant = new Player("Durant");

    // Création de l'équipe
    Team lakers("Lakers");
    lakers.addPlayer(POINT_GUARD, parker);
    lakers.addPlayer(SMALL_FORWARD, james);
    lakers.addPlayer(POWER_FORWARD, durant);
    lakers.addStatistics("Parker", 18, 9);
    lakers.addStatistics("James", 22, 12);
    lakers.addStatistics("Durant", 25, 10);

    // Enregistrement de l'équipe dans un fichier
    if (lakers.save()) {
        cout << "Equipe enregistree avec succes dans le fichier " << lakers.getItsTeamName() << ".team" << endl;
    } else {
        cout << "Erreur lors de l'enregistrement de l'equipe" << endl;
    }

    // Vérification du contenu du fichier
    ifstream teamFile(lakers.getItsTeamName() + ".team");
    if (!teamFile.is_open()) {
        cout << "Impossible d'ouvrir le fichier " << lakers.getItsTeamName() << ".team" << endl;
        return 0;
    }

}


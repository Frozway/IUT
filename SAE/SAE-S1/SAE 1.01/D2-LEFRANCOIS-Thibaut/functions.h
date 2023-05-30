#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "typeDef.h"

/*
 * \brief Initialise le tableau à vid
 * \param une grille
 * \return void
 */
void initializeGrid(Cell aGrid[][SIZE]);

/*
 * \brief Affiche les grilles des deux joueurs
 * \param aPlayer : le joueur
 * \param anOpponent l'adversaire
 * \return void
 */
void displayGrid(Player & aPlayer, Player & anOpponent);

/*
 * \brief Efface l'écran après appui sur une touche et affiche
 * << BattleShip >> stylisé avec votre nom
 * appel système de la commande console << cls >> voir
 * https://cplusplus.com/reference/cstdlib/system/
 * /!\ ne fonctionne que sous Windows
 * \return void
 */
void clearScreen();

/*
 * \brief Vérifie les valeurs saisies pour initialiser les coordonnées
 * de placement des navires de guerre
 * \param aPlace : la saisie du joeur par exemple << b10 >>
 * \param someCoordi : les coordonnées valides stockées
 * \return true si les coordonnées sont valides, false sinon
 */
bool checkCoordinate(std::string aPlace, Coordinate & someCoordi);

/*
 * \brief place un navire dans la grille en vérifiant les règles
 * \param aGrid : la grille du joueur
 * \param aPlace : les coordonnées et l'orientation du placement
 * \param aShip : le type de navire (donc sa taille)
 * \return true si le placement est valide et effectué, false sinon
 */
bool placeShip(Cell grid[][SIZE], Placement place, Ship ship);

/*
 * \brief demande au joueur de placer chaque navire, vérifie les coordonnées
 * (checkCoordinnate) et affiche les grilles (displayGrid) des joueurs à chaque
 * placement (placeShip)
 * \param aPlayer : le joueur
 * \param anOpponent : l'adversaire
 * \return void
 */
void askPlayerToPlace(Player & aPlayer, Player & anOpponent);

/* \brief indique si le coup a déjà été tiré
 * \param aGrid : la grille
 * \param someCoordi : les coordonnées du tir
 * \return true si le coup a déjà été tiré
 */
bool alreadyShot(Cell aGrid[][SIZE], Coordinate sommeCoordi);

/* \brief modifie l'état d'une case de la grille de l'adversaire
 * selon le coup joué
 * \param aGrid : la grille
 * \param someCoordi : les coordonnées du tir
 * \return true si HIT
 */
bool hitOrMiss(Cell aGrid[][SIZE], Coordinate someCoordi);

/*
 * \brief affiche les grilles (displayGrid) des joueurs puis demande au joueur
 * les coordonnées du tir en vérifiant les coordonnées (checkCoordinate) et si
 * elles n'ont pas déjà été jouées (alreadyShot) puis affiche HIT or MISS
 * (hitOrMiss)
 * \param aPlayer : le joueur
 * \param anOpponent : l'adversaire
 * \return void
 */
void askPlayerToShot(Player& aPlayer, Player& anOpponent);

/*
 * \brief place tous les navires aléatoirement en respectant les règles
 * du jeu (placeShip)
 * \param aPlayer : le joueur avec sa grille
 * \return void
 */
void randomPlacement(Player& aPlayer);

/*
 * \brief détermine si un bateau est coulé (toutes ses cases sont HIT)
 * \param aGrid : la grille
 * \param aRow : la ligne
 * \param aCol : la colonne
 */
bool isBoatSank(Cell aGrid[][SIZE], int aRow, int aCol);


//#################### MES FONCTIONS BONUS #########################//

/*
 * \brief affiche le menu HOME : permet d'accéder aux menus correspondant au style de jeu que le joueur souhaite
 */
void home();

/*
 * \brief affiche le menu 1 : modes de jeux pour 1 joueur contre 1 ordinateur
 */
void home_IA();

/*
 * \brief détermine si un bateau est coulé (toutes ses cases sont HIT)
 */
void iaRandom();

/*
 * \brief reprends les bases de askPlayerToShot mais adapté au mode contre IA EASY (rajoute le random shot plutôt que de demander des coordonnée de tir à l'ordinateur qui ne pourra répondre)
 * \param aPlayer : le joueur
 * \param anOpponent : la ligne
 */
void askPlayerToShotForRandomEasy(Player& aPlayer, Player& anOpponent);

/*
 * \brief reprends les bases de askPlayerToShot mais adapté au mode contre IA HARD (rajoute le random shot plutôt que de demander des coordonnée de tir à l'ordinateur qui ne pourra répondre)
 * \param aPlayer : le joueur
 * \param anOpponent : la ligne
 */
void askPlayerToShotForRandomHard(Player& aPlayer, Player& anOpponent);

/*
 * \brief fonction utilisé pour que l'ordinateur puisse tirer de façon aléatoire sur son ennemi (soit sur le vrai joueur de la partie)
 * \param anOpponent : l'ennemi de l'ordinateur
 */
bool randomShotEasy(Player& anOpponent);

/*
 * \brief fonction utilisé pour que l'ordinateur puisse tirer de façon aléatoire sur son ennemi et si il touche un bateau, ça le coule en entier (soit sur le vrai joueur de la partie)
 * \param anOpponent : l'ennemi de l'ordinateur
 */
bool randomShotHard(Player& anOpponent);

/*
 * \brief lance le mode de jeu contre un ordinateur facile
 */
void game_IA_EASY();

/*
 * \brief lance le mode de jeu salve
 */
void game_SALVE();

/*
 * \brief lance le mode de jeu contre un ordinateur difficile
 */
void game_IA_HARD();

/*
 * \brief définit un bateau en coulé lorsqu'on à 1 HIT
 * \param aGrid : la grille
 * \param aRow : la ligne
 * \param aCol : la colonne
 */
bool isBoatSankHard(Cell aGrid[][SIZE], int aRow, int aCol);

/*
 * \brief affiche le titre si besoin sans passer par le clearScreen()
 */
void displayTitle();

/*
 * \brief affiche le menu 2 : modes de jeux pour 2 joueurs
 */
void home_PVP();

/*
 * \brief lance le mode de jeu classique 1c1
 */
void game_CLASSIC();

/*
 * \brief reprends les bases de askPlayerToShot mais adapté au mode SALVE
 * \param aPlayer : le joueur
 * \param anOpponent : la ligne
 */
void askPlayerToShotForSalve(Player& aPlayer, Player& anOpponent);

/*
 * \brief demande au joueur veut placer ses bateaux aléatoirement
 * \param aPlayer : le joueur à qui on demande
 */
bool isRandomPlace(Player& aPlayer);

/*
 * \brief Lance tout les tests donné par le directeur logiciel
 */
void launchTest();


#endif // FUNCTIONS_H

#include <iostream>
#include "functions.h"
#include <random>
#include <stdlib.h>
#include "color.h"
#include "test.h"

using namespace std;

void initializeGrid(Cell aGrid[][SIZE])
{
    for (int row = 0; row < SIZE; row++)
    {
        for (int column = 0; column < SIZE; column++)
        {
            aGrid[row][column].ship = NONE;
            aGrid[row][column].state = UNSHOT;
        }
    }
}

void displayGrid(Player& aPlayer, Player& anOpponent)
{

    cout << endl << R"(//==========================================================\\)"<< endl ;

    //-----------------------------Centrer les noms associés aux grilles--------------------------------------------------



    //Déterminer le centre de la grille d'un joueur sans prendre en compte

    //Afficher le nom du joueur 1 centré sur sa grile
    //(pgridSIZE / 2) = centre de la grille du joueur
    //(pgridSIZE / 2) - (charp1 / 2) = pour que le nom soit à moitié affiché une fois arrivé à la moitié de la grille du joueur

    cout << endl ;

    cout << "   " ; // centrage avec titre
    for (int i = 1 ; i <= (PLAYER_GRID_SIZE / 2) - (int(aPlayer.name.length()) / 2) ; i++)
    {
        cout << " ";
    }

    cout << " " << CYAN_TEXT << aPlayer.name << COLOR_RESET ;

    for (int i = 1 ; i <= (PLAYER_GRID_SIZE / 2) - (int(aPlayer.name.length()) / 2); i++)
    {
        cout << " " ;
    }

    cout << "  " ;

    //Afficher le nom du joueur 2 centré sur sa grile
    //11 = centre de la grille du joueur 1 qui vaut 22
    //11 - (charp1 / 2) = pour mettre le centre du nom à 11

    for (int i = 1 ; i <= (PLAYER_GRID_SIZE / 2) - (int(anOpponent.name.length()) / 2) ; i++)
    {
        cout << " ";
    }

    cout << "   " ; //test centrage avec titre
    cout << " " << RED_TEXT << anOpponent.name << COLOR_RESET << endl << endl ;


    // Afficher une ligne char de A à J

    cout << "  ";

    cout << "   " ; //centrage avec titre
    for (int i = 0; i < 2; i++)
    {
        for (char letter = 'A'; letter < 'A' + (SIZE - 2); letter++)
        {
            cout << " " << RED_TEXT << letter << COLOR_RESET;
        }

        // Alligner la 2ème ligne avec la grille du joueur 2
        cout << "   " ; //centrage avec titre
        cout << "      ";
    }

    cout << endl;

    //-----------------------------Afficher la grille du joueur 1 et 2--------------------------------------------------

    for(int iRow = 1 ; iRow <= SIZE-2 ; iRow ++)
    {
        //afficher le numéro de la ligne et éviter un décallage pour les lignes à 2 chiffres
        string space = (iRow<10) ? "  " : " ";
        cout << "   " ; //centrage avec titre
        cout << RED_TEXT <<iRow << COLOR_RESET << space ;

        //Grille joueur 1
        for(int iCol = 1 ; iCol <= SIZE-2 ; iCol ++)
        {
            if ( (aPlayer.grid[iRow][iCol].ship != NONE ) && (aPlayer.grid[iRow][iCol].state == UNSHOT ) )
            {
                cout << BLUE_TEXT <<(int) aPlayer.grid[iRow][iCol].ship << COLOR_RESET ;
                cout << " " ;

            }
            else
            {
                if( (char) aPlayer.grid[iRow][iCol].state == UNSHOT)
                {
                    cout << WHITE_TEXT <<(char) aPlayer.grid[iRow][iCol].state << COLOR_RESET;
                    cout << " " ;
                }
                else if( (char) aPlayer.grid[iRow][iCol].state == HIT)
                {
                    cout << RED_TEXT <<(char) aPlayer.grid[iRow][iCol].state << COLOR_RESET;
                    cout << " " ;
                }
                else if ( (char) aPlayer.grid[iRow][iCol].state == SINK)
                {
                    cout << MAGENTA_TEXT <<(char) aPlayer.grid[iRow][iCol].state << COLOR_RESET;
                    cout << " " ;
                }
                else if ( (char) aPlayer.grid[iRow][iCol].state == MISS)
                {
                    cout << CYAN_TEXT <<(char) aPlayer.grid[iRow][iCol].state << COLOR_RESET;
                    cout << " " ;
                }


                //cout << RED_TEXT <<(char) aPlayer.grid[iRow][iCol].state << COLOR_RESET;
                //cout << " " ;
            }
        }

        cout << "   " ;

        //afficher le numéro de la ligne et éviter un décallage pour les lignes à 2 chiffres
        cout << "   " ; // centrage avec titre
        cout << RED_TEXT << iRow << COLOR_RESET << space ;


        //Grille joueur 2

        for(int iCol = 1 ; iCol <= SIZE-2 ; iCol ++)
        {

                if( (char) anOpponent.grid[iRow][iCol].state == UNSHOT)
                {
                    cout << WHITE_TEXT <<(char) anOpponent.grid[iRow][iCol].state << COLOR_RESET;
                    cout << " " ;
                }
                else if( (char) anOpponent.grid[iRow][iCol].state == HIT)
                {
                    cout << RED_TEXT <<(char) anOpponent.grid[iRow][iCol].state << COLOR_RESET;
                    cout << " " ;
                }
                else if ( (char) anOpponent.grid[iRow][iCol].state == SINK)
                {
                    cout << MAGENTA_TEXT <<(char) anOpponent.grid[iRow][iCol].state << COLOR_RESET;
                    cout << " " ;
                }
                else if ( (char) anOpponent.grid[iRow][iCol].state == MISS)
                {
                    cout << CYAN_TEXT <<(char) anOpponent.grid[iRow][iCol].state << COLOR_RESET;
                    cout << " " ;
                }

                //***********************Affichage bateau ennemi pour démo*****************************//
                /*

                if ( (anOpponent.grid[iRow][iCol].ship != NONE ) && (anOpponent.grid[iRow][iCol].state == UNSHOT ) )
                {
                    cout << BLUE_TEXT <<(int) anOpponent.grid[iRow][iCol].ship << COLOR_RESET ;
                    cout << " " ;

                }
                else if( (char) anOpponent.grid[iRow][iCol].state == UNSHOT)
                {
                    cout << WHITE_TEXT <<(char) anOpponent.grid[iRow][iCol].state << COLOR_RESET;
                    cout << " " ;
                }
                else if( (char) anOpponent.grid[iRow][iCol].state == HIT)
                {
                    cout << RED_TEXT <<(char) anOpponent.grid[iRow][iCol].state << COLOR_RESET;
                    cout << " " ;
                }
                else if ( (char) anOpponent.grid[iRow][iCol].state == SINK)
                {
                    cout << MAGENTA_TEXT <<(char) anOpponent.grid[iRow][iCol].state << COLOR_RESET;
                    cout << " " ;
                }
                else if ( (char) anOpponent.grid[iRow][iCol].state == MISS)
                {
                    cout << CYAN_TEXT <<(char) anOpponent.grid[iRow][iCol].state << COLOR_RESET;
                    cout << " " ;
                } */

        }


        //Passer à la ligne une fois la fin de la ligne actuel écrite pour le joueur 1 et 2
        cout << endl ;
    }

    cout << endl << endl << R"(\\==========================================================//)";

}

void clearScreen()
{
    //Récuperer les informations lié a l'OS de l'utilisateur pour que son clear fonctionne à l'appui d'une touche
    //Démarer VM pour montrer la compatibilité LINUX
    #ifdef _WIN32
    system("pause");
    system("cls") ;

    #elif __APPLE__
    system( "read -n 1 -s -p \"Appuyer sur une touche pour lancer le jeu\""); //Mac et Linux
    system("clear");

    #elif __linux
    system( "read -n 1 -s -p \"Appuyer sur une touche pour lancer le jeu\""); //Mac et Linux
    system("clear");

    #endif


    cout << YELLOW_TEXT << R"(
          ||=====================================||
          || BattleShip By Thibaut LEFRANCOIS D2 ||
          ||=====================================||

            )" << COLOR_RESET ;
}

bool checkCoordinate(string aPlace, Coordinate& someCoordi)
{

    if(aPlace.length() == 1)
    {
        return false;
    }

    //Vérifier que des chiffres pour la ligne on bien été rentré après la lettre (indice i = 1 pour passer après la lettre)
    //Retourner faux si en passant sur tout les éléments de la ligne après la lettre, on remarque que ce n'est pas un chiffre
    for (int i = 1 ; i < int (aPlace.length()) ; i++ )
    {

        //aPlace[i] étant transformé en char, on véréfie si il est égal au code ASCII de l'espace qui est 32 en décimal
        if (aPlace[i] == 32 )
        {
            return false;
            break ;
        }

        else if ( ( (aPlace[i] < 48) || (aPlace[i] > 57) )  ) //vérifier si le deuxième caractère de l'entrée est bienun chiffre
        {
            return false;
            break ;
        }

    }

    //Récupérer la lettre rentrée et la définir comme colonne choisis (et la transformer automatiquement en majuscule)
    char col = toupper(aPlace[0]) ;
    //Récupérer la suite de l'entrée après la lettre en utilisant la fonction substr et son paramètre 1 pour ne pas reprendre la lettre
    //Transformer le string entrée en int avec la fonction stoi et définir le résultat comme ligne choisis
    int row = stoi(aPlace.substr(1));

    //Vérifier que la colonne est compris entre A et la colonne maximum 'A' + (SIZE - 2)
    //
    if ( ( (col >= 'A') && (col < 'A' + SIZE - 2) )    &&    ( (row <= SIZE - 2) && (row > 0) ) )
    {
        someCoordi.col = col ; //int(col) - 64 ; // -64 pour avoir la valeur décimal de la lettre // A = 65 // A est la première lettre donc 65-64=1
        someCoordi.row = row ;
        return true ;
    }

    else
    {
        return false ;
    }

return false ;
}

bool placeShip(Cell grid[][SIZE], Placement place, Ship ship)
{

    //########################################################################################################################################//

    int row = place.coordi.row ;
    int col = int(place.coordi.col) - 64 ;
    int rowTemp = row ;
    int colTemp = col ; //Créer un entier temporaire pour que lors des tests autour du bateau on ne perde pas la réel valeur de la colonne rentrée

    //########################################################################################################################################//

    char direction = char(toupper(place.dir));

    //Vérifier que la direction soit bien indiqué
    if ( (direction != 'H') && (direction != 'V') )
    {
        cout << endl << RED_TEXT << "La direction sasie n'est pas valide (H ou V)" << COLOR_RESET ;
        return false ;
    }

    //########################################################################################################################################//

    //Vérifier qu'il n'y a rien autour du bateau case par case
    for (int i = 0 ; i < ship ; i++)
    {
        if (grid[rowTemp][colTemp].ship != NONE) //vérfier si aucun bateau n'est déjà placé
            return false;
        else if(grid[rowTemp-1][colTemp].ship != NONE)//vérfier si aucun bateau n'est au dessus
            return false;
        else if(grid[rowTemp+1][colTemp].ship != NONE)//vérfier si aucun bateau n'est en dessous
            return false;
        else if(grid[rowTemp-1][colTemp-1].ship != NONE)//vérfier si aucun bateau n'est dans la en haut à gauche
            return false;
        else if(grid[rowTemp][colTemp-1].ship != NONE)//vérfier si aucun bateau n'est à gauche
            return false;
        else if(grid[rowTemp+1][colTemp-1].ship != NONE)//vérfier si aucun bateau n'est en bas à gauche
            return false;
        else if(grid[rowTemp][colTemp+1].ship != NONE)//vérfier si aucun bateau n'est à droite
            return false;
        else if(grid[rowTemp-1][colTemp+1].ship != NONE)//vérfier si aucun bateau n'est en haut à droite
            return false;
        else if(grid[rowTemp+1][colTemp+1].ship != NONE)//vérfier si aucun bateau n'est en bas à droite
            return false;

        //Si le bateau est horizontal, on doit vérifier de la première colonne du bateau jusqu'à la dernière en augmentant l'indice de la colonne
        if (direction == 'H'){
            colTemp += 1 ;
            if ( (ship + col-1) > (SIZE -2) ) //Vérifier que la taille du bateau + la colonne sélectionné rentre bien dans la grille
            {
                return false ;
            }
        }

        //Si le bateau est vertical, on doit vérifier de la première ligne du bateau jusqu'à la dernière en augmentant l'indice de la ligne
        else{
            rowTemp +=1 ;
            if ( (ship + row-1) > (SIZE -2) )//row-1 car les lignes vont de 1 à 10 //Vérifier que la taille du bateau + la ligne sélectionné rentre bien dans la grille
            {
                return false ;
            }
        }
    }

    //########################################################################################################################################//

    //Définir chaque cellule que le bateau occupe selon les coordonnées et la direction
    //Vérifier qu'aucun bateau n'est déjà placé
    for (int i = 0 ; i < ship ; i++)
    {

        //Si oui, assigné le numéro du bateau aux cellules entrée en coordonnée
        if (direction == 'H')
        {
                grid[row][col].ship = ship; ;
                col += 1 ;
        }


        //Vérifier que la taille du bateau + la ligne sélectionné rentre bien dans la grille
        //Si oui, assigné le numéro du bateau aux cellules entrée en coordonnée
        if (direction == 'V')
        {
            grid[row][col].ship = ship;;
            row += 1 ;
        }
    }

    //########################################################################################################################################//

    //Si l'insertion à passé tout ces étapes c'est que sa position est conforme au règle et qu'il à été inclus à la grille du joueur
    return true ;
}

void askPlayerToPlace(Player & aPlayer, Player & anOpponent)
{
    string insertCoord ;
    Coordinate validCoord ;
    Placement placement ;

    int shipsPlaced = 0 ; //Nombre de bateau déjà placé

    //Afficher la  grille une première fois vierge
    //displayTitle();
    //cout << endl ;
    displayGrid(aPlayer, anOpponent);

    do
    {
        //cout << endl << endl << MAGENTA_TEXT << aPlayer.name << RED_TEXT << ", vous allez inserer le bateau " << MAGENTA_TEXT << ships[shipsPlaced] << RED_TEXT << (" de taille : ") << MAGENTA_TEXT << array[shipsPlaced] << COLOR_RESET; //récupéré dans le tableau string tout les noms des bateaux selon le bateau qui va être placé
        //Tant que la coordonnée n'est pas valide on ne vérifie pas si le bateau peut se placer
        do
        {
            cout << endl << endl << CYAN_TEXT << aPlayer.name << BLUE_TEXT << ", veuillez inserer une coordonnee pour le bateau " << CYAN_TEXT << ships[shipsPlaced] << BLUE_TEXT << " de taille " << CYAN_TEXT << listShips[shipsPlaced] << BLUE_TEXT << " (Exemple : B5) : " << COLOR_RESET ;
            cin >> insertCoord ;
            //getline(cin, insertCoord); devrait prendre toute la saisie du joueur mais considère le entrée de clearScreen comme une première entrée et mets donc une erreur dès debut qu'on ne veut pas
            checkCoordinate(insertCoord, validCoord);
            if (checkCoordinate(insertCoord, validCoord) == false )
            {
                cout << endl << RED_TEXT << "Votre saisie n'est pas correct, veilliez a ne pas mettre d'espace et a saisir au moins un chiffre" << COLOR_RESET ;
            }
            else
            {
                cout << endl << GREEN_TEXT << "Coordonnee valide !" << COLOR_RESET << endl ;
            }
        }
        while ( (checkCoordinate(insertCoord, validCoord)) == false );

        //Si la coordonnée est valide alors la coordonnée à placer prend la valeur de la coordonnée qui a été validé
        placement.coordi = validCoord ;

        //Enregistrer l'orientation de la coordonnée souhaité
        cout << endl << BLUE_TEXT << "Veuillez inserer le sens d'orientation du bateau (H ou V) : " << COLOR_RESET ;
        cin >> placement.dir ;


        //Si le placement du bateau est possible (true) placer le bateau dans l'ordredu tableau array avec l'indice "bateau à Placé"
        if(placeShip(aPlayer.grid, placement, listShips[shipsPlaced]) == true) //array[shipsToPlace-1]
        {
            shipsPlaced += 1 ; //Dire que 1 bateau à été placé et qu'on pourra passé au suivant si ce n'est pas le 5ème
            cout << endl ;
            cout << GREEN_TEXT << "Bateau place !" << COLOR_RESET << endl << endl ;
            clearScreen();
            displayGrid(aPlayer, anOpponent);
        }

        else
        {
            if( (placement.dir == 'H') || (placement.dir == 'V') ) //Si la direction n'est aucun des deux, un message d'erreur est déjà affiché
            {
                cout << endl << RED_TEXT << "Impossible de placer un bateau sur ces coordonnees (attention au debordement, chevauchement, ou bateau colle) " << COLOR_RESET << endl ;
            }
            else
            {
                cout << endl << RED_TEXT << "Impossible de placer un bateau sur ces coordonnees " << COLOR_RESET << endl ;

            }
        }

    }
    //Tant que le nombre de bateau à placé n'est pas à 5, continuer
    while (shipsPlaced != 5 ) ;

}

bool alreadyShot(Cell aGrid[][SIZE], Coordinate someCoordi)
{

    //Si l'état de la coordonnée n'est unshot, alors il est touché donc true, sinon faux
    if (aGrid[someCoordi.row][(someCoordi.col) - 64].state != UNSHOT)
    {
        return true;
    }
    else
    {
        return false;
    }

return false;
}

bool hitOrMiss(Cell aGrid[][SIZE], Coordinate someCoordi)
{

    //Si la cellule du joueur choisit par la coordonnée entré n'est pas sans bateau alors marqué touché sinon loupé
    if(aGrid[someCoordi.row][(someCoordi.col) - 64].ship != NONE)
    {
        aGrid[someCoordi.row][(someCoordi.col) - 64].state = HIT ;
        return true;
    }

    else
    {
        aGrid[someCoordi.row][(someCoordi.col) - 64].state = MISS ;
        return false ;
    }


return false;
}

void askPlayerToShot(Player& aPlayer, Player& anOpponent)
{
    string insertCoord ;
    Coordinate validCoord ;
    int scorePlayer1 = aPlayer.score ;
    int scorePlayer2 = anOpponent.score ;
    int scoreToReach = NBCELLS ;

    //Demander une coordonnée tant qu'elle est pas bonne
    do
    {


        cout << endl ;
        displayGrid(aPlayer, anOpponent);


        //Joueur 1
        do
        {
            cout << endl << endl << CYAN_TEXT << aPlayer.name << BLUE_TEXT << ", veuillez saisir une coordonnee pour tirer sur " << RED_TEXT << anOpponent.name << BLUE_TEXT << " (Exemple : B5) : " << COLOR_RESET ;
            cin >> insertCoord ;
            if(checkCoordinate(insertCoord, validCoord) == true )
            {
                if ( alreadyShot(anOpponent.grid, validCoord) == true)
                {
                    cout << endl << RED_TEXT << "Vous ne pouvez pas tirer 2 fois sur la même case, veuillez retirer : " << COLOR_RESET ;
                }
            }

        }
        while( (checkCoordinate(insertCoord, validCoord) == false) || (alreadyShot(anOpponent.grid, validCoord) == true) );

        //Si la case n'est pas déjà touché, et qu'il y'a un bateau qui va etre touché par les coordonnées de tir du joueur, alors augmenter le score
        if(hitOrMiss(anOpponent.grid, validCoord) == true )
        {
            isBoatSank(anOpponent.grid, validCoord.row, validCoord.col) ;
            scorePlayer1 += 1 ;
            cout << endl << GREEN_TEXT << "Touche ! Votre score : " << scorePlayer1 << endl << endl << COLOR_RESET ;
        }
        else
        {
            cout << endl << RED_TEXT << "Rater !" << COLOR_RESET << endl << endl ;
        }

        clearScreen();
        displayGrid(aPlayer, anOpponent);

        if(scorePlayer1 == scoreToReach)
        {
            cout << endl << YELLOW_TEXT << "Félicitations " << CYAN_TEXT << aPlayer.name << YELLOW_TEXT<< ", tu as gagné !" << COLOR_RESET << endl ;
            break;
        }

        cout << endl << endl << "Au tour de " << CYAN_TEXT <<anOpponent.name << COLOR_RESET << endl << endl ;
        clearScreen();
        displayGrid(anOpponent, aPlayer);

        //Joueur 2
        do
        {
            cout << endl << endl << CYAN_TEXT << aPlayer.name << BLUE_TEXT << ", veuillez saisir une coordonnee pour tirer sur " << RED_TEXT << anOpponent.name << BLUE_TEXT << " (Exemple : B5) : " << COLOR_RESET ;
            cin >> insertCoord ;
            if(checkCoordinate(insertCoord, validCoord) == true )
            {
                if ( alreadyShot(aPlayer.grid, validCoord) == true)
                {
                    cout << endl << RED_TEXT << "Vous ne pouvez pas tirer 2 fois sur la même case, veuillez retirer : " << COLOR_RESET ;
                }
            }

        }
        while( (checkCoordinate(insertCoord, validCoord) == false) || (alreadyShot(aPlayer.grid, validCoord) == true) );

        //Si la case n'est pas déjà touché, et qu'il y'a un bateau qui va etre touché par les coordonnées de tir du joueur, alors augmenter le score
        if( (alreadyShot(aPlayer.grid, validCoord) == false) && (hitOrMiss(aPlayer.grid, validCoord) == true ) )
        {
            isBoatSank(aPlayer.grid, validCoord.row, validCoord.col) ;
            scorePlayer2 += 1 ;
            cout << endl << GREEN_TEXT << "Touche ! Votre score : " << scorePlayer1 << endl << endl << COLOR_RESET ;
        }
        else
        {
            cout << endl << RED_TEXT << "Rater !" << COLOR_RESET << endl << endl ;
        }

        clearScreen();
        displayGrid(aPlayer, anOpponent);

        cout << endl << endl << "Au tour de " << CYAN_TEXT << aPlayer.name << COLOR_RESET << endl << endl ;
        clearScreen();

        if(scorePlayer2 == scoreToReach)
        {
            cout << endl << YELLOW_TEXT << "Félicitations " << CYAN_TEXT << anOpponent.name << YELLOW_TEXT << ", tu as gagné !" << COLOR_RESET << endl ;
            break;
        }

    }
    while ( (scorePlayer1 != scoreToReach) && (scorePlayer2 != scoreToReach) );

    //Quand on sort de la boucle c'est que la partie est finit donc retour au home
    clearScreen();
    home();

    //Message de fin de programme destiné au gagnant
    //cout << endl << "Félicitations " << aPlayer.name << ", tu as gagné !" << endl ;

}

void randomPlacement(Player& aPlayer)
{

    //********************************************************************************//

    srand((unsigned int)time(0));

    int randRow ; //= rand()%(SIZE-2) + 1 ; //Valeur de ligne aléatoire comprise entre 1 et la taille maximum de la grille (SIZE - 2)
    int randCol ; //= rand()%(SIZE-2) + 1 ; //Valeur de colonne aléatoire comprise entre la première lettre possible (A) et la lettre maximum de la grille (SIZE - 2)
    char randDir;
    int randNumber ; //= rand()%2 + 1 ; //Chiffre aléatoire entre 1 et 2

    //Coordinate randCoord ;
    Placement randPlace ;

     //********************************************************************************//

    int shipsPlaced = 0 ; //Nombre de bateau déjà placé

    do
    {

        //************************Random Coordinate***************************************//

        random_device r ;

        //Choisir une ligne au hasard entre 1 et et la taille de la grille jouable
        default_random_engine e1(r());
        uniform_int_distribution<int> row(1, (SIZE-2));
        randRow = row(e1) ;

        //Choisir une colonne au hasard entre la première 1 (soit A) et la taille de la grille jouable
        default_random_engine e2(r());
        uniform_int_distribution<int> col(1, (SIZE-2));
        randCol = col(e2) ;

        //Choisir une direction au hasard //Si le chiffre aléatoire tiré est 1 alors la direction sera horizontal, sinon vertical
        default_random_engine e3(r());
        uniform_int_distribution<int> dir(1, 2);
        randNumber = dir(e2) ;

        //Si le randNumber donne 1, on prendra la direction Horizontal
        if(randNumber == 1){
            randDir = 'H' ;
        }
        //Sinon on prendra la direction Vertical
        else{
            randDir = 'V';
        }

        //randCoord.row = randRow ;
        //randCoord.col = (randCol) + 64 ;

        randPlace.coordi.row = randRow ;
        randPlace.coordi.col = (randCol) + 64 ; //+ 64 pour aller sur les valeurs décimals correspondant au lettre en ASCII (Exemple : imaginons randCol nous donne 1 alors : 1 + 64 = 65 et char(65) = 'A'
        randPlace.dir = randDir ;

        //randPlace.coordi = randCoord ;


        //********************************************************************************//

        //Si le placement du bateau est possible (true) placer le bateau dans l'ordredu tableau array avec l'indice "bateau à Placé"
        if(placeShip(aPlayer.grid, randPlace, listShips[shipsPlaced]) == true)
        {
            shipsPlaced += 1 ; //Dire que 1 bateau à été placé et qu'on pourra passé au suivant si ce n'est pas le 5ème
        }

    }
    //Tant que le nombre de bateau à placé n'est pas à 5, continuer
    while (shipsPlaced != 5 ) ;

}

bool isBoatSank(Cell aGrid[][SIZE], int aRow, int aCol)
{

    //a cause de ça le test ne marche pas
    //aCol -= 64 ; //comme aCol est dans les paramètres un int alors qu'il est de base en char, on se retrouve avec la valeur décimal du caractère (Exemple : 'A' == 65 donc 65 - 64 == 1 (1ère col)

    //********************************************************************************//

    //Définir l'orientation du bateau

    char direction;

    //Si y'a un bateau à gauche ou à droite du tir, il est horizontal, sinon il est vertical
    if( (aGrid[aRow][aCol].ship == aGrid[aRow][aCol-1].ship) || (aGrid[aRow][aCol].ship == aGrid[aRow][aCol+1].ship)  )
    {
        direction = 'H' ;
    }
    else
    {
        direction = 'V' ;
    }

    //********************************************************************************//


    //sauvegrader

    //Créer des variables temporaires dont les valeurs seront modifiables pour nos tests
    int aColTemp = aCol ;
    int aRowTemp = aRow ;

    //Créer des variables de sauvegardes qui retiendront les valeurs qu'on cherche de col et de row (soit la première case du bateau)
    int aRowSave = aRow ;
    int aColSave = aCol ;

    //Créer une variable qui augmentera lors des vérifications et qui permettra de return true et de tout mettre en sink si c'est coulé
    int nbHit = 0 ;

    //cout << "direction : " << direction << endl << "row : " << aRow << endl << "col : " << aCol << endl << "Nbhit 1 : " << nbHit ;

    //Si on est horizontal la tête du bateau est forcément à gauche
    if (direction == 'H')
    {

        //Vérifier toutes les cases maximum qui peuent se trouver a gauche du bateau selon sa taille
        for(int i = 0 ; i < aGrid[aRow][aCol].ship ; i ++ )
        {
            //Si la case a gauche identique à celle ou on se trouve, c'est que nous sommes pas sur la tête du bateau, alors sauvegarder la colonne de gauche
            if(aGrid[aRow][aColSave-1].ship == aGrid[aRow][aColSave].ship)
            {
                aColSave -=1 ;
            }
        }

        //On a la tête du bateau, et on va devoir parcourir tout ce qui est à droite pour vérifier les hit, sans modifier la valeur de sauvegarde, alors on utilise la variable temporaire
        aColTemp = aColSave ;

        //On vérifie si toutes les cases sont hit à drotie de la tête du bateau et la tête du bateau elle même
        for (int i = 0 ; i < aGrid[aRow][aColSave].ship ; i++)
        {
            //Si la case est hit, augmenter nbhit et passé à la colonne d'après comme le bateau est horizontal
            if  (aGrid[aRow][aColTemp].state == HIT)
            {
                nbHit += 1 ;
                aColTemp += 1 ;
            }

        }

        //Si toutes les cases sont hit, repartir de la tête du bateau et passer en sink toutes les cases qui étaient hit
        if(nbHit == aGrid[aRow][aColSave].ship)
        {
            for (int i = 0 ; i < aGrid[aRow][aColSave].ship ; i++)
            {
                aGrid[aRow][aColSave].state = SINK ;
                aColSave +=1 ;
            }
            //return true une fois fait
            return true;
        }
        //si le nombre de hit était pas atteint pour couler le bateau, alors il n'est pas coulé
        else
        {
            return false;
        }

    }

    //Si on est horizontal la tête du bateau est forcément en haut
    if (direction == 'V')
    {

        //Vérifier toutes les cases maximum qui peuent se trouver en haut du bateau selon sa taille
        for(int i = 0 ; i < aGrid[aRow][aCol].ship ; i ++ )
        {
            //Si la case en haut identique à celle ou on se trouve, c'est que nous sommes pas sur la tête du bateau, alors sauvegarder la ligne au dessus
            if(aGrid[aRowSave-1][aCol].ship == aGrid[aRowSave][aCol].ship)
            {
                aRowSave -=1 ;
            }
        }

        //On a la tête du bateau, et on va devoir parcourir tout ce qui est en bas pour vérifier les hit, sans modifier la valeur de sauvegarde, alors on utilise la variable temporaire
        aRowTemp = aRowSave ;

        //On vérifie si toutes les cases sont hit en bas de la tête du bateau et la tête du bateau elle même
        for (int i = 0 ; i < aGrid[aRowSave][aCol].ship ; i++)
        {
            if  (aGrid[aRowTemp][aCol].state == HIT) // && (aGrid[aRow][aColSave+1].ship == aGrid[aRow][aColSave].ship) )
            {
                nbHit += 1 ;
                aRowTemp += 1 ;
            }

        }

        //Si toutes les cases sont hit, repartir de la tête du bateau et passer en sink toutes les cases qui étaient hit
        if(nbHit == aGrid[aRowSave][aCol].ship)
        {
            for (int i = 0 ; i < aGrid[aRowSave][aCol].ship ; i++)
            {
                aGrid[aRowSave][aCol].state = SINK ;
                aRowSave +=1 ;
            }
            //return true une fois fait
            return true;
        }
        //si le nombre de hit était pas atteint pour couler le bateau, alors il n'est pas coulé
        else
        {
            return false;
        }

    }


return false;
}


//#################### MES FONCTIONS BONUS #########################//


//################ HOME #####################//

void home(){

    //displayTitle();

    clearScreen();

    int choice ;

    cout << R"(
//==========================================================\\

              /-----------------------------\
              |      BattleShip - Menu      |
              |-----------------------------|
              |                             |
              | [1] : Player VS IA          |
              |                             |
              | [2] : Player1 VS Player2    |
              |                             |
              | [3] : Tests du code         |
              |                             |
              | [4] : Quitter le jeu        |
              \-----------------------------/

\\==========================================================//

)";

    cout << BLUE_TEXT << "Quel est votre choix : " << COLOR_RESET ;
    cin >> choice ;
    cout << endl ;

    if ( (choice < 1) || (choice > 4) )
    {
        do
        {
            cout << endl << RED_TEXT << "Votre choix n'est pas possible, veuillez recommencer : " << COLOR_RESET;
            cin >> choice ;
        }
        while ( (choice < 1) || (choice > 4) ) ;


    }


    switch(choice)
    {
        case 1 : home_IA();
        break;

        case 2 : home_PVP();
        break;

        case 3 : launchTest();
        break;


        case 4 : break;

        break;
    }


}

//################ HOME - PVP #####################//

void home_PVP()
{

    clearScreen();

    int choice ;

    //displayTitle();

    cout << R"(
//==========================================================\\

              /-----------------------------\
              |      BattleShip - PVP       |
              |-----------------------------|
              |                             |
              | [1] : Classic (P1 VS P2)    |
              |                             |
              | [2] : Salve PVP (3 shot)    |
              |                             |
              | [3] : Back to home          |
              |                             |
              \-----------------------------/

\\==========================================================//

)";

    cout << BLUE_TEXT << "Quel est votre choix : " << COLOR_RESET ;
    cin >> choice ;
    cout << endl ;

    if ( (choice < 1) || (choice > 3) )
    {
        do
        {
            cout << endl << RED_TEXT << "Votre choix n'est pas possible, veuillez recommencer : " << COLOR_RESET;
            cin >> choice ;
        }
        while ( (choice < 1) || (choice > 3) ) ;


    }


    switch(choice)
    {


        case 1 : game_CLASSIC();
        break;

        case 2 : game_SALVE();
        break;

        case 3 : home();
        break;


        break;
    }

}

void game_CLASSIC()
{

    clearScreen();

    Player player1, player2 ;

    cout << endl << R"(//==========================================================\\)" << endl;

    cout << endl << BLUE_TEXT << "Joueur 1, veuillez entrer votre nom : " << COLOR_RESET;
    cin >> player1.name ;
    cout << endl << BLUE_TEXT << "Joueur 2, veuillez entrer votre nom : " << COLOR_RESET;
    cin >> player2.name ;
    cout << endl ;

    player1.score = player2.score = 0 ;

    clearScreen();

    initializeGrid(player1.grid);
    initializeGrid(player2.grid);

    if(isRandomPlace(player1) == true)
    {
        randomPlacement(player1);
        clearScreen();
    }
    else
    {
        clearScreen();
        askPlayerToPlace(player1, player2) ;
        clearScreen();
    }

    if(isRandomPlace(player2) == true)
    {
        randomPlacement(player2);
        clearScreen();
    }
    else
    {
        clearScreen();
        askPlayerToPlace(player2, player1) ;
        clearScreen();
    }

    askPlayerToShot(player1, player2);

}

void game_SALVE()
{

    clearScreen();

    Player player1, player2 ;

    cout << endl << R"(//==========================================================\\)" << endl;

    cout << endl << BLUE_TEXT << "Joueur 1, veuillez entrer votre nom : " << COLOR_RESET;
    cin >> player1.name ;
    cout << endl << BLUE_TEXT << "Joueur 2, veuillez entrer votre nom : " << COLOR_RESET;
    cin >> player2.name ;
    cout << endl ;

    player1.score = player2.score = 0 ;

    clearScreen();

    initializeGrid(player1.grid);
    initializeGrid(player2.grid);

    if(isRandomPlace(player1) == true)
    {
        randomPlacement(player1);
        clearScreen();
    }
    else
    {
        clearScreen();
        askPlayerToPlace(player1, player2) ;
        clearScreen();
    }

    if(isRandomPlace(player2) == true)
    {
        randomPlacement(player2);
        clearScreen();
    }
    else
    {
        clearScreen();
        askPlayerToPlace(player2, player1) ;
        clearScreen();
    }

    askPlayerToShotForSalve(player1, player2);

}

//################ HOME - IA #####################//

void home_IA()
{

    clearScreen();

    int choice ;

    cout << R"(
//==========================================================\\

              /-----------------------------\
              |       BattleShip - IA       |
              |-----------------------------|
              |                             |
              | [1] : Easy level            |
              |                             |
              | [2] : Hardcore level        |
              |                             |
              | [3] : Back to home          |
              |                             |
              \-----------------------------/

\\==========================================================//

)";

    cout << BLUE_TEXT << "Quel est votre choix : " << COLOR_RESET ;
    cin >> choice ;
    cout << endl ;

    if ( (choice < 1) || (choice > 3) )
    {
        do
        {
            cout << endl << RED_TEXT << "Votre choix n'est pas possible, veuillez recommencer : " << COLOR_RESET;
            cin >> choice ;
        }
        while ( (choice < 1) || (choice > 3) ) ;


    }

    switch(choice)
    {


        case 1 : game_IA_EASY();
        break;

        case 2 : game_IA_HARD();
        break;

        case 3 : home();
        break;


        break;
    }

}

void game_IA_EASY()
{

clearScreen();

Player player1, iaRandom ;

cout << endl << R"(//==========================================================\\)" << endl;


cout << endl << BLUE_TEXT << "Veuillez entrer votre nom : " << COLOR_RESET ; //"Joueur 1, veuillez entrer votre nom : ";
cin >> player1.name ;

iaRandom.name = "Ordinateur" ;

player1.score = iaRandom.score = 0 ;

cout << endl ;
clearScreen();

initializeGrid(player1.grid);
initializeGrid(iaRandom.grid);

if(isRandomPlace(player1) == true)
{
    randomPlacement(player1);
    clearScreen();
}
else
{
    clearScreen();
    askPlayerToPlace(player1, iaRandom) ;
    cout << endl << endl ;
    clearScreen();
}

randomPlacement(iaRandom);

askPlayerToShotForRandomEasy(player1, iaRandom);

};

void game_IA_HARD()
{

    clearScreen();

    Player player1, iaRandom ;

    cout << endl << R"(//==========================================================\\)" << endl;


    cout << endl << BLUE_TEXT << "Veuillez entrer votre nom : " << COLOR_RESET ; //"Joueur 1, veuillez entrer votre nom : ";
    cin >> player1.name ;

    iaRandom.name = "Ordinateur" ;

    player1.score = iaRandom.score = 0 ;

    cout << endl ;
    clearScreen();

    initializeGrid(player1.grid);
    initializeGrid(iaRandom.grid);

    if(isRandomPlace(player1) == true)
    {
        randomPlacement(player1);
        clearScreen();
    }
    else
    {
        clearScreen();
        askPlayerToPlace(player1, iaRandom) ;
        cout << endl << endl ;
        clearScreen();
    }

    randomPlacement(iaRandom);

    askPlayerToShotForRandomHard(player1, iaRandom);


}

//################ FONCTIONS - IA EASY #####################//

bool randomShotEasy(Player& anOpponent)
{
    //********************************************************************************//

    //Générer une ligne et une colonne aléatoire pour définir une coordonnée à tirer (regénérer tant que la coordonée trouvé n'a pas déjà été tiré)

    Coordinate randCoord ;

    do
    {
        random_device r ;

        default_random_engine e1(r());
        uniform_int_distribution<int> row(1, (SIZE-2)); //Générer un nombre réprésentant la ligne du tir entre 1 et SIZE-2 soit la ligne maximum
        int randRow = row(e1) ;

        default_random_engine e2(r());
        uniform_int_distribution<int> col(65, (65 + (SIZE-3))); //Générer une valeur décimal réprésentant la colonne du tir en char ASCII entre 65 et SIZE-3 (-3 car sinon on tombe sur K) soit la ligne maximum (65 = 'A' et 65+(SIZE-2) = Colonne max)
        char randCol = col(e2) ; //associé la valeur décimal générer à la variable char randCol qui représentera la colonne aléatoire en ASCII (en char pour réaliser les tests tel que alreadyShot et hitOrMiss qui attende la colonne en char)

        randCoord.row = randRow ;
        randCoord.col = randCol ;

        alreadyShot(anOpponent.grid, randCoord);
    }
    while (alreadyShot(anOpponent.grid, randCoord) == true);


     //********************************************************************************//

        //Réaliser les mêmes tests qu'un tir normal pour savoir si l'ordinateur à touché le bateau ou non

        //Si la case n'est pas déjà touché, et qu'il y'a un bateau qui va etre touché par les coordonnées de tir du joueur, alors augmenter le score
        if(hitOrMiss(anOpponent.grid, randCoord) == true )
        {
            isBoatSank(anOpponent.grid, randCoord.row, randCoord.col) ;
            cout << endl << RED_TEXT << "L'ordinateur " << BLUE_TEXT << "vous a touche en " << RED_TEXT << char(randCoord.col) << randCoord.row << COLOR_RESET ; //afficher la lettre de la coordonnée et non son chiffre
            return true; //true pour dire dans askplayertoshotrandom si il a été touché, ce qui permettra de faire progresser aussi son score
        }
        else
        {
            cout << endl << RED_TEXT << "L'ordinateur " << BLUE_TEXT << "a tire en " << RED_TEXT << randCoord.col << randCoord.row << BLUE_TEXT << " mais n'a pas touche de bateau !" << COLOR_RESET ;
            return false ; //false pour dire que le tir aléatoire n'a rien touché
        }

return false ;

}

void askPlayerToShotForRandomEasy(Player& aPlayer, Player& anOpponent)
{
    string insertCoord ;
    Coordinate validCoord ;

    int scorePlayer = aPlayer.score ;
    int scoreIA = anOpponent.score ;
    int scoreToReach = 17 ;

    displayGrid(aPlayer, anOpponent);


    //Générer un nombre aléatoire qui déterminera qui tirera en premier

    random_device rd ;

    default_random_engine e5(rd());
    uniform_int_distribution<int> rdstart(0, 1);
    int startplayer = rdstart(e5) ;

    Player firstPlayer, secondPlayer ;

    if(startplayer == 0)
    {
        firstPlayer = aPlayer ;
        secondPlayer = anOpponent ;
    }
    else
    {
        firstPlayer = anOpponent ;
        secondPlayer = aPlayer ;
    }

    if (firstPlayer.name == aPlayer.name)
    {
        cout << endl << endl << CYAN_TEXT << aPlayer.name << BLUE_TEXT << " commence a tirer !" << COLOR_RESET << endl << endl ;
    }
    else
    {
        cout << endl << endl << RED_TEXT << "L'ordinateur " << BLUE_TEXT << "tir en premier !" << COLOR_RESET << endl ;
        if (randomShotEasy(aPlayer) == true)
        {
            scoreIA +=1;
        }
        cout << endl << endl ;
    }

    clearScreen(); //Effacer les
    displayGrid(aPlayer, anOpponent);




    //Demander une coordonnée tant qu'elle est pas bonne
    do
    {
        do
        {
            cout << endl << endl << CYAN_TEXT << aPlayer.name << BLUE_TEXT << ", veuillez saisir une coordonnee pour tirer sur " << RED_TEXT << "l'ordinateur" << BLUE_TEXT << " (Exemple : B5) : " << COLOR_RESET ;
            cin >> insertCoord ;
            if(checkCoordinate(insertCoord, validCoord) == true )
            {
                //Vérifier si la coordonnée saisit n'est pas une coordonnée déjà tiré
                if ( alreadyShot(anOpponent.grid, validCoord) == true)
                {
                    cout << endl << RED_TEXT << "Vous ne pouvez pas tirer 2 fois sur la même case, veuillez retirer : " << COLOR_RESET ;
                }
            }

        }
        while( (checkCoordinate(insertCoord, validCoord) == false) || (alreadyShot(anOpponent.grid, validCoord) == true) ); //Recomencer le tir tant que la coordonée est fausse ou que la coordonnée à déjà été tiré

        //Si la case n'est est touché (true), alors on vérifie si le bateau touché n'est pas coulé et on augmente le score avant d'afficher le tir sur la grille actualisé
        if(hitOrMiss(anOpponent.grid, validCoord) == true )
        {
            isBoatSank(anOpponent.grid, validCoord.row, validCoord.col) ;
            scorePlayer += 1 ;
            cout << endl << GREEN_TEXT << "Touche ! Votre score : " << scorePlayer << endl << endl << COLOR_RESET ;
        }
        //Sinon afficher la grille sans augmenter le score car le tir n'a pas touché de bateau
        else
        {
            cout << endl << RED_TEXT << "Rater !" << COLOR_RESET << endl << endl ;
        }
        //Vérifier si le tir a permis au joueur de gagner la partie en atteignant le score requis (si oui alors arréter le jeu)
        if(scorePlayer == scoreToReach)
        {
            clearScreen();
            cout << YELLOW_TEXT << "Felicitations " << CYAN_TEXT << aPlayer.name << YELLOW_TEXT<< ", tu as gagne !" << COLOR_RESET << endl << endl ;
            break ;
        }

        clearScreen();
        displayGrid(aPlayer, anOpponent);
        cout << endl ;

        //Tir aléatoire sur aPlayer et vérifier si l'ordinateur à touché un bateau
        if (randomShotEasy(aPlayer) == true)
        {
            scoreIA +=1;
        }

        //Vérifier si le tir a permis à l'ordinateur de gagner la partie en atteignant le score requis (si oui alors arréter le jeu)
        if(scoreIA == scoreToReach)
        {
            clearScreen();
            displayGrid(aPlayer, anOpponent); //afficher la grille de fin si l'ordinateur à gagné
            cout << YELLOW_TEXT << "L'ordinateur a gagne la partie, retente ta chance !" << COLOR_RESET << endl << endl ;
            break ;
        }

        //Espacé pour éclaircir l'affichage (grille et texte bien espacé) avant d'actualiser la grille après le tir de l'ordinateur
        cout << endl << endl ;
        clearScreen();
        displayGrid(aPlayer, anOpponent);

    }
    while ( (scorePlayer != scoreToReach) || (anOpponent.score != scoreToReach) );

}

//################ FONCTIONS - IA HARD #####################//

bool randomShotHard(Player& anOpponent)
{

    //********************************************************************************//

    //Générer une ligne et une colonne aléatoire pour définir une coordonnée à tirer (regénérer tant que la coordonée trouvé n'a pas déjà été tiré)

    Coordinate randCoord ;

    do
    {
        random_device r ;

        default_random_engine e1(r());
        uniform_int_distribution<int> row(1, (SIZE-2)); //Générer un nombre réprésentant la ligne du tir entre 1 et SIZE-2 soit la ligne maximum
        int randRow = row(e1) ;

        default_random_engine e2(r());
        uniform_int_distribution<int> col(65, (65 + (SIZE-3))); //Générer une valeur décimal réprésentant la colonne du tir en char ASCII entre 65 et SIZE-3 (-3 sinon on peut tomber sur K) soit la ligne maximum (65 = 'A' et 65+(SIZE-2) = Colonne max)
        char randCol = col(e2) ; //associé la valeur décimal générer à la variable char randCol qui représentera la colonne aléatoire en ASCII (en char pour réaliser les tests tel que alreadyShot et hitOrMiss qui attende la colonne en char)

        randCoord.row = randRow ;
        randCoord.col = randCol ;

        alreadyShot(anOpponent.grid, randCoord);
    }
    while (alreadyShot(anOpponent.grid, randCoord) == true);


     //********************************************************************************//

        //Réaliser les mêmes tests qu'un tir normal pour savoir si l'ordinateur à touché le bateau ou non

        //Si la case n'est pas déjà touché, et qu'il y'a un bateau qui va etre touché par les coordonnées de tir du joueur, alors augmenter le score
        if(hitOrMiss(anOpponent.grid, randCoord) == true )
        {
            isBoatSankHard(anOpponent.grid, randCoord.row, randCoord.col) ;
            cout << endl << RED_TEXT << "L'ordinateur " << BLUE_TEXT << "vous a touche en " << RED_TEXT << char(randCoord.col) << randCoord.row << COLOR_RESET ; //afficher la lettre de la coordonnée et non son chiffre
            return true; //true pour dire dans askplayertoshotrandom si il a été touché, ce qui permettra de faire progresser aussi son score
        }
        else
        {
            cout << endl << RED_TEXT << "L'ordinateur " << BLUE_TEXT << "a tire en " << RED_TEXT << randCoord.col << randCoord.row << BLUE_TEXT << " mais n'a pas touche de bateau !" << COLOR_RESET ;
            return false ; //false pour dire que le tir aléatoire n'a rien touché
        }

return false ;


}

void askPlayerToShotForRandomHard(Player& aPlayer, Player& anOpponent)
{
    string insertCoord ;
    Coordinate validCoord ;

    int scorePlayer = aPlayer.score ;
    int scoreIA = anOpponent.score ;
    int scoreToReachForPlayer = 17 ;
    int scoreToReachForIa = 5 ; //Nombre de bateau à coulé

    displayGrid(aPlayer, anOpponent);

    //Générer un nombre aléatoire qui déterminera qui tirera en premier

    random_device rd ;

    default_random_engine e5(rd());
    uniform_int_distribution<int> rdstart(0, 1);
    int startplayer = rdstart(e5) ;

    Player firstPlayer, secondPlayer ;

    if(startplayer == 0)
    {
        firstPlayer = aPlayer ;
        secondPlayer = anOpponent ;
    }
    else
    {
        firstPlayer = anOpponent ;
        secondPlayer = aPlayer ;
    }

    if (firstPlayer.name == aPlayer.name)
    {
        cout << endl << endl << CYAN_TEXT << aPlayer.name << BLUE_TEXT << " commence a tirer !" << COLOR_RESET << endl << endl ;
    }
    else
    {
        cout << endl << endl << RED_TEXT << "L'ordinateur " << BLUE_TEXT << "tir en premier !" << COLOR_RESET << endl ;
        if (randomShotHard(aPlayer) == true)
        {
            scoreIA +=1;
        }
        cout << endl << endl ;
    }

    clearScreen(); //Effacer les
    displayGrid(aPlayer, anOpponent);

    //Demander une coordonnée tant qu'elle est pas bonne
    do
    {
        do
        {
            cout << endl << endl << CYAN_TEXT << aPlayer.name << BLUE_TEXT << ", veuillez saisir une coordonnee pour tirer sur " << RED_TEXT << "l'ordinateur" << BLUE_TEXT << " (Exemple : B5) : " << COLOR_RESET ;
            cin >> insertCoord ;
            if(checkCoordinate(insertCoord, validCoord) == true )
            {
                //Vérifier si la coordonnée saisit n'est pas une coordonnée déjà tiré
                if ( alreadyShot(anOpponent.grid, validCoord) == true)
                {
                    cout << endl << RED_TEXT << "Vous ne pouvez pas tirer 2 fois sur la même case, veuillez retirer : " << COLOR_RESET ;
                }
            }

        }
        while( (checkCoordinate(insertCoord, validCoord) == false) || (alreadyShot(anOpponent.grid, validCoord) == true) ); //Recomencer le tir tant que la coordonée est fausse ou que la coordonnée à déjà été tiré

        //Si la case n'est est touché (true), alors on vérifie si le bateau touché n'est pas coulé et on augmente le score avant d'afficher le tir sur la grille actualisé
        if(hitOrMiss(anOpponent.grid, validCoord) == true )
        {
            isBoatSank(anOpponent.grid, validCoord.row, validCoord.col) ;
            scorePlayer += 1 ;
            cout << endl << GREEN_TEXT << "Touche ! Votre score : " << scorePlayer << endl << endl << COLOR_RESET ;
        }
        //Sinon afficher la grille sans augmenter le score car le tir n'a pas touché de bateau
        else
        {
            cout << endl << RED_TEXT << "Rater !" << COLOR_RESET << endl << endl ;
        }
        //Vérifier si le tir a permis au joueur de gagner la partie en atteignant le score requis (si oui alors arréter le jeu)
        if(scorePlayer == scoreToReachForPlayer)
        {
            clearScreen();
            cout << YELLOW_TEXT << "Felicitations " << CYAN_TEXT << aPlayer.name << YELLOW_TEXT<< ", tu as gagne !" << COLOR_RESET << endl << endl ;
            break ;
        }

        clearScreen();
        displayGrid(aPlayer, anOpponent);
        cout << endl ;

        //Tir aléatoire sur aPlayer et vérifier si l'ordinateur à touché un bateau
        if (randomShotHard(aPlayer) == true)
        {
            scoreIA +=1;
        }

        //Vérifier si le tir a permis à l'ordinateur de gagner la partie en atteignant le score requis (si oui alors arréter le jeu)
        if(scoreIA == scoreToReachForIa)
        {
            clearScreen();
            displayGrid(aPlayer, anOpponent); //afficher la grille de fin si l'ordinateur à gagné
            cout << YELLOW_TEXT << "L'ordinateur  gagne la partie, retente ta chance !" << COLOR_RESET << endl << endl ;
            break ;
        }

        //Espacé pour éclaircir l'affichage (grille et texte bien espacé) avant d'actualiser la grille après le tir de l'ordinateur
        cout << endl << endl ;
        clearScreen();
        displayGrid(aPlayer, anOpponent);

    }
    while ( (scorePlayer != scoreToReachForPlayer) || (anOpponent.score != scoreToReachForIa) );

}

bool isBoatSankHard(Cell aGrid[][SIZE], int aRow, int aCol)
{

    //a cause de ça le test ne marche pas
    aCol -= 64 ; //comme aCol est dans les paramètres un int alors qu'il est de base en char, on se retrouve avec la valeur décimal du caractère (Exemple : 'A' == 65 donc 65 - 64 == 1 (1ère col)

    //********************************************************************************//

    //Définir l'orientation du bateau

    char direction;

    //Si y'a un bateau à gauche ou à droite du tir, il est horizontal, sinon il est vertical
    if( (aGrid[aRow][aCol].ship == aGrid[aRow][aCol-1].ship) || (aGrid[aRow][aCol].ship == aGrid[aRow][aCol+1].ship)  )
    {
        direction = 'H' ;
    }
    else
    {
        direction = 'V' ;
    }

    //********************************************************************************//


    //sauvegrader


    int aRowSave = aRow ;
    int aColSave = aCol ;


    if (direction == 'H')
    {

        for(int i = 0 ; i < aGrid[aRow][aCol].ship ; i ++ )
        {
            if(aGrid[aRow][aColSave-1].ship == aGrid[aRow][aColSave].ship)
            {
                aColSave -=1 ;
            }
        }


        for (int i = 0 ; i < aGrid[aRow][aColSave].ship ; i++)
        {
            aGrid[aRow][aColSave].state = SINK ;
            aColSave +=1 ;
        }
        return true;

    }

    if (direction == 'V')
    {

        for(int i = 0 ; i < aGrid[aRow][aCol].ship ; i ++ )
        {
            if(aGrid[aRowSave-1][aCol].ship == aGrid[aRowSave][aCol].ship)
            {
                aRowSave -=1 ;
            }
        }

        for (int i = 0 ; i < aGrid[aRowSave][aCol].ship ; i++)
        {
            aGrid[aRowSave][aCol].state = SINK ;
            aRowSave +=1 ;
        }
        return true;
    }


return false;
}

//################ FONCTIONS - BONUS PLAYER #####################//

void askPlayerToShotForSalve(Player& aPlayer, Player& anOpponent)
{
    string insertCoord ;
    Coordinate validCoord ;
    int scorePlayer1 = aPlayer.score ;
    int scorePlayer2 = anOpponent.score ;
    int scoreToReach = NBCELLS ;

    //Afficher une première fois la grille vierge (sans tir)
    //displayGrid(aPlayer, anOpponent);

    //Demander une coordonnée tant qu'elle est pas bonne
    do
    {


        //displayTitle();
        cout << endl ;
        displayGrid(aPlayer, anOpponent);

        for(int i = 0 ; i < 3 ; i++)
        {
            //Joueur 1
            do
            {
                cout << endl << endl << CYAN_TEXT << aPlayer.name << BLUE_TEXT << ", veuillez saisir une coordonnee pour tirer sur " << RED_TEXT << anOpponent.name << BLUE_TEXT << " (Exemple : B5) : " << COLOR_RESET ;
                cin >> insertCoord ;
                if(checkCoordinate(insertCoord, validCoord) == true )
                {
                    if ( alreadyShot(anOpponent.grid, validCoord) == true)
                    {
                        cout << endl << RED_TEXT << "Vous ne pouvez pas tirer 2 fois sur la même case, veuillez retirer : " << COLOR_RESET ;
                    }
                }

            }
            while( (checkCoordinate(insertCoord, validCoord) == false) || (alreadyShot(anOpponent.grid, validCoord) == true) );

            //Si la case n'est pas déjà touché, et qu'il y'a un bateau qui va etre touché par les coordonnées de tir du joueur, alors augmenter le score
            if(hitOrMiss(anOpponent.grid, validCoord) == true )
            {
                isBoatSank(anOpponent.grid, validCoord.row, validCoord.col) ;
                scorePlayer1 += 1 ;
                cout << endl << GREEN_TEXT << "Touche !" << COLOR_RESET ;
            }
            else
            {
                cout << endl << RED_TEXT << "Rater !" << COLOR_RESET ;
            }

            if(scorePlayer1 == scoreToReach)
            {
                cout << endl << YELLOW_TEXT << "Félicitations " << CYAN_TEXT << aPlayer.name << YELLOW_TEXT<< ", tu as gagné !" << COLOR_RESET << endl ;
                break;
            }
        }


        cout << endl << endl << GREEN_TEXT << "Votre score : " << scorePlayer1 << endl << endl << COLOR_RESET ;
        clearScreen();
        displayGrid(aPlayer, anOpponent);



        cout << endl << endl << "Au tour de " << CYAN_TEXT <<anOpponent.name << COLOR_RESET << endl << endl ;
        clearScreen();
        displayGrid(anOpponent, aPlayer);


        for(int i = 0 ; i < 3 ; i++)
        {
            //Joueur 2
            do
            {
                cout << endl << endl << CYAN_TEXT << anOpponent.name << BLUE_TEXT << ", veuillez saisir une coordonnee pour tirer sur " << RED_TEXT << aPlayer.name << BLUE_TEXT << " (Exemple : B5) : " << COLOR_RESET ;
                cin >> insertCoord ;
                if(checkCoordinate(insertCoord, validCoord) == true )
                {
                    if ( alreadyShot(aPlayer.grid, validCoord) == true)
                    {
                        cout << endl << RED_TEXT << "Vous ne pouvez pas tirer 2 fois sur la même case, veuillez retirer : " << COLOR_RESET ;
                    }
                }

            }
            while( (checkCoordinate(insertCoord, validCoord) == false) || (alreadyShot(aPlayer.grid, validCoord) == true) );

            //Si la case n'est pas déjà touché, et qu'il y'a un bateau qui va etre touché par les coordonnées de tir du joueur, alors augmenter le score
            if( (alreadyShot(aPlayer.grid, validCoord) == false) && (hitOrMiss(aPlayer.grid, validCoord) == true ) )
            {
                isBoatSank(aPlayer.grid, validCoord.row, validCoord.col) ;
                scorePlayer2 += 1 ;
                cout << endl << GREEN_TEXT << "Touche !" << COLOR_RESET ;
            }
            else
            {
                cout << endl << RED_TEXT << "Rater !" << COLOR_RESET ;
            }
            if(scorePlayer2 == scoreToReach)
            {
                cout << endl << YELLOW_TEXT << "Félicitations " << CYAN_TEXT << anOpponent.name << YELLOW_TEXT << ", tu as gagné !" << COLOR_RESET << endl ;
                break;
            }

        }

        cout << endl << endl << GREEN_TEXT << "Votre score : " << scorePlayer2 << endl << endl << COLOR_RESET ;
        clearScreen();
        displayGrid(aPlayer, anOpponent);

        cout << endl << endl << "Au tour de " << CYAN_TEXT << aPlayer.name << COLOR_RESET << endl << endl ;
        clearScreen();



    }
    while ( (scorePlayer1 != scoreToReach) && (scorePlayer2 != scoreToReach) );

    //Quand on sort de la boucle c'est que la partie est finit donc retour au home
    clearScreen();
    home();

    //Message de fin de programme destiné au gagnant
    //cout << endl << "Félicitations " << aPlayer.name << ", tu as gagné !" << endl ;

}

bool isRandomPlace(Player& aPlayer)
{
    int answer;

    do
    {
        cout << endl << R"(//==========================================================\\)" << endl;

        cout << endl << CYAN_TEXT << aPlayer.name << BLUE_TEXT << ", comment voulez vous placer vos bateaux : " ;
        cout << endl << endl << "[1] : De facon aleatoire       [2] : De facon classique " << COLOR_RESET;
        cout << endl << endl<< "Votre choix : " ;
        cin >> answer ;
        cout << endl ;
        if( (answer != 1) && (answer != 2) )
        {
            cout << endl << "Veuillez entrer soit 1 soit 2 ";
        }

    }while ( (answer != 1) && (answer != 2) ) ;

    if(answer == 1)
    {
        return true ;
    }
    else
    {
        return false ;
    }

}

void launchTest()
{
    clearScreen();
    cout << endl ;

    //-----------TESTS------------//
       test_structureDonnees() ;  // OK
       test_initializeGrid() ;    // OK
       test_checkCoordinate();    // OK
       test_placeShip();          // OK
       test_aleadyShot();         // OK
       test_hitOrMiss();          // Ok
       test_isBoatSank();         // Ok
    //----------------------------//

}

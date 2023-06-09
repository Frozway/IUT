#ifndef TYPEDEF_H
#define TYPEDEF_H

#include <string>

using namespace std;

//la dimension de la grille de jeu 10+2 pour détection du navire voisin
const int SIZE = 12 ;

//Grille d'un joueur = SIZE / Grille d'un joueur avec tout les espaces = SIZE * 2
const int TOTAL_SIZE = (SIZE * 4) -2;

//Déterminer le centre de la grille d'un joueur sans prendre en compte les espaces
const int PLAYER_GRID_SIZE = (TOTAL_SIZE / 2) ;

//const int SPACES_BEFORE_GRID = 3;

//const int SPACES_BETWEEN_GRIDS = 4;

// le nombre de navires de guerre
const int NBSHIPS = 5;

// le nombre de cases occupées par les navires d'un joueur (score)
const int NBCELLS = 17;

// les navires de guerre disponibles et leur taille sur la grille
enum Ship
{
    CARRIER=5,
    CRUISER=4,
    DESTROYER=3,
    SUBMARINE=3,
    TORPEDO=2,
    NONE=0
}; //numéro = nb cases

const Ship listShips[NBSHIPS] = {CARRIER, CRUISER, DESTROYER, SUBMARINE, TORPEDO};

// les noms des navires de guerre
const string ships[NBSHIPS] = {"carrier", "cruiser", "destroyer", "submarine", "torpedo"};

// les différents états que peut prendre une case de la grille et leur affichage
enum State
{
    HIT='x',
    SINK='#',
    MISS='o',
    UNSHOT='~'
};

// une case de la grille
// le navire présent sur la case
// l’état de la case
struct Cell
{
    Ship ship;
    State state;
};

// le joueur avec
// son nom
// son score pour déterminer qui a perdu
// sa grille de jeu
struct Player
{
    std::string name;
    int score;
    Cell grid[SIZE][SIZE];
};

// les coordonnées de la case sur la grille
// sa ligne de 1 à 10
// sa colonne de ‘A’ à ‘J’ (lettre en MAJ)
struct Coordinate
{
  char col;
  int row;
};

// le placement du navire sur la grille
// sa coordonnée (E5)
// sa direction ‘H’ horizontal ou ‘V’ vertical depuis la coordonnée
struct Placement
{
    Coordinate coordi;
    char dir;
};

#endif // TYPEDEF_H

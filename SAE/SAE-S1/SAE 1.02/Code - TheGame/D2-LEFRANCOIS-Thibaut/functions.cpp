#include <iostream>
#include <algorithm>
#include <random>
#include <iomanip>
#include "functions.h"
#include "color.h"
#include "tests.h"

using namespace std;


/*
 * Utility functions for data structure (based on STL API)
 */

/*
 * Inserts a new element at the top of a list (stack), above its current top
 * element.
 * param: a list
 * param: an element
 */
void push(List* aList, Element* anElement)
{
    anElement->next = aList->first ; //On fait pointer l'élément suivant de notre élément sur le premier de la liste
    aList->first=anElement; //On définit le premier élément de la liste sur l'élément qu'on rajoute
    aList->size++; //On augmente la taille de la liste car un élément vient d'être ajouté
}

/*
 * Returns a reference to the top element in a list (stack)
 * param: a list
 * return: the fist element or 0
 */
int top(const List * aList)
{
    //Si la première adresse de la liste est nulle, la première valeur est alors nulle
    if (aList->first == nullptr)
    {
        return 0 ;
    }
    //Sinon retourner le premier élément de la liste
    else
    {
        return aList->first->value ;
    }
}

/*
 * removeOptis the element on top of a list (stack), effectively reducing its size
 * by one.
 * param: a list
 */
void pop(List * aList)
{
    //Element temporaire qui stockera l'adresse à supprimer
    Element * del = nullptr ;
    //Faire les démarches que si la liste n'est pas vide et existe
    if(aList->size != 0 and aList->first != nullptr)
    {
        del = aList->first ; //stocker l'adresse à supprimer
        aList->first = aList->first->next ; //assigner la première adresse de la liste au deuxième élement
        delete del ; //Supprimer l'ancienne première adresse
        aList->size-- ; //Réduire la taille de la liste
    }
}

/*
 * A given list is extended by inserting a new element before the element with
 * an equal or greater value. This effectively increases the list size by one.
 * param: a list
 * parma: an element
 */
void insert(List * aList, Element * anElement)
{
    //Vérifier si le premier élément de la liste n'est pas nullptr (soit que la liste est vide) ou si il est déjà plus grand ou égal que l'élément veut ajouter
    //Ajoute l'élément selon les propriétés
    if(aList->first == nullptr || aList->first->value >= anElement->value)
    {
        anElement->next = aList->first ;
        aList->first = anElement ;
    }

    else
    {
        bool isPlaced = false ; //Booléen qui passera true si la carte est placé pour éviter des vérifications inutiles
        //Boucle qui parcourt la liste tant que rien n'est placé en vérifiant les propriétés : l'élément avec une valeur égale ou supérieure
        for(Element * current = aList->first ; isPlaced != true ; current = current->next)
        {
            //Si on est au bout de la liste, ajouté en dernier l'élément
            //Ajoute l'élément selon les propriétés
            if(current->next == nullptr)
            {
                anElement->next = current->next ;
                current->next = anElement ;
                isPlaced = true ;
            }

            //Sinon vérifié simplement si la valeur suivante de notre pointeur actuel est plus grande que la valeur qu'on veut insérer
            //Ajoute l'élément selon les propriétés
            else if(anElement->value <= current->next->value)
            {
                anElement->next = current->next ;
                current->next = anElement ;
                isPlaced = true ;
            }
        }
    }
    //Augmente quoi qu'il en soit la taille de la liste après une insertion
    aList->size++ ;
}

/*
 * Display alist and its size
 * param: a list
 */
void displayList(const List * aList)
{
    //Espacement pour alligner le début de la main sur le plateau de jeu
    cout << endl << "            ||       " ;
    for(Element * current = aList->first ; current != nullptr ; current = current->next)
    {
        //setfill(' ') permet de définir un espace comme caractère de remplissage pour les espaces vides
        //setw(2) permet de définir 2 espaces de remplissage pour chaque valeur de la liste, ce qui permet d'aligner les valeurs
        //cout << RED_TEXT << " | " << setfill(' ') << setw(2) << current->value << COLOR_RESET ;

        //Si on essaye d'afficher le premier élément ne pas mettre la barre de séparations
        if (current == aList->first)
        {
            //setfill(' ') permet de définir un espace comme caractère de remplissage pour les espaces vides
            //setw(2) permet de définir 2 espaces de remplissage pour chaque valeur de la liste, ce qui permet d'aligner les valeurs
            cout << RED_TEXT << setfill(' ') << setw(2) << current->value <<COLOR_RESET ;
        }
        else
        {
            //setfill(' ') permet de définir un espace comme caractère de remplissage pour les espaces vides
            //setw(2) permet de définir 2 espaces de remplissage pour chaque valeur de la liste, ce qui permet d'aligner les valeurs
            cout << RED_TEXT << " | " << setfill(' ') << setw(2) << current->value << COLOR_RESET ;
        }

    }
    //Espacement à la fin de la main du jeu + ligne vide + ligne affichannt le nombre d'élements dans une main
    cout << "       ||" ;
    cout << endl << "            ||                                                   ||" << endl; //Ligne de séparation avec le nombre de cartes
    cout << "            ||             (Nombre de cartes : " << aList->size << ")" "                ||" ;
}

/*
 * Delete a list. Free the memory occupied by each element
 */
void deleteList(List * aList)
{
    //Création d'élements permettant la suppression d'une liste élément par élément
    Element * eltToBeDeleted;
    Element * elt = aList->first;
    //Si la liste à plus d'un élement alors supprimer élément par élément de gauche à droite de la liste tant qu'il y en a
    if (elt->next != nullptr)
    {
        while (elt->next != nullptr)
        {
            eltToBeDeleted = elt;
            elt = elt->next;
            delete eltToBeDeleted;
        }
    }
    //Sinon supprimer juste le premier élement quelque soit sa valeur
    else
    {
        delete elt;
    }

    //S'assurer que chaque mémoire occupé soit bien supprimé
    aList = nullptr ;
    //delete aList ;

    /*
      // Vérifiez si la liste est vide
      if (aList == nullptr) return;

      // Définir un pointeur temporaire pour parcourir la liste
      Element * temp = aList->first;

      // Parcourir la liste jusqu'à ce que vous atteigniez la fin
      while (temp != nullptr)
      {
        // Définissez un pointeur de liste pour stocker le prochain élément
        Element * next = temp->next;

        // Supprimer l'élément actuel
        delete temp;

        // Avancer au prochain élément
        temp = next;

        aList->size-- ;
      }

      // Réinitialiser le pointeur de liste en entrée pour indiquer que la liste est vide
      aList = nullptr;
      delete aList ; */
}

/*
 * removeOptis from the container the element that compare equal to aValue. This
 * reduces the container size by one.
 * param: a list
 * parma: a value
 *
 */
void remove(List * aList, const int aValue)
{
    //Ne pas continuer si la liste est déjà vide pour ne pas planter
    if(aList->size == 0 || aList->first == nullptr)
    {
        return ;
    }
    //Si la première valeur et celle qu'on veut supprimer, on utilise pop et ne parcour pas la liste
    else if (aList->first->value == aValue)
    {
        pop(aList) ;
        return;
    }

    //Booléen permettant de sortir de la boucle à l'instant où l'élément contenant la valeur entrée aura été supprimé
    //Plus optimisé que de parcourir une liste tant qu'elle n'est pas à sa fin même si ça rajoute une condition
    bool isremoveOptid = false ;

    //Boucle qui passe d'élément à élément
    for(Element * current = aList->first ; isremoveOptid != true ; current = current->next )
    {
        //Condition rajouté pour éviter une boucle infinie au cas où l'élément n'a pas été trouvé
        if(current->next == nullptr)
        {
            isremoveOptid = true ;
        }

        //Si la valeur choisit et celle d'après, effectuer une suppression à l'aide d'un pointeur temporaire
        else if(aValue == current->next->value)
        {
            Element * del = current->next ; //stocker l'adresse à supprimer
            current->next = current->next->next ; //assigner la première adresse de la liste au deuxième élement
            delete del ; //Supprimer l'ancienne première adresse
            aList->size-- ; //Réduire la taille de la liste
            isremoveOptid = true ;
        }
    }
}

void removeOpti(List * aList, const int aValue)
{
    // before est un pointeur qui va stocker l'adresse de l'élément précédent à l'élément courant.
    Element *before = nullptr;

    // current est un pointeur qui va stocker l'adresse de l'élément courant. Il est initialisé à la première valeur de la liste pour commencer la recherche de l'élément à supprimer.
    Element *current = aList->first;

    // Tant qu'on n'a pas atteint la fin de la liste, on parcourt les éléments un à un.
    while (current != nullptr)
    {
        // Si la valeur courante est celle qu'on veut supprimer, on effectue les opérations de suppression.
        if (current->value == aValue)
        {
            // Si before est nullptr, cela signifie qu'on est sur la première valeur de la liste, il faut donc réassigner la première valeur de la liste à la suivante.
            if (before == nullptr)
            {
                aList->first = current->next;
            }
            // Sinon, on relie l'élément précédent à l'élément suivant, en sautant l'élément à supprimer.
            else
            {
                before->next = current->next;
            }
            // On libère la mémoire allouée pour l'élément à supprimer.
            delete current;
            // On décrémente la taille de la liste de 1.
            aList->size--;
            // On sort de la boucle car l'élément a été supprimé.
            break;
        }
        // On assigne l'adresse de l'élément courant à before pour le stocker en tant qu'élément précédent.
        before = current;
        // On passe à l'élément suivant en assignant l'adresse de next à current.
        current = current->next;
    }
}




/*
 * Returns the smallest of a and b. If both are equivalent, a is returned.
 * param: a number
 * param: an other number
 * return: the number min of the first if equality
 */
int min(const int aNb1, const int aNb2)
{
    //Vérfie que nb1 est plus petit ou égal à nb2 pour renvoyer nb1
    if(aNb1 <= aNb2)
    {
        return aNb1 ;
    }
    //Sinon renvoyer nb2
    else
    {
        return aNb2 ;
    }
}

/*
 * Utility functions for The Game
 */

/*
 * Put a card on a stack.
 * param: a list (stack)
 * param: a card
 */
void putACard(List * aList, const int aCard)
{
    //Créer une carte qui prendra la valeur entrée, et la mettre au début de la liste souhaité
    Element * Card = new Element ;
    Card->value = aCard ;
    push(aList, Card);
}

/*
 * Shuffle the stock (98 cards numbered from 2 to 99)
 * param: a list
 * var: drawIndex
 */

void shuffle(List * aList)
{
    //Si la liste est vide, ne rien faire
    if(aList == nullptr)
    {
        return ;
    }

    //Création d'un tableau d'une taille 98 (Nombres de cartes présent dans le paquet au début du jeu)
    const int SIZE = 98 ;
    int array[SIZE] ;

    //Remplir ce tableau avec la valeur de chaque carte possible dans l'ordre (2-98)
    for(int i = 0 ; i < SIZE ; i++)
    {
        array[i] = i + 2 ;
    }

    /*
        Sert à afficher la liste non mélangée
        for(int i = 0 ; i < SIZE ; i++ )
        {
            cout << " ->" << array[i]  ;
        }

    */

    //Créer un sysème de génération aléatoire avec des variables représentant :
    //randPermut : indice aléatoire qu'on choisira pour permuter avec l'indice i de la boucle for
    random_device r ;
    default_random_engine e1(r());
    int randPermut, temp ;

    //Permuter chaque élément du tableau un par un avec un autre élément du tableau choisit au hasard
    for(int i = 0 ; i < SIZE ; i++ )
    {
        uniform_int_distribution<int> rand(0, 97); //Génère un indice aléatoire compris entre 0 et 97 (98 cartes)
        //Permuter les valeurs de l'indice de la boucle avec l'indice aléatoire
        randPermut = rand(e1) ;
        temp = array[i] ;
        array[i] = array[randPermut] ;
        array[randPermut] = temp ;
    }

        /*
        Sert à afficher la liste non mélangée
        for(int i = 0 ; i < SIZE ; i++ )
        {
            cout << " ->" << array[i]  ;
        }
        */

    //Boucle qui ajoute carte par carte les carte mélangé dans notre paquet vide
    for(int drawIndex = 0 ; drawIndex < SIZE ; drawIndex ++)
    {
        putACard(aList, array[drawIndex]) ;
    }
}

void shuffleOpti(List * aList)
{
    //Si la liste est vide, ne rien faire
    if(aList == nullptr)
    {
        return ;
    }

    //Création d'un tableau d'une taille 98 (Nombres de cartes présent dans le paquet au début du jeu)
    const int SIZE = 98 ;
    int array[SIZE] ;

    //Remplir ce tableau avec la valeur de chaque carte possible dans l'ordre (2-98)
    for(int i = 0 ; i < SIZE ; i++)
    {
        array[i] = i + 2 ;
    }

    /*
     * Utiliser std::shuffle de la bibliotèque standard pour mélanger les éléments du tableau
     * begin(array) retourne un itérateur pointant sur le premier élément du tableau array
     * end(array) retourne un itérateur pointant juste après le dernier élément du tableau array
     * default_random_engine() générateur de nombres aléatoires qui est utilisé pour mélanger les éléments
     *
    */
    shuffle(begin(array), end(array), default_random_engine());

    //Boucle qui ajoute carte par carte les carte mélangé dans notre paquet vide
    for(int drawIndex = 0 ; drawIndex < SIZE ; drawIndex ++)
    {
        putACard(aList, array[drawIndex]) ;
    }
}

void shuffleMaxiOpti(List * aList) {
    if(!aList) return;
    int array[98];
    for(int i = 0; i < 98; i++) array[i] = i + 2;
    shuffle(begin(array), end(array), default_random_engine());
    for(int i = 0; i < 98; i++) putACard(aList, array[i]);
}

/*
 * Afficher les fondations une par une avec un centrage selon leur valeur (valeur à un chiffre ou deux)
 */

void displayFundationA(const List * aFundation)
{
    if(aFundation->first->value < 10)
    {
        cout << endl << "            ||       |  "<< aFundation->first->value <<"  | " ;
    }
    else
    {
        cout << endl << "            ||       | "<< aFundation->first->value <<"  | " ;
    }

}

void displayFundationB(const List * aFundation)
{
    if(aFundation->first->value < 10)
    {
        cout << "|  " << aFundation->first->value << "  |      " ;
    }
    else
    {
        cout << "| " << aFundation->first->value << "  |      " ;
    }
}

void displayFundationC(const List * aFundation)
{
    if(aFundation->first->value < 10)
    {
        cout << "|  "<< aFundation->first->value <<"  | " ;
    }
    else if (aFundation->first->value == 100)
    {
        cout << "| "<< aFundation->first->value <<" | " ;
    }
    else
    {
        cout << "| "<< aFundation->first->value <<"  | " ;
    }
}

void displayFundationD(const List * aFundation)
{
    if(aFundation->first->value < 10)
    {
        cout << "|  " << aFundation->first->value << "  |        ||" ;
    }
    else if (aFundation->first->value == 100)
    {
        cout << "| "<< aFundation->first->value <<" |        ||" ;
    }
    else
    {
        cout << "| " << aFundation->first->value << "  |        ||" ;
    }
}

/*
 * Display a game board
 * use displayList
 * param: fundations (up and down)
 * param: a stock (stack)
 * param: the player hand (list)
 */
void displayBoard(const List * aFundationUpA, const List * aFundationUpB, const  List * aFundationDownA, const List * aFundationDownB, Player player)
{
    cout << R"(
            //===================================================\\
            ||                                                   ||
            ||                      BOARD                        ||
            ||                                                   ||
            ||         U+P     U+P         DO-WN   DO-WN         ||
            ||       +-----+ +-----+      +-----+ +-----+        ||
            ||       |     | |     |      |     | |     |        ||)" ;
                       displayFundationA(aFundationUpA);
                       displayFundationB(aFundationUpB);
                       displayFundationC(aFundationDownA);
                       displayFundationD(aFundationDownB);
    cout << R"(
            ||       |     | |     |      |     | |     |        ||
            ||       +-----+ +-----+      +-----+ +-----+        ||
            ||                                                   ||
            ||                   Main actuel :                   ||
            ||                                                   ||)";
                            displayList(player.hand) ; cout << R"(
            ||                                                   ||
            \\===================================================//)";

}

/*
 * Move a card on a fundation up if possible
 * Condition: the value of the card is greater than the one on the top
 * or the value of the card is 10 lower than the top of the fundation.
 * param: a fundation (stack)
 * param: a card
 * return: true if the move is possible
 * var: valid boolean
 */
bool moveUp(List * aList, const int aCard)
{
    //Vérifier que la carte choisit est plus grande que celle déjà posé ou qu'elle est plus petite de 10
    //if(min(aCard, aList->first->value) != aCard || aCard == aList->first->value - 10)
    if(aCard > aList->first->value || aCard == aList->first->value - 10)
    {
        //Pour que remplisse les tests
       putACard(aList, aCard) ;
        return true ;
    }
    else
    {
        return false ;
    }
}

/*
 * Move a card on a fundation down if possible
 * Condition: the value of the card is lower than the one on the top
 * or the value of the card is 10 greater than the top of the fundation
 * param: a fundation (stack)
 * param: a card
 * return: true if the move is possible
 * var: valid boolean
 */
bool moveDown(List * aList, const int aCard)
{
    //Vérifier que la carte choisit est plus petite que celle déjà posé ou qu'elle est plus grande de 10
    //if(min(aCard, aList->first->value) == aCard || aCard == aList->first->value + 10)
    if(aCard < aList->first->value || aCard == aList->first->value + 10)
    {
        putACard(aList, aCard) ;
        return true ;
    }
    else
    {
        return false ;
    }
}

/*
 * Ask a player to play a card
 * Ask first to choose the value of a card
 * then the name of the fundation for the move
 * param: a fundation (stack)
 * param: a card
 * param: a player (use the name and check his input in relation to his hand)
 */
void play(int & aCard, char & aStack, Player & player)
{

    //Demander une carte et vérifier sa validité
    cout << endl << endl << "                " ;
    cout << CYAN_TEXT << player.name << BLUE_TEXT <<", quelle carte souhaites tu jouer : " << COLOR_RESET ;
    //Boucle qui redemande à l'utilisateur tant que l'entrée n'est pas un int compris entre 2 et 99 compris
    while(true){
        cin >> aCard;
        if(cin.fail() || aCard < 2 || aCard > 99 || isValid(player.hand, aCard) == false)
        {
            if(isValid(player.hand, aCard) == false)
            {
                cout << endl << RED_TEXT << "Cette carte ne se trouve pas dans ta main, veuillez recommencer : " << COLOR_RESET;
            }
            else
            {
                cout << endl << RED_TEXT << "Cette carte n'existe pas, veuillez entrer un nombre entre 2 et 99 qui se trouve dans votre main : " << COLOR_RESET ;
            }
            cin.clear(); //Réinitialiser l'entrée si une erreur à été produite pour pouvoir de nouveau entrée une valeur
            cin.ignore(10,'\n'); //Ignore un certains nombre de caractères pour ne pas prendre en compte l'entrée comme plusieurs entrée et cela à partir la fin de ligne
        }
        else
            break;
    }

    //Demander une pile et vérifier sa validité
    cout << endl << endl << "           " ;
    cout << CYAN_TEXT << player.name << BLUE_TEXT <<", sur quelle pile souhaites tu jouer (A B | C D) : " << COLOR_RESET ;
    while(true)
    {
        cin >> aStack;
        aStack = toupper(aStack);
        if(cin.fail() || aStack < 'A' || aStack > 'D')
        {
            cout << endl << RED_TEXT << "   Cette fondation n'existe pas, veuillez entrer une lettre entre A et D : " << COLOR_RESET;
            cin.clear(); //Réinitialiser l'entrée si une erreur à été produite pour pouvoir de nouveau entrée une valeur
            cin.ignore(10,'\n'); //Ignore un certains nombre de caractères pour ne pas prendre en compte l'entrée comme plusieurs entrée et cela à partir la fin de ligne
        }
        else
        {
            break;
        }
    }

    cout << endl ;

}

/*
 * Check if a card is in a hand
 * param: a hand (list)
 * param: a card
 * return: true if the card is in the hand
 * var: valid boolean
 */
bool isValid(const List * aHand, const int aValue)
{
    for(Element * current = aHand->first ; current != nullptr  ; current = current->next)
    {
        if(current->value == aValue)
        {
            return true ;
        }

        else if(current->next == nullptr)
        {
            //cout << RED_TEXT << "La carte choisit n'est pas dans votre main, recommencez !" << endl;
            return false ;
        }
    }
    return false ;
}

/*
 * Calculate a score
 * Sum cards' value of the hand and the stock
 * param: a hand (list)
 * param: a stock (list)
 * return: int a score
 * var: int sum
 */
int score(const List* aHand, const List* aStock, ListPlayers* gamePlayers)
{
    int score = 0;

    if(gamePlayers == nullptr)
    {
        if(aHand->size == 0 && aStock->size == 0)
        {
            return 0 ;
        }
        else if(aStock->size != 0)
        {
            for(Element * current = aStock->first ; current != nullptr ; current = current->next)
            {
                score += current->value ;
            }
        }

        for(Element * current = aHand->first ; current != nullptr ; current = current->next)
        {
            score += current->value ;
        }

        return score ;
    }
    else
    {
        if(aStock->size != 0)
        {
            for(Element * current = aStock->first ; current != nullptr ; current = current->next)
            {
                score += current->value ;
            }
        }

        for(Player * currentPlayer = gamePlayers->firstPlayer ; currentPlayer != nullptr ; currentPlayer = currentPlayer->nextPlayer)
        {
            if(currentPlayer->hand->size != 0)
            {
                for(Element * current = aHand->first ; current != nullptr ; current = current->next)
                {
                    score += current->value ;
                }
            }
        }

        return score ;
    }
}


//************************************************************************************************//

void displayTitle()
{
    cout << BLUE_TEXT << R"(

    $$$$$$$$\ $$\                  $$$$$$\
    \__$$  __|$$ |                $$  __$$\
       $$ |   $$$$$$$\   $$$$$$\  $$ /  \__| $$$$$$\  $$$$$$\$$$$\   $$$$$$\
       $$ |   $$  __$$\ $$  __$$\ $$ |$$$$\  \____$$\ $$  _$$  _$$\ $$  __$$\
       $$ |   $$ |  $$ |$$$$$$$$ |$$ |\_$$ | $$$$$$$ |$$ / $$ / $$ |$$$$$$$$ |
       $$ |   $$ |  $$ |$$   ____|$$ |  $$ |$$  __$$ |$$ | $$ | $$ |$$   ____|
       $$ |   $$ |  $$ |\$$$$$$$\ \$$$$$$  |\$$$$$$$ |$$ | $$ | $$ |\$$$$$$$\
       \__|   \__|  \__| \_______| \______/  \_______|\__| \__| \__| \_______|
       by Thibaut LEFRANCOIS D2 ==============================================
        )" << COLOR_RESET ;

}

/*
 * \brief Efface l'écran après appui sur une touche et affiche
 * << BattleShip >> stylisé avec votre nom
 * appel système de la commande console << cls >> voir
 * https://cplusplus.com/reference/cstdlib/system/
 * /!\ ne fonctionne que sous Windows
 * \return void
 */

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

    displayTitle();
}

/*
 * \brief affiche le menu HOME : permet d'accéder aux menus correspondant au style de jeu que le joueur souhaite
 */
void home();

/*
 * \brief Lance tout les tests donné par le directeur logiciel
 */
void launchTest()
{
    clearScreen() ;
    cout << endl ;

    test_push() ;
    test_top() ;
    test_pop() ;
    test_insert() ;
    test_displayList();
    test_remove() ;
    test_min() ;
    test_putACard() ;
    //test_shuffle() ;
    test_moveUp() ;
    test_moveDown();
    //test_play() ;
    test_isValid();
    test_score();
    test_timeShuffle();
    test_timeRemove();

}

bool isFinished(Player & aPlayer, List * aFundationUpA, List * aFundationUpB, List * aFundationDownA, List * aFundationDownB)
{
    bool canPlace = false ;

    for(Element * current = aPlayer.hand->first ; current != nullptr ; current = current->next)
    {
        if( moveUp(aFundationUpA, current->value) || moveUp(aFundationUpB, current->value) || moveDown(aFundationDownA, current->value) || moveDown(aFundationDownB, current->value) )
        {
            canPlace = true ;
        }
    }

    if (canPlace == false)
    {
        return true;
    }
    else
    {
        return false;
    }

}

/*
 * \brief lance le mode de jeu Solo de Thegame
 */
void soloMode()
{
    clearScreen();

    //Initialisation des bases d'une partie

    //Création d'un joueur
    ListPlayers* gamePlayers = nullptr ;
    Player player ;
    cout << endl << R"(//==========================================================\\)" << endl;
    cout << endl << CYAN_TEXT << "Joueur 1" << BLUE_TEXT <<", veuillez entrer votre nom : " << COLOR_RESET;
    cin >> player.name ;
    cout << endl ;
    player.score = 0 ;
    player.hand = new List ;
    clearScreen() ;

    //Créer les fondations montante et descendante et les initailiser à leurs valeur respective
    List *aFundationUpA = new List ;
    putACard(aFundationUpA, 1) ;
    List *aFundationUpB = new List ;
    putACard(aFundationUpB, 1) ;
    List *aFundationDownA = new List ;
    putACard(aFundationDownA, 100) ;
    List *aFundationDownB = new List ;
    putACard(aFundationDownB, 100) ;
    List *aStock = new List ;
    shuffle(aStock) ;

    //Attribuer les cartes à la main d'un joueur
    for (int i = 0 ; i < 8 ; i++ )
    {
        putACard(player.hand, aStock->first->value);
        removeOpti(aStock, aStock->first->value);
    }
    int aCard ;
    char aStack ;

    //Afficher le plateau préparé
    displayBoard(aFundationUpA, aFundationUpB, aFundationDownA, aFundationDownB, player) ;

    //Début de la partie

    //bool isFinished = false ;
    do
    {
        //Demande au joueur une carte et une pile en s'assurant que l'entrée est valide
        play(aCard, aStack, player) ;

        //******** Placer la carte selon la pile choisit par le joueur *****************
        bool isPlaced = false ;
        if(aStack == 'A' && moveUp(aFundationUpA, aCard))
        {
            putACard(aFundationUpA, aCard) ;
            removeOpti(player.hand, aCard) ;
            isPlaced = true ;
        }
        else if(aStack == 'B' && moveUp(aFundationUpB, aCard))
        {
            putACard(aFundationUpB, aCard) ;
            removeOpti(player.hand, aCard) ;
            isPlaced = true ;
        }
        else if(aStack == 'C' && moveDown(aFundationDownA, aCard))
        {
            putACard(aFundationDownA, aCard) ;
            removeOpti(player.hand, aCard) ;
            isPlaced = true ;
        }
        else if(aStack == 'D' && moveDown(aFundationDownB, aCard))
        {
            putACard(aFundationDownB, aCard);
            removeOpti(player.hand, aCard) ;
            isPlaced = true ;
        }
        else
        {
            cout << RED_TEXT << endl << "    Impossible de placer cette carte sur la pile voulue, verifier que sa valeur est  : " << endl << endl ;
            cout << "    -plus grande ou plus petite de 10 que celle deja posee pour les piles UP" << endl ;
            cout << "    -plus petite ou plus grande de 10 que celle deja posee pour les piles DOWN" << COLOR_RESET << endl << endl ;
        }
        //*****************************************************************************

        //Faire piocher le joueur tant que la pile n'est pas vide
        if(aStock->size != 0 && isPlaced)
        {
        int card = top(aStock);
        putACard(player.hand, card) ;
        removeOpti(aStock, card);
        cout << endl << GREEN_TEXT << "                     " << "Vous avez pioche la carte : " << card << endl << endl << COLOR_RESET;
        }

        //Mettre à jour le plateau du jeu
        clearScreen();
        displayBoard(aFundationUpA, aFundationUpB, aFundationDownA, aFundationDownB, player) ;
    }
    //Recommencer tant que les conditions pour finir une partie ne sont pas remplies (dans ce cas, on attend que le joueur ne puissent plus  placer)
    while (isFinished(player, aFundationUpA, aFundationUpB, aFundationDownA, aFundationDownB) != true) ;

    //Affichage de fin de partie + suppression propre des listes créée pour libérer la mémoire

    cout << endl << endl << "       " << "//**************************************************************\\" << endl << endl ;

    cout << RED_TEXT << "               " << "La partie est terminee, voici votre score : " << score(player.hand, aStock, gamePlayers) << endl << endl ;

    cout << BLUE_TEXT <<"                       " << "Merci d'avoir joue a TheGame !" << COLOR_RESET << endl << endl  ;

    deleteList(aFundationUpA);
    deleteList(aFundationUpB);
    deleteList(aFundationDownA);
    deleteList(aFundationDownB);
    deleteList(player.hand);
    deleteList(aStock);

}

void multiMode()
{

    //Nettoye le menu d'accueil
    clearScreen();

    //*************************************** Initialisation partie : Listes + élément + mélange ***************************************************************

    //Création de la liste de joueurs
    ListPlayers * gamePlayers = new ListPlayers ;

    //Créer les fondations montante et descendante et les initailiser à leurs valeur respective
    List *aFundationUpA = new List ;
    putACard(aFundationUpA, 1) ;
    List *aFundationUpB = new List ;
    putACard(aFundationUpB, 1) ;
    List *aFundationDownA = new List ;
    putACard(aFundationDownA, 100) ;
    List *aFundationDownB = new List ;
    putACard(aFundationDownB, 100) ;
    List *aStock = new List ;
    shuffle(aStock) ; //Mélanger le paquet de carte

    //*************************************** Insertion joueur : Combien de joueurs ? Leurs noms ? Leur créer une main ***************************************************************

    cout << endl << R"(//==========================================================\\)" << endl;
    cout << endl << BLUE_TEXT << "Combien de joueurs souhaitent jouer ? (2/3/4/5) : " << COLOR_RESET ;
    //Boucle qui redemande à l'utilisateur tant que l'entrée n'est pas un int compris entre 2 et 5 compris
    while(true)
    {
        cin >> gamePlayers->nbPlayers;
        if(cin.fail() || gamePlayers->nbPlayers < 2 || gamePlayers->nbPlayers > 5)
        {
            if(gamePlayers->nbPlayers < 2 || gamePlayers->nbPlayers > 5)
            {
                cout << endl << RED_TEXT << "Trop de joueurs choisit, vous pouvez en choisir un maximum de 5, recommencez : " << COLOR_RESET;
            }
            else
            {
                cout << endl << RED_TEXT << "Mauvaise entrée, veuillez choisir un chiffre compris entre 2 et 4 : " << COLOR_RESET ;
            }
            cin.clear(); //Réinitialiser l'entrée si une erreur à été produite pour pouvoir de nouveau entrée une valeur
            cin.ignore(10,'\n'); //Ignore un certains nombre de caractères pour ne pas prendre en compte l'entrée comme plusieurs entrée et cela à partir la fin de ligne
        }
        else
            break;
    }

    //Proposition de difficulté
    string choice ;
    do
    {
        cout << endl << RED_TEXT << "Souhaites tu rajouter un vrai challenge en enlevant 3 cartes de ta main ? (oui/non) : " << COLOR_RESET ;
        cin >> choice ;
        cout << endl ;
        if(choice != "oui" && choice != "non")
        {
            cout << RED_TEXT << "Entrez soit oui soit non (en minuscule), recommencez ! " << COLOR_RESET ;
        }
    }
    while(choice != "oui" && choice != "non");

    //Combien de cartes selon nbPlayers
    int nbCardsinHand = 0 ;
    //Définir alors le nombre de carte selon le nombre de joueurs
    if(gamePlayers->nbPlayers == 2)
    {
        nbCardsinHand = 7 ;
    }
    else
    {
        nbCardsinHand = 6 ;
    }

    if(choice == "oui")
    {
        nbCardsinHand -= 3 ;
    }

    //Intéraction joueurs machine pour initialiser la liste de joueur

    cout << endl ;
    clearScreen();

    cout << endl << R"(//==========================================================\\)" << endl;

    for(int i = 0 ; i < gamePlayers->nbPlayers ; i++)
    {
        //Création d'un joueur et insertion de ses données
        Player * player = new Player ;
        player->nextPlayer = gamePlayers->firstPlayer ;
        gamePlayers->firstPlayer = player ;
        cout << endl << BLUE_TEXT <<"Entrez le nom d'un joueur : " << COLOR_RESET;
        cin >> player->name ;
        player->score = 0 ;
        player->hand = new List ;

        //Attribuer les cartes à la main d'un joueur
        for (int i = 0 ; i < nbCardsinHand ; i++ )
        {
            putACard(player->hand, aStock->first->value);
            removeOpti(aStock, aStock->first->value);
        }
    }
    cout << endl ;

    //*************************************** Début d'une partie : Boucle de jeu tant que ce n'est pas perdu ***************************************************************

    //Initialisation des variables en intéraction avec les joueurs
    int aCard ; //Une carte choisit
    char aStack ; //Une fondation choisit
    bool isLosed ; //Un statut de partie
    bool endPlayers = false; //Booléen qui passe vrai quand on doit retourner au premier joueur

    //Boucle de jeu
    do
    {
        //Boucle faisant jouer les joueurs de la liste un par un si ils ont le droit (canPlay==true)
        for(Player * currentPlayer = gamePlayers->firstPlayer ; currentPlayer != nullptr ; currentPlayer = currentPlayer->nextPlayer)
        {
            if(endPlayers==true)
            {
                currentPlayer = gamePlayers->firstPlayer ;
                endPlayers = false ;
            }

            if (isFinished(*currentPlayer, aFundationUpA, aFundationUpB, aFundationDownA, aFundationDownB))
            {
                currentPlayer->canPlay = false ;
                int nbLose = 0 ;
                for(Player * testLose = gamePlayers->firstPlayer ; testLose != nullptr ; testLose = testLose->nextPlayer)
                {
                    if((isFinished(*testLose, aFundationUpA, aFundationUpB, aFundationDownA, aFundationDownB)))
                    {
                        testLose->canPlay = false ;
                    }
                    if(testLose->canPlay == false)
                    {
                        nbLose += 1 ;
                    }
                }

                if(nbLose == gamePlayers->nbPlayers)
                {
                    isLosed = true ;
                }
            }
            else
            {
                currentPlayer->canPlay = true ;
            }


            //Vérifier si le joueur à le droit de jouer
            if(currentPlayer->canPlay==true)
            {
                int nbPlaced = 0 ; //Combien de cartes placées
                //Ajout de la règle, une carte a posé si la pioche est vide en commençant à jouer avec plus qu'une seule carte à posé (1 carte placé, manque 1 autre pour finir le tour)
                if(aStock->size==0)
                {
                    nbPlaced += 1;
                }
                bool placeAgain = true; //Doit-il encore placé une carte (si il le choisit et qu'il peut)
                bool isPlaced = false ; //Vérifie si la carte à bien été placé
                do
                {
                    clearScreen(); //Nettoie l'affichage pour le nouveau/premier joueur
                    displayBoard(aFundationUpA, aFundationUpB, aFundationDownA, aFundationDownB, *currentPlayer) ;

                    //Demande au joueur une carte et une pile en s'assurant que l'entrée est valide
                    play(aCard, aStack, *currentPlayer);

                    //******** Placer la carte selon la pile choisit par le joueur *****************

                    if(aStack == 'A' && moveUp(aFundationUpA, aCard))
                    {
                        putACard(aFundationUpA, aCard) ;
                        removeOpti(currentPlayer->hand, aCard) ;
                        nbPlaced += 1 ;
                        isPlaced = true ;
                    }
                    else if(aStack == 'B' && moveUp(aFundationUpB, aCard))
                    {
                        putACard(aFundationUpB, aCard) ;
                        removeOpti(currentPlayer->hand, aCard) ;
                        nbPlaced += 1 ;
                        isPlaced = true ;
                    }
                    else if(aStack == 'C' && moveDown(aFundationDownA, aCard))
                    {
                        putACard(aFundationDownA, aCard) ;
                        removeOpti(currentPlayer->hand, aCard) ;
                        nbPlaced += 1 ;
                        isPlaced = true ;
                    }
                    else if(aStack == 'D' && moveDown(aFundationDownB, aCard))
                    {
                        putACard(aFundationDownB, aCard);
                        removeOpti(currentPlayer->hand, aCard) ;
                        nbPlaced += 1 ;
                        isPlaced = true ;
                    }
                    else
                    {
                        cout << RED_TEXT << endl << "    Impossible de placer cette carte sur la pile voulue, verifier que sa valeur est  : " << endl << endl ;
                        cout << "    -plus grande ou plus petite de 10 que celle deja posee pour les piles UP" << endl ;
                        cout << "    -plus petite ou plus grande de 10 que celle deja posee pour les piles DOWN" << COLOR_RESET << endl << endl ;
                        isPlaced = false ;
                    }

                    //clearScreen();
                    //displayBoard(aFundationUpA, aFundationUpB, aFundationDownA, aFundationDownB, *currentPlayer) ;

                    //*****************************************************************************
                    if (isFinished(*currentPlayer, aFundationUpA, aFundationUpB, aFundationDownA, aFundationDownB))
                    {
                        currentPlayer->canPlay = false ;
                    }

                    if(nbPlaced >=2)
                    {
                        placeAgain = false ;
                    }

                    if(nbPlaced >= 2 && isPlaced && currentPlayer->canPlay)
                    {
                        string choice ;
                        do
                        {
                            cout << BLUE_TEXT << endl << endl << "          " << "Veux tu continuer a jouer ? (oui/non) : " << COLOR_RESET ;
                            cin >> choice ;
                            cout << endl ;
                            if(choice != "oui" && choice != "non")
                            {
                                cout << RED_TEXT << endl << "Entrez soit oui soit non, recommencez ! " << COLOR_RESET ;
                            }
                        }
                        while(choice != "oui" && choice != "non");

                        if(choice == "oui")
                        {
                            placeAgain = true ;
                        }
                        else
                        {
                            placeAgain = false;
                        }

                    }
                    if (isFinished(*currentPlayer, aFundationUpA, aFundationUpB, aFundationDownA, aFundationDownB))
                    {
                        currentPlayer->canPlay = false ;
                        int nbLose = 0 ;
                        for(Player * testLose = gamePlayers->firstPlayer ; testLose != nullptr ; testLose = testLose->nextPlayer)
                        {
                            if((isFinished(*testLose, aFundationUpA, aFundationUpB, aFundationDownA, aFundationDownB)))
                            {
                                testLose->canPlay = false ;
                            }
                            if(testLose->canPlay == false)
                            {
                                nbLose += 1 ;
                            }
                        }

                        if(nbLose == gamePlayers->nbPlayers)
                        {
                            isLosed = true ;
                        }
                    }
                    else
                    {
                        currentPlayer->canPlay = true ;
                    }

                    if(currentPlayer->canPlay == false)
                    {
                        cout << endl << endl << CYAN_TEXT << "    " << currentPlayer->name << RED_TEXT << ", vous ne pouvez plus jouer, vous passez alors votre tour..." << COLOR_RESET << endl ;
                        placeAgain = false;
                    }


                    clearScreen();
                    displayBoard(aFundationUpA, aFundationUpB, aFundationDownA, aFundationDownB, *currentPlayer) ;


                }
                while(placeAgain == true && currentPlayer->canPlay );

                //Faire piocher le joueur tant que la pile n'est pas vide
                if(aStock->size != 0 && aStock->size >= nbPlaced)
                {
                    for (int i  = 1 ; i < nbPlaced ; i++)
                    {
                        int card = top(aStock);
                        putACard(currentPlayer->hand, card) ;
                        removeOpti(aStock, card);
                        cout << endl << GREEN_TEXT << "                     " << "Vous avez pioche la carte : " << card << endl << endl << COLOR_RESET;
                    }
                }

                if(currentPlayer->nextPlayer == nullptr)
                {
                    endPlayers = true ;
                }
            }
        }
    }
    while (isLosed != true) ;
    //Affichage de fin de partie + suppression propre des listes créée pour libérer la mémoire

    cout << endl << endl << "       " << "//**************************************************************\\" << endl << endl ;

    cout << RED_TEXT << "               " << "La partie est terminee, voici votre score : " << score(gamePlayers->firstPlayer->hand, aStock, gamePlayers) << endl << endl ;

    cout << BLUE_TEXT <<"                       " << "Merci d'avoir joue a TheGame !" << COLOR_RESET << endl << endl  ;

    deleteList(aFundationUpA);
    deleteList(aFundationUpB);
    deleteList(aFundationDownA);
    deleteList(aFundationDownB);
    deleteList(aStock);
    for(Player * deletePlayer = gamePlayers->firstPlayer ; deletePlayer != nullptr ; deletePlayer = deletePlayer->nextPlayer)
    {
        deleteList(deletePlayer->hand);
    }
    delete gamePlayers ;

}

void launchRules()
{
    clearScreen();

    cout << R"(

Règles de Piles de cartes :

La partie est jouée par 1 à 5 joueurs, âgés de 8 ans et plus, et dure environ 20 minutes.

Il y a 4 piles de cartes au centre de la table : 2 piles sont en ordre croissant (de 1 à 99) et 2 autres en sens décroissant (de 100 à 2).

Le but est de poser le plus grand nombre de cartes possible, idéalement les 98, sur les 4 piles.

Sur les piles croissantes, la valeur de chaque nouvelle carte posée doit être supérieure à la valeur de la carte au-dessus de la pile.

Sur les piles décroissantes, c’est exactement l’inverse : la valeur de chaque nouvelle carte posée doit être inférieure à la valeur de la carte au-dessus de la pile.

Les joueurs décident ensemble qui commence. Le jeu se déroule ensuite à tour de rôle dans le sens des aiguilles d'une montre.

À votre tour, vous devez poser au moins 2 cartes de votre main à droite de l'une des 4 piles de base. Vous pouvez poser autant de cartes que vous le souhaitez, éventuellement jusqu'à ne plus avoir aucune carte en main.

Vous pouvez poser toutes vos cartes sur la même pile, ou sur plusieurs piles dans n'importe quel ordre comme vous souhaitez.

Une fois que vous avez terminé de poser des cartes, prenez du dessus de la pioche le même nombre de cartes que ce que vous avez posé, pour compléter votre main à 6 (pour un jeu à 3, 4 ou 5 joueurs), 7 (pour un jeu à 2 joueurs) ou 8 (jeu en solitaire) cartes à nouveau.

Le joueur suivant joue ensuite, en posant au moins 2 cartes puis en complétant sa main depuis la pioche.

Les 4 bases de piles sont disposées face visible, les unes au-dessus des autres, au centre de la table. Mélangez soigneusement les 98 cartes numérotées.

)";
}

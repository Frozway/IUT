#include <iostream>
#include <chrono>
#include "typeDef.h"
#include "functions.h"

using namespace std;



/*
 * Utility functions for tests
 */

void addElt(List * aList, const int aValue)
{
    Element * elt;
    elt = new Element;
    elt->value = aValue;
    elt->next = aList->first;
    aList->first = elt;
    aList->size++;
}

void initList(List * aList, int a, int b, int c)
{
    addElt(aList, c);
    addElt(aList, b);
    addElt(aList, a);
}

void emptyList(List* aList)
{
    Element * eltToBeDeleted;
    Element * elt = aList->first;
    if (elt->next != nullptr)
    {
        while (elt->next != nullptr)
        {
            eltToBeDeleted = elt;
            elt = elt->next;
            delete eltToBeDeleted;
        }
    }
    else
    {
        delete elt;
    }
}

/*
 * Utility functions for data structure (based on STL API)
 */

/*
 * Tests
 * Liste vide valeur 73 -> liste 73 taille = 1
 * Liste 1, 2, valeur 73 -> liste 73, 1, 2 taille = 3
 */
void test_push()
{
    int pass = 0;
    int failed = 0;
    cout << "********* Start testing of push *********" << endl;
    List* list;
    Element * elt;
    list = new List;
    elt = new Element;
    elt->value = 73;
    push(list, elt);
    if (list->size == 1 and
            list->first->value == 73 and
            list->first->next == nullptr)
    {
        cout << "PASS \t: push 73 in {}" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: push 73 in {}" << endl;
        failed++;
    }
    emptyList(list);
    delete list;
    list = new List;
    addElt(list, 2);
    addElt(list, 1);
    elt = new Element;
    elt->value = 73;
    push(list, elt);
    if (list->size == 3 and
            list->first->value == 73 and
            list->first->next->value == 1 and
            list->first->next->next->value == 2 and
            list->first->next->next->next == nullptr)
    {
        cout << "PASS \t: push 73 in {1,2}" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: push 73 in {1,2}" << endl;
        failed++;
    }
    emptyList(list);
    delete list;
    cout << "Totals: " << pass << " passed, " << failed << " failed" << endl;
    cout << "********* Finished testing of push *********" << endl;
}


/*
 * Tests
 * Liste 1, 2, 3 -> 1 taille = 3
 * Liste vide -> 0 taille = 0
 */
void test_top()
{
    int pass = 0;
    int failed = 0;
    cout << "********* Start testing of top *********" << endl;
    List* list;
    list = new List;
    initList(list, 1, 2, 3);
    if (top(list) == 1 and
            list->size == 3 and
            list->first->value == 1 and
            list->first->next->value == 2 and
            list->first->next->next->value == 3 and
            list->first->next->next->next == nullptr)
    {
        cout << "PASS \t: top {1,2,3}" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: top {1,2,3}" << endl;
        failed++;
    }
    emptyList(list);
    delete list;
    list = new List;
    if (top(list) == 0 and
            list->size == 0 and
            list->first == nullptr)
    {
        cout << "PASS \t: top {}" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: top {}" << endl;
        failed++;
    }
    delete list;
    cout << "Totals: " << pass << " passed, " << failed << " failed" << endl;
    cout << "********* Finished testing of top *********" << endl;
}


/*
 * Tests
 * Liste 1, 2, 3 -> liste 2, 3 taille = 2
 * Liste 1 -> liste vide, taille 0
 * Liste vide -> liste vide, taille = 0
 */
void test_pop()
{
    int pass = 0;
    int failed = 0;
    cout << "********* Start testing of pop *********" << endl;
    List * list;
    list = new List;
    initList(list, 1, 2, 3);
    pop(list);
    if (list->size == 2 and
            list->first->value == 2 and
            list->first->next->value == 3 and
            list->first->next->next == nullptr)
    {
        cout << "PASS \t: pop {1,2,3}" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: pop {1,2,3}" << endl;
        failed++;
    }
    emptyList(list);
    delete list;
    list = new List;
    addElt(list, 1);
    pop(list);
    if (list->size == 0 and list->first == nullptr)
    {
        cout << "PASS \t: pop {1}" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: pop {1}" << endl;
        failed++;
    }
    delete list;
    list = new List;
    pop(list);
    if (list->size == 0 and list->first == nullptr)
    {
        cout << "PASS \t: pop {}" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: pop {}" << endl;
        failed++;
    }
    delete list;
    cout << "Totals: " << pass << " passed, " << failed << " failed" << endl;
    cout << "********* Finished testing of pop *********" << endl;
}


/*
 * Tests
 * Une liste vide, valeur 35 -> liste 35 et taille = 1
 * Liste 2, 4 et 6, valeur 1 -> liste 1, 2, 4, 6 et taille = 4
 * Liste 2, 4 et 6, valeur 3 -> liste 2, 3, 4, 6 et taille = 4
 * Liste 2, 4 et 6, valeur 5 -> liste 2, 4, 5, 6 et taille = 4
 * Liste 2, 4 et 6, valeur 7 -> liste 2, 4, 6, 7 et taille = 4
 */
void test_insert()
{
    int pass = 0;
    int failed = 0;
    cout << "********* Start testing of insert *********" << endl;
    List * list;
    Element * elt;
    list = new List;
    elt = new Element;
    elt->value = 35;
    insert(list, elt);
    if (list->first->value == 35 and
            list->size == 1 and
            list->first->next == nullptr)
    {
        cout << "PASS \t: insert 35 in {}" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: insert 35 in {}" << endl;
        failed++;
    }
    emptyList(list);
    delete list;
    list = new List;
    elt = new Element;
    elt->value = 1;
    initList(list, 2, 4, 6);
    insert(list, elt);
    if (list->size == 4 and
            list->first->value == 1 and
            list->first->next->value == 2 and
            list->first->next->next->value == 4 and
            list->first->next->next->next->value == 6 and
            list->first->next->next->next->next == nullptr)
    {
        cout << "PASS \t: insert 1 in {2,4,6}" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: insert 1 in {2,4,6}" << endl;
        failed++;
    }
    emptyList(list);
    delete list;
    list = new List;
    elt = new Element;
    elt->value = 3;
    initList(list, 2, 4, 6);
    insert(list, elt);
    if (list->size == 4 and
            list->first->value == 2 and
            list->first->next->value == 3 and
            list->first->next->next->value == 4 and
            list->first->next->next->next->value == 6 and
            list->first->next->next->next->next == nullptr)
    {
        cout << "PASS \t: insert 3 in {2,4,6}" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: insert 3 in {2,4,6}" << endl;
        failed++;
    }
    emptyList(list);
    delete list;
    list = new List;
    elt = new Element;
    elt->value = 5;
    initList(list, 2, 4, 6);
    insert(list, elt);
    if (list->size == 4 and
            list->first->value == 2 and
            list->first->next->value == 4 and
            list->first->next->next->value == 5 and
            list->first->next->next->next->value == 6 and
            list->first->next->next->next->next == nullptr)
    {
        cout << "PASS \t: insert 5 in {2,4,6}" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: insert 5 in {2,4,6}" << endl;
        failed++;
    }
    emptyList(list);
    delete list;
    list = new List;
    elt = new Element;
    elt->value = 7;
    initList(list, 2, 4, 6);
    insert(list, elt);
    if (list->size == 4 and
            list->first->value == 2 and
            list->first->next->value == 4 and
            list->first->next->next->value == 6 and
            list->first->next->next->next->value == 7 and
            list->first->next->next->next->next == nullptr)
    {
        cout << "PASS \t: insert 7 in {2,4,6}" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: insert 7 in {2,4,6}" << endl;
        failed++;
    }
    emptyList(list);
    delete list;
    cout << "Totals: " << pass << " passed, " << failed << " failed" << endl;
    cout << "********* Finished testing of insert *********" << endl;
}


/*
 * Tests
 * Liste 1, 2 et 3 et voir affichage
 */
void test_displayList()
{

    cout << "********* Start testing of displayList *********" << endl;
    cout << "Test d'affichage d'une liste {1, 2, 3} :" << endl;
    List * list;
    list = new List;
    initList(list, 1, 2, 3);
    displayList(list);
    emptyList(list);
    delete list;
    cout << "\nTest d'afichage d'une liste vide :" << endl;
    list = new List;
    initList(list, 1, 2, 3);
    pop(list);
    pop(list);
    pop(list);
    displayList(list);
    delete list;
    cout << "********* Finished testing of displayList *********" << endl;
}


/*
 * Tests
 * Une liste vide, valeur 31 -> la taille = 0
 * Une liste 1, 2, 3 valeur 17 -> la taille = 3
 * Une liste 1, 2, 3 valeur 1 -> la taille = 2, liste = 2, 3
 * Une liste 1, 2, 3 valeur 2 -> la taille = 2, liste 1, 3
 * Une liste 1, 2, 3 valeur 3 -> la taille = 2, liste 1, 2
 */
void test_remove()
{
    int pass = 0;
    int failed = 0;
    cout << "********* Start testing of remove *********" << endl;
    List * list;
    list = new List;
    remove(list, 31);
    if (list->size == 0)
    {
        cout << "PASS \t: remove 31 form {}" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: remove 31 form {}" << endl;
        failed++;
    }
    delete list;
    list = new List;
    initList(list, 1, 2, 3);
    remove(list, 17);
    if (list->size == 3)
    {
        cout << "PASS \t: remove 17 from {1,2,3}" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: remove 17 from {1,2,3}" << endl;
        failed++;
    }
    emptyList(list);
    delete list;
    list = new List;
    initList(list, 1, 2, 3);
    remove(list, 1);
    if (list->size == 2 and
            list->first->value == 2 and
            list->first->next->value == 3 and
            list->first->next->next == nullptr)
    {
        cout << "PASS \t: remove 1 from {1,2,3}" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: remove 1 from {1,2,3}" << endl;
        failed++;
    }
    emptyList(list);
    delete list;
    list = new List;
    initList(list, 1, 2, 3);
    remove(list, 2);
    if (list->size == 2 and
            list->first->value == 1 and
            list->first->next->value == 3 and
            list->first->next->next == nullptr)
    {
        cout << "PASS \t: remove 2 from {1,2,3}" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: remove 2 from {1,2,3}" << endl;
        failed++;
    }
    emptyList(list);
    delete list;
    list = new List;
    initList(list, 1, 2, 3);
    remove(list, 3);
    if (list->size == 2 and
            list->first->value == 1 and
            list->first->next->value == 2 and
            list->first->next->next == nullptr)
    {
        cout << "PASS \t: remove 3 from {1,2,3}" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: remove 3 from {1,2,3}" << endl;
        failed++;
    }
    emptyList(list);
    delete list;
    cout << "Totals: " << pass << " passed, " << failed << " failed" << endl;
    cout << "********* Finished testing of remove *********" << endl;
}

/*
 * Tests
 * min(3, 99) -> 3
 * min(76, 17) -> 17
 * min(27, 27) -> 27 (pas possible de tester le premier 27)
 */
void test_min()
{
    int pass = 0;
    int failed = 0;
    cout << "********* Start testing of min *********" << endl;
    if (min(3, 99) == 3)
    {
        cout << "PASS \t: min(3, 99)" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: min(3, 99)" << endl;
        failed++;
    }
    if (min(76, 17) == 17)
    {
        cout << "PASS \t: min(76, 17)" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: min(76, 17)" << endl;
        failed++;
    }
    if (min(27, 27) == 27)
    {
        cout << "PASS \t: min(27, 27)" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: min(27, 27)" << endl;
        failed++;
    }
    cout << "Totals: " << pass << " passed, " << failed << " failed" << endl;
    cout << "********* Finished testing of min *********" << endl;
}

/*
 * Utility functions for The Game
 */

/*
 * Tests
 * liste 1, 2 et 3, carte 5 -> top = 5 size = 4
 * liste vide carte 5 -> top = 5 size = 1
 */
void test_putACard()
{
    int pass = 0;
    int failed = 0;
    List * fundation;
    cout << "********* Start testing of putACard *********" << endl;
    fundation = new List;
    initList(fundation, 1, 2, 3);
    putACard(fundation, 5);
    if (fundation->first->value == 5 and fundation->size == 4)
    {
        cout << "PASS \t: add 5 on {1,2,3}" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: add 5 on {1,2,3}" << endl;
        failed++;
    }
    emptyList(fundation);
    delete fundation;
    fundation = new List;
    putACard(fundation, 5);
    if (fundation->first->value == 5 and fundation->size == 1)
    {
        cout << "PASS \t: add 5 on {}" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: add 5 on {}" << endl;
        failed++;
    }
    cout << "Totals: " << pass << " passed, " << failed << " failed" << endl;
    cout << "********* Finished testing of putACard *********" << endl;
    delete fundation;
}


/*
 * Tests
 * shuffle une liste -> taille = 98
 * shuffle deux listes et compter les différences -> >0
 */
void test_shuffle()
{
    int pass = 0;
    int failed = 0;
    List * stockA;
    List * stockB;
    stockA = new List;
    stockB = new List;
    cout << "********* Start testing of shuffle *********" << endl;
    shuffle(stockA);
    if (stockA->size == 98)
    {
        cout << "PASS \t: shuffle size 98" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: shuffle size 98" << endl;
        failed++;
    }
    shuffle(stockB);
    int diff = 0;
    Element * eltA = stockA->first;
    Element * eltB = stockB->first;
    for (; eltA != nullptr and eltB != nullptr ; eltA = eltA->next, eltB = eltB->next)
    {
        if (eltA->value != eltB->value)
        {
            diff++;
        }
    }
    delete eltA;
    delete eltB;
    if (diff > 0)
    {
        cout << "PASS \t: shuffle diff (" << diff << ")" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: shuffle diff (" << diff << ")" << endl;
        failed++;
    }
    cout << "Totals: " << pass << " passed, " << failed << " failed" << endl;
    cout << "********* Finished testing of shuffle *********" << endl;
    emptyList(stockA);
    emptyList(stockB);
    delete stockA;
    delete stockB;
}

/*
 * Tests
 * Liste contenant 17, carte = 18 -> true et top = 18
 * Liste contenant 17, carte = 16 -> false et top = 17
 * Liste contenant 17, carte = 7 -> true et top = 7
 */
void test_moveUp()
{
    int pass = 0;
    int failed = 0;
    List * fundation;
    fundation = new List;
    cout << "********* Start testing of moveUp *********" << endl;
    addElt(fundation, 17);
    if (moveUp(fundation, 18) and top(fundation) == 18)
    {
        cout << "PASS \t: Put 18 on 17" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: Put 18 on 17" << endl;
        failed++;
    }
    addElt(fundation, 17);
    if (!moveUp(fundation, 16) and top(fundation) == 17)
    {
        cout << "PASS \t: Put 16 on 17" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: Put 16 on 17" << endl;
        failed++;
    }
    addElt(fundation, 17);
    if (moveUp(fundation, 7) and top(fundation) == 7)
    {
        cout << "PASS \t: Put 7 on 17" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: Put 7 on 17" << endl;
        failed++;
    }
    cout << "Totals: " << pass << " passed, " << failed << " failed" << endl;
    cout << "********* Finished testing of moveUp *********" << endl;
    emptyList(fundation);
    delete fundation;
}


/*
 * Tests
 * Liste contenant 56, carte = 55 -> true et top = 55
 * Liste contenant 56, carte = 57 -> false et top = 56
 * Liste contenant 56, carte = 66 -> true et top = 66
 */
void test_moveDown()
{
    int pass = 0;
    int failed = 0;
    List * fundation;
    fundation = new List;
    addElt(fundation, 56);
    cout << "********* Start testing of moveDown *********" << endl;
    if (moveDown(fundation, 55) and top(fundation) == 55)
    {
        cout << "PASS \t: Put 55 on 56" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: Put 55 on 56" << endl;
        failed++;
    }
    addElt(fundation, 56);
    if (!moveDown(fundation, 57) and top(fundation) == 56)
    {
        cout << "PASS \t: Put 57 on 56" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: Put 57 on 56" << endl;
        failed++;
    }
    addElt(fundation, 56);
    if (moveDown(fundation, 66) and top(fundation) == 66)
    {
        cout << "PASS \t: Put 66 on 56" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: Put 66 on 56" << endl;
        failed++;
    }
    cout << "Totals: " << pass << " passed, " << failed << " failed" << endl;
    cout << "********* Finished testing of moveDown *********" << endl;
    emptyList(fundation);
    delete fundation;
}


/*
 * Tests
 * Exécuter play, saisir 72 et C et voir valeur de retour -> 72 et C
 * Exécuter play, saisir 1 et C et voir valeur de retour -> ne doit pas être possible de saisir 1
 * Exécuter play, saisir 72 et R et voir valeur de retour -> ne doit pas être possible de saisir R
 */
void test_play()
{
    Player player;
    player.name = "test" ;
    int pass = 0;
    int failed = 0;
    cout << "********* Start testing of play *********" << endl;
    int nb;
    char c;
    cout << "saisir 72 puis C" << endl;
    play(nb, c, player);
    if (nb == 72 and c == 'C')
    {
        cout << "PASS \t: 72 et C" << endl << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: 72 et C" << endl;
        failed++;
    }
    cout << "saisir 2 puis D" << endl;
    play(nb, c, player);
    if (nb == 2 and c == 'D')
    {
        cout << "PASS \t: 1 et C" << endl << endl ;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: 1 et C" << endl;
        failed++;
    }
    cout << "saisir 15 puis A" << endl;
    play(nb, c, player);
    if (nb == 15 and c == 'A')
    {
        cout << "PASS \t: 15 et A" << endl << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: 15 et A" << endl;
        failed++;
    }
    cout << "Totals: " << pass << " passed, " << failed << " failed" << endl;
    cout << "********* Finished testing of play *********" << endl;
}

/*
 * Tests
 * 1, 2 et 3 dans la main et value 3 -> true
 * 1, 2 et 3 dans la main et value 2 -> true
 * 1, 2 et 3 dans la main et value 1 -> true
 * 1, 2 et 3 dans la main et value 4 -> false
 * main vide et value 7 -> false
 */
void test_isValid()
{
    int pass = 0;
    int failed = 0;
    List * hand;
    hand = new List;
    initList(hand, 1, 2, 3);
    cout << "********* Start testing of isValid *********" << endl;
    for (int i = 1; i < 4; i++)
    {
        if (isValid(hand, i))
        {
            cout << "PASS \t: "<< i <<" in {1,2,3}" << endl;
            pass++;
        }
        else
        {
            cout << "FAIL! \t: "<< i << " in {1,2,3}" << endl;
            failed++;
        }
    }
    if (!isValid(hand, 4))
    {
        cout << "PASS \t: 4 in {1,2,3}" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: 4 in {1,2,3}" << endl;
        failed++;
    }
    cout << "Totals: " << pass << " passed, " << failed << " failed" << endl;
    cout << "********* Finished testing of isValid *********" << endl;
    emptyList(hand);
    delete hand;
}

/*
 * Tests
 * Require shuffle, insert, top and pop
 * listes vides -> 0
 * état initial du jeu -> 4 949
 * une liste avec 1, 2 et 3 et une avec 4, 5, 6 -> 21
 */
void test_score()
{
    int pass = 0;
    int failed = 0;
    List * stock;
    List * hand;
    ListPlayers* gamePlayers = nullptr ;
    cout << "********* Start testing of score *********" << endl;
    stock = new List;
    hand = new List;
    if (score(hand, stock, gamePlayers) == 0)
    {
        cout << "PASS \t: Listes vides" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: Listes vides" << endl;
        failed++;
    }
    shuffle(stock);
    for (int i=0; i<8; i++)
    {
        Element * elt;
        elt = new Element;
        elt->value = top(stock);
        insert(hand, elt);
        pop(stock);
    }
    if (score(hand, stock, gamePlayers) == 4949)
    {
        cout << "PASS \t: Début de partie" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: Début de partie" << endl;
        failed++;
    }
    emptyList(stock);
    emptyList(hand);
    delete stock;
    delete hand;
    stock = new List;
    hand = new List;
    initList(stock, 1, 2, 3);
    initList(hand, 4, 5, 6);
    if (score(hand, stock, gamePlayers) == 21)
    {
        cout << "PASS \t: stock {1,2,3} hand {4,5,6}" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: stock {1,2,3} hand {4,5,6}" << endl;
        failed++;
    }
    emptyList(stock);
    emptyList(hand);
    cout << "Totals: " << pass << " passed, " << failed << " failed" << endl;
    cout << "********* Finished testing of score *********" << endl;
    delete stock;
    delete hand;
}

void test_timeShuffle() {

    List * list = new List;

    //list = List();
    auto start = chrono::high_resolution_clock::now();
    shuffleMaxiOpti(list);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "ShuffleMaxiOpti : " << duration.count() << " microsecondes" << endl;

    delete(list);
    list = new List;

    //list = List();
    start = chrono::high_resolution_clock::now();
    shuffleOpti(list);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "ShuffleOpti : " << duration.count() << " microsecondes" << endl;

    delete(list);
    list = new List;

    start = chrono::high_resolution_clock::now();
    shuffle(list);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Shuffle : " << duration.count() << " microsecondes" << endl;

    delete(list);
}

void test_timeRemove()
{
    List * list = new List;
    shuffleOpti(list);
    auto start = chrono::high_resolution_clock::now();
    remove(list, 50);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Remove : " << duration.count() << " microsecondes" << endl;
    delete(list);
    list = new List ;
    shuffleOpti(list);
    start = chrono::high_resolution_clock::now();
    removeOpti(list, 50);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "removeOpti : " << duration.count() << " microsecondes" << endl;
    delete(list);
}




#include <iostream>
#include "matrix.h"

using namespace std;

void initializeMatrix(int Matrix[][SIZE])
{
    int Coord ;

    for (int i=0 ; i < SIZE ; i++)
    {
        for (int j=0 ; j < SIZE ; j++)
        {

            cout << "Coordonees (" << i << ", " << j << ") de la matrice : " ;
            cin >> Coord ;
            cout << endl ;
            Matrix[i][j] = Coord ;
        }

        cout << endl ;

    } ;

} ;

void displayMatrix(int Matrix[][SIZE])
{
    cout << "Matrice A : " << endl ;

    for (int i=0 ; i < SIZE ; i++)
    {
        cout << "[ " ;
        for (int j=0 ; j < SIZE ; j++)
        {
            cout << Matrix[i][j] << " " ;
        }
        cout << "]" << endl ;

    } ;

} ;

void sumTriangSup(int Matrix[][SIZE])
{
    int sum = 0 ;

    for (int i=0 ; i < SIZE ; i++)
    {

        for (int j=i ; j < SIZE ; j++)
        {
            sum = sum + Matrix[i][j] ;
        }

    } ;

    cout << endl << "La somme du triangle superieur est : " << sum << endl << endl ;
} ;

void transpoMatrix(int Matrix[][SIZE])
{

    cout << "Transpose de la matrice A : " << endl ;

    //Afficher la transposé
    for (int i=0 ; i < SIZE ; i++)
    {
        cout << "[ " ;
        for (int j=0 ; j < SIZE ; j++)
        {
            cout << Matrix[j][i] << " " ;
        }
        cout << "]" << endl ;

    } ;

}

void isSymmetrical(int Matrix[][SIZE])
{

} ;

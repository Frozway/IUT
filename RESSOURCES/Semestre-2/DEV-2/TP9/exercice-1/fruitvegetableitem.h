#ifndef FRUITVEGETABLEITEM_H
#define FRUITVEGETABLEITEM_H
#include "article.h"
#include <iostream>

using namespace std ;

///
/// \brief The FruitVegetableItem class
/// Detailed description of the Article class
/// \author Lefrancois
/// \version 0.1
/// \date April 2023
/// \copyright GNU Public License
///

class FruitVegetableItem : public Article
{
private:
    double itsStockKg ;
    double itsTotalKg ;
public:
    FruitVegetableItem(string name, string vendor, double purchasePrice, double sellingPrice);
    double fillStock(double kg);
    double sell(double sell);
    double benefice();
    void display();
};

#endif // FRUITVEGETABLEITEM_H

#ifndef ELECTRICALAPPLIANCE_H
#define ELECTRICALAPPLIANCE_H
#include "article.h"
#include <iostream>

using namespace std ;

///
/// \brief The ElectricalAppliance class
/// Detailed description of the Article class
/// \author Lefrancois
/// \version 0.1
/// \date April 2023
/// \copyright GNU Public License
///

class ElectricalAppliance: public Article
{
private:
    int itsStockNb ;
    int itsTotalNb ;
public:
    ElectricalAppliance(string name, string vendor, double purchasePrice, double sellingPrice);
    double fillStock(int nb) ;
    double sell(int nb);
    void display();
};

#endif // ELECTRICALAPPLIANCE_H

#ifndef ARTICLE_H
#define ARTICLE_H

#include <iostream>

using namespace std;

///
/// \brief The Article class
/// Detailed description of the Article class
/// \author Lefrancois
/// \version 0.1
/// \date April 2023
/// \copyright GNU Public License
///

class Article
{
private:
    string itsName ;
    string itsVendor ;

protected:
    double itsPurchasePrice ;
    double itsSellingPrice ;
    double itsBeneficePerUnit ;

public:
    Article(string name, string vendor, double purchasePrice, double sellingPrice);
    virtual double benefice() = 0 ;
    virtual void display();
};

#endif // ARTICLE_H

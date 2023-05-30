#ifndef ARTICLE_H
#define ARTICLE_H

#include <iostream>

using namespace std;


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

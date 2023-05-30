#include "product.h"

int Product::getItsCode() const
{
    return itsCode;
}

string Product::getItsName() const
{
    return itsName;
}

string Product::getItsBrand() const
{
    return itsBrand;
}

double Product::getItsPrice() const
{
    return itsPrice;
}

Product::Product(int code, string name, string brand, double price)
{
    itsCode = code ;
    itsName = name ;
    itsBrand = brand ;
    itsPrice = price ;
}


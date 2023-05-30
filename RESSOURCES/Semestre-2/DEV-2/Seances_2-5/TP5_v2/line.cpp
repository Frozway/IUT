#include "line.h"

int Line::getItsQuantity() const
{
    return itsQuantity;
}

void Line::setItsQuantity(int newItsQuantity)
{
    itsQuantity = newItsQuantity;
}

Product * Line::getItsProduct() const
{
    return itsProduct;
}

Line::Line(int quantity, Product * product)
{
    itsQuantity = quantity ;
    itsProduct = product ;
}

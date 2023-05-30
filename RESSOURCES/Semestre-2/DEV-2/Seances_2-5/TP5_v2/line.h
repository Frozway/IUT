#ifndef LINE_H
#define LINE_H

#include "product.h"

class Line
{
private:
    int itsQuantity ;
    Product * itsProduct ;
public:
    Line(int quantity, Product * product);
    int getItsQuantity() const;
    void setItsQuantity(int quantity);
    Product * getItsProduct() const;
    void display();
};

#endif // LINE_H

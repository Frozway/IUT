#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include "address.h"
#include "line.h"
#include "product.h"
#include <vector>

using namespace std ;

class Order
{
private:
    static int itsNbOrders ;
    int itsNo ;
    double itsPrice ;
    string itsDate ;
    Address * itsDeliveryAddress ;
    vector<Line>* itsLines ;

public:
    Order(string date, Address * deliveryAddress);
    ~Order();
    int getItsNo() const;
    double getItsPrice() const;
    string getItsDate() const;
    void addLine(int quantity, Product * product);
    void removeLine(Product * product);
    void modifyLine(int quantity, Product * product);
    void display();
};

#endif // ORDER_H

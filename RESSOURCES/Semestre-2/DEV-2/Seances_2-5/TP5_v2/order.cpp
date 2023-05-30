#include "order.h"

int Order::itsNbOrders = 0 ;

int Order::getItsNo() const
{
    return itsNo;
}

double Order::getItsPrice() const
{
    return itsPrice;
}

string Order::getItsDate() const
{
    return itsDate;
}

Order::Order(string date, Address * deliveryAddress)
{
    itsDate = date ;
    itsDeliveryAddress = deliveryAddress ;
    itsLines = new vector<Line> ;
}

Order::~Order()
{
    delete itsLines ;
}

void Order::addLine(int quantity, Product * product)
{
    itsLines->push_back(Line(quantity, product));
}

void Order::removeLine(Product * product)
{
    for (auto it = itsLines->begin(); it != itsLines->end(); ++it)
    {
        if (it->getItsProduct() == product)
        {
            itsLines->erase(it);
        }
    }
}

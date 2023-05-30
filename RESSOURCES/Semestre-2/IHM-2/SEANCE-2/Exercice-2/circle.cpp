#include "circle.h"

Circle::Circle()
{
    itsDiameter = 0.;
}

Circle::Circle(double aDiameter)
{
    itsDiameter = aDiameter;
}

void Circle::setDiameter(double aDiameter)
{
    itsDiameter = aDiameter;
}

double Circle::calculatePerimeter()
{
    return PI * itsDiameter;
}

double Circle::calculateArea()
{
    return PI * itsDiameter * itsDiameter / 4.0;
}

#ifndef CIRCLE_H
#define CIRCLE_H

#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>

class Circle
{
public:
    Circle();
    Circle(double aDiameter);
    void setDiameter(double aDiameter);
    double calculatePerimeter();
    double calculateArea();

private:
    const double PI = 3.14159265;
    double itsDiameter;
};



#endif // CIRCLE_H

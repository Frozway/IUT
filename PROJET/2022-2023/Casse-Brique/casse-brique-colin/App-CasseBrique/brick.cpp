#include "brick.h"

Brick::Brick(int x, int y)
{
    itsX = x;
    itsY = y;
    destroyed = 0;

    itsBrick = QRect(itsX, itsY, 75, 15);
}

void Brick::destroy()
{
    destroyed = 1;
}

bool Brick::isDestroyed()
{
    return destroyed;
}

QRect Brick::getBrick()
{
    return itsBrick;
}

void Brick::draw(QPainter *aPainter)
{
    itsBrick.moveTo(itsX, itsY);
    aPainter->setPen(Qt::green);
    QBrush b;
    b.setColor(Qt::green);
    b.setStyle(Qt::SolidPattern);
    aPainter->setBrush(b);
    aPainter->drawRect(itsBrick);
}

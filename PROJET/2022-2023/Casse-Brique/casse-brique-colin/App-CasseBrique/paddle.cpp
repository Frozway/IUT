#include "paddle.h"

Paddle::Paddle()
{
    itsX = 200-36;
    itsY= 565;
    itsHeight=15;
    itsWidth= 70;
    itsSpeed=0;

    itsRect = QRect(itsX, itsY, itsWidth, itsHeight);
}

void Paddle::setSpeed(int aSpeed)
{
    itsSpeed = aSpeed;
}

void Paddle::calculatePosition()
{
    if(itsX > 0 && itsX+itsWidth < 400)
    {
        itsX += itsSpeed;
    }
    else if(itsX == 0)
    {
        itsX += 2;
    }
    else if(itsX+itsWidth == 400)
    {
        itsX -= 2;
    }
}

void Paddle::draw(QPainter *aPainter)
{
    itsRect.moveTo(itsX + itsSpeed, itsY);
    aPainter->setPen(Qt::blue);
    QBrush b;
    b.setColor(Qt::blue);
    b.setStyle(Qt::SolidPattern);
    aPainter->setBrush(b);
    aPainter->drawRect(itsRect);
}

QRect Paddle::getRect()
{
    return itsRect;
}

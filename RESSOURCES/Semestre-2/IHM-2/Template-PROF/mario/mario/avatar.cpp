#include "avatar.h"

Avatar::Avatar()
{
    itsX = 150;
    itsY = 300;
    itsWidth = 20;
    itsHeight = 50;
    itsXSpeed = 0;
    itsYSpeed = 0;
    itsJump = 0;

    itsAvatar.setX(itsX);
    itsAvatar.setY(itsY);
    itsAvatar.setWidth(itsWidth);
    itsAvatar.setHeight(itsHeight);
}

void Avatar::setXSpeed(int aSpeed)
{
    itsXSpeed = aSpeed;
}

void Avatar::setYSpeed(int aSpeed)
{
    itsYSpeed = aSpeed;
}

#include <QtDebug>

void Avatar::calculatePosition()
{
    if (itsJump > 50)
    {
        itsYSpeed = -1;
        itsJump--;
    }
    else
    {
        if (itsJump > 0)
        {
            itsYSpeed = 1;
            itsJump--;
        }
    }
    itsX = itsX + itsXSpeed;
    itsY = itsY + itsYSpeed;
    if (itsY >= 300)
    {
        itsY = 300;
        itsYSpeed = 0;
        itsJump = 0;
    }
//    qDebug() << itsY << ":" << itsYSpeed << ":" << itsJump;
}

void Avatar::draw(QPainter *aPainter)
{
    itsAvatar.moveTo(itsX, itsY);
    aPainter->setPen(Qt::blue);
    aPainter->setBrush(Qt::SolidPattern);
    aPainter->drawRect(itsAvatar);
}

QRect Avatar::getRect()
{
    return itsAvatar;
}

int Avatar::getX()
{
    return itsX;
}

void Avatar::jump()
{
    itsJump = 100;
}

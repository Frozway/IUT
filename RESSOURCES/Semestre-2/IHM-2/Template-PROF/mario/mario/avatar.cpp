#include "avatar.h"

Avatar::Avatar()
{
    itsX = 150;
    itsY = 720; // Hauteur du widget - hauteur de l'avatar
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
    if (itsY >= 720)
    {
        itsY = 720;
        itsYSpeed = 0;
        itsJump = 0;
    }
//    qDebug() << itsY << ":" << itsYSpeed << ":" << itsJump;
}

void Avatar::draw(QPainter *aPainter, int cameraX, int cameraY) // Ajout de la position de la caméra sur l'axe Y
{
    itsAvatar.moveTo(itsX - cameraX, itsY - cameraY); // Soustraire la position de la caméra sur l'axe Y
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

int Avatar::getY()
{
    return itsY;
}

void Avatar::jump()
{
    itsJump = 100;
}

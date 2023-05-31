#include "obstacle.h"

Obstacle::Obstacle(int x, int y)
{
    itsX = x;
    itsY = y;

    itsObstacle.setX(itsX);
    itsObstacle.setY(itsY);
    itsObstacle.setWidth(20);
    itsObstacle.setHeight(20);
}

void Obstacle::draw(QPainter * aPainter, int cameraX, int cameraY) // Ajout de la position de la caméra sur l'axe Y
{
    itsObstacle.moveTo(itsX - cameraX, itsY - cameraY); // Soustraire la position de la caméra sur l'axe Y
    aPainter->setPen(Qt::red);
    aPainter->setBrush(Qt::SolidPattern);
    aPainter->drawRect(itsObstacle);
}

QRect Obstacle::getRect()
{
    return itsObstacle;
}

void Obstacle::calculatePosition(int speed)
{
    itsX = itsX + speed;
}

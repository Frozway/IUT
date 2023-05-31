#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QPainter>
#include <QRect>

class Obstacle
{
public:
    Obstacle(int x, int y);
    void draw(QPainter * aPainter, int cameraX, int cameraY); // Ajout de la position de la caméra
    QRect getRect();
    void calculatePosition(int speed);

private:
    QRect itsObstacle;
    int itsX;
    int itsY;
};

#endif // OBSTACLE_H

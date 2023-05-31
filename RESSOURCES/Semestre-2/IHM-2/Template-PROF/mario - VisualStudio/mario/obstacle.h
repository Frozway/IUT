#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QPainter>
#include <QRect>

class Obstacle
{
public:
    Obstacle(int x, int y);
    void draw(QPainter * painter);
    QRect getRect();
    void calculatePosition(int speed);

private:
    int itsX;
    int itsY;
    QRect itsObstacle;
};

#endif // OBSTACLE_H

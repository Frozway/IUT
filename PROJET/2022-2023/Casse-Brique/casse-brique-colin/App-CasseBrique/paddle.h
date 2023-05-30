#ifndef PADDLE_H
#define PADDLE_H

#include <QRect>
#include <QPainter>

class Paddle
{
private:
    int itsX;
    int itsY;
    int itsWidth;
    int itsHeight;
    int itsSpeed;
    QRect itsRect;
public:
    Paddle();
    void setSpeed(int aSpeed);
    void calculatePosition();
    void draw(QPainter *aPainter);
    QRect getRect();
};

#endif // PADDLE_H

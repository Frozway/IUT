#ifndef BALL_H
#define BALL_H

#include <QRect>
#include <QImage>
#include <QPainter>

class Ball
{
private:
    int itsX;
    int itsY;
    int itsDiameter;
    int itsXSpeed;
    int itsYSpeed;
    QImage itsImage;
public:
    Ball();
    void setXSpeed(int aSpeed);
    void setYSpeed(int aSpeed);
    void calculatePosition();
    void draw(QPainter *aPainter);
    void reverseXSpeed();
    void reverseYSpeed();
    bool intersect(QRect anObstacle);
};

#endif // BALL_H

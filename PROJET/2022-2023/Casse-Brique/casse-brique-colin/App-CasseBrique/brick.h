#ifndef BRICK_H
#define BRICK_H

#include <QRect>
#include <QPainter>

class Brick
{
private :
    int itsX;
    int itsY;
    bool destroyed;
    QRect itsBrick;
public:
    Brick(int x, int y);
    void destroy();
    bool isDestroyed();
    QRect getBrick();
    void draw(QPainter *aPainter);
};

#endif // BRICK_H

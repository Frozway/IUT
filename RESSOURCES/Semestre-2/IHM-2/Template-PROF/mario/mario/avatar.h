#ifndef AVATAR_H
#define AVATAR_H

#include <QPainter>
#include <QRect>

class Avatar
{
public:
    Avatar();
    void setXSpeed(int aSpeed);
    void setYSpeed(int aSpeed);
    void calculatePosition();
    void draw(QPainter *aPainter, int cameraX); // Ajout de la position de la caméra
    QRect getRect();
    int getX();
    void jump();

private:
    QRect itsAvatar;
    int itsX;
    int itsY;
    int itsWidth;
    int itsHeight;
    int itsXSpeed;
    int itsYSpeed;
    int itsJump;
};

#endif // AVATAR_H

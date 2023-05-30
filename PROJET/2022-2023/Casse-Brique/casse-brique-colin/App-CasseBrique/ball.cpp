#include "ball.h"

void Ball::setXSpeed(int aSpeed)
{
    itsXSpeed = aSpeed;
}

void Ball::setYSpeed(int aSpeed)
{
    itsYSpeed = aSpeed;
}

Ball::Ball()
{
    itsX = 200-8;
    itsY = 200;
    itsDiameter = 16;
    itsXSpeed = 1;
    itsYSpeed = 1;

    itsImage.load(":image/ball.png");
    itsImage = itsImage.scaled(QSize(itsDiameter, itsDiameter));
    Q_ASSERT(! itsImage.isNull());
}

void Ball::calculatePosition()
{
    itsX += itsXSpeed;
    itsY += itsYSpeed;
}

void Ball::draw(QPainter * aPainter)
{
    aPainter->drawImage(itsX , itsY , itsImage);
}

void Ball::reverseXSpeed()
{
    itsXSpeed *= -1;
}

void Ball::reverseYSpeed()
{
    itsYSpeed *= -1;
}

bool Ball::intersect(QRect anObstacle)
{
    QRect ballRectangle = QRect(itsX, itsY, itsDiameter, itsDiameter);
    return anObstacle.intersects(ballRectangle);
}

#include "widget.h"

#include <QKeyEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    itsAvatar = new Avatar();

    itsObstacles.push_back(new Obstacle(50, 720)); // Hauteur du widget - hauteur de l'obstacle
    itsObstacles.push_back(new Obstacle(350, 720)); // Hauteur du widget - hauteur de l'obstacle
    itsObstacles.push_back(new Obstacle(200, 720)); // Hauteur du widget - hauteur de l'obstacle
    itsObstacles.push_back(new Obstacle(100, 720)); // Hauteur du widget - hauteur de l'obstacle

    setFixedSize(1920, 1080);
    itsPosition = 0;
    itsSpeed = 0;
    itsCameraPositionX = 0; // Initialisation de la position de la caméra sur l'axe X
    itsCameraPositionY = 0; // Initialisation de la position de la caméra sur l'axe Y

    itsTimer = new QTimer(this);
    connect(itsTimer, SIGNAL(timeout()), this, SLOT(gameLoop()));
    itsTimer->start(10);
}


Widget::~Widget()
{
    itsTimer->stop();
}

#include <QtDebug>

void Widget::gameLoop()
{
    itsAvatar->setXSpeed(itsSpeed);
    itsAvatar->calculatePosition();

    if (itsAvatar->getX() > 960 && itsAvatar->getX() < 1920 - 960) // Si l'avatar est au milieu de l'écran sur l'axe X
    {
        itsCameraPositionX = itsAvatar->getX() - 960; // La caméra suit l'avatar
    }

    if (itsAvatar->getY() < 720 && itsAvatar->getY() > 1080 - 720) // Si l'avatar est au milieu de l'écran sur l'axe Y
    {
        itsCameraPositionY = itsAvatar->getY() - 720; // La caméra suit l'avatar
    }

    for (Obstacle* obs : itsObstacles)
    {
        obs->calculatePosition(-itsSpeed);
    }

    repaint();
}


void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter * painter = new QPainter(this);

    itsAvatar->draw(painter, itsCameraPositionX, itsCameraPositionY); // Passer la position de la caméra à la méthode draw

    for (Obstacle* obs : itsObstacles)
    {
        obs->draw(painter, itsCameraPositionX, itsCameraPositionY); // Passer la position de la caméra à la méthode draw
    }

    painter->end();
}

void Widget::keyPressEvent(QKeyEvent * event)
{
    if (event->key() == Qt::Key_Left)
    {
        itsSpeed = -1;
    }
    if (event->key() == Qt::Key_Right)
    {
        itsSpeed = 1;
    }
    if (event->key() == Qt::Key_Space)
    {
        itsAvatar->jump();
    }
}

void Widget::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left)
    {
        itsSpeed = 0;
    }
    if (event->key() == Qt::Key_Right)
    {
        itsSpeed = 0;
    }
}

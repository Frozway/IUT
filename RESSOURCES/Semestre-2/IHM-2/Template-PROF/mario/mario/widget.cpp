#include "widget.h"

#include <QKeyEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    itsAvatar = new Avatar();

    itsObstacles.push_back(new Obstacle(50, 330));
    itsObstacles.push_back(new Obstacle(350, 330));
    itsObstacles.push_back(new Obstacle(200, 330));
    itsObstacles.push_back(new Obstacle(100, 330));

    setFixedSize(300, 400);
    itsPosition = 0;
    itsSpeed = 0;
    itsCameraPosition = 0; // Initialisation de la position de la caméra

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
    float lerpSpeed = 0.1f; // Vitesse d'interpolation
    itsCameraPosition = itsCameraPosition + (itsAvatar->getX() - itsCameraPosition) * lerpSpeed;

    itsAvatar->setXSpeed(itsSpeed);
    itsAvatar->calculatePosition();
    itsPosition = itsAvatar->getX();

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

    itsAvatar->draw(painter, itsCameraPosition); // Passer la position de la caméra à la méthode draw

    for (Obstacle* obs : itsObstacles)
    {
        obs->draw(painter, itsCameraPosition); // Passer la position de la caméra à la méthode draw
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

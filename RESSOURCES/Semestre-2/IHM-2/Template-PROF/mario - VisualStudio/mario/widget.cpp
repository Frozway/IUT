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
    if (itsPosition <= 150)
    {
        itsAvatar->setXSpeed(itsSpeed);
        if (itsAvatar->getX() == 0)
        {
            itsAvatar->setXSpeed(1);
            itsAvatar->calculatePosition();
            itsAvatar->setXSpeed(0);
        }
        else
        {
                itsAvatar->calculatePosition();
        }
        itsPosition = itsAvatar->getX();
    }
    else
    {
        if (itsPosition >= 250)
        {
            itsAvatar->setXSpeed(itsSpeed);
            if (itsAvatar->getX() == 280)
            {
                itsAvatar->setXSpeed(-1);
                itsAvatar->calculatePosition();
                itsAvatar->setXSpeed(0);
            }
            else
            {
                itsAvatar->calculatePosition();
            }
            itsPosition = itsAvatar->getX() + 250 - 150;
        }
        else
        {
            itsPosition = itsPosition + itsSpeed;
            for (Obstacle* obs : itsObstacles)
            {
                obs->calculatePosition(-itsSpeed);
            }
            itsAvatar->setXSpeed(0);
            itsAvatar->calculatePosition();
        }
    }
//    qDebug() << itsPosition;
    repaint();
}


void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter * painter = new QPainter(this);

    itsAvatar->draw(painter);

    for (Obstacle* obs : itsObstacles)
    {
        obs->draw(painter);
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

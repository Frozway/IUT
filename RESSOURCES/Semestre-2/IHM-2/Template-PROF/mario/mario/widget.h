#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>

#include "avatar.h"
#include "obstacle.h"

#include <list>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void gameLoop();

private:
    void paintEvent(QPaintEvent * event);
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);

    QTimer * itsTimer;
    Avatar * itsAvatar;
    std::list<Obstacle *> itsObstacles;

    int itsCameraPositionX; // Position de la caméra sur l'axe X
    int itsCameraPositionY; // Position de la caméra sur l'axe Y

    int itsPosition;
    int itsSpeed;
};
#endif // WIDGET_H

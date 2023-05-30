#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QObject>
#include <QKeyEvent>
#include <QPaintEvent>
#include <list>

#include "paddle.h"
#include "ball.h"
#include "brick.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void gameloop();
    void start();

private:
    Ui::Widget *ui;
    Paddle *itsPaddle;
    Ball *itsBall;
    QTimer *itsTimer;
    list<Brick*> itsWall;
    void keyPressEvent (QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void paintEvent(QPaintEvent *event);
};
#endif // WIDGET_H

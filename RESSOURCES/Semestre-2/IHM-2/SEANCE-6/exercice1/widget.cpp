#include "widget.h"
#include "ui_widget.h"

#include <QKeyEvent>
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(gameLoop()));
    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(starter()));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::gameLoop()
{
    itsCounter += 1;
    ui->lcdTimeElapsed->display(itsCounter);
}


void Widget::starter()
{
    itsCounter = 0;
    ui->lcdTimeElapsed->display(itsCounter);
    timer->start(1000);
}

void Widget::keyPressEvent (QKeyEvent * event)
{
    if (event->key() == Qt::Key_P) {
    timer->stop(); }
}

void Widget::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_P) {
        timer->start(1000);
    }
}

void Widget::keyPressEvent2(QKeyEvent *event2)
{
    if (event2->key() == Qt::Key_I   ) {
        if (timer->isActive()) {
            timer->stop();
        } else {
            timer->start(1000);
        }
    }
}


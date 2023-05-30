#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    itsPaddle = new Paddle;
    itsBall = new Ball;

    itsTimer = new QTimer(this);
    connect(itsTimer, SIGNAL(timeout()), this, SLOT(gameloop()));
    start();

    itsWall.push_back(new Brick(20, 30));
    itsWall.push_back(new Brick(115, 30));
    itsWall.push_back(new Brick(210, 30));
    itsWall.push_back(new Brick(305, 30));

    itsWall.push_back(new Brick(20, 60));
    itsWall.push_back(new Brick(115, 60));
    itsWall.push_back(new Brick(210, 60));
    itsWall.push_back(new Brick(305, 60));

    itsWall.push_back(new Brick(20, 90));
    itsWall.push_back(new Brick(115, 90));
    itsWall.push_back(new Brick(210, 90));
    itsWall.push_back(new Brick(305, 90));

    itsWall.push_back(new Brick(20, 120));
    itsWall.push_back(new Brick(115, 120));
    itsWall.push_back(new Brick(210, 120));
    itsWall.push_back(new Brick(305, 120));

}

Widget::~Widget()
{
    for (std::list<Brick*>::iterator it = itsWall.begin(); it != itsWall.end(); ++it) {
        delete (*it);
    }
    delete itsBall;
    delete itsPaddle;
    delete itsTimer;
    delete ui;
}

void Widget::gameloop()
{
    itsPaddle->calculatePosition();
    // Collision avec la paddle
    if(itsBall->intersect(itsPaddle->getRect()))
    {
        itsBall->reverseYSpeed();
    }

    // Collision avec les deux murs
    if( (itsBall->intersect(QRect(0, 0, 1, 600))) || (itsBall->intersect(QRect(400, 0, 1, 600))))
    {
        itsBall->reverseXSpeed();
    }

    // Collision avec le plafond
    if(itsBall->intersect(QRect(0, 0, 400, 1)))
    {
        itsBall->reverseYSpeed();
    }

    // Collision avec le sol
    if(itsBall->intersect(QRect(0, 600, 400, 1)))
    {
        itsBall->setXSpeed(0);
        itsBall->setYSpeed(0);
    }

    //Collision avec une brique
    Brick * destroyedBall;
    for (std::list<Brick*>::iterator it = itsWall.begin(); it != itsWall.end(); ++it) {
        if(itsBall->intersect((*it)->getBrick()))
        {
            (*it)->destroy();
            destroyedBall = *it;
            itsBall->reverseYSpeed();
        }
    }
    itsWall.remove(destroyedBall);
    itsBall->calculatePosition();

    repaint();
}

void Widget::start()
{
    if(itsTimer->isActive())
    {
        itsTimer->stop();
    }
    else
    {
        itsTimer->start(5);
    }
}

void Widget::keyPressEvent (QKeyEvent * event)
{
    if (event->key() == Qt::Key_Left)
    {
        itsPaddle->setSpeed(-2);
    }
    else if(event->key() == Qt::Key_Right)
    {
        itsPaddle->setSpeed(2);
    }
}

void Widget::keyReleaseEvent (QKeyEvent * event)
{
    if ((event->key() == Qt::Key_Left) || event->key() == Qt::Key_Right)
    {
        itsPaddle->setSpeed(0);
    }
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter * painter = new QPainter(this);
    itsPaddle->draw(painter);
    itsBall->draw(painter);

    // Parcourir la liste avec un itérateur et accéder à chaque élément via son pointeur
    for (std::list<Brick*>::iterator it = itsWall.begin(); it != itsWall.end(); ++it) {
        if(!(*it)->isDestroyed())
        {
            (*it)->draw(painter);
        }
    }

    delete painter;
}

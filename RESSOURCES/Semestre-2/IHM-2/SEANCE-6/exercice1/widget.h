#ifndef WIDGET_H
#define WIDGET_H

#include "qtimer.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QTimer * timer ;
    int itsCounter ;
    void keyPressEvent (QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent *event);
    void keyPressEvent2(QKeyEvent *event2);

public slots:
    void gameLoop();
    void starter();

};
#endif // WIDGET_H

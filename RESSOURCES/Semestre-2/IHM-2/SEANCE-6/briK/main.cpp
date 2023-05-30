#include "mainwindow.h"
#include <QApplication>
#include <QLCDNumber>
#include <QTimer>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;

    QVBoxLayout *layout = new QVBoxLayout(&w);

    QLCDNumber *lcd = new QLCDNumber(&w);
    layout->addWidget(lcd);



    QObject::connect(timer, &QTimer::timeout, [&]() {
        timeElapsed += 1;
        lcd->display(timeElapsed);
    });

    timer->start(1000);

    w.show();
    return a.exec();
}

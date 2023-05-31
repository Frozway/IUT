#include "forma.h"
#include "ui_forma.h"

#include <QKeyEvent>

FormA::FormA(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormA)
{
    ui->setupUi(this);

    count = 24;
    ui->progressBar->setValue(count);
}

FormA::~FormA()
{
    delete ui;
}

void FormA::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_J)
    {
        count++;
        ui->progressBar->setValue(count);
    }
}

#include "formb.h"
#include "ui_formb.h"

#include <QKeyEvent>

FormB::FormB(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormB)
{
    ui->setupUi(this);

    count = 0;
    ui->horizontalSlider->setValue(count);
}

FormB::~FormB()
{
    delete ui;
}

void FormB::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_J)
    {
        count++;
        ui->horizontalSlider->setValue(count);
    }
}

#include "widget.h"
#include "ui_widget.h"

#include "forma.h"
#include "formb.h"

#include <QKeyEvent>
#include <QStackedWidget>
#include <QComboBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    count = 0;
    ui->lcdNumber->display(count);

    FormA * fa = new FormA;
    FormB * fb = new FormB;

    ui->comboBox->addItem(tr("Page 1"));
    ui->comboBox->addItem(tr("Page 2"));

    stackedWidget = new QStackedWidget;
    stackedWidget->addWidget(fa);
    stackedWidget->addWidget(fb);

    ui->verticalLayout->addWidget(stackedWidget);

    // à commenter et décommenter
    connect(ui->comboBox, SIGNAL(activated(int)), this, SLOT(selectForm(int)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::selectForm(int index)
{
    stackedWidget->setCurrentIndex(index);
    stackedWidget->currentWidget()->setFocus();
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_J)
    {
        count++;
        ui->lcdNumber->display(count);
    }
}


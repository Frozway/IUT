#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::IHM)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QString firstname = ui->lineEdit->text();
    Person person;
    QString transformedName = person.transformName(firstname);
    ui->label->setText("Bonjour " + transformedName + "!");
}



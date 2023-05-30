#include "widget.h"
#include "ui_widget.h"
#include <iostream>

using namespace std;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::IHM)
{
    ui->setupUi(this);
    //connect(ui->button, SIGNAL(clicked()), this, SLOT(onAction()));
    //connect(ui->leFirstname, SIGNAL(textChanged(QString)), this, SLOT(onEditFirstname(QString)));
    //connect(ui->leName, SIGNAL(editingFinished()), this, SLOT(onEditName(ui->leName->text())));
//QObject::connect(leName, &QLineEdit::editingFinished, lPrintName, qOverload<>(&QLabel::clear));
    //connect(ui->leFirstname, SIGNAL(editingFinished()), this, SLOT(onEditFirstname(QString)));
    connect(ui->leFirstname, &QLineEdit::editingFinished, [this](){onEditFirstname(ui->lFirstname->text());});

}

Widget::~Widget()
{
    delete ui;
}

void Widget::onEditFirstname(const QString &aFirstname)
{
    qDebug() << "Déclenchement de onEditFirstname" ;
    itsPerson.setFirstname(aFirstname);
    ui->lPrintFirstname->setText(itsPerson.getItsFirstname());
}

void Widget::onEditName(const QString &aName)
{
    cout << "Déclenchement de onEditName";
    //itsPerson.setName(aName);
    ui->lPrintName->setText(itsPerson.getItsName());
}


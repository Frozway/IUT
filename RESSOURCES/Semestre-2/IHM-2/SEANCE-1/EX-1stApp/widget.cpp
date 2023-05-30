#include "widget.h"
#include "person.h"
#include "qpushbutton.h"
#include "ui_widget.h"

#include <QPushButton>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle ( "Mon premier programme" ) ;

    QGridLayout * gLayout = new QGridLayout();
    QLabel * lTitlte = new QLabel ("Veuillez saisir votre prénom");
    gLayout->addWidget(lTitlte, 0, 0, 1, 2);

    QLabel * lName = new QLabel ("Votre prénom : ");
    gLayout->addWidget(lName, 1, 0);

    leName = new QLineEdit("James");
    leName->selectAll();
    gLayout->addWidget(leName, 1, 1);

    lGreetings = new QLabel();
    gLayout->addWidget(lGreetings, 3, 0, 1, 2);

    setLayout(gLayout);

    QPushButton * button = new QPushButton("Validez");
    gLayout->addWidget(button, 2, 1);

    connect(button, &QPushButton::clicked,
            [this](){Person p;
            lGreetings->setText("Bonjour " + p.transformName(leName->text()));});

}

Widget::~Widget()
{
    delete ui;
}


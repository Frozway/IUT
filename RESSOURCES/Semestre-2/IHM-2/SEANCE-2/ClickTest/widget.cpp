#include "widget.h"
#include "ui_widget.h"



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


    lGreetings = new QLabel();
    gLayout->addWidget(lGreetings, 3, 0, 1, 2);



    QPushButton * button = new QPushButton("Cliquez");
    gLayout->addWidget(button, 2, 1);

    int click = 0 ;

    connect(button, &QPushButton::clicked,
            [this, &click](){
        click++ ;
        cout << click ;

    });

    setLayout(gLayout);
}

Widget::~Widget()
{
    delete ui;
}


#include "widget.h"
#include "qpushbutton.h"
#include "ui_widget.h"

#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    //, clickCount(0)
{
    ui->setupUi(this);
    setWindowTitle ("ClickCount") ;

    QGridLayout * gLayout = new QGridLayout();


    QPushButton * button = new QPushButton("Cliquez");
    QPushButton * reset = new QPushButton();
    reset->setText("Reset");
    gLayout->addWidget(button);
    gLayout->addWidget(reset) ;


    int clickCount = 0;
    setLayout(gLayout);

    connect(button, &QPushButton::clicked, [&clickCount]()
    {
        clickCount ++ ;
        cout << clickCount << endl;
        QMessageBox m ;
        m.setText(QString::number(clickCount)),
        m.exec();
    });

    connect(reset, &QPushButton::clicked, [&clickCount](){clickCount=0;});

}

Widget::~Widget()
{
    delete ui;
}


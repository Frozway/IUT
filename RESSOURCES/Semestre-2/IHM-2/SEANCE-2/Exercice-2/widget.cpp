#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , circle()
{
    ui->setupUi(this);
    setWindowTitle("Circle");

    QGridLayout *layout = new QGridLayout(this);
    setLayout(layout);

    titleLabel = new QLabel();
    titleLabel->setText("Veuillez saisir le diamètre");
    layout->addWidget(titleLabel, 0, 0, 1, 2);

    textLabel = new QLabel();
    textLabel->setText("Diamètre :");
    layout->addWidget(textLabel, 1, 0);

    diameterField = new QLineEdit();
    layout->addWidget(diameterField, 1, 1);

    perimeterButton = new QPushButton();
    perimeterButton->setText("Calculer le périmètre");
    layout->addWidget(perimeterButton, 2, 0);

    areaButton = new QPushButton();
    areaButton->setText("Calculer la surface");
    layout->addWidget(areaButton, 2, 1);

    resultLabel = new QLabel();
    layout->addWidget(resultLabel, 3, 0, 1, 2);

    connect(perimeterButton, &QPushButton::clicked, this, &Widget::calculatePerimeter);
    connect(areaButton, &QPushButton::clicked, this, &Widget::calculateArea);

}

void Widget::calculatePerimeter()
{
    bool ok;
    double diameter = diameterField->text().toDouble(&ok);
    if (!ok)
    {
        resultLabel->setText("Erreur : diamètre invalide");
        return;
    }

    circle.setDiameter(diameter);
    double perimeter = circle.calculatePerimeter();
    resultLabel->setText(QString("Périmètre : %1").arg(perimeter));
}

void Widget::calculateArea()
{
    bool ok;
    double diameter = diameterField->text().toDouble(&ok);
    if (!ok)
    {
        resultLabel->setText("Erreur : diamètre invalide");
        return;
    }

    circle.setDiameter(diameter);
    double area = circle.calculateArea();
    resultLabel->setText(QString("Surface : %1").arg(area));
}

Widget::~Widget()
{
    delete ui;
}


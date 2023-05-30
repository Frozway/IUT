/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *addButton;
    QPushButton *deleteButton;
    QPushButton *submitButton;
    QTableView *tableView;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *edId;
    QLineEdit *edMatiere;
    QLineEdit *edNature;
    QLineEdit *edDate;
    QLineEdit *edSalle;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *edEnseignant;
    QLabel *label_8;
    QLineEdit *edDuree;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 600);
        addButton = new QPushButton(Widget);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(260, 240, 80, 24));
        deleteButton = new QPushButton(Widget);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(350, 240, 80, 24));
        submitButton = new QPushButton(Widget);
        submitButton->setObjectName("submitButton");
        submitButton->setGeometry(QRect(440, 240, 80, 24));
        tableView = new QTableView(Widget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(20, 280, 751, 301));
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(170, 80, 49, 16));
        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(170, 110, 49, 16));
        label_3 = new QLabel(Widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(170, 140, 49, 16));
        label_4 = new QLabel(Widget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(170, 170, 61, 16));
        label_5 = new QLabel(Widget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(170, 200, 49, 16));
        edId = new QLineEdit(Widget);
        edId->setObjectName("edId");
        edId->setGeometry(QRect(240, 80, 113, 16));
        edMatiere = new QLineEdit(Widget);
        edMatiere->setObjectName("edMatiere");
        edMatiere->setGeometry(QRect(240, 110, 113, 16));
        edNature = new QLineEdit(Widget);
        edNature->setObjectName("edNature");
        edNature->setGeometry(QRect(240, 140, 113, 16));
        edDate = new QLineEdit(Widget);
        edDate->setObjectName("edDate");
        edDate->setGeometry(QRect(240, 170, 113, 16));
        edSalle = new QLineEdit(Widget);
        edSalle->setObjectName("edSalle");
        edSalle->setGeometry(QRect(240, 200, 113, 16));
        label_6 = new QLabel(Widget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(370, 140, 61, 16));
        label_7 = new QLabel(Widget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(370, 170, 49, 16));
        edEnseignant = new QLineEdit(Widget);
        edEnseignant->setObjectName("edEnseignant");
        edEnseignant->setGeometry(QRect(440, 140, 113, 16));
        label_8 = new QLabel(Widget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(360, 30, 81, 16));
        edDuree = new QLineEdit(Widget);
        edDuree->setObjectName("edDuree");
        edDuree->setGeometry(QRect(440, 170, 113, 16));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        addButton->setText(QCoreApplication::translate("Widget", "Add", nullptr));
        deleteButton->setText(QCoreApplication::translate("Widget", "Delete", nullptr));
        submitButton->setText(QCoreApplication::translate("Widget", "Submit", nullptr));
        label->setText(QCoreApplication::translate("Widget", "ID", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "Mati\303\250re", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "Nature", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "Date", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "Salle", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "Enseignant", nullptr));
        label_7->setText(QCoreApplication::translate("Widget", "Duree", nullptr));
        label_8->setText(QCoreApplication::translate("Widget", "Add New Book", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

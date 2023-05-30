/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IHM
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *lName;
    QLabel *lBirthdate;
    QLabel *lFirstname;
    QLabel *lPrintFirstname;
    QLabel *lPrintName;
    QLabel *lPrintBirthDate;
    QLineEdit *leName;
    QLineEdit *leFirstname;
    QCalendarWidget *calendarWidget;

    void setupUi(QWidget *IHM)
    {
        if (IHM->objectName().isEmpty())
            IHM->setObjectName("IHM");
        IHM->resize(672, 510);
        gridLayoutWidget = new QWidget(IHM);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 10, 447, 341));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lName = new QLabel(gridLayoutWidget);
        lName->setObjectName("lName");

        gridLayout->addWidget(lName, 0, 0, 1, 1, Qt::AlignRight);

        lBirthdate = new QLabel(gridLayoutWidget);
        lBirthdate->setObjectName("lBirthdate");

        gridLayout->addWidget(lBirthdate, 2, 0, 1, 1, Qt::AlignRight|Qt::AlignTop);

        lFirstname = new QLabel(gridLayoutWidget);
        lFirstname->setObjectName("lFirstname");

        gridLayout->addWidget(lFirstname, 1, 0, 1, 1, Qt::AlignRight);

        lPrintFirstname = new QLabel(gridLayoutWidget);
        lPrintFirstname->setObjectName("lPrintFirstname");

        gridLayout->addWidget(lPrintFirstname, 4, 0, 1, 1);

        lPrintName = new QLabel(gridLayoutWidget);
        lPrintName->setObjectName("lPrintName");

        gridLayout->addWidget(lPrintName, 3, 0, 1, 1);

        lPrintBirthDate = new QLabel(gridLayoutWidget);
        lPrintBirthDate->setObjectName("lPrintBirthDate");

        gridLayout->addWidget(lPrintBirthDate, 5, 0, 1, 1);

        leName = new QLineEdit(gridLayoutWidget);
        leName->setObjectName("leName");
        leName->setMaximumSize(QSize(150, 21));

        gridLayout->addWidget(leName, 0, 1, 1, 1);

        leFirstname = new QLineEdit(gridLayoutWidget);
        leFirstname->setObjectName("leFirstname");
        leFirstname->setMaximumSize(QSize(150, 21));

        gridLayout->addWidget(leFirstname, 1, 1, 1, 1);

        calendarWidget = new QCalendarWidget(gridLayoutWidget);
        calendarWidget->setObjectName("calendarWidget");

        gridLayout->addWidget(calendarWidget, 2, 1, 1, 1);


        retranslateUi(IHM);
        QObject::connect(leName, &QLineEdit::editingFinished, lPrintName, qOverload<>(&QLabel::clear));

        QMetaObject::connectSlotsByName(IHM);
    } // setupUi

    void retranslateUi(QWidget *IHM)
    {
        IHM->setWindowTitle(QCoreApplication::translate("IHM", "Formulaire de saisie", nullptr));
        lName->setText(QCoreApplication::translate("IHM", "Nom :", nullptr));
        lBirthdate->setText(QCoreApplication::translate("IHM", "Date de naissance :", nullptr));
        lFirstname->setText(QCoreApplication::translate("IHM", "Pr\303\251nom :", nullptr));
        lPrintFirstname->setText(QCoreApplication::translate("IHM", "X", nullptr));
        lPrintName->setText(QCoreApplication::translate("IHM", "X", nullptr));
        lPrintBirthDate->setText(QCoreApplication::translate("IHM", "X", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IHM: public Ui_IHM {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

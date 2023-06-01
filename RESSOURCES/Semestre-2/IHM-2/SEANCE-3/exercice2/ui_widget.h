/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
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
    QCalendarWidget *cwBirthdate;
    QLabel *lPrintBirthdate;
    QLabel *lFirstName;
    QLabel *lName;
    QLabel *lBirthdate;
    QLineEdit *leFirstName;
    QLabel *lPrintFirstName;
    QLabel *lPrintName;
    QLineEdit *leName;

    void setupUi(QWidget *IHM)
    {
        if (IHM->objectName().isEmpty())
            IHM->setObjectName("IHM");
        IHM->resize(800, 600);
        gridLayoutWidget = new QWidget(IHM);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(190, 80, 451, 421));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        cwBirthdate = new QCalendarWidget(gridLayoutWidget);
        cwBirthdate->setObjectName("cwBirthdate");

        gridLayout->addWidget(cwBirthdate, 3, 1, 1, 1);

        lPrintBirthdate = new QLabel(gridLayoutWidget);
        lPrintBirthdate->setObjectName("lPrintBirthdate");

        gridLayout->addWidget(lPrintBirthdate, 6, 0, 1, 1);

        lFirstName = new QLabel(gridLayoutWidget);
        lFirstName->setObjectName("lFirstName");

        gridLayout->addWidget(lFirstName, 1, 0, 1, 1);

        lName = new QLabel(gridLayoutWidget);
        lName->setObjectName("lName");
        lName->setEnabled(true);

        gridLayout->addWidget(lName, 0, 0, 1, 1);

        lBirthdate = new QLabel(gridLayoutWidget);
        lBirthdate->setObjectName("lBirthdate");

        gridLayout->addWidget(lBirthdate, 3, 0, 1, 1, Qt::AlignTop);

        leFirstName = new QLineEdit(gridLayoutWidget);
        leFirstName->setObjectName("leFirstName");
        leFirstName->setMaximumSize(QSize(200, 17));

        gridLayout->addWidget(leFirstName, 1, 1, 1, 1);

        lPrintFirstName = new QLabel(gridLayoutWidget);
        lPrintFirstName->setObjectName("lPrintFirstName");

        gridLayout->addWidget(lPrintFirstName, 4, 0, 1, 1);

        lPrintName = new QLabel(gridLayoutWidget);
        lPrintName->setObjectName("lPrintName");

        gridLayout->addWidget(lPrintName, 5, 0, 1, 1);

        leName = new QLineEdit(gridLayoutWidget);
        leName->setObjectName("leName");
        leName->setMaximumSize(QSize(200, 17));

        gridLayout->addWidget(leName, 0, 1, 1, 1);


        retranslateUi(IHM);

        QMetaObject::connectSlotsByName(IHM);
    } // setupUi

    void retranslateUi(QWidget *IHM)
    {
        IHM->setWindowTitle(QCoreApplication::translate("IHM", "Widget", nullptr));
        lPrintBirthdate->setText(QCoreApplication::translate("IHM", "TextLabel", nullptr));
        lFirstName->setText(QCoreApplication::translate("IHM", "Pr\303\251nom", nullptr));
        lName->setText(QCoreApplication::translate("IHM", "Nom :", nullptr));
        lBirthdate->setText(QCoreApplication::translate("IHM", "Date de naissance", nullptr));
        lPrintFirstName->setText(QCoreApplication::translate("IHM", "TextLabel", nullptr));
        lPrintName->setText(QCoreApplication::translate("IHM", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IHM: public Ui_IHM {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

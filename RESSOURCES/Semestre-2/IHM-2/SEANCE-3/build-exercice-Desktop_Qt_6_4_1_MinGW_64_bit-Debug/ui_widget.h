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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IHM
{
public:
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *IHM)
    {
        if (IHM->objectName().isEmpty())
            IHM->setObjectName("IHM");
        IHM->resize(800, 600);
        lineEdit = new QLineEdit(IHM);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(380, 250, 113, 24));
        label = new QLabel(IHM);
        label->setObjectName("label");
        label->setGeometry(QRect(220, 220, 151, 16));
        pushButton = new QPushButton(IHM);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(380, 280, 111, 24));
        label_2 = new QLabel(IHM);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(220, 250, 151, 16));
        label_3 = new QLabel(IHM);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(220, 320, 49, 16));

        retranslateUi(IHM);

        QMetaObject::connectSlotsByName(IHM);
    } // setupUi

    void retranslateUi(QWidget *IHM)
    {
        IHM->setWindowTitle(QCoreApplication::translate("IHM", "Widget", nullptr));
        lineEdit->setText(QCoreApplication::translate("IHM", "James", nullptr));
        label->setText(QCoreApplication::translate("IHM", "Veuillez saisir votre pr\303\251nom", nullptr));
        pushButton->setText(QCoreApplication::translate("IHM", "Validez", nullptr));
        label_2->setText(QCoreApplication::translate("IHM", "Votre pr\303\251nom :", nullptr));
        label_3->setText(QCoreApplication::translate("IHM", "Bonjour ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IHM: public Ui_IHM {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

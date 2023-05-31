/********************************************************************************
** Form generated from reading UI file 'formb.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMB_H
#define UI_FORMB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormB
{
public:
    QSlider *horizontalSlider;

    void setupUi(QWidget *FormB)
    {
        if (FormB->objectName().isEmpty())
            FormB->setObjectName("FormB");
        FormB->resize(200, 200);
        horizontalSlider = new QSlider(FormB);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(20, 90, 160, 22));
        horizontalSlider->setOrientation(Qt::Horizontal);

        retranslateUi(FormB);

        QMetaObject::connectSlotsByName(FormB);
    } // setupUi

    void retranslateUi(QWidget *FormB)
    {
        FormB->setWindowTitle(QCoreApplication::translate("FormB", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormB: public Ui_FormB {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMB_H

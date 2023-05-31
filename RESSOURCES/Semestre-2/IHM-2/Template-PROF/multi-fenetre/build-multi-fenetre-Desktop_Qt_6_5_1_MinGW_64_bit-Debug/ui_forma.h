/********************************************************************************
** Form generated from reading UI file 'forma.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMA_H
#define UI_FORMA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormA
{
public:
    QProgressBar *progressBar;

    void setupUi(QWidget *FormA)
    {
        if (FormA->objectName().isEmpty())
            FormA->setObjectName("FormA");
        FormA->resize(200, 200);
        progressBar = new QProgressBar(FormA);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(50, 90, 118, 23));
        progressBar->setValue(24);

        retranslateUi(FormA);

        QMetaObject::connectSlotsByName(FormA);
    } // setupUi

    void retranslateUi(QWidget *FormA)
    {
        FormA->setWindowTitle(QCoreApplication::translate("FormA", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormA: public Ui_FormA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMA_H

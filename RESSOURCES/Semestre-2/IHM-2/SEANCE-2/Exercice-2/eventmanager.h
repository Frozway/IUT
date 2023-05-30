#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <QObject>
#include <QMessageBox>
#include "Circle.h"

class EventManager : public QObject {
    Q_OBJECT
public:
    EventManager(Circle* circle, QLineEdit* diameterField, QLabel* resultLabel) :
    m_circle(circle),
    m_diameterField(diameterField),
    m_resultLabel(resultLabel) {}

public slots:
    void onPerimeterButtonClicked() {
    bool ok;
    double diameter = m_diameterField->text().toDouble(&ok);
    if (!ok || diameter <= 0)
    {
        QMessageBox::warning(nullptr, "Erreur", "Le diamètre doit être un nombre positif");
        return;
    }

    m_circle->setDiameter(diameter);
    double perimeter = m_circle->calculatePerimeter();
    m_resultLabel->setText(QString("Périmètre : %1").arg(perimeter));
    }

private:
    Circle* m_circle;
    QLineEdit* m_diameterField;
    QLabel* m_resultLabel;
};

#endif // EVENTMANAGER_H

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "person.h"

QT_BEGIN_NAMESPACE
namespace Ui { class IHM; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Person itsPerson;
    Ui::IHM *ui;
public slots:
    void onEditFirstname(const QString &aFirstname);
    void onEditName(const QString &aName);
};
#endif // WIDGET_H

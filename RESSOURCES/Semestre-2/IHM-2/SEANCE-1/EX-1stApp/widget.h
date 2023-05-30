#ifndef WIDGET_H
#define WIDGET_H

#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QLineEdit * leName ;
    QLabel * lGreetings ;

};
#endif // WIDGET_H

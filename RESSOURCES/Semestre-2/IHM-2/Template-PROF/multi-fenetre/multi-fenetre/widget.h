#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStackedWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void selectForm(int index);

private:
    Ui::Widget *ui;
    void keyPressEvent(QKeyEvent* event);
    int count;
    QStackedWidget* stackedWidget;
};
#endif // WIDGET_H

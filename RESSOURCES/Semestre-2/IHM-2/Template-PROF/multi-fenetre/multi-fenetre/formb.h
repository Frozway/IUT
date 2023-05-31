#ifndef FORMB_H
#define FORMB_H

#include <QWidget>

namespace Ui {
class FormB;
}

class FormB : public QWidget
{
    Q_OBJECT

public:
    explicit FormB(QWidget *parent = nullptr);
    ~FormB();

private:
    Ui::FormB *ui;
    void keyPressEvent(QKeyEvent* event);
    int count;
};

#endif // FORMB_H

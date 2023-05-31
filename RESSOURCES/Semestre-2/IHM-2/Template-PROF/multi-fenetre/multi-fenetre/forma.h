#ifndef FORMA_H
#define FORMA_H

#include <QWidget>

namespace Ui {
class FormA;
}

class FormA : public QWidget
{
    Q_OBJECT

public:
    explicit FormA(QWidget *parent = nullptr);
    ~FormA();

private:
    Ui::FormA *ui;
    void keyPressEvent(QKeyEvent* event);
    int count;
};

#endif // FORMA_H

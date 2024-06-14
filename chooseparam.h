#ifndef CHOOSEPARAM_H
#define CHOOSEPARAM_H

#include <QWidget>

namespace Ui {
class Chooseparam;
}

class Chooseparam : public QWidget
{
    Q_OBJECT

public:
    explicit Chooseparam(QWidget *parent = nullptr);
    ~Chooseparam();

private:
    Ui::Chooseparam *ui;
};

#endif // CHOOSEPARAM_H

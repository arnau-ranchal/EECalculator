#ifndef PARAMVARIATES_H
#define PARAMVARIATES_H

#include <QWidget>

namespace Ui {
class paramVariates;
}

class paramVariates : public QWidget
{
    Q_OBJECT

public:
    explicit paramVariates(QWidget *parent = nullptr);
    ~paramVariates();

private:
    Ui::paramVariates *ui;
};

#endif // PARAMVARIATES_H

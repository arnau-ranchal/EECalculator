#ifndef PARAMORDER_H
#define PARAMORDER_H

#include <QWidget>

namespace Ui {
class ParamOrder;
}

class ParamOrder : public QWidget
{
    Q_OBJECT

public:
    explicit ParamOrder(QWidget *parent = nullptr);
    ~ParamOrder();

private:
    Ui::ParamOrder *ui;
};

#endif // PARAMORDER_H

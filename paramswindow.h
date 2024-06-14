#ifndef PARAMSWINDOW_H
#define PARAMSWINDOW_H

#include <QWidget>

namespace Ui {
class ParamsWindow;
}

class ParamsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ParamsWindow(QWidget *parent = nullptr);
    ~ParamsWindow();

private:
    Ui::ParamsWindow *ui;
};

#endif // PARAMSWINDOW_H

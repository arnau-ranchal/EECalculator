#ifndef GRAPHSWINDOW_H
#define GRAPHSWINDOW_H

#include <QWidget>

namespace Ui {
class graphsWindow;
}

class graphsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit graphsWindow(QWidget *parent = nullptr);
    ~graphsWindow();

private:
    Ui::graphsWindow *ui;
};

#endif // GRAPHSWINDOW_H

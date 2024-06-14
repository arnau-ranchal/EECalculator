#ifndef SNRWINDOW_H
#define SNRWINDOW_H

#include <QWidget>

namespace Ui {
class snrWindow;
}

class snrWindow : public QWidget
{
    Q_OBJECT

public:
    explicit snrWindow(QWidget *parent = nullptr);
    ~snrWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::snrWindow *ui;
};

#endif // SNRWINDOW_H

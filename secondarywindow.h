#ifndef SECONDARYWINDOW_H
#define SECONDARYWINDOW_H

#include <QWidget>


namespace Ui {
class SecondaryWindow;
}

class SecondaryWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SecondaryWindow(QWidget *parent = nullptr);
    ~SecondaryWindow();

private slots:
    void on_iidExpButton_clicked();
    void gotoshowPlotsWindow();

    void on_nextButton_clicked();

    void on_ccExpButton_clicked();

    void on_ccompExpButton_clicked();

private:
    Ui::SecondaryWindow *ui;
    void iidButtonToggled(bool a);
    void ccButtonToggled(bool a);
    void ccompButtonToggled(bool a);
};

#endif // SECONDARYWINDOW_H

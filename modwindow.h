#ifndef MODWINDOW_H
#define MODWINDOW_H

#include <QWidget>
#include "PowerOfTwoSpinBox.h" // Include the custom spin box header


namespace Ui {
class ModWindow;
}

class ModWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ModWindow(QWidget *parent = nullptr);
    ~ModWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ModWindow *ui;
    PowerOfTwoSpinBox *powerOfTwoSpinBox; // Declare the custom spin box
};

#endif // MODWINDOW_H

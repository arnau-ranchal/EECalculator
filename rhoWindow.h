#ifndef RHOWINDOW_H
#define RHOWINDOW_H

#include <QDialog>

namespace Ui {
class rhoWindow;
}

class showPlotsWindow; // Forward declaration

class rhoWindow : public QDialog
{
    Q_OBJECT

public:
    explicit rhoWindow(QString a, QString b, QString c, QString d, QWidget *parent = nullptr);
    ~rhoWindow();

private slots:
    void on_OK_clicked();
    void on_Default_clicked();
    void on_doubleSpinBox_valueChanged(double value);
    void on_doubleSpinBox_2_valueChanged(double value);
    void setSNRWheels();
    void setMODWheels();
    void setRWheels();

private:
    Ui::rhoWindow *ui;
    showPlotsWindow *s; // Member variable to keep track of the main window
};

#endif // RHOWINDOW_H

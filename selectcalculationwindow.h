#ifndef SELECTCALCULATIONWINDOW_H
#define SELECTCALCULATIONWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_2_sliderMoved(int position);

    void on_DONE_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // SELECTCALCULATIONWINDOW_H

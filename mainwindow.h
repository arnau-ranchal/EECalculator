#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dualhandleslider.h"

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
    static void setMODmin(int m);
    static void setMODmax(int m);
    static void setMODpts(int p);
    static void setSNRmin(double s);
    static void setSNRmax(double s);
    static void setSNRpts(int p);
    static void setRmin  (double r);
    static void setRmax  (double r);
    static void setRpts  (int p);

private slots:


private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H

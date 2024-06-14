#ifndef SHOWPLOTSWINDOW_H
#define SHOWPLOTSWINDOW_H

#include <QMainWindow>
#include <QRadioButton>
#include "worker.h"

QT_BEGIN_NAMESPACE
namespace Ui { class showPlotsWindow; }
QT_END_NAMESPACE

class DualHandleSlider;

class showPlotsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit showPlotsWindow(QWidget *parent = nullptr);
    ~showPlotsWindow();

    static void setMODmin(int m);
    static void setMODmax(int m);
    static void setMODpts(int p);
    static void setSNRmin(double s);
    static void setSNRmax(double s);
    static void setSNRpts(int p);
    static void setRmin(double r);
    static void setRmax(double r);
    static void setRpts(int p);
    static void setIndexRate(int i);
    static void setIndexSNR(int i);
    static void setIndexMod(int i);
    static void setIndexE0(int i);
    static void setMode1(bool a);
    static void setMode2(bool a);
    static void setMode3(bool a);
    void setAllowedModes(bool mode1Allowed, bool mode2Allowed, bool mode3Allowed);

private slots:
    void on_plot_clicked();
    void plot();

    void on_checkBox_stateChanged(int arg1);
    void on_modeSelected();

    void setModeAllowed(bool iidAllowed, bool ccAllowed, bool ccompAllowed);

    void onWorkFinished();
    void updateProgress(int value);

private:
    Ui::showPlotsWindow *ui;
    DualHandleSlider *modSlider;
    DualHandleSlider *snrSlider;
    DualHandleSlider *rateSlider;
    QRadioButton *iidButton;
    QRadioButton *ccButton;
    QRadioButton *ccompButton;
    QButtonGroup *modeButtonGroup;
    Worker *worker;
    QThread *workerThread;
};

#endif // SHOWPLOTSWINDOW_H

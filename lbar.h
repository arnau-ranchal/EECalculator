#ifndef LBAR_H
#define LBAR_H

#include <QWidget>

namespace Ui {
class lbar;
}

class lbar : public QWidget
{
    Q_OBJECT

public:
    explicit lbar(double minRate, double maxRate, int ptsRate, double minSNR, double maxSNR, int ptsSNR, double minMod, double maxMod, int ptsMod, bool mode1, bool mode2, bool mode3, QWidget *parent = nullptr);
    ~lbar();
    void start();

private:
    Ui::lbar *ui;
};

#endif // LBAR_H

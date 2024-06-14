#pragma once

#include <QObject>
#include <QProgressBar>
#include <QLabel>
#include "mymain.h"

class Worker : public QObject {
    Q_OBJECT

public:
    explicit Worker(int minRate, int maxRate, int ptsRate, int minSNR, int maxSNR, int ptsSNR,
                    int minMod, int maxMod, int ptsMod, int mode1, int mode2, int mode3,
                    QProgressBar* progressBar, QLabel* timeLabel, QLabel* totalTime);
    ~Worker();

public slots:
    void doWork();

signals:
    void workFinished();

private:
    int minRate, maxRate, ptsRate, minSNR, maxSNR, ptsSNR, minMod, maxMod, ptsMod;
    int mode1, mode2, mode3;
    QProgressBar* progressBar;
    QLabel* timeLabel;
    QLabel* totalTime;
};

#include "worker.h"

Worker::Worker(int minRate, int maxRate, int ptsRate, int minSNR, int maxSNR, int ptsSNR,
               int minMod, int maxMod, int ptsMod, int mode1, int mode2, int mode3,
               QProgressBar* progressBar, QLabel* timeLabel, QLabel* totalTime) :
    minRate(minRate), maxRate(maxRate), ptsRate(ptsRate), minSNR(minSNR),
    maxSNR(maxSNR), ptsSNR(ptsSNR), minMod(minMod), maxMod(maxMod), ptsMod(ptsMod),
    mode1(mode1), mode2(mode2), mode3(mode3), progressBar(progressBar),
    timeLabel(timeLabel), totalTime(totalTime) {}

Worker::~Worker(){

}
void Worker::doWork() {
    mymain(minRate, maxRate, ptsRate, minSNR, maxSNR, ptsSNR, minMod, maxMod, ptsMod, mode1, mode2, mode3, progressBar, timeLabel, totalTime);
    emit workFinished();
}

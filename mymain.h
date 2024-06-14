#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <QDebug>
#include <QProgressBar>
#include <QLabel>


void saveData(const QString &filename, const QVector<QVector<double>> &e0_samples, const QVector<double> &rates, const QVector<double> &snrs, const QVector<int> &mods);

int mymain(double minRate, double maxRate, int ptsRate, double minSNR, double maxSNR, int ptsSNR, int minMod, int maxMod, int ptsMod, bool mode1, bool mode2, bool mode3, QProgressBar *progressBar, QLabel *percentText, QLabel *totalTime);

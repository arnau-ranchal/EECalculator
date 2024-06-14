#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <QDebug>
#include <QProgressBar>
#include "functions.h"
#include <QLabel>
#include "mymain.h"

void saveData(const QString &filename, const QVector<QVector<double>> &e0_samples, const QVector<double> &rates, const QVector<double> &snrs, const QVector<int> &mods) {
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        for (int i = 0; i < rates.size(); ++i) {
            for (int j = 0; j < snrs.size(); ++j) {
                for (int k = 0; k < mods.size(); ++k) {
                    out << rates[i] << "," << snrs[j] << "," << mods[k] << "," << e0_samples[i * snrs.size() + j][k] << "\n";
                }
            }
        }
        file.close();
    } else {
        qDebug() << "Unable to open file for writing";
    }
}

int mymain(double minRate, double maxRate, int ptsRate, double minSNR, double maxSNR, int ptsSNR, int minMod, int maxMod, int ptsMod, bool mode1, bool mode2, bool mode3, QProgressBar *progressBar, QLabel *percentText, QLabel *totalTime) {
    QVector<QVector<double>> e0_1_samples;
    QVector<QVector<double>> e0_2_samples;
    QVector<QVector<double>> e0_3_samples;
    QVector<double> rates, snrs;
    QVector<int> mods;

    // Generate rates, snrs, and mods based on the input ranges and pts
    if (ptsRate == 1) {
        rates.push_back(minRate);
    } else {
        for (int i = 0; i < ptsRate; ++i) {
            double rate = minRate + i * (maxRate - minRate) / (ptsRate - 1);
            rates.push_back(rate);
        }
    }

    if (ptsSNR == 1) {
        snrs.push_back(minSNR);
    } else {
        for (int i = 0; i < ptsSNR; ++i) {
            double snr = minSNR + i * (maxSNR - minSNR) / (ptsSNR - 1);
            snrs.push_back(snr);
        }
    }

    // Generate mods as powers of 2 within the specified range
    int currentMod = 1;
    while (currentMod <= maxMod) {
        if (currentMod >= minMod) {
            mods.push_back(currentMod);
        }
        currentMod *= 2;
    }

    // Gradient descent parameters
    int it = 80, n = 17;
    compute_hweights(n,it);
    double e0_1, e0_2, e0_3;
    int totalIterations = rates.size() * snrs.size() * mods.size();
    int currentIteration = 0;
    auto deltas_sum = 0;
    double rho = 0.01, r = 1; unordered_map<int, vector<double>> alphadict;
    for(int k = 0; k < mods.size(); k++){
        std::vector<double> alphas(mods[k], 0.01);
        alphadict[mods[k]] = alphas;
    }
    // Calculate e0_samples using gradient descent for each combination of rate, snr, and mod
    for (int i = 0; i < rates.size(); ++i) {
        for (int j = 0; j < snrs.size(); ++j) {
            QVector<double> e0_row_1, e0_row_2, e0_row_3;

            for (int k = 0; k < mods.size(); ++k) {
                auto start = std::chrono::high_resolution_clock::now();
                vector<double> e0_samples;

                //qDebug() << "i:" << i << " j:" << j << " k:" << k;
                //qDebug() << "modval: " << mods[k];
                setR(rates[i]); setSNR(snrs[j]); setMod(mods[k],"pam");
                double beta = -1/e02(n);

                if(mode1){ // iid mode
                    //rho = 0; r = 0;
                    e0_1 = GD_iid(r, rho, 1/beta, it, n);
                    e0_row_1.append(e0_1);
                }
                if(mode2){ // cost constraint mode
                    //rho = 0; r = 0;
                    e0_2 = GD_cc(r, rho, 1/beta, it, n);
                    e0_row_2.append(e0_2);
                }
                if(mode3){ // constant composition mode
                    /*vector<double> alphas(mods[k],0); rho = 0;*/
                    e0_3 = GD_ccomp(/*alphas*/alphadict[mods[k]], rho, 1/beta, it, n);
                    e0_row_3.append(e0_3);
                }

                auto stop = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
                //qDebug() << "modulation " << mods[k] << "Duration: " << duration.count() * pow(10,-6) << "s";
                deltas_sum += duration.count();
                totalTime->setText(QString::number(((((deltas_sum / (currentIteration+1))) * totalIterations)) * pow(10,-6)) + " s");
                percentText->setText(QString::number(((((deltas_sum / (currentIteration+1))) * totalIterations) - deltas_sum) * pow(10,-6)) + " s");
                ++currentIteration;

                float percentage = (static_cast<float>(currentIteration) / totalIterations) * 100;
                //qDebug() << "progress: " << percentage;
                progressBar->setValue(percentage); // percentage
            }

            if(mode1)
                e0_1_samples.append(e0_row_1);
            if(mode2)
                e0_2_samples.append(e0_row_2);
            if(mode3)
                e0_3_samples.append(e0_row_3);
        }
    }
    qDebug() << "done";


    // Save the e0_samples along with their corresponding parameters to a file
    if(mode1){
        QString filename = "C:/Users/TESTER/Documents/TFG1000/e0_samples_iid.txt";
        saveData(filename, e0_1_samples, rates, snrs, mods);
    }
    if(mode2){
        QString filename = "C:/Users/TESTER/Documents/TFG1000/e0_samples_cc.txt";
        saveData(filename, e0_2_samples, rates, snrs, mods);
    }
    if(mode3){
        QString filename = "C:/Users/TESTER/Documents/TFG1000/e0_samples_ccomp.txt";
        saveData(filename, e0_3_samples, rates, snrs, mods);
    }
    return 0;
}

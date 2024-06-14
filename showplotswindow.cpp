#include "showplotswindow.h"
#include "ui_showplotswindow.h"
#include "dualhandleslider.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QProcess>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QDir>
#include <QFileInfoList>
#include <QPixmap>
#include <QImageReader>
#include <QString>
#include <QThread>
#include "mymain.h"
#include <QtConcurrent/QtConcurrent>
#include <QThread>
#include <QProgressBar>

double minRate=0, maxRate=1, ptsRate = 10, incrementRate;
double minSNR=0.5,  maxSNR=1, ptsSNR = 2, incrementSNR;
double minMod=pow(2,1),  maxMod=pow(2,3), ptsMod=3-1+1, incrementMod;
int indexRate, indexSNR, indexMod, indexE0;

QVector<double> powof2;
bool save = false;
bool mode1=false, mode2=false, mode3=false;

bool isplot;

showPlotsWindow::showPlotsWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::showPlotsWindow)
{
    ui->setupUi(this);
    if(!mode1) ui->iidRadio->hide();
    if(!mode2) ui->ccRadio ->hide();
    if(!mode3) ui->ccompRadio->hide();

    if(mode1){
        ui->iidRadio->setChecked(true);
    }
    else{
        if(mode2){
            ui->ccRadio->setChecked(true);
        }
        else{
            ui->ccompRadio->setChecked(true);
        }
    }

    qDebug() << "minRate "   << minRate   ;
    qDebug() << "maxRate "   << maxRate   ;
    qDebug() << "ptsRate "   << ptsRate   ;
    qDebug() << "minSNR "    << minSNR    ;
    qDebug() << "maxSNR "    << maxSNR    ;
    qDebug() << "ptsSNR "    << ptsSNR    ;
    qDebug() << "minMod "    << minMod    ;
    qDebug() << "maxMod "    << maxMod    ;
    qDebug() << "ptsMod "    << ptsMod    ;
    qDebug() << "indexRate " << indexRate ;
    qDebug() << "indexSNR "  << indexSNR  ;
    qDebug() << "indexMod "  << indexMod  ;
    qDebug() << "indexE0 "   << indexE0   ;
    qDebug() << "mode1 "     << mode1     ;
    qDebug() << "mode2 "     << mode2     ;
    qDebug() << "mode3 "     << mode3     ;

    incrementSNR =  (maxSNR - minSNR)   / (ptsSNR-1);
    incrementRate = (maxRate - minRate) / (ptsRate-1);

    // Find the placeholder widget in the UI
    QWidget *sliderContainer = ui->sliderContainer; // Ensure this name matches your .ui file

    // Create the layout for custom widgets
    QVBoxLayout *layout = new QVBoxLayout(sliderContainer);

    // Create and configure DualHandleSliders
    rateSlider = new DualHandleSlider(Qt::Horizontal);
    rateSlider->setRange(minRate, maxRate);
    rateSlider->setMinValue(minRate);
    rateSlider->setMaxValue(maxRate);
    rateSlider->setPoints(ptsRate);

    snrSlider = new DualHandleSlider(Qt::Horizontal);
    snrSlider->setRange(minSNR, maxSNR);
    snrSlider->setMinValue(minSNR);
    snrSlider->setMaxValue(maxSNR);
    snrSlider->setPoints(ptsSNR);

    modSlider = new DualHandleSlider(Qt::Horizontal);
    modSlider->setRange(minMod, maxMod);
    modSlider->setMinValue(minMod);
    modSlider->setMaxValue(maxMod);
    modSlider->setPowerOfTwo(true); // Enable power of 2 mode for modulation
    modSlider->setPoints(ptsMod);
    powof2 = modSlider->getPowersOfTwoInRange(); // store the pow of 2 selected


    // Add widgets to layout
    layout->addWidget(rateSlider);
    layout->addWidget(new QLabel("Rate"));

    layout->addWidget(snrSlider);
    layout->addWidget(new QLabel("SNR"));

    layout->addWidget(modSlider);
    layout->addWidget(new QLabel("Modulation"));

    // Set the layout to the slider container
    sliderContainer->setLayout(layout);
}

showPlotsWindow::~showPlotsWindow()
{
    if (workerThread->isRunning()) {
        workerThread->quit();
        workerThread->wait();
    }
    delete ui;
}

void showPlotsWindow::setMODmin(int m) {
    minMod = m;
}

void showPlotsWindow::setMODmax(int m) {
    maxMod = m;
}

void showPlotsWindow::setMODpts(int p) {
    ptsMod = p;
}

void showPlotsWindow::setSNRmin(double s) {
    minSNR = s;
}

void showPlotsWindow::setSNRmax(double s) {
    maxSNR = s;
}

void showPlotsWindow::setSNRpts(int p) {
    ptsSNR = p;
}

void showPlotsWindow::setRmin(double r) {
    minRate = r;
}

void showPlotsWindow::setRmax(double r) {
    maxRate = r;
}

void showPlotsWindow::setRpts(int p) {
    ptsRate = p;
}

void showPlotsWindow::setIndexRate(int i){
    indexRate = i;
}

void showPlotsWindow::setIndexSNR(int i){
    indexSNR = i;
}

void showPlotsWindow::setIndexMod(int i){
    indexMod = i;
}

void showPlotsWindow::setIndexE0(int i){
    indexE0 = i;
}

void showPlotsWindow::onWorkFinished() {

}

void showPlotsWindow::on_plot_clicked()
{
    if(!isplot){
        ui->plot->setText("COMPUTE");

        QFutureWatcher<void> *watcher = new QFutureWatcher<void>(this);
        connect(watcher, &QFutureWatcher<void>::finished, this, &showPlotsWindow::onWorkFinished);
        //QFuture<void> future = QtConcurrent::run([this]() {
           // mymain(minRate, maxRate, ptsRate, minSNR, maxSNR, ptsSNR, minMod, maxMod, ptsMod, mode1, mode2, mode3, ui->progressBar, ui->timeLabel, ui->totalTime);
        //});
        isplot = true;
        ui->label->hide();
        ui->timeLabel->hide();
        ui->label_2->setText("Finished in: ");
        ui->plot->setText("PLOT");
        ui->progressBar->hide();

        // Set the parent of the QFutureWatcher to ensure proper memory management
        watcher->setParent(this);

        // Set the future for the watcher
        //watcher->setFuture(future);

        /*worker = new Worker(minRate, maxRate, ptsRate, minSNR, maxSNR, ptsSNR, minMod, maxMod, ptsMod, mode1, mode2, mode3, ui->progressBar, ui->timeLabel, ui->totalTime);
        workerThread = new QThread();

        worker->moveToThread(workerThread);

        connect(workerThread, &QThread::started, worker, &Worker::doWork);
        connect(worker, &Worker::workFinished, this, &showPlotsWindow::onWorkFinished);
        connect(worker, &Worker::workFinished, workerThread, &QThread::quit);
        connect(workerThread, &QThread::finished, worker, &QObject::deleteLater);
        connect(workerThread, &QThread::finished, workerThread, &QObject::deleteLater);

        // Start the thread
        workerThread->start();
        worker -> doWork();*/
    }
    else{
        ui->label_2->hide();
        ui->totalTime->hide();
        minSNR = (snrSlider -> currentValues()).first;
        maxSNR = (snrSlider -> currentValues()).second;
        minRate = (rateSlider -> currentValues()).first;
        maxRate = (rateSlider -> currentValues()).second;
        minMod = (modSlider -> currentValues()).first;
        maxMod = (modSlider -> currentValues()).second;
        ptsSNR = (maxSNR - minSNR) / incrementSNR + 1;
        ptsRate = (maxRate - minRate) / incrementRate + 1;
        ptsMod = std::distance(std::lower_bound(powof2.begin(), powof2.end(), minMod), std::upper_bound(powof2.begin(), powof2.end(), maxMod));

        qDebug() << "Starting Python script";

        QDir directory("C:/Users/TESTER/Documents/TFG1000/plots");
        QStringList files = directory.entryList(QDir::Files);

        for(const QString& file : files) {
            QString filePath = directory.filePath(file);
            QFile::remove(filePath);
        }

        QDir directory2("C:/Users/TESTER/Documents/TFG1000/good_plots");
        QStringList files2 = directory.entryList(QDir::Files);

        for(const QString& file : files2) {
            QString filePath = directory.filePath(file);
            QFile::remove(filePath);
        }

        int mode;
        if(ui->iidRadio->isChecked()){
            mode = 1;
        }
        else if (ui->ccRadio->isChecked()){
            mode = 2;
        }
        else{
            mode = 3;
        }

        qDebug() << "minRate "   << minRate  ;
        qDebug() << "maxRate "   << maxRate  ;
        qDebug() << "ptsRate "   << ptsRate  ;
        qDebug() << "minSNR "    << minSNR   ;
        qDebug() << "maxSNR "    << maxSNR   ;
        qDebug() << "ptsSNR "    << ptsSNR   ;
        qDebug() << "minMod "    << minMod   ;
        qDebug() << "maxMod "    << maxMod   ;
        qDebug() << "ptsMod "    << ptsMod   ;
        qDebug() << "incrementSNR " << incrementSNR;
        qDebug() << "incrementMOD " << incrementMod;
        qDebug() << "incrementRate " << incrementRate;
        qDebug() << "indexRate " << indexRate;
        qDebug() << "indexE0 " << indexE0;
        qDebug() << "indexMod " << indexMod;
        qDebug() << "indexSNR " << indexSNR;
        qDebug() << "E0 selected " << mode;

        // Run the Python script
        QProcess process;
        process.start("python", QStringList() << "C:/Users/TESTER/Documents/TFG1000/plot_data.py" <<
                                    QString::number(minSNR)  << QString::number(maxSNR)  << QString::number(ptsSNR) <<
                                    QString::number(minRate) << QString::number(maxRate) << QString::number(ptsRate) <<
                                    QString::number(minMod)  << QString::number(maxMod)  << QString::number(ptsMod) <<
                                    QString::number(indexRate) << QString::number(indexE0) <<
                                    QString::number(indexMod) << QString::number(indexSNR) <<
                                    QString::number(ui->plotsContainer->size().width()) << QString::number(ui->plotsContainer->size().height()) <<
                                    QString::number(save) << QString::number(mode)
                      );

        process.waitForFinished(-1);

        if (process.exitStatus() != QProcess::NormalExit || process.exitCode() != 0) {
            qDebug() << "Python script execution failed";
            qDebug() << process.readAllStandardError();
            return;
        }

        qDebug() << "Python script executed successfully";

        // Path to the directory containing the generated plot images
        QString plotsDirPath = "C:/Users/TESTER/Documents/TFG1000/plots/";

        // Find the placeholder widget in the UI
        QWidget *plotsContainer = ui->plotsContainer; // Ensure this name matches your .ui file

        if (!plotsContainer) {
            qDebug() << "plotsContainer not found in the UI";
            return;
        }

        // Clear any existing content in the plots container
        QLayout *existingLayout = plotsContainer->layout();
        if (existingLayout) {
            QLayoutItem *item;
            while ((item = existingLayout->takeAt(0)) != nullptr) {
                delete item->widget();
                delete item;
            }
            delete existingLayout;
        }

        qDebug() << "Existing content cleared";

        // Create a grid layout for the plots
        QGridLayout *layout = new QGridLayout(plotsContainer);
        layout->setSpacing(10); // Set spacing between widgets

        // Load and display each plot image
        QDir plotsDir(plotsDirPath);
        QFileInfoList fileList = plotsDir.entryInfoList(QStringList() << "*.png", QDir::Files);

        int row = 0, col = 0;
        int maxCols = 2;  // Adjust this number based on how many images per row you want

        for (const QFileInfo &fileInfo : fileList) {
            qDebug() << "Loading image: " << fileInfo.absoluteFilePath();
            QPixmap pixmap(fileInfo.absoluteFilePath());
            if (pixmap.isNull()) {
                qDebug() << "Failed to load image: " << fileInfo.absoluteFilePath();
                continue;
            }
            QLabel *label = new QLabel();
            label->setPixmap(pixmap);
            label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored); // Allow the label to expand to the pixmap size
            label->setScaledContents(true); // Ensure the pixmap is scaled to fit the label
            layout->addWidget(label, row, col);
            col++;
            if (col >= maxCols) {
                col = 0;
                row++;
            }
        }

        qDebug() << "Images loaded and added to layout";

        // Set the layout to the plots container
        plotsContainer->setLayout(layout);

        qDebug() << "Layout set to plots container";
    }
}

void showPlotsWindow::on_checkBox_stateChanged(int arg1)
{
    if(ui->checkBox->isChecked()){
        save = true;
    }
    else{
        save = false;
    }
}

void showPlotsWindow::setMode1(bool a){
    if(a) mode1 = true; else mode1 = false;
}

void showPlotsWindow::setMode2(bool a){
    if(a) mode2 = true; else mode2 = false;
}

void showPlotsWindow::setMode3(bool a){
    if(a) mode3 = true; else mode3 = false;
}


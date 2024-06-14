#include "mainwindow.h"
#include "mymain.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>
#include <QPen>
#include <QPixmap>
#include <QVBoxLayout>
#include "dualhandleslider.h"


double minRate=0, maxRate=1,   ptsRate=20;
double minSNR=0,  maxSNR=1 ,   ptsSNR =20;
double minMod=1,  maxMod=1024, ptsMod=20;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget *centralWidget = new QWidget(this); // Create a central widget
    QVBoxLayout *layout = new QVBoxLayout(centralWidget); // Set the layout on the central widget

    // Create and configure DualHandleSliders
    DualHandleSlider *rateSlider = new DualHandleSlider(Qt::Horizontal);
    rateSlider->setRange(minRate, maxRate);
    rateSlider->setMinValue(minRate);
    rateSlider->setMaxValue(maxRate);

    DualHandleSlider *snrSlider = new DualHandleSlider(Qt::Horizontal);
    snrSlider->setRange(minSNR, maxSNR);
    snrSlider->setMinValue(minSNR);
    snrSlider->setMaxValue(maxSNR);

    DualHandleSlider *modSlider = new DualHandleSlider(Qt::Horizontal);
    modSlider->setRange(minMod, maxMod);
    modSlider->setMinValue(minMod);
    modSlider->setMaxValue(maxMod);
    modSlider->setPowerOfTwo(true); // Enable power of 2 mode for modulation

    // Add widgets to layout
    layout->addWidget(rateSlider);
    layout->addWidget(new QLabel("Rate"));

    layout->addWidget(snrSlider);
    layout->addWidget(new QLabel("SNR"));

    layout->addWidget(modSlider);
    layout->addWidget(new QLabel("Modulation"));

    // Set the central widget
    setCentralWidget(centralWidget);

    this->show();
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow:: setMODmin(int m){
    minMod = m;
}

void MainWindow:: setMODmax(int m){
    maxMod = m;
}
void MainWindow:: setMODpts(int p){
    ptsMod = p;
}
void MainWindow:: setSNRmin(double s){
    minSNR = s;
}
void MainWindow:: setSNRmax(double s){
    maxSNR = s;
}
void MainWindow:: setSNRpts(int p){
    ptsSNR = p;
}
void MainWindow:: setRmin(double r){
    minRate = r;
}
void MainWindow:: setRmax(double r){
    maxRate = r;
}
void MainWindow:: setRpts(int p){
    ptsRate = p;
}

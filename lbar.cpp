#include "lbar.h"
#include "ui_lbar.h"


double minRate_, maxRate_, ptsRate_;
double minSNR_,  maxSNR_,  ptsSNR_;
double minMod_,  maxMod_,  ptsMod_;
bool mode1_, mode2_, mode3_;

lbar::lbar(double MinRate, double MaxRate, int PtsRate, double MinSNR, double MaxSNR, int PtsSNR, double MinMod, double MaxMod, int PtsMod, bool Mode1, bool Mode2, bool Mode3, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::lbar)
{
    ui->setupUi(this);

    minRate_ = MinRate;
    maxRate_ = MaxRate;
    ptsRate_ = PtsRate;
    minSNR_ = MinSNR;
    maxSNR_ = MaxSNR;
    ptsSNR_ = PtsSNR;
    minMod_ = MinMod;
    maxMod_ = MaxMod;
    ptsMod_ = PtsMod;
    mode1_ = Mode1;
    mode2_ = Mode2;
    mode3_ = Mode3;
}

lbar::~lbar()
{
    delete ui;
}

void lbar::start(){
    //mymain(minRate_, maxRate_, ptsRate_, minSNR_, maxSNR_, ptsSNR_, minMod_, maxMod_, ptsMod_, mode1_, mode2_, mode3_, ui->progressBar);
}

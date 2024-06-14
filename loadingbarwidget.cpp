#include "loadingbarwidget.h"
#include "ui_loadingbarwidget.h"

LoadingBarWidget::LoadingBarWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoadingBarWidget)
{
    ui->setupUi(this);
}

LoadingBarWidget::~LoadingBarWidget()
{
    delete ui;
}

void LoadingBarWidget::setProgress(int value)
{
    ui->progressBar->setValue(value);
}

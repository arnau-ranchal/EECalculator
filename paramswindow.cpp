#include "paramswindow.h"
#include "ui_paramswindow.h"

ParamsWindow::ParamsWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ParamsWindow)
{
    ui->setupUi(this);
}

ParamsWindow::~ParamsWindow()
{
    delete ui;
}

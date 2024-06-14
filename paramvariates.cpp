#include "paramvariates.h"
#include "ui_paramvariates.h"

paramVariates::paramVariates(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::paramVariates)
{
    ui->setupUi(this);
}

paramVariates::~paramVariates()
{
    delete ui;
}

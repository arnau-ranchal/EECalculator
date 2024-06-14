#include "snrwindow.h"
#include "ui_snrwindow.h"
#include "modwindow.h"
#include "showPlotsWindow.h"

snrWindow::snrWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::snrWindow)
{
    ui->setupUi(this);
    ui->doubleSpinBox->setMinimum(0.0);
    ui->doubleSpinBox->setMaximum(1.0);
    ui->doubleSpinBox->setDecimals(3);
    ui->doubleSpinBox->setSingleStep(0.1); // Increment by 0.1
}

snrWindow::~snrWindow()
{
    delete ui;
}

void snrWindow::on_pushButton_clicked()
{
    /*
    showPlotsWindow::setSNR(ui->doubleSpinBox->value());

    ModWindow *mw = new ModWindow();
    this -> hide();
    mw -> show();
*/
}


void snrWindow::on_pushButton_2_clicked()
{
    /*
    double snr = 0.5;
    ui->doubleSpinBox->setValue(snr);
    showPlotsWindow::setRate(snr);
*/
}


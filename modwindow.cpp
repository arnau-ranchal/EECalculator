#include "modwindow.h"
#include "mainwindow.h"
#include "ui_modwindow.h"
#include "PowerOfTwoSpinBox.h"

ModWindow::ModWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ModWindow)
{
    ui->setupUi(this);

    powerOfTwoSpinBox = new PowerOfTwoSpinBox(this);
    ui->verticalLayout->addWidget(powerOfTwoSpinBox); // Assuming you have a layout to add the widget

}

ModWindow::~ModWindow()
{
    delete ui;
}

void ModWindow::on_pushButton_clicked()
{
    int mod = 4;
    MainWindow::setMod(mod);

    MainWindow *mw = new MainWindow();
    this -> hide();
    mw -> show();
}


void ModWindow::on_pushButton_2_clicked()
{
    int mod = 4;
    //powerOfTwoSpinBox::setModValue(mod);
    MainWindow::setRate(mod);
}


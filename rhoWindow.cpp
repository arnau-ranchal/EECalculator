#include "rhoWindow.h"
#include "showplotswindow.h"
#include "ui_rhoWindow.h"
#include <QThread>


QString p1 = "SNR";        int pa1;
QString p2 = "Modulation"; int pa2;
QString p3 = "Rate";       int pa3;
QString p4 = "E0";         int pa4;
int current, next = -1, last;
int vc = 0;

rhoWindow::rhoWindow(QString a, QString b, QString c, QString d, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::rhoWindow) // Initialize showPlotsWindow to nullptr
    , s(nullptr)
{
    ui->setupUi(this);
    // a = "Modulation", b = "SNR", c = "Rate", d = "E0"
    if (a == p1) {
        pa1 = 1;
    } else if (a == p2) {
        pa2 = 1;
    } else if (a == p3){
        pa3 = 1;
    }
    else{
        pa4 = 1;
    }

    if (b == p1) {
        pa1 = 2;
    } else if (b == p2) {
        pa2 = 2;
    } else if (b == p3){
        pa3 = 2;
    }
    else{
        pa4 = 2;
    }

    if (c == p1) {
        pa1 = 3;
    } else if (c == p2) {
        pa2 = 3;
    } else if (c == p3){
        pa3 = 3;
    }
    else{
        pa4 = 3;
    }

    if (d == p1) {
        pa1 = 4;
    } else if (d == p2) {
        pa2 = 4;
    } else if (d == p3){
        pa3 = 4;
    }
    else{
        pa4 = 4;
    }

    showPlotsWindow::setIndexSNR (pa1);
    showPlotsWindow::setIndexMod (pa2);
    showPlotsWindow::setIndexRate(pa3);
    showPlotsWindow::setIndexE0  (pa4);


    qDebug() << "SNR: " << pa1;
    qDebug() << "Mod: " << pa2;
    qDebug() << "Rat: " << pa3;
    qDebug() << "E0:  " << pa4;


    if(pa4 == 3){
        if(pa1 == 4){
            pa1--;
        }
        else if (pa2 == 4){
            pa2--;
        }
        else if (pa3 == 4){
            pa3--;
        }
    }
    else if (pa4 == 2){
        if(pa1 == 3 || pa1 == 4){
            pa1--;
        }
        if (pa2 == 3 || pa2 == 4){
            pa2--;
        }
        if (pa3 == 3 || pa3 == 4){
            pa3--;
        }
    }
    else if (pa4 == 1){
        pa1--;
        pa2--;
        pa3--;
    }

    ui->doubleSpinBox->setValue(0);
    ui->doubleSpinBox_2->setValue(0);
    ui->npoints->setValue(1);

    if (pa1 == 1) {
        ui->label->setText(p1);
        qDebug() << "-----1-----"; //s
        setSNRWheels();


    } else if (pa2 == 1) {
        ui->label->setText(p2);
        qDebug() << "-----2-----"; //m
        setMODWheels();

    } else if (pa3 == 1) {
        ui->label->setText(p3);
        qDebug() << "-----3-----"; //r
        setRWheels();
    }

    if (pa1 == 1) {
        current = 1;
        if (pa2 == 2) {
            next = 2;
        } else if (pa3 == 2) {
            next = 3;
        }
    } else if (pa2 == 1) {
        current = 2;
        if (pa1 == 2) {
            next = 1;
        } else if (pa3 == 2) {
            next = 3;
            qDebug() << next;
        }
    } else if (pa3 == 1) {
        current = 3;
        qDebug() << "c: " << current;
        if (pa1 == 2) {
            next = 1;
        } else if (pa2 == 2) {
            next = 2;
        }
    }
}

rhoWindow::~rhoWindow()
{
    delete ui;
}

void rhoWindow::setSNRWheels(){
    // min wheel
    ui->doubleSpinBox->setMinimum(0);
    ui->doubleSpinBox->setMaximum(std::numeric_limits<int>::max());
    ui->doubleSpinBox->setSingleStep(0.01);

    // max wheel
    ui->doubleSpinBox_2->setMinimum(0);
    ui->doubleSpinBox_2->setMaximum(std::numeric_limits<int>::max());
    ui->doubleSpinBox_2->setSingleStep(0.01);

    // points wheel
    ui->npoints->setMinimum(1);
    ui->npoints->setMaximum(std::numeric_limits<int>::max());
    ui->npoints->setSingleStep(1);
}



void rhoWindow::setMODWheels(){
    //min wheel
    ui->doubleSpinBox->setMinimum(1);
    ui->doubleSpinBox->setMaximum(pow(2,32) - 1);
    ui->doubleSpinBox->setSingleStep(1);

    // max wheel
    ui->doubleSpinBox_2->setMinimum(1);
    ui->doubleSpinBox_2->setMaximum(pow(2,32) - 1);
    ui->doubleSpinBox_2->setSingleStep(1);

    // points wheel
    ui->npoints->setMinimum(1);
    ui->npoints->setMaximum(std::numeric_limits<int>::max());
    ui->npoints->setSingleStep(1);
}

void rhoWindow::setRWheels(){
    // min wheel
    ui->doubleSpinBox->setMinimum(0);
    ui->doubleSpinBox->setMaximum(std::numeric_limits<int>::max());
    ui->doubleSpinBox->setSingleStep(0.01);

    // max wheel
    ui->doubleSpinBox_2->setMinimum(0);
    ui->doubleSpinBox_2->setMaximum(std::numeric_limits<int>::max());
    ui->doubleSpinBox_2->setSingleStep(0.01);

    // points wheel
    ui->npoints->setMinimum(1);
    ui->npoints->setMaximum(std::numeric_limits<int>::max());
    ui->npoints->setSingleStep(1);
}


void rhoWindow::on_OK_clicked()
{
    qDebug() << "n" << next;
    qDebug() << "c" << current;

    if (current == 1) {
        qDebug() << "----------1--------------- updating s";
        /*showPlotsWindow::setSNRmin(ui->doubleSpinBox->value());
        showPlotsWindow::setSNRmax(ui->doubleSpinBox_2->value());
        showPlotsWindow::setSNRpts(ui->npoints->value());*/

        if (next == 2) {
            current = 2;
            next = 3;
            ui->label->setText(p2);
        } else if (next == 3) {
            current = 3;
            next = 1;
            ui->label->setText(p3);
        }

        vc++;

    } else if (current == 2) {
        qDebug() << "---------2--------------- updating m";
        /*
        showPlotsWindow::setMODmin(ui->doubleSpinBox->value());
        showPlotsWindow::setMODmax(ui->doubleSpinBox_2->value());
        showPlotsWindow::setMODpts(ui->npoints->value());
        */

        if (next == 1) {
            current = 1;
            next = 3;
            ui->label->setText(p1);
        } else if (next == 3) {
            current = 3;
            next = 1;
            ui->label->setText(p3);
        }

        vc++;

    } else if (current == 3) {
        qDebug() << "------------3-------------- updating r";
        /*showPlotsWindow::setRmin(ui->doubleSpinBox->value());
        showPlotsWindow::setRmax(ui->doubleSpinBox_2->value());
        showPlotsWindow::setRpts(ui->npoints->value());*/

        if (next == 1) {
            current = 1;
            next = 2;
            ui->label->setText(p1);
        } else if (next == 2) {
            current = 2;
            next = 1;
            ui->label->setText(p2);
        }

        vc++;

    }
    else {
        qDebug() << "----------ERROR---------------";
    }

    if(vc == 3){ // number of variables explored, if we have asked for all of them then exit
        qDebug() << "END!";

        if (s == nullptr) {
            s = new showPlotsWindow(this); // Pass 'this' as the parent
        }
        s->show();
        this->hide(); // Hide the current rhoWindow
    }

    ui->doubleSpinBox->setValue(0);
    ui->doubleSpinBox_2->setValue(0);
    ui->npoints->setValue(1);


}

void rhoWindow::on_Default_clicked()
{
    /*
    double rate = 0.5;
    ui->doubleSpinBox->setValue(rate);
    showPlotsWindow::setRate(rate);
    */
}

void rhoWindow::on_doubleSpinBox_valueChanged(double value)
{
    if (value > ui->doubleSpinBox_2->value()) {
        ui->doubleSpinBox_2->setValue(value);
    }

    if(current == 2) // mod
    {
        // Assuming you have a QDoubleSpinBox named "myDoubleSpinBox"
        double currentValue = ui->doubleSpinBox->value();

        // Calculate the next and previous powers of 2
        double nextPowerOf2 = std::pow(2, std::ceil(std::log2(currentValue)));
        double prevPowerOf2 = std::pow(2, std::floor(std::log2(currentValue)));

        // Determine the direction (up or down)
        bool isIncreasing = (ui->doubleSpinBox->value() > prevPowerOf2);

        // Set the step size based on the direction
        double stepSize = isIncreasing ? nextPowerOf2 : prevPowerOf2;
        ui->doubleSpinBox->setSingleStep(stepSize);
    }
}

void rhoWindow::on_doubleSpinBox_2_valueChanged(double value)
{
    if (value < ui->doubleSpinBox->value()) {
        ui->doubleSpinBox->setValue(value);
    }

    if(current == 2) // mod
    {
        // Assuming you have a QDoubleSpinBox named "myDoubleSpinBox"
        double currentValue = ui->doubleSpinBox_2->value();

        // Calculate the next and previous powers of 2
        double nextPowerOf2 = std::pow(2, std::ceil(std::log2(currentValue)));
        double prevPowerOf2 = std::pow(2, std::floor(std::log2(currentValue)));

        // Determine the direction (up or down)
        bool isIncreasing = (ui->doubleSpinBox_2->value() > prevPowerOf2);

        // Set the step size based on the direction
        double stepSize = isIncreasing ? nextPowerOf2 - currentValue : currentValue - prevPowerOf2;
        ui->doubleSpinBox_2->setSingleStep(stepSize);
    }
}

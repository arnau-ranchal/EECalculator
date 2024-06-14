#include "secondarywindow.h"
#include "rhoWindow.h"
#include "ui_secondarywindow.h"
#include "ui_rhoWindow.h"
#include "showplotswindow.h"
#include "choparam.h"
#include "showplotswindow.h"

SecondaryWindow::SecondaryWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SecondaryWindow)
{
    ui->setupUi(this);

    ui->iidExpButton->setCheckable(true);
    ui->iidExpButton->setStyleSheet("QPushButton:checked { border: 2px solid white; }");
    ui->iidExpButton->setChecked(false);
    connect(ui->iidExpButton, &QPushButton::toggled, this, &SecondaryWindow::iidButtonToggled);

    ui->ccExpButton->setCheckable(true);
    ui->ccExpButton->setStyleSheet("QPushButton:checked { border: 2px solid white; }");
    ui->ccExpButton->setChecked(false);
    connect(ui->ccExpButton, &QPushButton::toggled, this, &SecondaryWindow::ccButtonToggled);

    ui->ccompExpButton->setCheckable(true);
    ui->ccompExpButton->setStyleSheet("QPushButton:checked { border: 2px solid white; }");
    ui->ccompExpButton->setChecked(false);
    connect(ui->ccompExpButton, &QPushButton::toggled, this, &SecondaryWindow::ccompButtonToggled);
}

SecondaryWindow::~SecondaryWindow()
{
    delete ui;
}

void SecondaryWindow::iidButtonToggled(bool checked) {
    if (checked) {
        showPlotsWindow::setMode1(true);
    } else {
        showPlotsWindow::setMode1(false);
    }
}

void SecondaryWindow::ccButtonToggled(bool checked) {
    if (checked) {
        showPlotsWindow::setMode2(true);
    } else {
        showPlotsWindow::setMode2(false);
    }
}

void SecondaryWindow::ccompButtonToggled(bool checked) {
    if (checked) {
        showPlotsWindow::setMode3(true);
    } else {
        showPlotsWindow::setMode3(false);
    }
}

void SecondaryWindow::gotoshowPlotsWindow()
{
    this->close();
    showPlotsWindow *s = new showPlotsWindow(); // Create a new instance of the main window
    s->show(); // Show the main window
}

void SecondaryWindow::on_nextButton_clicked()
{
    qDebug() << "next";
    ChoParam *cho = new ChoParam();
    cho -> show();
}

void SecondaryWindow::on_iidExpButton_clicked(){
}
void SecondaryWindow::on_ccExpButton_clicked(){
}
void SecondaryWindow::on_ccompExpButton_clicked(){
}

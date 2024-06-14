#include "graphswindow.h"
#include "ui_graphswindow.h"

graphsWindow::graphsWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::graphsWindow)
{
    ui->setupUi(this);
}

graphsWindow::~graphsWindow()
{
    delete ui;
}

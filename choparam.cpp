#include "choparam.h"
#include "ui_choparam.h"
#include <QMessageBox>
#include "rhoWindow.h"
#include <QList>

QString param1 = "SNR";
QString param2 = "Modulation";
QString param3 = "Rate";
QString param4 = "Error Exponent";

ChoParam::ChoParam(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChoParam)
    , r(nullptr) // Initialize the rhoWindow pointer to nullptr
{
    ui->setupUi(this);
    // Initialize the list widget with items
    ui->orderListWidget->addItem(param1);
    ui->orderListWidget->addItem(param2);
    ui->orderListWidget->addItem(param3);
    ui->orderListWidget->addItem(param4);

    // Enable drag and drop functionality
    ui->orderListWidget->setDragDropMode(QAbstractItemView::InternalMove);

    // Connect the confirm button to the slot
    connect(ui->confirmButton, &QPushButton::clicked, this, &ChoParam::on_confirmButton_clicked);
}

ChoParam::~ChoParam()
{
    delete ui;
    delete r; // Delete the rhoWindow instance when ChoParam is destroyed
}

int ChoParam::index(QString s)
{
    if (s == param1) { // SNR
        return 1;
    } else if (s == param2) { // Mod
        return 2;
    } else { // Rate
        return 3;
    }
}

void ChoParam::on_confirmButton_clicked()
{
    QStringList order;
    for (int i = 0; i < ui->orderListWidget->count(); ++i) {
        order << ui->orderListWidget->item(i)->text();
    }

    if (!r) {
        r = new rhoWindow(order[0], order[1], order[2], order[3], this); // Pass `this` as the parent
    }

    this->hide();
    r->show();
}

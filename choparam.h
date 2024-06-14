#ifndef CHOPARAM_H
#define CHOPARAM_H

#include <QWidget>

namespace Ui {
class ChoParam;
}

class rhoWindow; // Forward declaration

class ChoParam : public QWidget
{
    Q_OBJECT

public:
    explicit ChoParam(QWidget *parent = nullptr);
    ~ChoParam();

private slots:
    void on_confirmButton_clicked();

private:
    Ui::ChoParam *ui;
    rhoWindow *r; // Member variable to keep track of the rhoWindow instance
    int index(QString s);
};

#endif // CHOPARAM_H

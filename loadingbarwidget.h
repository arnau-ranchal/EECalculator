#ifndef LOADINGBARWIDGET_H
#define LOADINGBARWIDGET_H

#include <QWidget>
#include <QProgressBar>

namespace Ui {
class LoadingBarWidget;
}

class LoadingBarWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoadingBarWidget(QWidget *parent = nullptr);
    ~LoadingBarWidget();

    // Function to set the progress value
    void setProgress(int value);

private:
    Ui::LoadingBarWidget *ui;
};

#endif // LOADINGBARWIDGET_H

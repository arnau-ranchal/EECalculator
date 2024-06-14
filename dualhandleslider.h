#ifndef DUALHANDLER_SLIDER_H
#define DUALHANDLER_SLIDER_H

#include <QWidget>
#include <QLabel>

class DualHandleSlider : public QWidget
{
    Q_OBJECT

public:
    DualHandleSlider(Qt::Orientation orientation, QWidget *parent = nullptr);

    void setMinValue(double value);
    void setMaxValue(double value);
    void setRange(double min, double max);
    void setPowerOfTwo(bool powerOfTwo);
    void setPoints(int points);
    QPair<double, double> currentValues() const;
    QVector<double> getPowersOfTwoInRange() const;

signals:
    void valuesChanged(double minVal, double maxVal);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    double pixelPosToValue(int pos) const;
    int valueToPixelPos(double value) const;
    double nearestPowerOfTwo(double value) const;
    void updateLabels();
    double nearestPoint(double value) const;

    int handleSize;
    bool draggingMin;
    bool draggingMax;
    double minVal;
    double maxVal;
    double rangeMin;
    double rangeMax;
    int pts;
    Qt::Orientation orientation;
    bool isPowerOfTwo;

    QLabel *minLabel;
    QLabel *maxLabel;
};

#endif // DUALHANDLER_SLIDER_H

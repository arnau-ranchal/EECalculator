#include "dualhandleslider.h"
#include <QPainter>
#include <QMouseEvent>
#include <cmath>
#include <QVector>
#include <QColor>

DualHandleSlider::DualHandleSlider(Qt::Orientation orientation, QWidget *parent)
    : QWidget(parent), handleSize(10), draggingMin(false), draggingMax(false),
    minVal(0), maxVal(100), rangeMin(0), rangeMax(100), orientation(orientation),
    isPowerOfTwo(false), pts(10)
{
    setMinimumSize(150, 50); // Minimum size for the slider widget

    // Create labels to display the values
    minLabel = new QLabel(this);
    maxLabel = new QLabel(this);
    updateLabels();
}

void DualHandleSlider::setMinValue(double value)
{
    minVal = qBound(rangeMin, value, maxVal);
    if (isPowerOfTwo) {
        minVal = nearestPowerOfTwo(minVal);
    } else {
        minVal = nearestPoint(minVal);
    }
    if (minVal > maxVal) {
        maxVal = minVal;
        if (isPowerOfTwo) {
            maxVal = nearestPowerOfTwo(maxVal);
        } else {
            maxVal = nearestPoint(maxVal);
        }
    }
    emit valuesChanged(minVal, maxVal);
    updateLabels();
    update();
}

void DualHandleSlider::setMaxValue(double value)
{
    maxVal = qBound(minVal, value, rangeMax);
    if (isPowerOfTwo) {
        maxVal = nearestPowerOfTwo(maxVal);
    } else {
        maxVal = nearestPoint(maxVal);
    }
    if (maxVal < minVal) {
        minVal = maxVal;
        if (isPowerOfTwo) {
            minVal = nearestPowerOfTwo(minVal);
        } else {
            minVal = nearestPoint(minVal);
        }
    }
    emit valuesChanged(minVal, maxVal);
    updateLabels();
    update();
}

void DualHandleSlider::setRange(double min, double max)
{
    rangeMin = min;
    rangeMax = max;
    setMinValue(minVal);
    setMaxValue(maxVal);
    update();
}

void DualHandleSlider::setPowerOfTwo(bool powerOfTwo)
{
    isPowerOfTwo = powerOfTwo;
    setMinValue(minVal); // Revalidate minVal
    setMaxValue(maxVal); // Revalidate maxVal
}

void DualHandleSlider::setPoints(int points)
{
    pts = points;
}

QPair<double, double> DualHandleSlider::currentValues() const
{
    return QPair<double, double>(minVal, maxVal);
}

void DualHandleSlider::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Draw the track
    QRect trackRect = rect().adjusted(handleSize / 2, height() / 2 - 2, -handleSize / 2, height() / 2 + 2);
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(60, 63, 65, 150));
    painter.drawRect(trackRect);

    // Draw the selected range
    int minPos = valueToPixelPos(minVal);
    int maxPos = valueToPixelPos(maxVal);
    QRect selectedRangeRect = trackRect;
    selectedRangeRect.setLeft(minPos);
    selectedRangeRect.setRight(maxPos);
    painter.setBrush(Qt::white);
    painter.drawRect(selectedRangeRect);

    // Draw the handles
    painter.setBrush(Qt::white);
    painter.drawEllipse(QPoint(minPos, height() / 2), handleSize / 2, handleSize / 2);
    painter.drawEllipse(QPoint(maxPos, height() / 2), handleSize / 2, handleSize / 2);

    // Update label positions
    int minLabelX = minPos - minLabel->width() / 2;
    int maxLabelX = maxPos - maxLabel->width() / 2;

    // Ensure labels do not go out of the widget bounds
    if (minLabelX < 0) minLabelX = 0;
    if (maxLabelX + maxLabel->width() > width()) maxLabelX = width() - maxLabel->width();

    minLabel->move(minLabelX, height() - minLabel->height() - handleSize);
    maxLabel->move(maxLabelX, height() - maxLabel->height() - handleSize);
}

void DualHandleSlider::mousePressEvent(QMouseEvent *event)
{
    int minPos = valueToPixelPos(minVal);
    int maxPos = valueToPixelPos(maxVal);
    QRect minHandle(minPos - handleSize / 2, 0, handleSize, height());
    QRect maxHandle(maxPos - handleSize / 2, 0, handleSize, height());

    if (minHandle.contains(event->pos()))
        draggingMin = true;
    else if (maxHandle.contains(event->pos()))
        draggingMax = true;
}

void DualHandleSlider::mouseMoveEvent(QMouseEvent *event)
{
    if (draggingMin)
    {
        int pos = (orientation == Qt::Horizontal) ? event->pos().x() : event->pos().y();
        setMinValue(pixelPosToValue(pos));
    }
    else if (draggingMax)
    {
        int pos = (orientation == Qt::Horizontal) ? event->pos().x() : event->pos().y();
        setMaxValue(pixelPosToValue(pos));
    }
}

void DualHandleSlider::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    draggingMin = false;
    draggingMax = false;
}

double DualHandleSlider::pixelPosToValue(int pos) const
{
    int sliderLength = (orientation == Qt::Horizontal) ? width() : height();
    double value;

    if (isPowerOfTwo) {
        auto powersOfTwo = getPowersOfTwoInRange();
        double step = sliderLength / static_cast<double>(powersOfTwo.size() - 1);
        int index = std::round(pos / step);
        value = powersOfTwo[qBound(0, index, powersOfTwo.size() - 1)];
    } else {
        double step = (rangeMax - rangeMin) / (pts - 1);
        value = rangeMin + std::round((pos / static_cast<double>(sliderLength)) * (pts - 1)) * step;
    }

    return value;
}

int DualHandleSlider::valueToPixelPos(double value) const
{
    int sliderLength = (orientation == Qt::Horizontal) ? width() : height();
    int pixelPos;

    if (isPowerOfTwo) {
        auto powersOfTwo = getPowersOfTwoInRange();
        auto it = std::lower_bound(powersOfTwo.begin(), powersOfTwo.end(), value);
        int index = std::distance(powersOfTwo.begin(), it);
        double step = sliderLength / static_cast<double>(powersOfTwo.size() - 1);
        pixelPos = step * index;
    } else {
        double step = (rangeMax - rangeMin) / (pts - 1);
        int index = std::round((value - rangeMin) / step);
        pixelPos = (index * (sliderLength - handleSize)) / (pts - 1) + handleSize / 2;
    }

    return pixelPos;
}

double DualHandleSlider::nearestPowerOfTwo(double value) const
{
    if (value <= 0) return 1;
    int power = std::log2(value);
    double lower = std::pow(2, power);
    double upper = std::pow(2, power + 1);
    return (value - lower < upper - value) ? lower : upper;
}

QVector<double> DualHandleSlider::getPowersOfTwoInRange() const
{
    QVector<double> powersOfTwo;
    int minExponent = std::ceil(std::log2(rangeMin));
    int maxExponent = std::floor(std::log2(rangeMax));

    for (int i = minExponent; i <= maxExponent; ++i) {
        powersOfTwo.append(std::pow(2, i));
    }

    if (powersOfTwo.size() > pts) {
        while (powersOfTwo.size() > pts) {
            powersOfTwo.remove(powersOfTwo.size() / 2);
        }
    }

    return powersOfTwo;
}

double DualHandleSlider::nearestPoint(double value) const
{
    double step = (rangeMax - rangeMin) / (pts - 1);
    return rangeMin + std::round((value - rangeMin) / step) * step;
}

void DualHandleSlider::updateLabels()
{
    minLabel->setText(QString::number(minVal));
    maxLabel->setText(QString::number(maxVal));
    minLabel->adjustSize();
    maxLabel->adjustSize();
}

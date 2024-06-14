#include "PowerOfTwoSpinBox.h"
#include <cmath>
#include <limits>

int vvalue;

PowerOfTwoSpinBox::PowerOfTwoSpinBox(QWidget *parent)
    : QSpinBox(parent)
{
    setRange(1, std::numeric_limits<int>::max());
    setValue(1);
    vvalue = 1;
}

QValidator::State PowerOfTwoSpinBox::validate(QString &text, int &pos) const
{
    bool ok;
    int value = text.toInt(&ok);
    if (ok && isPowerOfTwo(value)) {
        return QValidator::Acceptable;
    }
    return QValidator::Invalid;
}

int PowerOfTwoSpinBox::valueFromText(const QString &text) const
{
    return text.toInt();
}

QString PowerOfTwoSpinBox::textFromValue(int value) const
{
    return QString::number(value);
}

void PowerOfTwoSpinBox::stepBy(int steps)
{
    int value = this->value();
    if (steps > 0) {
        setValue(nextPowerOfTwo(value));
    } else {
        setValue(previousPowerOfTwo(value));
    }
}

bool PowerOfTwoSpinBox::isPowerOfTwo(int value) const
{
    return value > 0 && (value & (value - 1)) == 0;
}

int PowerOfTwoSpinBox::nextPowerOfTwo(int value) const
{
    if (value >= (std::numeric_limits<int>::max() / 2)) {
        return std::numeric_limits<int>::max();
    }
    int nextValue = 1;
    while (nextValue <= value) {
        nextValue <<= 1;
    }
    return nextValue;
}

int PowerOfTwoSpinBox::previousPowerOfTwo(int value) const
{
    if (value <= 1) {
        return 1;
    }
    int prevValue = 1;
    while ((prevValue << 1) < value) {
        prevValue <<= 1;
    }
    return prevValue;
}


int PowerOfTwoSpinBox::getModValue()
{
    return this->value();
}

#ifndef POWEROF2SPINBOX_H
#define POWEROF2SPINBOX_H

#include <QSpinBox>

class PowerOfTwoSpinBox : public QSpinBox
{
    Q_OBJECT

public:
    explicit PowerOfTwoSpinBox(QWidget *parent = nullptr);
    int getModValue();

protected:
    QValidator::State validate(QString &text, int &pos) const override;
    int valueFromText(const QString &text) const override;
    QString textFromValue(int value) const override;
    void stepBy(int steps) override;

private:
    bool isPowerOfTwo(int value) const;
    int nextPowerOfTwo(int value) const;
    int previousPowerOfTwo(int value) const;
};

#endif // POWEROF2SPINBOX_H

/********************************************************************************
** Form generated from reading UI file 'snrwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SNRWINDOW_H
#define UI_SNRWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_snrWindow
{
public:
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;

    void setupUi(QWidget *snrWindow)
    {
        if (snrWindow->objectName().isEmpty())
            snrWindow->setObjectName("snrWindow");
        snrWindow->resize(400, 300);
        label = new QLabel(snrWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 130, 63, 20));
        doubleSpinBox = new QDoubleSpinBox(snrWindow);
        doubleSpinBox->setObjectName("doubleSpinBox");
        doubleSpinBox->setGeometry(QRect(150, 120, 67, 29));
        pushButton = new QPushButton(snrWindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(300, 20, 83, 29));
        pushButton_2 = new QPushButton(snrWindow);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(220, 120, 83, 29));
        radioButton = new QRadioButton(snrWindow);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(110, 170, 71, 21));
        radioButton_2 = new QRadioButton(snrWindow);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(110, 200, 71, 21));

        retranslateUi(snrWindow);

        QMetaObject::connectSlotsByName(snrWindow);
    } // setupUi

    void retranslateUi(QWidget *snrWindow)
    {
        snrWindow->setWindowTitle(QCoreApplication::translate("snrWindow", "Form", nullptr));
        label->setText(QCoreApplication::translate("snrWindow", "SNR:", nullptr));
        pushButton->setText(QCoreApplication::translate("snrWindow", "OK", nullptr));
        pushButton_2->setText(QCoreApplication::translate("snrWindow", "Default", nullptr));
        radioButton->setText(QCoreApplication::translate("snrWindow", "Fixed", nullptr));
        radioButton_2->setText(QCoreApplication::translate("snrWindow", "Range", nullptr));
    } // retranslateUi

};

namespace Ui {
    class snrWindow: public Ui_snrWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SNRWINDOW_H

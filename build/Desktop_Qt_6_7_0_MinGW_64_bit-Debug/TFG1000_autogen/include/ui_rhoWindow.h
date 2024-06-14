/********************************************************************************
** Form generated from reading UI file 'rhoWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RHOWINDOW_H
#define UI_RHOWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rhoWindow
{
public:
    QLabel *label;
    QPushButton *OK;
    QPushButton *Default;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_2;
    QDoubleSpinBox *npoints;
    QLabel *label_2;
    QLabel *label_4;

    void setupUi(QDialog *rhoWindow)
    {
        if (rhoWindow->objectName().isEmpty())
            rhoWindow->setObjectName("rhoWindow");
        rhoWindow->resize(400, 300);
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("accessories-calculator")));
        rhoWindow->setWindowIcon(icon);
        label = new QLabel(rhoWindow);
        label->setObjectName("label");
        label->setEnabled(true);
        label->setGeometry(QRect(20, -10, 261, 111));
        QFont font;
        font.setPointSize(26);
        label->setFont(font);
        OK = new QPushButton(rhoWindow);
        OK->setObjectName("OK");
        OK->setGeometry(QRect(300, 20, 83, 29));
        Default = new QPushButton(rhoWindow);
        Default->setObjectName("Default");
        Default->setGeometry(QRect(240, 120, 83, 29));
        layoutWidget = new QWidget(rhoWindow);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(130, 120, 113, 111));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        doubleSpinBox = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox->setObjectName("doubleSpinBox");
        doubleSpinBox->setCursor(QCursor(Qt::ArrowCursor));
        doubleSpinBox->setWrapping(false);
        doubleSpinBox->setMaximum(0.990000000000000);
        doubleSpinBox->setSingleStep(0.010000000000000);

        gridLayout->addWidget(doubleSpinBox, 0, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        doubleSpinBox_2 = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_2->setObjectName("doubleSpinBox_2");
        doubleSpinBox_2->setCursor(QCursor(Qt::ArrowCursor));
        doubleSpinBox_2->setWrapping(false);
        doubleSpinBox_2->setMaximum(0.990000000000000);
        doubleSpinBox_2->setSingleStep(0.010000000000000);

        gridLayout->addWidget(doubleSpinBox_2, 3, 1, 1, 1);

        npoints = new QDoubleSpinBox(layoutWidget);
        npoints->setObjectName("npoints");
        npoints->setCursor(QCursor(Qt::ArrowCursor));
        npoints->setWrapping(false);
        npoints->setDecimals(0);
        npoints->setMaximum(1000.000000000000000);

        gridLayout->addWidget(npoints, 4, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 4, 0, 1, 1);


        retranslateUi(rhoWindow);

        QMetaObject::connectSlotsByName(rhoWindow);
    } // setupUi

    void retranslateUi(QDialog *rhoWindow)
    {
        rhoWindow->setWindowTitle(QCoreApplication::translate("rhoWindow", "EE Calculator", nullptr));
        label->setText(QCoreApplication::translate("rhoWindow", "rate:", nullptr));
        OK->setText(QCoreApplication::translate("rhoWindow", "Next", nullptr));
        Default->setText(QCoreApplication::translate("rhoWindow", "Default", nullptr));
        label_3->setText(QCoreApplication::translate("rhoWindow", "max", nullptr));
        label_2->setText(QCoreApplication::translate("rhoWindow", "min", nullptr));
        label_4->setText(QCoreApplication::translate("rhoWindow", "points", nullptr));
    } // retranslateUi

};

namespace Ui {
    class rhoWindow: public Ui_rhoWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RHOWINDOW_H

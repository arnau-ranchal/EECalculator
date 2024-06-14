/********************************************************************************
** Form generated from reading UI file 'secondarywindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDARYWINDOW_H
#define UI_SECONDARYWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SecondaryWindow
{
public:
    QPushButton *iidExpButton;
    QPushButton *ccExpButton;
    QPushButton *ccompExpButton;
    QPushButton *nextButton;

    void setupUi(QWidget *SecondaryWindow)
    {
        if (SecondaryWindow->objectName().isEmpty())
            SecondaryWindow->setObjectName("SecondaryWindow");
        SecondaryWindow->resize(563, 300);
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("accessories-calculator")));
        SecondaryWindow->setWindowIcon(icon);
        SecondaryWindow->setWindowOpacity(1.000000000000000);
        SecondaryWindow->setAutoFillBackground(false);
        iidExpButton = new QPushButton(SecondaryWindow);
        iidExpButton->setObjectName("iidExpButton");
        iidExpButton->setGeometry(QRect(40, 80, 141, 141));
        ccExpButton = new QPushButton(SecondaryWindow);
        ccExpButton->setObjectName("ccExpButton");
        ccExpButton->setGeometry(QRect(210, 80, 141, 141));
        ccompExpButton = new QPushButton(SecondaryWindow);
        ccompExpButton->setObjectName("ccompExpButton");
        ccompExpButton->setGeometry(QRect(380, 80, 141, 141));
        nextButton = new QPushButton(SecondaryWindow);
        nextButton->setObjectName("nextButton");
        nextButton->setGeometry(QRect(470, 260, 80, 31));

        retranslateUi(SecondaryWindow);

        QMetaObject::connectSlotsByName(SecondaryWindow);
    } // setupUi

    void retranslateUi(QWidget *SecondaryWindow)
    {
        SecondaryWindow->setWindowTitle(QCoreApplication::translate("SecondaryWindow", "EE Calculator", nullptr));
        iidExpButton->setText(QCoreApplication::translate("SecondaryWindow", "IID \n"
"Exponent", nullptr));
        ccExpButton->setText(QCoreApplication::translate("SecondaryWindow", "Cost\n"
" Constrained\n"
" Exponent", nullptr));
        ccompExpButton->setText(QCoreApplication::translate("SecondaryWindow", "Constant\n"
" Composition\n"
"Exponent", nullptr));
        nextButton->setText(QCoreApplication::translate("SecondaryWindow", "NEXT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SecondaryWindow: public Ui_SecondaryWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDARYWINDOW_H

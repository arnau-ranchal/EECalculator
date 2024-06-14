/********************************************************************************
** Form generated from reading UI file 'choparam.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOPARAM_H
#define UI_CHOPARAM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChoParam
{
public:
    QListWidget *orderListWidget;
    QPushButton *confirmButton;

    void setupUi(QWidget *ChoParam)
    {
        if (ChoParam->objectName().isEmpty())
            ChoParam->setObjectName("ChoParam");
        ChoParam->resize(400, 300);
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("accessories-calculator")));
        ChoParam->setWindowIcon(icon);
        orderListWidget = new QListWidget(ChoParam);
        orderListWidget->setObjectName("orderListWidget");
        orderListWidget->setGeometry(QRect(170, 70, 191, 141));
        confirmButton = new QPushButton(ChoParam);
        confirmButton->setObjectName("confirmButton");
        confirmButton->setGeometry(QRect(40, 120, 83, 29));

        retranslateUi(ChoParam);

        QMetaObject::connectSlotsByName(ChoParam);
    } // setupUi

    void retranslateUi(QWidget *ChoParam)
    {
        ChoParam->setWindowTitle(QCoreApplication::translate("ChoParam", "Order the parameters", nullptr));
        confirmButton->setText(QCoreApplication::translate("ChoParam", "Done", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChoParam: public Ui_ChoParam {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOPARAM_H

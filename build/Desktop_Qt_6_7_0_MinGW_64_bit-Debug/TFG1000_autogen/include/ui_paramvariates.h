/********************************************************************************
** Form generated from reading UI file 'paramvariates.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMVARIATES_H
#define UI_PARAMVARIATES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_paramVariates
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QWidget *paramVariates)
    {
        if (paramVariates->objectName().isEmpty())
            paramVariates->setObjectName("paramVariates");
        paramVariates->resize(400, 300);
        pushButton = new QPushButton(paramVariates);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(110, 110, 81, 81));
        pushButton_2 = new QPushButton(paramVariates);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(200, 110, 81, 81));
        pushButton_3 = new QPushButton(paramVariates);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(290, 110, 81, 81));
        pushButton_4 = new QPushButton(paramVariates);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(20, 110, 81, 81));

        retranslateUi(paramVariates);

        QMetaObject::connectSlotsByName(paramVariates);
    } // setupUi

    void retranslateUi(QWidget *paramVariates)
    {
        paramVariates->setWindowTitle(QCoreApplication::translate("paramVariates", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("paramVariates", "Static \n"
"Rate", nullptr));
        pushButton_2->setText(QCoreApplication::translate("paramVariates", "Static \n"
"SNR", nullptr));
        pushButton_3->setText(QCoreApplication::translate("paramVariates", "Static \n"
"Modulation", nullptr));
        pushButton_4->setText(QCoreApplication::translate("paramVariates", "Static\n"
"Parameters", nullptr));
    } // retranslateUi

};

namespace Ui {
    class paramVariates: public Ui_paramVariates {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMVARIATES_H

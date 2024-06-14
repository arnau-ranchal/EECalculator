/********************************************************************************
** Form generated from reading UI file 'showplotswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWPLOTSWINDOW_H
#define UI_SHOWPLOTSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_showPlotsWindow
{
public:
    QWidget *sliderContainer;
    QPushButton *plot;
    QWidget *plotsContainer;
    QCheckBox *checkBox;
    QRadioButton *iidRadio;
    QRadioButton *ccRadio;
    QRadioButton *ccompRadio;
    QProgressBar *progressBar;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *totalTime;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *timeLabel;

    void setupUi(QWidget *showPlotsWindow)
    {
        if (showPlotsWindow->objectName().isEmpty())
            showPlotsWindow->setObjectName("showPlotsWindow");
        showPlotsWindow->resize(780, 531);
        sliderContainer = new QWidget(showPlotsWindow);
        sliderContainer->setObjectName("sliderContainer");
        sliderContainer->setGeometry(QRect(590, 30, 161, 321));
        plot = new QPushButton(showPlotsWindow);
        plot->setObjectName("plot");
        plot->setGeometry(QRect(620, 460, 131, 51));
        plotsContainer = new QWidget(showPlotsWindow);
        plotsContainer->setObjectName("plotsContainer");
        plotsContainer->setGeometry(QRect(29, 29, 551, 461));
        checkBox = new QCheckBox(showPlotsWindow);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(590, 430, 111, 22));
        iidRadio = new QRadioButton(showPlotsWindow);
        iidRadio->setObjectName("iidRadio");
        iidRadio->setGeometry(QRect(590, 360, 111, 22));
        ccRadio = new QRadioButton(showPlotsWindow);
        ccRadio->setObjectName("ccRadio");
        ccRadio->setGeometry(QRect(590, 380, 111, 22));
        ccompRadio = new QRadioButton(showPlotsWindow);
        ccompRadio->setObjectName("ccompRadio");
        ccompRadio->setGeometry(QRect(590, 400, 111, 22));
        progressBar = new QProgressBar(showPlotsWindow);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(30, 500, 551, 23));
        progressBar->setValue(0);
        layoutWidget = new QWidget(showPlotsWindow);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 450, 251, 18));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        totalTime = new QLabel(layoutWidget);
        totalTime->setObjectName("totalTime");

        horizontalLayout_2->addWidget(totalTime);

        widget = new QWidget(showPlotsWindow);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(30, 470, 251, 18));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        timeLabel = new QLabel(widget);
        timeLabel->setObjectName("timeLabel");

        horizontalLayout->addWidget(timeLabel);


        retranslateUi(showPlotsWindow);

        QMetaObject::connectSlotsByName(showPlotsWindow);
    } // setupUi

    void retranslateUi(QWidget *showPlotsWindow)
    {
        showPlotsWindow->setWindowTitle(QCoreApplication::translate("showPlotsWindow", "Form", nullptr));
        plot->setText(QCoreApplication::translate("showPlotsWindow", "COMPUTE", nullptr));
        checkBox->setText(QCoreApplication::translate("showPlotsWindow", "Save Images", nullptr));
        iidRadio->setText(QCoreApplication::translate("showPlotsWindow", "IID", nullptr));
        ccRadio->setText(QCoreApplication::translate("showPlotsWindow", "CC", nullptr));
        ccompRadio->setText(QCoreApplication::translate("showPlotsWindow", "CComp", nullptr));
        label_2->setText(QCoreApplication::translate("showPlotsWindow", "Estimated total time:", nullptr));
        totalTime->setText(QString());
        label->setText(QCoreApplication::translate("showPlotsWindow", "Estimated time remaining:", nullptr));
        timeLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class showPlotsWindow: public Ui_showPlotsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWPLOTSWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'loadingbarwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADINGBARWIDGET_H
#define UI_LOADINGBARWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoadingBarWidget
{
public:
    QProgressBar *progressBar;

    void setupUi(QWidget *LoadingBarWidget)
    {
        if (LoadingBarWidget->objectName().isEmpty())
            LoadingBarWidget->setObjectName("LoadingBarWidget");
        LoadingBarWidget->resize(400, 300);
        progressBar = new QProgressBar(LoadingBarWidget);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(110, 130, 191, 41));
        progressBar->setValue(24);

        retranslateUi(LoadingBarWidget);

        QMetaObject::connectSlotsByName(LoadingBarWidget);
    } // setupUi

    void retranslateUi(QWidget *LoadingBarWidget)
    {
        LoadingBarWidget->setWindowTitle(QCoreApplication::translate("LoadingBarWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoadingBarWidget: public Ui_LoadingBarWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADINGBARWIDGET_H

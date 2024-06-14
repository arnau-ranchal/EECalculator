/********************************************************************************
** Form generated from reading UI file 'lbar.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LBAR_H
#define UI_LBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lbar
{
public:
    QProgressBar *progressBar;

    void setupUi(QWidget *lbar)
    {
        if (lbar->objectName().isEmpty())
            lbar->setObjectName("lbar");
        lbar->resize(400, 300);
        progressBar = new QProgressBar(lbar);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(150, 130, 118, 23));
        progressBar->setValue(24);

        retranslateUi(lbar);

        QMetaObject::connectSlotsByName(lbar);
    } // setupUi

    void retranslateUi(QWidget *lbar)
    {
        lbar->setWindowTitle(QCoreApplication::translate("lbar", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lbar: public Ui_lbar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LBAR_H

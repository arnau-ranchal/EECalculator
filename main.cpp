#include "showplotswindow.h"
#include "secondarywindow.h"
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QVBoxLayout>
#include <QLabel>
#include <QProcess>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    //SecondaryWindow s;
    //s.show();

    QFile file(":/darktheme.qss");
    if (file.open(QFile::ReadOnly | QFile::Text)) {
        QTextStream stream(&file);
        QString stylesheet = stream.readAll();
        a.setStyleSheet(stylesheet);
    }

    SecondaryWindow s;
    s.show();
    //showPlotsWindow m;
    //m.show();
    return a.exec();
}

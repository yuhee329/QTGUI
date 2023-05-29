#include "customwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CustomWidget w;
    QObject::connect(&w,SIGNAL(widgetClicked()),&a,SLOT(quit()));
    w.show();
    return a.exec();
}

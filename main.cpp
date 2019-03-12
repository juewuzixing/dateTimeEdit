#include "qdatetimeedittest.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDateTimeEditTest w;
    w.show();

    return a.exec();
}

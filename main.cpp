
#include "IrisAnalysisUI.h"
#include "IrisCompare.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    IrisAnalysisUI ui;
    ui.show();

//    IrisCompare compare;
//    compare.show();

    return a.exec();
}

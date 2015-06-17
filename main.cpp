#include "IrisAnalysisUI.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    MainWindow w;
//    w.show();

    IrisAnalysisUI ui;
    ui.show();

    return a.exec();
}

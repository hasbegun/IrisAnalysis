
#ifndef IRISANALYSISUI_H
#define IRISANALYSISUI_H

#include <QMainWindow>
#include <QString>

#include <opencv2/core/core_c.h>
#include <Iris/ImageUtility.h>

#include <IrisAnalysis.h>

namespace Ui {
class IrisAnalysisUI;
}

class IrisAnalysisUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit IrisAnalysisUI(QWidget *parent = 0);
    ~IrisAnalysisUI();

    IrisAnalysis *irisAnalysis;

private slots:
    void on_loadImageBtn_clicked();
    void on_zoomInBtn_clicked();
    void on_zoomOutBtn_clicked();
    void on_scale1Btn_clicked();
    void on_analysis0Btn_clicked();
    void on_analysis1Btn_clicked();

    void on_compareBtn_clicked();

private:
    Ui::IrisAnalysisUI *ui;
    QString testIrisFile;
    double scaleFactor;

    IplImage *iris;
    IplImage *irisGray;

    void scaleImage(double);


};

#endif // IRISANALYSISUI_H

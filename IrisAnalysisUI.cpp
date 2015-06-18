
#include "IrisAnalysisUI.h"
#include "ui_IrisAnalysisUI.h"
#include "IrisAnalysis.h"

#include <QDebug>
#include <QMessageBox>

IrisAnalysisUI::IrisAnalysisUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IrisAnalysisUI)
{
    ui->setupUi(this);
}

IrisAnalysisUI::~IrisAnalysisUI()
{
    delete ui;
    delete irisAnalysis;
}

void IrisAnalysisUI::on_loadImageBtn_clicked()
{
    //testIrisFile = "/Users/hasbegun/devel/eyedentiscan/proj/data/CASIA-Iris-Interval/001/L/S1001L01.jpg";
    //testIrisFile = "/Users/hasbegun/devel/eyedentiscan/proj/data/CASIA-Iris-Interval/002/L/S1002L01.jpg";

    testIrisFile = "/Users/hasbegun/devel/eyedentiscan/proj/data/CASIA-Iris-Thousand/000/L/S5000L01.jpg";
//    testIrisFile = "/Users/hasbegun/devel/eyedentiscan/proj/data/CASIA-Iris-Thousand/001/L/S5001L01.jpg";

    qDebug() << testIrisFile;

    if (!testIrisFile.isEmpty()) {
        QImage image(testIrisFile);
        if (testIrisFile.isNull()) {
            QMessageBox::information(this, tr("image viewer"), tr("Cannot load $1").arg(testIrisFile));
            return;
        }
        ui->imageFileName->setText(testIrisFile);

        ui->imageView->setPixmap(QPixmap::fromImage(image));
        scaleFactor = 1.0;
        ui->imageView->adjustSize();

        ui->zoomInBtn->setEnabled(true);
        ui->zoomOutBtn->setEnabled(true);
        ui->scale1Btn->setEnabled(true);
        ui->analysis0Btn->setEnabled(true);
        ui->analysis1Btn->setEnabled(true);

        //convert qstring to char
        //QByteArray byteArray = fileName.toUtf8();
        //const char* filename = byteArray.constData();

        //convert qstring to std::string
        //QString qs;
        // either this
        //std::string utf8_text = qs.toUtf8().constData();
        // or this (if windows)
        //std::string current_locale_text = qs.toLocal8Bit().constData();

        irisAnalysis = new IrisAnalysis(testIrisFile.toUtf8().constData());
    }
}

void IrisAnalysisUI::scaleImage(double factor)
{
    Q_ASSERT(ui->imageView->pixmap());
    scaleFactor *= factor;
    ui->imageView->resize(scaleFactor * ui->imageView->pixmap()->size());
    ui->imageView->setScaledContents(true);
}


void IrisAnalysisUI::on_zoomInBtn_clicked()
{
    scaleImage(1.25);
}

void IrisAnalysisUI::on_zoomOutBtn_clicked()
{
    scaleImage(0.8);

}

void IrisAnalysisUI::on_scale1Btn_clicked()
{
    ui->imageView->adjustSize();
    scaleFactor = 1.0;
}

void IrisAnalysisUI::on_analysis1Btn_clicked()
{
    irisAnalysis->getEyeImage();

    irisAnalysis->checkQuality();
    ui->qualityValue->setText(QString::number(irisAnalysis->getImageQuality()));

    irisAnalysis->irisCheck();

}



void IrisAnalysisUI::on_analysis0Btn_clicked()
{
    irisAnalysis->eyeAnalysis();
}

void IrisAnalysisUI::on_compareBtn_clicked()
{

}

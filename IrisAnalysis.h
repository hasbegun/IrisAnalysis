
#ifndef IRISANALYSIS_H
#define IRISANALYSIS_H

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/core/core_c.h>
#include <iostream>

class IrisAnalysis
{
public:
    IrisAnalysis();
    IrisAnalysis(std::string filename);

    virtual ~IrisAnalysis();

    void getEyeImage();
    void checkQuality();

    void setIrisFileName(std::string filename);
    std::string getIrisFileName();
    double getImageQuality();
    void irisCheck();
    void eyeAnalysis();

private:
    std::string irisFileName;
    cv::Mat irisImage;

    double imageQualityScore = 0.0;
};

#endif // IRISANALYSIS_H

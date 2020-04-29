#ifndef IRIS_COMPARE_CLI
#define IRIS_COMPARE_CLI

#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>

#include "Iris/EyeDetection.h"

class IrisCompareCli {
  public:
    // Assumes that these two files are Iris images for now.
    IrisCompareCli(std::string, std::string);
    virtual ~IrisCompareCli();

    std::string getBaseIrisImagePath();
    void setBaseIrisImagePath(std::string);
    std::string getTargetIrisImagePath();
    void setTargetIrisImagePath(std::string);
    double checkQuality(cv::Mat&);  // legacy way
    double checkQuality2(cv::Mat&); // using cv mat
    bool compare(); // Compare two iris images and return T/F.
    double baseIrisMatQualityScore;
    double targetIrisMatQualityScore;

    double getImageQualityThreshold();
    void setImageQualityThreshold(double);
    double getMatchingThreshold();
    void setMatchingThreshold(double);
    void setCascade(std::string); // OCV cascade files are /usr/local/share/OpenCv
    std::string getCascade(); // get the cascade file.
    bool isMatch();
    void setSkipQualityCheck(bool);

  private:
    std::string baseIrisImgPath;
    std::string targetIrisImgPath;
    cv::Mat baseIrisMat;
    cv::Mat targetIrisMat;
    EyeDetection *eyeDetection;
    std::string cascade;
    bool skipQualityCheck;
    double imageQualityThreshold;
    double matchingThreshold;
    int gDataType;
    int pDataType;
    bool match; // final result of maching
};

#endif
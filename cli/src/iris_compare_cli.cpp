#include <spdlog/spdlog.h>

#include "iris_compare_cli.hpp"
#include "Iris/ImageQuality.h"
#include "Iris/MatchAlg.h"

#include "utils.hpp"

using namespace cv;

IrisCompareCli::IrisCompareCli(std::string baseIrisImgPath, std::string targetIrisImgPath) {
  this->baseIrisImgPath = baseIrisImgPath;
  this->targetIrisImgPath = targetIrisImgPath;
  cascade = "/usr/local/share/OpenCV/haarcascades/haarcascade_eye.xml";
  this->imageQualityThreshold = 0.30;
  this->matchingThreshold = 0.39;
  this->gDataType = 0;
  this->pDataType = 0;
  skipQualityCheck = false;
}

IrisCompareCli::~IrisCompareCli() {
}

std::string IrisCompareCli::getBaseIrisImagePath() {
  return this->baseIrisImgPath;
}

double IrisCompareCli::getImageQualityThreshold() {
  return imageQualityThreshold;
}
void IrisCompareCli::setImageQualityThreshold(double t) {
  imageQualityThreshold = t;
}
double IrisCompareCli::getMatchingThreshold() {
  return matchingThreshold;
}
void IrisCompareCli::setMatchingThreshold(double t) {
  matchingThreshold = t;
}
void IrisCompareCli::setBaseIrisImagePath(std::string baseIrisImgPath) {
  this->baseIrisImgPath = baseIrisImgPath;
}

std::string IrisCompareCli::getTargetIrisImagePath() {
  return this->targetIrisImgPath;
}

void IrisCompareCli::setTargetIrisImagePath(std::string targetIrisImgPath) {
  this->targetIrisImgPath = targetIrisImgPath;
}

bool IrisCompareCli::isMatch() {
  return match;
}

void IrisCompareCli::setCascade(std::string cascadePath) {
  if (Utils::fileExist(cascadePath)) {
    cascade = cascadePath;
    spdlog::debug("Cascade {} is set.", cascade);
  } else {
    spdlog::warn("Unable to set the cascade {}. Set it as default: haarcascade_eye.xml", cascade);
    cascade = "/usr/local/share/OpenCV/haarcascades/haarcascade_eye.xml";
  }
}

std::string IrisCompareCli::getCascade() {
  return cascade;
}

double IrisCompareCli::checkQuality(cv::Mat& img) {
  // double score1 = 0.0;
  // double score2 = 0.0;
  // IplImage targetImg = cvIplImage(baseIrisMat);
  // score1 = ImageQuality::doProcess(&targetImg, 0);  // 0: sobel
  // spdlog::debug("img score {}", score);

  // targetImg = cvIplImage(targetIrisMat);
  // score2 = ImageQuality::doProcess(&targetImg, 0);  // 0: sobel
  // spdlog::debug("img score {}", score);

  double score = 0.0;
  IplImage i = cvIplImage(img);
  score = ImageQuality::doProcess(&i, 0);  // 0: sobel
  spdlog::debug("The image quality score {}", score);

  return score;
}

double IrisCompareCli::checkQuality2(cv::Mat& img) {
  double score = 0.0;
  IplImage i = cvIplImage(img);
  score = ImageQuality::doProcess(&i, 0);  // 0: sobel
  spdlog::debug("The image quality score {}", score);

  return score;
}

void IrisCompareCli::setSkipQualityCheck(bool s) {
  skipQualityCheck = s;
}

bool IrisCompareCli::compare() {
  // case 1
  // baseIrisImg = openImage(baseIrisImgPath);
  // targetIrisImg = openImage(targetIrisImgPath);

  // case 2 pointer
  // openImage(baseIrisImgPath, &baseIrisImg);
  // openImage(targetIrisImgPath, &targetIrisImg);
  // if (baseIrisImg.empty()) {
  //     spdlog::error("Base Iris is empty.");
  // }

  // case 3
  if (!skipQualityCheck) {
    Utils::openImage(baseIrisImgPath, baseIrisMat);
    Utils::openImage(targetIrisImgPath, targetIrisMat);

    double baseIrisQuality = checkQuality(baseIrisMat);
    if (baseIrisQuality < imageQualityThreshold) {
      spdlog::error("The base image quality({}) is too low to perform analysis.", baseIrisQuality);
      return false;
    } else {
      spdlog::debug("The base iris image quality score {}", baseIrisQuality);
    }

    double targetIrisQuality = checkQuality(targetIrisMat);
    if (targetIrisQuality < imageQualityThreshold) {
      spdlog::error("The target image quality({}) is too low to perform analysis.", baseIrisQuality);
      return false;
    } else {
      spdlog::debug("The base iris image quality score {}", targetIrisQuality);
    }
  }
  // convert string to char*
  // case 1
  // const char* cstr = str.c_str(); // doesn't work because lib requires char*

  // case 2
  char *basePath = new char [baseIrisImgPath.length()+1];
  strcpy(basePath, baseIrisImgPath.c_str());
  char *targetPath = new char [targetIrisImgPath.length()+1];
  strcpy(targetPath, targetIrisImgPath.c_str());

  // case 3 == doesn't work....
  // std::vector<char> basePath(baseIrisImgPath.c_str(), baseIrisImgPath.c_str()+baseIrisImgPath.size() + 1);
  // std::vector<char> targetPath(targetIrisImgPath.c_str(), targetIrisImgPath.c_str()+targetIrisImgPath.size() + 1);

  double measureDiff = MatchAlg::mainMatchAlg(basePath, targetPath, gDataType, pDataType);
  spdlog::debug("measure {}", measureDiff);

  delete [] basePath;
  delete [] targetPath;

  if (measureDiff > matchingThreshold) {
    match = false;
  } else {
    match =true;
  }
  spdlog::debug("Match: diff by {}", measureDiff);
  return match;
}

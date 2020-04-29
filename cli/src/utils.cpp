#include <iostream>
#include <string>
#include <sys/stat.h>
#include "utils.hpp"

Utils::Utils() {
}

Utils::~Utils() {
}

bool Utils::fileExist (const std::string& name) {
    struct stat buffer;
    return (stat (name.c_str(), &buffer) == 0);
}

// Open image file at the given path.
void Utils::openImage(const std::string& imgPath, cv::Mat& img) {
    openImage(imgPath, img, 0); // open img in gray scale
    // if (fileExist(imgPath)) {
    //     img = imread(imgPath, imageMode);
    //     if (img.empty()) {
    //         spdlog::error("The image is empty: {}", imgPath);
    //     }
    // } else {
    //     spdlog::error("The image {} does not exist.", imgPath);
    // }
}

// Open image file at the given path.
void Utils::openImage(const std::string& imgPath, cv::Mat& img, const int imgMode=0) {
    if (fileExist(imgPath)) {
        img = imread(imgPath, imgMode);
        if (img.empty()) {
            spdlog::error("The image is empty: {}", imgPath);
        }
    } else {
        spdlog::error("The image {} does not exist.", imgPath);
    }
}

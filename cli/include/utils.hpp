#ifndef IRIS_COMPARE_CLI_UTILS_H
#define IRIS_COMPARE_CLI_UTILS_H

#include <iostream>
#include <string>
#include <sys/stat.h>

#include <spdlog/spdlog.h>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace cv;

class Utils {
    public:
        Utils();
        virtual ~Utils();

        static bool fileExist(const std::string& fileName);
        static void openImage(const std::string& imgPath, cv::Mat& img); // open image in gray scale
        static void openImage(const std::string& imgPath, cv::Mat& img, const int imgMode /* 0 by default: grayscale */);
};

// inline bool file_exist (const std::string& name) {
//     struct stat buffer;
//     return (stat (name.c_str(), &buffer) == 0);
// }

// case 1
// inline cv::Mat openImage(std::string& imgPath, cv::Mat* img, int imgMode=0) {
//     // Mat img;
//     if (file_exist(imgPath)) {
//         img = imread(imgPath, imgMode);
//         if (img.empty()) {
//             spdlog::error("The image is empty: {}", imgPath);
//         }
//     } else {
//         spdlog::error("The image {} does not exist.", imgPath);
//     }
//     return img;
// }

// case 2 pointer
// inline void openImage(std::string& imgPath, cv::Mat* img, int imgMode=0) {
//     // Mat img;
//     if (file_exist(imgPath)) {
//         *img = imread(imgPath, imgMode);
//         if (img->empty()) {
//             spdlog::error("The image is empty: {}", imgPath);
//         }
//     } else {
//         spdlog::error("The image {} does not exist.", imgPath);
//     }
// }

// open image at the given path and load it in a gray scale.
// imgmode: -1=unchanged, 0=grayscale, color=1, anydepth=2
//https://docs.opencv.org/3.4/d4/da8/group__imgcodecs.html
//   cv::IMREAD_UNCHANGED = -1,
//   cv::IMREAD_GRAYSCALE = 0,
//   cv::IMREAD_COLOR = 1,
//   cv::IMREAD_ANYDEPTH = 2,
//   cv::IMREAD_ANYCOLOR = 4,
//   cv::IMREAD_LOAD_GDAL = 8,
//   cv::IMREAD_REDUCED_GRAYSCALE_2 = 16,
//   cv::IMREAD_REDUCED_COLOR_2 = 17,
//   cv::IMREAD_REDUCED_GRAYSCALE_4 = 32,
//   cv::IMREAD_REDUCED_COLOR_4 = 33,
//   cv::IMREAD_REDUCED_GRAYSCALE_8 = 64,
//   cv::IMREAD_REDUCED_COLOR_8 = 65,
//   cv::IMREAD_IGNORE_ORIENTATION = 128
// inline void openImage(std::string& imgPath, cv::Mat& img, int imgMode=0) {
//     if (file_exist(imgPath)) {
//         img = imread(imgPath, imgMode);
//         if (img.empty()) {
//             spdlog::error("The image is empty: {}", imgPath);
//         }
//     } else {
//         spdlog::error("The image {} does not exist.", imgPath);
//     }
// }

#endif // IRIS_COMPARE_CLI_UTILS_H

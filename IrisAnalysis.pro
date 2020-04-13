#-------------------------------------------------
#
# Project created by QtCreator 2015-06-03T10:34:31
#
#-------------------------------------------------

#################################################################################
# This config works on Mac.
# Ubunto 18.04 with Qt5.9 doesn't work.
# The error is the staick lib doesn't link properly.
#/usr/local/alphablocks/lib/libIrisLib.a(EyeDetection.cpp.o): In function `EyeDetection::detect(_IplImage*, int, int, int, int)':
#EyeDetection.cpp:(.text+0x26e): undefined reference to `cvHaarDetectObjects'
#/usr/local/alphablocks/lib/libIrisLib.a(ImageUtility.cpp.o): In function `ImageUtility::showImage(char const*, _IplImage*)':
#ImageUtility.cpp:(.text+0x579): undefined reference to `cvNamedWindow'
#ImageUtility.cpp:(.text+0x58c): undefined reference to `cvShowImage'
#ImageUtility.cpp:(.text+0x596): undefined reference to `cvWaitKey'
#ImageUtility.cpp:(.text+0x5a2): undefined reference to `cvDestroyWindow'
#/usr/local/alphablocks/lib/libIrisLib.a(ImageUtility.cpp.o): In function `ImageUtility::showMatImage(char const*, cv::Mat*)':
#ImageUtility.cpp:(.text+0x5ea): undefined reference to `cv::namedWindow(cv::String const&, int)'
#ImageUtility.cpp:(.text+0x62f): undefined reference to `cv::imshow(cv::String const&, cv::_InputArray const&)'
#ImageUtility.cpp:(.text+0x651): undefined reference to `cv::waitKey(int)'
#ImageUtility.cpp:(.text+0x670): undefined reference to `cv::destroyWindow(cv::String const&)'
#collect2: error: ld returned 1 exit status
#Makefile:125: recipe for target '../build/IrisAnalysis' failed
#make: *** [../build/IrisAnalysis] Error 1
###################################################################################

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IrisAnalysis
TEMPLATE = app

### compiler setting
CONFIG += c++17
#CONFIG += -static -static-libgcc

QMAKE_CFLAG += -std=c++17 -stdlib=libc++
QMAKE_CXXFLAG += -std=c++17 -stdlib=libc++
#######

unix:!macx {
    OPENCV_PATH = /usr/local
# Qt5
    INCLUDEPATH += \
        /usr/include/x86_64-linux-gnu/qt5 \
        /usr/include/x86_64-linux-gnu/qt5/QtGui \
        /usr/include/x86_64-linux-gnu/qt5/QtCore \
        /usr/include/x86_64-linux-gnu/qt5/QtWidgets \
        /usr/include/libdrm \
        /usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++

    message("Patform: Linux.")
}

macx: {
    OPENCV_PATH = /usr/local/opt/opencv@3
    INCLUDEPATH += $$OPENCV_PATH/include
    message("Patform: Mac.")
}

LIBS += -L$$OPENCV_PATH/lib \
            -lopencv_core \
            -lopencv_highgui \
            -lopencv_imgproc \
            -lopencv_imgcodecs \
            -lopencv_objdetect \
            -lopencv_videoio

message("OCV PATH: $$OPENCV_PATH")
message("Include Path: $$INCLUDEPATH")
message("Link Lib Path: $$LIBS")

### Link OpenCV & Iris
BIOLIB_PATH = /usr/local/alphablocks
INCLUDEPATH += $$BIOLIB_PATH/include

### Analysis, MasekAlg, and IrisLib
CONFIG(debug) {
    LIBS += -L$$BIOLIB_PATH/lib -lIrisLib \
                                -lIrisAnalysisLib
} else {
    LIBS += -L$$BIOLIB_PATH/lib -lIrisLib \
                                -lIrisAnalysisLib
}

SOURCES += \
    main.cpp\
    IrisAnalysisUI.cpp \
    IrisAnalysis.cpp \
    ModeDialog.cpp \
    InputDialog.cpp \
    CVImageSource.cpp \
    ImageWidget.cpp \
    IrisCompare.cpp

HEADERS += \
    IrisAnalysisUI.h \
    IrisAnalysis.h \
    ModeDialog.h \
    InputDialog.h \
    CVImageSource.h \
    ImageSource.h \
    ImageWidget.h \
    IrisCompare.h

FORMS += \
    IrisAnalysisUI.ui \
    ModeDialog.ui \
    InputDialog.ui \
    IrisCompare.ui

DESTDIR = ./build
CONFIG += link_prl

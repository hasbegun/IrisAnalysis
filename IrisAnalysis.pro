#-------------------------------------------------
#
# Project created by QtCreator 2015-06-03T10:34:31
#
#-------------------------------------------------

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IrisAnalysis
TEMPLATE = app

### compiler setting
CONFIG += c++17
QMAKE_CFLAG += -std=c++17 -stdlib=libc++
QMAKE_CXXFLAG += -std=c++17 -stdlib=libc++
#######

### Link OpenCV & Iris
OPENCV_PATH = /usr/local/opt/opencv@3
BIOLIB_PATH = /usr/local/alphablocks
LIBS += -L$$OPENCV_PATH/lib \
    -lopencv_core \
    -lopencv_imgproc \
    -lopencv_highgui \
    -lopencv_objdetect \
    -lopencv_imgcodecs \
    -lopencv_videoio

INCLUDEPATH += $$OPENCV_PATH/include
INCLUDEPATH += $$BIOLIB_PATH/include

### Analysis, MasekAlg, and IrisLib
CONFIG(debug) {
    LIBS += -L$$BIOLIB_PATH/lib -lIrisAnalysisLib
    LIBS += -L$$BIOLIB_PATH/lib -lIrisLib
} else {
    LIBS += -L$$BIOLIB_PATH/lib -lIrisAnalysisLib
    LIBS += -L$$BIOLIB_PATH/lib -lIrisLib
}

SOURCES += \
    main.cpp\
    IrisAnalysisUI.cpp \
    IrisAnalysis.cpp \
    ModeDialog.cpp \
    InputDialog.cpp \
    CVImageSource.cpp \
    ImageWidget.cpp \
    IrisCompare.cpp \

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

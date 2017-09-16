#-------------------------------------------------
#
# Project created by QtCreator 2015-06-03T10:34:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IrisAnalysis
TEMPLATE = app

### compiler setting
CONFIG += c++11
QMAKE_CFLAG += -std=c++11 -stdlib=libc++ -mmacosx-version-min=10.8
QMAKE_CXXFLAG += -std=c++11 -stdlib=libc++ -mmacosx-version-min=10.8
#######

### Link OpenCV & Iris
OPENCV_PATH = /usr/local/opencv/2.4
EYEDENTISCANBUILD = /usr/local/eyedentiscan
LIBS += -L$$OPENCV_PATH/lib \
    -lopencv_core \
    -lopencv_imgproc \
    -lopencv_highgui \
    -lopencv_objdetect \
    -lopencv_legacy

INCLUDEPATH += $$OPENCV_PATH/include
INCLUDEPATH += $$EYEDENTISCANBUILD/include
### Analysis, MasekAlg, and IrisLib
CONFIG(debug) {
    LIBS += -L$$EYEDENTISCANBUILD/lib -lIrisAnalysisLib
    LIBS += -L$$EYEDENTISCANBUILD/lib -lIrisLib
} else {
    LIBS += -L$$EYEDENTISCANBUILD/lib -lIrisAnalysisLib
    LIBS += -L$$EYEDENTISCANBUILD/lib -lIrisLib
}

SOURCES += main.cpp\
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

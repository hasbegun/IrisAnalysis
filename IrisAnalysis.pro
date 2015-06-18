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

### OpenCV link
OPENCV_PATH = /usr/local/opencv/2.4.11
LIBS += -L$$OPENCV_PATH/osx/lib \
    -lopencv_core \
    -lopencv_imgproc \
    -lopencv_highgui \
    -lopencv_objdetect \
    -lopencv_legacy

INCLUDEPATH += $$OPENCV_PATH/osx/include
#######

### Analysis, MasekAlg, and IrisLib
EYEDENTISCANBUILD = /Users/hasbegun/devel/eyedentiscan/proj
CONFIG(debug) {
    LIBS += -L$$EYEDENTISCANBUILD/build/IrisAnalysisLib-Desktop_Qt_5_4_2_clang_64bit-Debug -lIrisAnalysisLib
    LIBS += -L$$EYEDENTISCANBUILD/build/IrisLib2-Desktop_Qt_5_4_2_clang_64bit-Debug -lIrisLib2
} else {
    LIBS += -L$$EYEDENTISCANBUILD/build/IrisAnalysisLib-Desktop_Qt_5_4_2_clang_64bit-Release -lIrisAnalysisLib
    LIBS += -L$$EYEDENTISCANBUILD/build/IrisLib2-Desktop_Qt_5_4_2_clang_64bit-Release -lIrisLib2
}

INCLUDEPATH += $$EYEDENTISCANBUILD/IrisAnalysisLib
INCLUDEPATH += $$EYEDENTISCANBUILD/IrisLib2
#########

SOURCES += main.cpp\
    IrisAnalysisUI.cpp \
    IrisAnalysis.cpp \
    ModeDialog.cpp \
    InputDialog.cpp \
    CVImageSource.cpp \
    ImageWidget.cpp \
    IrisCompare.cpp

HEADERS  += \
    IrisAnalysisUI.h \
    IrisAnalysis.h \
    ModeDialog.h \
    InputDialog.h \
    CVImageSource.h \
    ImageSource.h \
    ImageWidget.h \
    IrisCompare.h

FORMS    += \
    IrisAnalysisUI.ui \
    ModeDialog.ui \
    InputDialog.ui \
    IrisCompare.ui

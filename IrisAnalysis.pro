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
OPENCV_PATH = /usr/local/opt/opencv
LIBS += -L$$OPENCV_PATH/lib \
    -lopencv_core \
    -lopencv_imgproc \
    -lopencv_highgui \
    -lopencv_objdetect \
    -lopencv_legacy

INCLUDEPATH += $$OPENCV_PATH/include
#######

### Analysis, MasekAlg, and IrisLib
EYEDENTISCANBUILD = /Users/hasbegun/devel/biometric/BiometricLib/build
CONFIG(debug) {
    LIBS += -L$$EYEDENTISCANBUILD/lib -lIrisAnalysis
    LIBS += -L$$EYEDENTISCANBUILD/lib -lIris
} else {
    LIBS += -L$$EYEDENTISCANBUILD/lib -lIrisAnalysis
    LIBS += -L$$EYEDENTISCANBUILD/lib -lIris
}

###INCLUDEPATH += $$EYEDENTISCANBUILD/include/IrisAnalysis
###INCLUDEPATH += $$EYEDENTISCANBUILD/include/Iris
INCLUDEPATH += $$EYEDENTISCANBUILD/include
#########

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

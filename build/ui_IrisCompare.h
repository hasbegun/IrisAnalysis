/********************************************************************************
** Form generated from reading UI file 'IrisCompare.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IRISCOMPARE_H
#define UI_IRISCOMPARE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "ImageWidget.h"

QT_BEGIN_NAMESPACE

class Ui_IrisCompare
{
public:
    QAction *actionOpen_AVI;
    QAction *actionOpen_CAM;
    QAction *actionSelect_cascade;
    QAction *actionStart_Match;
    QAction *actionOpen_IRIS_AVI;
    QAction *actionImage_Quality;
    QAction *actionMatching;
    QAction *actionNonmatching;
    QAction *actionROC;
    QAction *actionReducedROC;
    QAction *actionReports;
    QAction *actionOpen_Iris_Analysis;
    QAction *actionStep_By_Step_Anaysis;
    QWidget *m_centralwidget;
    QTabWidget *tabWidget;
    QWidget *Detection;
    ImageWidget *imgWidget;
    QWidget *Match;
    ImageWidget *imgLeftWidget1;
    QPushButton *btnOpenLeft1;
    ImageWidget *imgLeftWidget2;
    QPushButton *btnOpenLeft2;
    QPushButton *btnOpenRight1;
    QPushButton *btnOpenRight2;
    ImageWidget *imgRightWidget1;
    ImageWidget *imgRightWidget2;
    QPushButton *btnGoMatch;
    QLabel *txtLeftResult;
    QLabel *txtRightResult;
    QLabel *txtLeftDataType1;
    QLabel *txtLeftDataType2;
    QLabel *txtRightDataType1;
    QLabel *txtRightDataType2;
    QMenuBar *m_menuBar;
    QMenu *menuFiles;
    QMenu *menuCascade;
    QMenu *menuMatch;
    QMenu *menuQuality;
    QMenu *menuAnalysis;
    QStatusBar *m_statusBar;

    void setupUi(QMainWindow *IrisCompare)
    {
        if (IrisCompare->objectName().isEmpty())
            IrisCompare->setObjectName(QStringLiteral("IrisCompare"));
        IrisCompare->resize(711, 720);
        IrisCompare->setMaximumSize(QSize(715, 720));
        actionOpen_AVI = new QAction(IrisCompare);
        actionOpen_AVI->setObjectName(QStringLiteral("actionOpen_AVI"));
        actionOpen_CAM = new QAction(IrisCompare);
        actionOpen_CAM->setObjectName(QStringLiteral("actionOpen_CAM"));
        actionOpen_CAM->setEnabled(true);
        actionSelect_cascade = new QAction(IrisCompare);
        actionSelect_cascade->setObjectName(QStringLiteral("actionSelect_cascade"));
        actionStart_Match = new QAction(IrisCompare);
        actionStart_Match->setObjectName(QStringLiteral("actionStart_Match"));
        actionOpen_IRIS_AVI = new QAction(IrisCompare);
        actionOpen_IRIS_AVI->setObjectName(QStringLiteral("actionOpen_IRIS_AVI"));
        actionOpen_IRIS_AVI->setEnabled(false);
        actionImage_Quality = new QAction(IrisCompare);
        actionImage_Quality->setObjectName(QStringLiteral("actionImage_Quality"));
        actionMatching = new QAction(IrisCompare);
        actionMatching->setObjectName(QStringLiteral("actionMatching"));
        actionNonmatching = new QAction(IrisCompare);
        actionNonmatching->setObjectName(QStringLiteral("actionNonmatching"));
        actionROC = new QAction(IrisCompare);
        actionROC->setObjectName(QStringLiteral("actionROC"));
        actionReducedROC = new QAction(IrisCompare);
        actionReducedROC->setObjectName(QStringLiteral("actionReducedROC"));
        actionReports = new QAction(IrisCompare);
        actionReports->setObjectName(QStringLiteral("actionReports"));
        actionOpen_Iris_Analysis = new QAction(IrisCompare);
        actionOpen_Iris_Analysis->setObjectName(QStringLiteral("actionOpen_Iris_Analysis"));
        actionStep_By_Step_Anaysis = new QAction(IrisCompare);
        actionStep_By_Step_Anaysis->setObjectName(QStringLiteral("actionStep_By_Step_Anaysis"));
        m_centralwidget = new QWidget(IrisCompare);
        m_centralwidget->setObjectName(QStringLiteral("m_centralwidget"));
        tabWidget = new QTabWidget(m_centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 20, 691, 661));
        tabWidget->setBaseSize(QSize(0, 2));
        Detection = new QWidget();
        Detection->setObjectName(QStringLiteral("Detection"));
        imgWidget = new ImageWidget(Detection);
        imgWidget->setObjectName(QStringLiteral("imgWidget"));
        imgWidget->setGeometry(QRect(10, 10, 661, 611));
        tabWidget->addTab(Detection, QString());
        Match = new QWidget();
        Match->setObjectName(QStringLiteral("Match"));
        imgLeftWidget1 = new ImageWidget(Match);
        imgLeftWidget1->setObjectName(QStringLiteral("imgLeftWidget1"));
        imgLeftWidget1->setGeometry(QRect(19, 50, 241, 160));
        btnOpenLeft1 = new QPushButton(Match);
        btnOpenLeft1->setObjectName(QStringLiteral("btnOpenLeft1"));
        btnOpenLeft1->setGeometry(QRect(40, 20, 191, 25));
        imgLeftWidget2 = new ImageWidget(Match);
        imgLeftWidget2->setObjectName(QStringLiteral("imgLeftWidget2"));
        imgLeftWidget2->setGeometry(QRect(289, 50, 241, 160));
        btnOpenLeft2 = new QPushButton(Match);
        btnOpenLeft2->setObjectName(QStringLiteral("btnOpenLeft2"));
        btnOpenLeft2->setGeometry(QRect(310, 20, 191, 25));
        btnOpenRight1 = new QPushButton(Match);
        btnOpenRight1->setObjectName(QStringLiteral("btnOpenRight1"));
        btnOpenRight1->setGeometry(QRect(40, 280, 191, 25));
        btnOpenRight2 = new QPushButton(Match);
        btnOpenRight2->setObjectName(QStringLiteral("btnOpenRight2"));
        btnOpenRight2->setGeometry(QRect(310, 280, 191, 25));
        imgRightWidget1 = new ImageWidget(Match);
        imgRightWidget1->setObjectName(QStringLiteral("imgRightWidget1"));
        imgRightWidget1->setEnabled(true);
        imgRightWidget1->setGeometry(QRect(19, 310, 241, 160));
        imgRightWidget2 = new ImageWidget(Match);
        imgRightWidget2->setObjectName(QStringLiteral("imgRightWidget2"));
        imgRightWidget2->setGeometry(QRect(289, 310, 241, 160));
        btnGoMatch = new QPushButton(Match);
        btnGoMatch->setObjectName(QStringLiteral("btnGoMatch"));
        btnGoMatch->setGeometry(QRect(260, 550, 121, 61));
        QFont font;
        font.setPointSize(16);
        btnGoMatch->setFont(font);
        txtLeftResult = new QLabel(Match);
        txtLeftResult->setObjectName(QStringLiteral("txtLeftResult"));
        txtLeftResult->setGeometry(QRect(550, 50, 121, 160));
        QFont font1;
        font1.setPointSize(14);
        txtLeftResult->setFont(font1);
        txtLeftResult->setAlignment(Qt::AlignCenter);
        txtRightResult = new QLabel(Match);
        txtRightResult->setObjectName(QStringLiteral("txtRightResult"));
        txtRightResult->setGeometry(QRect(550, 310, 121, 160));
        txtRightResult->setFont(font1);
        txtRightResult->setAlignment(Qt::AlignCenter);
        txtLeftDataType1 = new QLabel(Match);
        txtLeftDataType1->setObjectName(QStringLiteral("txtLeftDataType1"));
        txtLeftDataType1->setGeometry(QRect(40, 220, 201, 21));
        QFont font2;
        font2.setPointSize(8);
        font2.setBold(true);
        font2.setWeight(75);
        font2.setStrikeOut(false);
        txtLeftDataType1->setFont(font2);
        txtLeftDataType1->setScaledContents(false);
        txtLeftDataType1->setAlignment(Qt::AlignCenter);
        txtLeftDataType2 = new QLabel(Match);
        txtLeftDataType2->setObjectName(QStringLiteral("txtLeftDataType2"));
        txtLeftDataType2->setGeometry(QRect(310, 220, 201, 21));
        txtLeftDataType2->setFont(font2);
        txtLeftDataType2->setScaledContents(false);
        txtLeftDataType2->setAlignment(Qt::AlignCenter);
        txtRightDataType1 = new QLabel(Match);
        txtRightDataType1->setObjectName(QStringLiteral("txtRightDataType1"));
        txtRightDataType1->setGeometry(QRect(40, 480, 201, 21));
        txtRightDataType1->setFont(font2);
        txtRightDataType1->setScaledContents(false);
        txtRightDataType1->setAlignment(Qt::AlignCenter);
        txtRightDataType2 = new QLabel(Match);
        txtRightDataType2->setObjectName(QStringLiteral("txtRightDataType2"));
        txtRightDataType2->setGeometry(QRect(310, 480, 201, 21));
        txtRightDataType2->setFont(font2);
        txtRightDataType2->setScaledContents(false);
        txtRightDataType2->setAlignment(Qt::AlignCenter);
        tabWidget->addTab(Match, QString());
        IrisCompare->setCentralWidget(m_centralwidget);
        m_menuBar = new QMenuBar(IrisCompare);
        m_menuBar->setObjectName(QStringLiteral("m_menuBar"));
        m_menuBar->setGeometry(QRect(0, 0, 711, 22));
        menuFiles = new QMenu(m_menuBar);
        menuFiles->setObjectName(QStringLiteral("menuFiles"));
        menuCascade = new QMenu(m_menuBar);
        menuCascade->setObjectName(QStringLiteral("menuCascade"));
        menuMatch = new QMenu(m_menuBar);
        menuMatch->setObjectName(QStringLiteral("menuMatch"));
        menuQuality = new QMenu(m_menuBar);
        menuQuality->setObjectName(QStringLiteral("menuQuality"));
        menuAnalysis = new QMenu(m_menuBar);
        menuAnalysis->setObjectName(QStringLiteral("menuAnalysis"));
        IrisCompare->setMenuBar(m_menuBar);
        m_statusBar = new QStatusBar(IrisCompare);
        m_statusBar->setObjectName(QStringLiteral("m_statusBar"));
        IrisCompare->setStatusBar(m_statusBar);

        m_menuBar->addAction(menuCascade->menuAction());
        m_menuBar->addAction(menuFiles->menuAction());
        m_menuBar->addAction(menuQuality->menuAction());
        m_menuBar->addAction(menuMatch->menuAction());
        m_menuBar->addAction(menuAnalysis->menuAction());
        menuFiles->addAction(actionOpen_AVI);
        menuFiles->addSeparator();
        menuFiles->addAction(actionOpen_IRIS_AVI);
        menuFiles->addSeparator();
        menuFiles->addAction(actionOpen_CAM);
        menuCascade->addAction(actionSelect_cascade);
        menuMatch->addAction(actionStart_Match);
        menuQuality->addAction(actionImage_Quality);
        menuAnalysis->addAction(actionReports);

        retranslateUi(IrisCompare);
        QObject::connect(actionOpen_AVI, SIGNAL(triggered()), IrisCompare, SLOT(OpenAVIFile()));
        QObject::connect(actionOpen_CAM, SIGNAL(triggered()), IrisCompare, SLOT(OpenCAM()));
        QObject::connect(actionSelect_cascade, SIGNAL(triggered()), IrisCompare, SLOT(SelectCascade()));
        QObject::connect(actionStart_Match, SIGNAL(triggered()), IrisCompare, SLOT(StartMatch()));
        QObject::connect(actionOpen_IRIS_AVI, SIGNAL(triggered()), IrisCompare, SLOT(OpenIrisAVIFile()));
        QObject::connect(actionImage_Quality, SIGNAL(triggered()), IrisCompare, SLOT(checkQuality()));
        QObject::connect(btnOpenLeft1, SIGNAL(clicked()), IrisCompare, SLOT(openLeftEye1()));
        QObject::connect(btnOpenLeft2, SIGNAL(clicked()), IrisCompare, SLOT(openLeftEye2()));
        QObject::connect(btnOpenRight1, SIGNAL(clicked()), IrisCompare, SLOT(openRightEye1()));
        QObject::connect(btnOpenRight2, SIGNAL(clicked()), IrisCompare, SLOT(openRightEye2()));
        QObject::connect(btnGoMatch, SIGNAL(clicked()), IrisCompare, SLOT(goMatch()));
        QObject::connect(actionReports, SIGNAL(triggered()), IrisCompare, SLOT(generateReports()));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(IrisCompare);
    } // setupUi

    void retranslateUi(QMainWindow *IrisCompare)
    {
        IrisCompare->setWindowTitle(QApplication::translate("IrisCompare", "Iris Compare", Q_NULLPTR));
        actionOpen_AVI->setText(QApplication::translate("IrisCompare", "Open FACE AVI", Q_NULLPTR));
        actionOpen_CAM->setText(QApplication::translate("IrisCompare", "Open CAM", Q_NULLPTR));
        actionSelect_cascade->setText(QApplication::translate("IrisCompare", "Select cascade", "Select cascade for the eye detection"));
        actionStart_Match->setText(QApplication::translate("IrisCompare", "Choose...", Q_NULLPTR));
        actionOpen_IRIS_AVI->setText(QApplication::translate("IrisCompare", "Open IRIS AVI", Q_NULLPTR));
        actionImage_Quality->setText(QApplication::translate("IrisCompare", "Choose...", Q_NULLPTR));
        actionMatching->setText(QApplication::translate("IrisCompare", "Matching", Q_NULLPTR));
        actionNonmatching->setText(QApplication::translate("IrisCompare", "Nonmatching", Q_NULLPTR));
        actionROC->setText(QApplication::translate("IrisCompare", "ROC", Q_NULLPTR));
        actionReducedROC->setText(QApplication::translate("IrisCompare", "ReducedROC", Q_NULLPTR));
        actionReports->setText(QApplication::translate("IrisCompare", "Reports", Q_NULLPTR));
        actionOpen_Iris_Analysis->setText(QApplication::translate("IrisCompare", "Open Iris Analysis", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionOpen_Iris_Analysis->setToolTip(QApplication::translate("IrisCompare", "Open iris analysis window", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionStep_By_Step_Anaysis->setText(QApplication::translate("IrisCompare", "Step By Step Anaysis", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Detection), QApplication::translate("IrisCompare", "Detection", Q_NULLPTR));
        btnOpenLeft1->setText(QApplication::translate("IrisCompare", "Open Left Image (Target)", Q_NULLPTR));
        btnOpenLeft2->setText(QApplication::translate("IrisCompare", "Open Left Image (Query)", Q_NULLPTR));
        btnOpenRight1->setText(QApplication::translate("IrisCompare", "Open Right Image (Target)", Q_NULLPTR));
        btnOpenRight2->setText(QApplication::translate("IrisCompare", "Open Right Image (Query)", Q_NULLPTR));
        btnGoMatch->setText(QApplication::translate("IrisCompare", "Compare", Q_NULLPTR));
        txtLeftResult->setText(QApplication::translate("IrisCompare", "?", Q_NULLPTR));
        txtRightResult->setText(QApplication::translate("IrisCompare", "?", Q_NULLPTR));
        txtLeftDataType1->setText(QApplication::translate("IrisCompare", "Data Type here", Q_NULLPTR));
        txtLeftDataType2->setText(QApplication::translate("IrisCompare", "Data Type here", Q_NULLPTR));
        txtRightDataType1->setText(QApplication::translate("IrisCompare", "Data Type here", Q_NULLPTR));
        txtRightDataType2->setText(QApplication::translate("IrisCompare", "Data Type here", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Match), QApplication::translate("IrisCompare", "Match", Q_NULLPTR));
        menuFiles->setTitle(QApplication::translate("IrisCompare", "Detect", Q_NULLPTR));
        menuCascade->setTitle(QApplication::translate("IrisCompare", "Cascade", Q_NULLPTR));
        menuMatch->setTitle(QApplication::translate("IrisCompare", "Match", Q_NULLPTR));
        menuQuality->setTitle(QApplication::translate("IrisCompare", "Quality", Q_NULLPTR));
        menuAnalysis->setTitle(QApplication::translate("IrisCompare", "Analysis", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class IrisCompare: public Ui_IrisCompare {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IRISCOMPARE_H

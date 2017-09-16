/********************************************************************************
** Form generated from reading UI file 'IrisAnalysisUI.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IRISANALYSISUI_H
#define UI_IRISANALYSISUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IrisAnalysisUI
{
public:
    QWidget *centralwidget;
    QLabel *imageView;
    QLabel *imageFileName;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *loadImageBtn;
    QPushButton *zoomInBtn;
    QPushButton *zoomOutBtn;
    QPushButton *scale1Btn;
    QPushButton *analysis0Btn;
    QPushButton *analysis1Btn;
    QLabel *qualityValue;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *IrisAnalysisUI)
    {
        if (IrisAnalysisUI->objectName().isEmpty())
            IrisAnalysisUI->setObjectName(QStringLiteral("IrisAnalysisUI"));
        IrisAnalysisUI->resize(786, 764);
        centralwidget = new QWidget(IrisAnalysisUI);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        imageView = new QLabel(centralwidget);
        imageView->setObjectName(QStringLiteral("imageView"));
        imageView->setGeometry(QRect(10, 115, 596, 371));
        imageView->setAutoFillBackground(true);
        imageFileName = new QLabel(centralwidget);
        imageFileName->setObjectName(QStringLiteral("imageFileName"));
        imageFileName->setGeometry(QRect(10, 60, 491, 36));
        imageFileName->setAutoFillBackground(true);
        imageFileName->setLineWidth(1);
        imageFileName->setWordWrap(true);
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(5, 10, 731, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        loadImageBtn = new QPushButton(horizontalLayoutWidget);
        loadImageBtn->setObjectName(QStringLiteral("loadImageBtn"));

        horizontalLayout->addWidget(loadImageBtn);

        zoomInBtn = new QPushButton(horizontalLayoutWidget);
        zoomInBtn->setObjectName(QStringLiteral("zoomInBtn"));
        zoomInBtn->setEnabled(false);

        horizontalLayout->addWidget(zoomInBtn);

        zoomOutBtn = new QPushButton(horizontalLayoutWidget);
        zoomOutBtn->setObjectName(QStringLiteral("zoomOutBtn"));
        zoomOutBtn->setEnabled(false);

        horizontalLayout->addWidget(zoomOutBtn);

        scale1Btn = new QPushButton(horizontalLayoutWidget);
        scale1Btn->setObjectName(QStringLiteral("scale1Btn"));
        scale1Btn->setEnabled(false);

        horizontalLayout->addWidget(scale1Btn);

        analysis0Btn = new QPushButton(horizontalLayoutWidget);
        analysis0Btn->setObjectName(QStringLiteral("analysis0Btn"));
        analysis0Btn->setEnabled(false);

        horizontalLayout->addWidget(analysis0Btn);

        analysis1Btn = new QPushButton(horizontalLayoutWidget);
        analysis1Btn->setObjectName(QStringLiteral("analysis1Btn"));
        analysis1Btn->setEnabled(false);

        horizontalLayout->addWidget(analysis1Btn);

        qualityValue = new QLabel(horizontalLayoutWidget);
        qualityValue->setObjectName(QStringLiteral("qualityValue"));
        qualityValue->setAutoFillBackground(true);

        horizontalLayout->addWidget(qualityValue);

        IrisAnalysisUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(IrisAnalysisUI);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 786, 22));
        IrisAnalysisUI->setMenuBar(menubar);
        statusbar = new QStatusBar(IrisAnalysisUI);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        IrisAnalysisUI->setStatusBar(statusbar);
        QWidget::setTabOrder(loadImageBtn, zoomInBtn);
        QWidget::setTabOrder(zoomInBtn, zoomOutBtn);
        QWidget::setTabOrder(zoomOutBtn, scale1Btn);
        QWidget::setTabOrder(scale1Btn, analysis0Btn);
        QWidget::setTabOrder(analysis0Btn, analysis1Btn);

        retranslateUi(IrisAnalysisUI);

        QMetaObject::connectSlotsByName(IrisAnalysisUI);
    } // setupUi

    void retranslateUi(QMainWindow *IrisAnalysisUI)
    {
        IrisAnalysisUI->setWindowTitle(QApplication::translate("IrisAnalysisUI", "MainWindow", Q_NULLPTR));
        imageView->setText(QString());
        imageFileName->setText(QString());
        loadImageBtn->setText(QApplication::translate("IrisAnalysisUI", "Load Image", Q_NULLPTR));
        zoomInBtn->setText(QApplication::translate("IrisAnalysisUI", "+", Q_NULLPTR));
        zoomOutBtn->setText(QApplication::translate("IrisAnalysisUI", "-", Q_NULLPTR));
        scale1Btn->setText(QApplication::translate("IrisAnalysisUI", "1", Q_NULLPTR));
        analysis0Btn->setText(QApplication::translate("IrisAnalysisUI", "Anaysis0", Q_NULLPTR));
        analysis1Btn->setText(QApplication::translate("IrisAnalysisUI", "Analysis 1", Q_NULLPTR));
        qualityValue->setText(QApplication::translate("IrisAnalysisUI", "Quality:0", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class IrisAnalysisUI: public Ui_IrisAnalysisUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IRISANALYSISUI_H

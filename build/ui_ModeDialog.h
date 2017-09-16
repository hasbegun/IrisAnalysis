/********************************************************************************
** Form generated from reading UI file 'ModeDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODEDIALOG_H
#define UI_MODEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModeDialog
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *stillRadioButton;
    QRadioButton *videoRadioButton;

    void setupUi(QDialog *ModeDialog)
    {
        if (ModeDialog->objectName().isEmpty())
            ModeDialog->setObjectName(QStringLiteral("ModeDialog"));
        ModeDialog->setWindowModality(Qt::WindowModal);
        ModeDialog->resize(241, 181);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ModeDialog->sizePolicy().hasHeightForWidth());
        ModeDialog->setSizePolicy(sizePolicy);
        ModeDialog->setModal(true);
        buttonBox = new QDialogButtonBox(ModeDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(40, 140, 161, 32));
        buttonBox->setLayoutDirection(Qt::RightToLeft);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(ModeDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 10, 181, 111));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 161, 80));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        stillRadioButton = new QRadioButton(layoutWidget);
        stillRadioButton->setObjectName(QStringLiteral("stillRadioButton"));

        verticalLayout->addWidget(stillRadioButton);

        videoRadioButton = new QRadioButton(layoutWidget);
        videoRadioButton->setObjectName(QStringLiteral("videoRadioButton"));

        verticalLayout->addWidget(videoRadioButton);


        retranslateUi(ModeDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ModeDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ModeDialog, SLOT(reject()));
        QObject::connect(stillRadioButton, SIGNAL(clicked()), ModeDialog, SLOT(modeButtonClicked()));
        QObject::connect(videoRadioButton, SIGNAL(clicked()), ModeDialog, SLOT(modeButtonClicked()));

        QMetaObject::connectSlotsByName(ModeDialog);
    } // setupUi

    void retranslateUi(QDialog *ModeDialog)
    {
        ModeDialog->setWindowTitle(QApplication::translate("ModeDialog", "Select Mode", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("ModeDialog", "Mode", Q_NULLPTR));
        stillRadioButton->setText(QApplication::translate("ModeDialog", "Classical Still Image", Q_NULLPTR));
        videoRadioButton->setText(QApplication::translate("ModeDialog", "Distant Video Frame", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ModeDialog: public Ui_ModeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODEDIALOG_H

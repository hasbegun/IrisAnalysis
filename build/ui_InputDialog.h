/********************************************************************************
** Form generated from reading UI file 'InputDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTDIALOG_H
#define UI_INPUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_InputDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QTextEdit *txtInputFilePath;
    QLabel *label_2;
    QRadioButton *radioLeft;
    QRadioButton *radioRight;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QTextEdit *txtCode4Query;
    QTextEdit *txtFileList4Query;
    QPushButton *btnLoading4Query;
    QTextEdit *txtCode4Target;
    QTextEdit *txtFileList4Target;
    QPushButton *btnLoading4Target;
    QLabel *label_7;
    QLabel *label_8;
    QTextEdit *txtOutputFileName;
    QPushButton *btnLoadingFilePath;
    QButtonGroup *radioBtnGroup;

    void setupUi(QDialog *InputDialog)
    {
        if (InputDialog->objectName().isEmpty())
            InputDialog->setObjectName(QStringLiteral("InputDialog"));
        InputDialog->resize(600, 515);
        buttonBox = new QDialogButtonBox(InputDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(100, 480, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(InputDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 30, 251, 31));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        txtInputFilePath = new QTextEdit(InputDialog);
        txtInputFilePath->setObjectName(QStringLiteral("txtInputFilePath"));
        txtInputFilePath->setGeometry(QRect(30, 60, 501, 31));
        label_2 = new QLabel(InputDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 130, 171, 31));
        label_2->setFont(font);
        radioLeft = new QRadioButton(InputDialog);
        radioBtnGroup = new QButtonGroup(InputDialog);
        radioBtnGroup->setObjectName(QStringLiteral("radioBtnGroup"));
        radioBtnGroup->addButton(radioLeft);
        radioLeft->setObjectName(QStringLiteral("radioLeft"));
        radioLeft->setGeometry(QRect(270, 140, 95, 20));
        radioLeft->setIconSize(QSize(20, 20));
        radioRight = new QRadioButton(InputDialog);
        radioBtnGroup->addButton(radioRight);
        radioRight->setObjectName(QStringLiteral("radioRight"));
        radioRight->setGeometry(QRect(390, 140, 95, 20));
        radioRight->setIconSize(QSize(20, 20));
        label_3 = new QLabel(InputDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 200, 541, 31));
        label_3->setFont(font);
        label_4 = new QLabel(InputDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 260, 51, 31));
        QFont font1;
        font1.setPointSize(9);
        label_4->setFont(font1);
        label_5 = new QLabel(InputDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(70, 230, 41, 31));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(InputDialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(130, 230, 101, 31));
        label_6->setFont(font1);
        txtCode4Query = new QTextEdit(InputDialog);
        txtCode4Query->setObjectName(QStringLiteral("txtCode4Query"));
        txtCode4Query->setGeometry(QRect(70, 260, 41, 31));
        txtFileList4Query = new QTextEdit(InputDialog);
        txtFileList4Query->setObjectName(QStringLiteral("txtFileList4Query"));
        txtFileList4Query->setGeometry(QRect(120, 260, 411, 31));
        btnLoading4Query = new QPushButton(InputDialog);
        btnLoading4Query->setObjectName(QStringLiteral("btnLoading4Query"));
        btnLoading4Query->setGeometry(QRect(530, 260, 41, 28));
        txtCode4Target = new QTextEdit(InputDialog);
        txtCode4Target->setObjectName(QStringLiteral("txtCode4Target"));
        txtCode4Target->setGeometry(QRect(70, 300, 41, 31));
        txtFileList4Target = new QTextEdit(InputDialog);
        txtFileList4Target->setObjectName(QStringLiteral("txtFileList4Target"));
        txtFileList4Target->setGeometry(QRect(120, 300, 411, 31));
        btnLoading4Target = new QPushButton(InputDialog);
        btnLoading4Target->setObjectName(QStringLiteral("btnLoading4Target"));
        btnLoading4Target->setGeometry(QRect(530, 300, 41, 28));
        label_7 = new QLabel(InputDialog);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 300, 51, 31));
        label_7->setFont(font1);
        label_8 = new QLabel(InputDialog);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(30, 370, 231, 31));
        label_8->setFont(font);
        txtOutputFileName = new QTextEdit(InputDialog);
        txtOutputFileName->setObjectName(QStringLiteral("txtOutputFileName"));
        txtOutputFileName->setGeometry(QRect(30, 400, 541, 31));
        btnLoadingFilePath = new QPushButton(InputDialog);
        btnLoadingFilePath->setObjectName(QStringLiteral("btnLoadingFilePath"));
        btnLoadingFilePath->setGeometry(QRect(530, 60, 41, 28));

        retranslateUi(InputDialog);
        QObject::connect(btnLoading4Query, SIGNAL(clicked()), InputDialog, SLOT(btnLoadingQueryClicked()));
        QObject::connect(btnLoading4Target, SIGNAL(clicked()), InputDialog, SLOT(btnLoadingTargetClicked()));
        QObject::connect(buttonBox, SIGNAL(rejected()), InputDialog, SLOT(reject()));
        QObject::connect(buttonBox, SIGNAL(accepted()), InputDialog, SLOT(btnAcceptClicked()));
        QObject::connect(btnLoadingFilePath, SIGNAL(clicked()), InputDialog, SLOT(btnLoadingFilePathClicked()));

        QMetaObject::connectSlotsByName(InputDialog);
    } // setupUi

    void retranslateUi(QDialog *InputDialog)
    {
        InputDialog->setWindowTitle(QApplication::translate("InputDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("InputDialog", "1. Enter or choose the file path:", Q_NULLPTR));
        label_2->setText(QApplication::translate("InputDialog", "2. Select eye position:", Q_NULLPTR));
        radioLeft->setText(QApplication::translate("InputDialog", "LEFT", Q_NULLPTR));
        radioRight->setText(QApplication::translate("InputDialog", "RIGHT", Q_NULLPTR));
        label_3->setText(QApplication::translate("InputDialog", "3. Enter dataset code and load the file that contains the list of imagery", Q_NULLPTR));
        label_4->setText(QApplication::translate("InputDialog", "Query", Q_NULLPTR));
        label_5->setText(QApplication::translate("InputDialog", "Code", Q_NULLPTR));
        label_6->setText(QApplication::translate("InputDialog", "File Name", Q_NULLPTR));
        btnLoading4Query->setText(QApplication::translate("InputDialog", "...", Q_NULLPTR));
        btnLoading4Target->setText(QApplication::translate("InputDialog", "...", Q_NULLPTR));
        label_7->setText(QApplication::translate("InputDialog", "Target", Q_NULLPTR));
        label_8->setText(QApplication::translate("InputDialog", "4. Enter the output file name:", Q_NULLPTR));
        btnLoadingFilePath->setText(QApplication::translate("InputDialog", "...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InputDialog: public Ui_InputDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTDIALOG_H

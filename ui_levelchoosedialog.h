/********************************************************************************
** Form generated from reading UI file 'levelchoosedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEVELCHOOSEDIALOG_H
#define UI_LEVELCHOOSEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LevelChooseDialog
{
public:
    QLabel *label;
    QPushButton *level1_btn;
    QPushButton *level2_btn;
    QPushButton *level3_btn;
    QPushButton *level4_btn;
    QPushButton *about_btn;

    void setupUi(QDialog *LevelChooseDialog)
    {
        if (LevelChooseDialog->objectName().isEmpty())
            LevelChooseDialog->setObjectName(QString::fromUtf8("LevelChooseDialog"));
        LevelChooseDialog->resize(1920, 1080);
        label = new QLabel(LevelChooseDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 1920, 1080));
        label->setPixmap(QPixmap(QString::fromUtf8("resources/bg.png")));
        level1_btn = new QPushButton(LevelChooseDialog);
        level1_btn->setObjectName(QString::fromUtf8("level1_btn"));
        level1_btn->setGeometry(QRect(490, 200, 1048, 145));
        level1_btn->setStyleSheet(QString::fromUtf8("border:0px;"));
        level2_btn = new QPushButton(LevelChooseDialog);
        level2_btn->setObjectName(QString::fromUtf8("level2_btn"));
        level2_btn->setGeometry(QRect(490, 400, 1048, 145));
        level2_btn->setStyleSheet(QString::fromUtf8("border:0px;"));
        level3_btn = new QPushButton(LevelChooseDialog);
        level3_btn->setObjectName(QString::fromUtf8("level3_btn"));
        level3_btn->setGeometry(QRect(490, 620, 1048, 145));
        level3_btn->setStyleSheet(QString::fromUtf8("border:0px;"));
        level4_btn = new QPushButton(LevelChooseDialog);
        level4_btn->setObjectName(QString::fromUtf8("level4_btn"));
        level4_btn->setGeometry(QRect(490, 820, 1048, 145));
        level4_btn->setStyleSheet(QString::fromUtf8("border:0px;"));
        about_btn = new QPushButton(LevelChooseDialog);
        about_btn->setObjectName(QString::fromUtf8("about_btn"));
        about_btn->setGeometry(QRect(50, 910, 133, 133));

        retranslateUi(LevelChooseDialog);

        QMetaObject::connectSlotsByName(LevelChooseDialog);
    } // setupUi

    void retranslateUi(QDialog *LevelChooseDialog)
    {
        LevelChooseDialog->setWindowTitle(QCoreApplication::translate("LevelChooseDialog", "Human Resource Machine", nullptr));
        label->setText(QString());
        level1_btn->setText(QString());
        level2_btn->setText(QString());
        level3_btn->setText(QString());
        level4_btn->setText(QString());
        about_btn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LevelChooseDialog: public Ui_LevelChooseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEVELCHOOSEDIALOG_H

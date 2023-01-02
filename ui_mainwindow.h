/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainWindow
{
public:
    QWidget *centralwidget;
    QLabel *bg;
    QLabel *level_lbl;
    QTextEdit *information_txt;
    QLabel *num_lbl1;
    QLabel *num_lbl2;
    QLabel *num_lbl3;
    QLabel *num_lbl4;
    QLabel *num_lbl5;
    QLabel *num_lbl6;
    QLabel *num_lbl7;
    QLabel *num_lbl8;
    QLabel *num_lbl9;
    QLabel *num_lbl10;
    QLabel *num_lbl11;
    QLabel *cmd_lbl_1;
    QLabel *cmd_lbl_2;
    QLabel *cmd_lbl_3;
    QLabel *cmd_lbl_4;
    QLabel *cmd_lbl_5;
    QLabel *cmd_lbl_6;
    QLabel *cmd_lbl_7;
    QLabel *cmd_lbl_8;
    QLabel *cmd_lbl_9;
    QLabel *cmd_lbl_10;
    QLabel *cmd_lbl_11;
    QPushButton *run_btn;
    QPushButton *load_btn;
    QLabel *inbox_lbl_1;
    QLabel *outbox_lbl_1;
    QLabel *outbox_lbl_2;
    QLabel *outbox_lbl_3;
    QLabel *outbox_lbl_4;
    QLabel *human_lbl;
    QLabel *inbox_lbl_2;
    QLabel *inbox_lbl_3;
    QLabel *inbox_lbl_4;
    QLabel *current_llbl;
    QLabel *space_1;
    QLabel *space_2;
    QLabel *space_3;
    QLabel *space_4;
    QLabel *space_5;
    QLabel *space_6;
    QLabel *space_7;
    QLabel *space_8;
    QPushButton *help_btn;

    void setupUi(QMainWindow *mainWindow)
    {
        if (mainWindow->objectName().isEmpty())
            mainWindow->setObjectName(QString::fromUtf8("mainWindow"));
        mainWindow->resize(1920, 1044);
        centralwidget = new QWidget(mainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        bg = new QLabel(centralwidget);
        bg->setObjectName(QString::fromUtf8("bg"));
        bg->setGeometry(QRect(0, 0, 1920, 1048));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        font.setKerning(false);
        bg->setFont(font);
        bg->setPixmap(QPixmap(QString::fromUtf8("resources/bg_main.png")));
        level_lbl = new QLabel(centralwidget);
        level_lbl->setObjectName(QString::fromUtf8("level_lbl"));
        level_lbl->setGeometry(QRect(1495, 58, 371, 58));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        font1.setKerning(false);
        font1.setStyleStrategy(QFont::PreferDefault);
        level_lbl->setFont(font1);
        level_lbl->setStyleSheet(QString::fromUtf8("color:#82776e;"));
        information_txt = new QTextEdit(centralwidget);
        information_txt->setObjectName(QString::fromUtf8("information_txt"));
        information_txt->setGeometry(QRect(1500, 180, 351, 241));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font2.setPointSize(10);
        information_txt->setFont(font2);
        information_txt->setStyleSheet(QString::fromUtf8("background-color:rgb(218, 214, 181);\n"
"border:0px;\n"
"\n"
"\n"
"\n"
""));
        information_txt->setReadOnly(true);
        num_lbl1 = new QLabel(centralwidget);
        num_lbl1->setObjectName(QString::fromUtf8("num_lbl1"));
        num_lbl1->setGeometry(QRect(1480, 519, 31, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial"));
        font3.setPointSize(10);
        num_lbl1->setFont(font3);
        num_lbl2 = new QLabel(centralwidget);
        num_lbl2->setObjectName(QString::fromUtf8("num_lbl2"));
        num_lbl2->setGeometry(QRect(1480, 560, 31, 31));
        num_lbl2->setFont(font3);
        num_lbl3 = new QLabel(centralwidget);
        num_lbl3->setObjectName(QString::fromUtf8("num_lbl3"));
        num_lbl3->setGeometry(QRect(1480, 600, 31, 31));
        num_lbl3->setFont(font3);
        num_lbl4 = new QLabel(centralwidget);
        num_lbl4->setObjectName(QString::fromUtf8("num_lbl4"));
        num_lbl4->setGeometry(QRect(1480, 640, 31, 31));
        num_lbl4->setFont(font3);
        num_lbl5 = new QLabel(centralwidget);
        num_lbl5->setObjectName(QString::fromUtf8("num_lbl5"));
        num_lbl5->setGeometry(QRect(1480, 680, 31, 31));
        num_lbl5->setFont(font3);
        num_lbl6 = new QLabel(centralwidget);
        num_lbl6->setObjectName(QString::fromUtf8("num_lbl6"));
        num_lbl6->setGeometry(QRect(1480, 720, 31, 31));
        num_lbl6->setFont(font3);
        num_lbl7 = new QLabel(centralwidget);
        num_lbl7->setObjectName(QString::fromUtf8("num_lbl7"));
        num_lbl7->setGeometry(QRect(1480, 760, 31, 31));
        num_lbl7->setFont(font3);
        num_lbl8 = new QLabel(centralwidget);
        num_lbl8->setObjectName(QString::fromUtf8("num_lbl8"));
        num_lbl8->setGeometry(QRect(1480, 800, 31, 31));
        num_lbl8->setFont(font3);
        num_lbl9 = new QLabel(centralwidget);
        num_lbl9->setObjectName(QString::fromUtf8("num_lbl9"));
        num_lbl9->setGeometry(QRect(1480, 840, 31, 31));
        num_lbl9->setFont(font3);
        num_lbl10 = new QLabel(centralwidget);
        num_lbl10->setObjectName(QString::fromUtf8("num_lbl10"));
        num_lbl10->setGeometry(QRect(1480, 880, 31, 31));
        num_lbl10->setFont(font3);
        num_lbl11 = new QLabel(centralwidget);
        num_lbl11->setObjectName(QString::fromUtf8("num_lbl11"));
        num_lbl11->setGeometry(QRect(1480, 920, 31, 31));
        num_lbl11->setFont(font3);
        cmd_lbl_1 = new QLabel(centralwidget);
        cmd_lbl_1->setObjectName(QString::fromUtf8("cmd_lbl_1"));
        cmd_lbl_1->setGeometry(QRect(1580, 520, 271, 31));
        cmd_lbl_1->setFont(font2);
        cmd_lbl_2 = new QLabel(centralwidget);
        cmd_lbl_2->setObjectName(QString::fromUtf8("cmd_lbl_2"));
        cmd_lbl_2->setGeometry(QRect(1580, 560, 271, 31));
        cmd_lbl_2->setFont(font2);
        cmd_lbl_3 = new QLabel(centralwidget);
        cmd_lbl_3->setObjectName(QString::fromUtf8("cmd_lbl_3"));
        cmd_lbl_3->setGeometry(QRect(1580, 600, 271, 31));
        cmd_lbl_3->setFont(font2);
        cmd_lbl_4 = new QLabel(centralwidget);
        cmd_lbl_4->setObjectName(QString::fromUtf8("cmd_lbl_4"));
        cmd_lbl_4->setGeometry(QRect(1580, 640, 271, 31));
        cmd_lbl_4->setFont(font2);
        cmd_lbl_5 = new QLabel(centralwidget);
        cmd_lbl_5->setObjectName(QString::fromUtf8("cmd_lbl_5"));
        cmd_lbl_5->setGeometry(QRect(1580, 680, 271, 31));
        cmd_lbl_5->setFont(font2);
        cmd_lbl_6 = new QLabel(centralwidget);
        cmd_lbl_6->setObjectName(QString::fromUtf8("cmd_lbl_6"));
        cmd_lbl_6->setGeometry(QRect(1580, 720, 271, 31));
        cmd_lbl_6->setFont(font2);
        cmd_lbl_7 = new QLabel(centralwidget);
        cmd_lbl_7->setObjectName(QString::fromUtf8("cmd_lbl_7"));
        cmd_lbl_7->setGeometry(QRect(1580, 760, 271, 31));
        cmd_lbl_7->setFont(font2);
        cmd_lbl_8 = new QLabel(centralwidget);
        cmd_lbl_8->setObjectName(QString::fromUtf8("cmd_lbl_8"));
        cmd_lbl_8->setGeometry(QRect(1580, 800, 271, 31));
        cmd_lbl_8->setFont(font2);
        cmd_lbl_9 = new QLabel(centralwidget);
        cmd_lbl_9->setObjectName(QString::fromUtf8("cmd_lbl_9"));
        cmd_lbl_9->setGeometry(QRect(1580, 840, 271, 31));
        cmd_lbl_9->setFont(font2);
        cmd_lbl_10 = new QLabel(centralwidget);
        cmd_lbl_10->setObjectName(QString::fromUtf8("cmd_lbl_10"));
        cmd_lbl_10->setGeometry(QRect(1580, 880, 271, 31));
        cmd_lbl_10->setFont(font2);
        cmd_lbl_11 = new QLabel(centralwidget);
        cmd_lbl_11->setObjectName(QString::fromUtf8("cmd_lbl_11"));
        cmd_lbl_11->setGeometry(QRect(1580, 920, 271, 31));
        cmd_lbl_11->setFont(font2);
        run_btn = new QPushButton(centralwidget);
        run_btn->setObjectName(QString::fromUtf8("run_btn"));
        run_btn->setGeometry(QRect(340, 946, 96, 96));
        load_btn = new QPushButton(centralwidget);
        load_btn->setObjectName(QString::fromUtf8("load_btn"));
        load_btn->setGeometry(QRect(490, 946, 354, 96));
        inbox_lbl_1 = new QLabel(centralwidget);
        inbox_lbl_1->setObjectName(QString::fromUtf8("inbox_lbl_1"));
        inbox_lbl_1->setGeometry(QRect(196, 590, 82, 82));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Arial"));
        font4.setPointSize(20);
        font4.setBold(true);
        font4.setWeight(75);
        inbox_lbl_1->setFont(font4);
        inbox_lbl_1->setStyleSheet(QString::fromUtf8("background-color:rgb(172, 200, 103);\n"
"border-radius:20px;\n"
"padding:2px 4px;"));
        inbox_lbl_1->setAlignment(Qt::AlignCenter);
        outbox_lbl_1 = new QLabel(centralwidget);
        outbox_lbl_1->setObjectName(QString::fromUtf8("outbox_lbl_1"));
        outbox_lbl_1->setGeometry(QRect(1180, 600, 82, 82));
        outbox_lbl_1->setFont(font4);
        outbox_lbl_1->setStyleSheet(QString::fromUtf8("background-color:rgb(172, 200, 103);\n"
"border-radius:20px;\n"
"padding:2px 4px;"));
        outbox_lbl_1->setAlignment(Qt::AlignCenter);
        outbox_lbl_2 = new QLabel(centralwidget);
        outbox_lbl_2->setObjectName(QString::fromUtf8("outbox_lbl_2"));
        outbox_lbl_2->setGeometry(QRect(1180, 700, 82, 82));
        outbox_lbl_2->setFont(font4);
        outbox_lbl_2->setStyleSheet(QString::fromUtf8("background-color:rgb(172, 200, 103);\n"
"border-radius:20px;\n"
"padding:2px 4px;"));
        outbox_lbl_2->setAlignment(Qt::AlignCenter);
        outbox_lbl_3 = new QLabel(centralwidget);
        outbox_lbl_3->setObjectName(QString::fromUtf8("outbox_lbl_3"));
        outbox_lbl_3->setGeometry(QRect(1180, 810, 82, 82));
        outbox_lbl_3->setFont(font4);
        outbox_lbl_3->setStyleSheet(QString::fromUtf8("background-color:rgb(172, 200, 103);\n"
"border-radius:20px;\n"
"padding:2px 4px;"));
        outbox_lbl_3->setAlignment(Qt::AlignCenter);
        outbox_lbl_4 = new QLabel(centralwidget);
        outbox_lbl_4->setObjectName(QString::fromUtf8("outbox_lbl_4"));
        outbox_lbl_4->setGeometry(QRect(1180, 920, 82, 82));
        outbox_lbl_4->setFont(font4);
        outbox_lbl_4->setStyleSheet(QString::fromUtf8("background-color:rgb(172, 200, 103);\n"
"border-radius:20px;\n"
"padding:2px 4px;"));
        outbox_lbl_4->setAlignment(Qt::AlignCenter);
        human_lbl = new QLabel(centralwidget);
        human_lbl->setObjectName(QString::fromUtf8("human_lbl"));
        human_lbl->setGeometry(QRect(350, 430, 104, 151));
        human_lbl->setPixmap(QPixmap(QString::fromUtf8("resources/Human.png")));
        inbox_lbl_2 = new QLabel(centralwidget);
        inbox_lbl_2->setObjectName(QString::fromUtf8("inbox_lbl_2"));
        inbox_lbl_2->setGeometry(QRect(196, 690, 82, 82));
        inbox_lbl_2->setFont(font4);
        inbox_lbl_2->setStyleSheet(QString::fromUtf8("background-color:rgb(172, 200, 103);\n"
"border-radius:20px;\n"
"padding:2px 4px;"));
        inbox_lbl_2->setAlignment(Qt::AlignCenter);
        inbox_lbl_3 = new QLabel(centralwidget);
        inbox_lbl_3->setObjectName(QString::fromUtf8("inbox_lbl_3"));
        inbox_lbl_3->setGeometry(QRect(196, 790, 82, 82));
        inbox_lbl_3->setFont(font4);
        inbox_lbl_3->setStyleSheet(QString::fromUtf8("background-color:rgb(172, 200, 103);\n"
"border-radius:20px;\n"
"padding:2px 4px;"));
        inbox_lbl_3->setAlignment(Qt::AlignCenter);
        inbox_lbl_4 = new QLabel(centralwidget);
        inbox_lbl_4->setObjectName(QString::fromUtf8("inbox_lbl_4"));
        inbox_lbl_4->setGeometry(QRect(196, 900, 82, 82));
        inbox_lbl_4->setFont(font4);
        inbox_lbl_4->setStyleSheet(QString::fromUtf8("background-color:rgb(172, 200, 103);\n"
"border-radius:20px;\n"
"padding:2px 4px;"));
        inbox_lbl_4->setAlignment(Qt::AlignCenter);
        current_llbl = new QLabel(centralwidget);
        current_llbl->setObjectName(QString::fromUtf8("current_llbl"));
        current_llbl->setGeometry(QRect(360, 350, 82, 82));
        current_llbl->setFont(font4);
        current_llbl->setStyleSheet(QString::fromUtf8("background-color:rgb(172, 200, 103);\n"
"border-radius:20px;\n"
"padding:2px 4px;"));
        current_llbl->setAlignment(Qt::AlignCenter);
        space_1 = new QLabel(centralwidget);
        space_1->setObjectName(QString::fromUtf8("space_1"));
        space_1->setGeometry(QRect(490, 600, 112, 112));
        space_1->setFont(font4);
        space_1->setStyleSheet(QString::fromUtf8("background-color:rgb(127, 119, 65);\n"
"border-radius:20px;\n"
"padding:2px 4px;"));
        space_1->setTextFormat(Qt::PlainText);
        space_1->setAlignment(Qt::AlignCenter);
        space_2 = new QLabel(centralwidget);
        space_2->setObjectName(QString::fromUtf8("space_2"));
        space_2->setGeometry(QRect(620, 600, 112, 112));
        space_2->setFont(font4);
        space_2->setStyleSheet(QString::fromUtf8("background-color:rgb(127, 119, 65);\n"
"border-radius:20px;\n"
"padding:2px 4px;"));
        space_2->setTextFormat(Qt::PlainText);
        space_2->setAlignment(Qt::AlignCenter);
        space_3 = new QLabel(centralwidget);
        space_3->setObjectName(QString::fromUtf8("space_3"));
        space_3->setGeometry(QRect(750, 600, 112, 112));
        space_3->setFont(font4);
        space_3->setStyleSheet(QString::fromUtf8("background-color:rgb(127, 119, 65);\n"
"border-radius:20px;\n"
"padding:2px 4px;"));
        space_3->setTextFormat(Qt::PlainText);
        space_3->setAlignment(Qt::AlignCenter);
        space_4 = new QLabel(centralwidget);
        space_4->setObjectName(QString::fromUtf8("space_4"));
        space_4->setGeometry(QRect(880, 600, 112, 112));
        space_4->setFont(font4);
        space_4->setStyleSheet(QString::fromUtf8("background-color:rgb(127, 119, 65);\n"
"border-radius:20px;\n"
"padding:2px 4px;"));
        space_4->setTextFormat(Qt::PlainText);
        space_4->setAlignment(Qt::AlignCenter);
        space_5 = new QLabel(centralwidget);
        space_5->setObjectName(QString::fromUtf8("space_5"));
        space_5->setGeometry(QRect(490, 720, 112, 112));
        space_5->setFont(font4);
        space_5->setStyleSheet(QString::fromUtf8("background-color:rgb(127, 119, 65);\n"
"border-radius:20px;\n"
"padding:2px 4px;"));
        space_5->setTextFormat(Qt::PlainText);
        space_5->setAlignment(Qt::AlignCenter);
        space_6 = new QLabel(centralwidget);
        space_6->setObjectName(QString::fromUtf8("space_6"));
        space_6->setGeometry(QRect(620, 720, 112, 112));
        space_6->setFont(font4);
        space_6->setStyleSheet(QString::fromUtf8("background-color:rgb(127, 119, 65);\n"
"border-radius:20px;\n"
"padding:2px 4px;"));
        space_6->setTextFormat(Qt::PlainText);
        space_6->setAlignment(Qt::AlignCenter);
        space_7 = new QLabel(centralwidget);
        space_7->setObjectName(QString::fromUtf8("space_7"));
        space_7->setGeometry(QRect(750, 720, 112, 112));
        space_7->setFont(font4);
        space_7->setStyleSheet(QString::fromUtf8("background-color:rgb(127, 119, 65);\n"
"border-radius:20px;\n"
"padding:2px 4px;"));
        space_7->setTextFormat(Qt::PlainText);
        space_7->setAlignment(Qt::AlignCenter);
        space_8 = new QLabel(centralwidget);
        space_8->setObjectName(QString::fromUtf8("space_8"));
        space_8->setGeometry(QRect(880, 720, 112, 112));
        space_8->setFont(font4);
        space_8->setStyleSheet(QString::fromUtf8("background-color:rgb(127, 119, 65);\n"
"border-radius:20px;\n"
"padding:2px 4px;"));
        space_8->setTextFormat(Qt::PlainText);
        space_8->setAlignment(Qt::AlignCenter);
        help_btn = new QPushButton(centralwidget);
        help_btn->setObjectName(QString::fromUtf8("help_btn"));
        help_btn->setGeometry(QRect(900, 946, 173, 96));
        mainWindow->setCentralWidget(centralwidget);

        retranslateUi(mainWindow);

        QMetaObject::connectSlotsByName(mainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *mainWindow)
    {
        mainWindow->setWindowTitle(QCoreApplication::translate("mainWindow", "Human Resource Machine", nullptr));
        bg->setText(QString());
        level_lbl->setText(QCoreApplication::translate("mainWindow", "<html><head/><body><p><span>Level 1</span></p></body></html>", nullptr));
        information_txt->setHtml(QCoreApplication::translate("mainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\351\273\221\344\275\223'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'\351\273\221\344\275\223'; font-size:12pt;\"><br /></p></body></html>", nullptr));
        num_lbl1->setText(QCoreApplication::translate("mainWindow", "00", nullptr));
        num_lbl2->setText(QString());
        num_lbl3->setText(QString());
        num_lbl4->setText(QString());
        num_lbl5->setText(QString());
        num_lbl6->setText(QString());
        num_lbl7->setText(QString());
        num_lbl8->setText(QString());
        num_lbl9->setText(QString());
        num_lbl10->setText(QString());
        num_lbl11->setText(QString());
        cmd_lbl_1->setText(QCoreApplication::translate("mainWindow", "\350\257\267\345\215\225\345\207\273\342\200\234\344\273\216\346\226\207\344\273\266\344\270\255\345\212\240\350\275\275\342\200\235", nullptr));
        cmd_lbl_2->setText(QString());
        cmd_lbl_3->setText(QString());
        cmd_lbl_4->setText(QString());
        cmd_lbl_5->setText(QString());
        cmd_lbl_6->setText(QString());
        cmd_lbl_7->setText(QString());
        cmd_lbl_8->setText(QString());
        cmd_lbl_9->setText(QString());
        cmd_lbl_10->setText(QString());
        cmd_lbl_11->setText(QString());
        run_btn->setText(QString());
        load_btn->setText(QString());
        inbox_lbl_1->setText(QString());
        outbox_lbl_1->setText(QString());
        outbox_lbl_2->setText(QString());
        outbox_lbl_3->setText(QString());
        outbox_lbl_4->setText(QString());
        human_lbl->setText(QString());
        inbox_lbl_2->setText(QString());
        inbox_lbl_3->setText(QString());
        inbox_lbl_4->setText(QString());
        current_llbl->setText(QString());
        space_1->setText(QString());
        space_2->setText(QString());
        space_3->setText(QString());
        space_4->setText(QString());
        space_5->setText(QString());
        space_6->setText(QString());
        space_7->setText(QString());
        space_8->setText(QString());
        help_btn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class mainWindow: public Ui_mainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

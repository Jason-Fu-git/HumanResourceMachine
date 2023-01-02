//
// Created by Jason Fu on 2022/12/18.
//

// You may need to build the project (run Qt uic code generator) to get "ui_LevelChooseDialog.h" resolved

#include "levelchoosedialog.h"
#include "ui_LevelChooseDialog.h"
#include "mainwindow.h"
#include <QPushButton>
#include <QMessageBox>
#include <QFileDialog>
#include <QButtonGroup>

QPushButton *buttons[4];
QButtonGroup buttonGroup;

LevelChooseDialog::LevelChooseDialog(QWidget *parent,int maxLevel) :
        QDialog(parent), ui(new Ui::LevelChooseDialog) {
    ui->setupUi(this);

    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);    // 禁止最大化按钮
    setFixedSize(this->width(),this->height());                    // 禁止拖动窗口大小

    buttons[0]=ui->level1_btn;
    buttons[1]=ui->level2_btn;
    buttons[2]=ui->level3_btn;
    buttons[3]=ui->level4_btn;

    //设置按钮图片
    setButtonIcon(buttons[0],"resources/level1.png");
    setButtonIcon(buttons[1],"resources/level2.png");
    setButtonIcon(buttons[2],"resources/level3.png");
    setButtonIcon(buttons[3],"resources/level4.png");


    ui->about_btn->setText("");
    QPixmap pixmap("resources/about.png");//背景
    QPixmap fitpixmap=pixmap.scaled(113,113);//设置长宽
    ui->about_btn->setIcon(QIcon(fitpixmap));
    ui->about_btn->setIconSize(QSize(113,113));
    ui->about_btn->setStyleSheet("border: 0px");//取消边框


    for(int i=0;i<=3;i++){//小于等于最高通关数的button 可点击
        if (i<=maxLevel){
            if (maxLevel<=3) {
                buttons[i]->setEnabled(true);
            }
        }else{//其他关卡不可选
            buttons[i]->setEnabled(false);
        }
        buttonGroup.addButton(buttons[i]);
    }
    //事件处理
    QObject::connect(buttons[0],&QPushButton::clicked,this,&LevelChooseDialog::btn1clicked);
    QObject::connect(buttons[1],&QPushButton::clicked,this,&LevelChooseDialog::btn2clicked);
    QObject::connect(buttons[2],&QPushButton::clicked,this,&LevelChooseDialog::btn3clicked);
    QObject::connect(buttons[3],&QPushButton::clicked,this,&LevelChooseDialog::btn4clicked);
    QObject::connect(ui->about_btn,&QPushButton::clicked,this,&LevelChooseDialog::about_btnclicked);

}

LevelChooseDialog::~LevelChooseDialog() {
    delete ui;
}

void LevelChooseDialog::btn1clicked(){//选中了第一关
    level=1;
    close();
}

void LevelChooseDialog::btn2clicked(){//选中了第2关
    level=2;
    close();
}

void LevelChooseDialog::btn3clicked(){//选中了第3关
    level=3;
    close();
}

void LevelChooseDialog::btn4clicked(){//选中了第4关
    level=4;
    QMessageBox::information(this,"信息","自定义关卡文件规范：\n"
                                         "     * 第一行：一个正整数，代表关卡编号\n"
                                         "     * 第二行：关卡的描述信息\n"
                                         "     * 第三行：输入序列 一群正整数，用空格隔开\n"
                                         "     * 第四行：输出序列 一群正整数，用空格隔开\n"
                                         "     * 第五行：可用空地数 一个整数\n"
                                         "     * 第六行：可用指令集 一群字符串，用空格隔开\n"
                                         "     *\n"
                                         "     * 注意：描述信息不能换行！");
    QString s = QFileDialog::getOpenFileName(this, "Choose your file", QDir::currentPath(), "text file(*.txt)");
    if (!s.isEmpty()) {//有效路径
        diypath = s.toStdString();
    } else {
        QMessageBox::critical(this, "Error", "File not found!");
    }
    close();
}

void LevelChooseDialog::about_btnclicked() {
    QMessageBox::information(this,"关于","本程序作者： 付甲申、王乃琦\n "
                                         "游戏原型为Tomorrow Corporation的Human Resource Machine\n"
                                         "GUI元素与原作保持一致\n"
                                         "仅限清华大学FOP编程大作业使用，请勿传播！");
}

void LevelChooseDialog::setButtonIcon(QPushButton *btn, const QString& path){//为按钮设置背景
    btn->setText("");
    QPixmap pixmap(path);//背景
    QPixmap fitpixmap=pixmap.scaled(1048,145);//设置长宽
    btn->setIcon(QIcon(fitpixmap));
    btn->setIconSize(QSize(1048,145));
    btn->setStyleSheet("border: 0px");//取消边框
}



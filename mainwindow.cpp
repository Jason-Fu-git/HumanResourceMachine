//
// Created by Jason Fu on 2022/11/22.
//


#include "mainWindow.h"
#include "ui_mainWindow.h"
#include <vector>
#include <QStandardItemModel>
#include <QApplication>
#include <QPushButton>
#include <QString>
#include <QDesktopServices>
#include "levelchoosedialog.h"
#include <iostream>
#include<fstream>
#include<cstring>
#include<QMessageBox>
#include <QFileDialog>
#include <CoreThread.h>

using namespace std;


QString path;//指令文件的路径
CoreThread *workingThread;
const int SLEEP = 1;


mainWindow::mainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::mainWindow) {
    ui->setupUi(this);

    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);    // 禁止最大化按钮
    setFixedSize(this->width(),this->height());                    // 禁止拖动窗口大小

    //初始化数组对象
    SPACELOC_HUMAN[0] = {490, 430};
    SPACELOC_HUMAN[1] = {620, 430};
    SPACELOC_HUMAN[2] = {750, 430};
    SPACELOC_HUMAN[3] = {880, 430};

    SPACELOC_ABOVE[0] = {500, 350};
    SPACELOC_ABOVE[1] = {630, 350};
    SPACELOC_ABOVE[2] = {760, 350};
    SPACELOC_ABOVE[3] = {890, 350};


    inbox_labels[0] = ui->inbox_lbl_1;
    inbox_labels[1] = ui->inbox_lbl_2;
    inbox_labels[2] = ui->inbox_lbl_3;
    inbox_labels[3] = ui->inbox_lbl_4;

    outbox_labels[0] = ui->outbox_lbl_1;
    outbox_labels[1] = ui->outbox_lbl_2;
    outbox_labels[2] = ui->outbox_lbl_3;
    outbox_labels[3] = ui->outbox_lbl_4;

    space_labels[0] = ui->space_1;
    space_labels[1] = ui->space_2;
    space_labels[2] = ui->space_3;
    space_labels[3] = ui->space_4;
    space_labels[4] = ui->space_5;
    space_labels[5] = ui->space_6;
    space_labels[6] = ui->space_7;
    space_labels[7] = ui->space_8;

    num_labels[0] = ui->num_lbl1;
    num_labels[1] = ui->num_lbl2;
    num_labels[2] = ui->num_lbl3;
    num_labels[3] = ui->num_lbl4;
    num_labels[4] = ui->num_lbl5;
    num_labels[5] = ui->num_lbl6;
    num_labels[6] = ui->num_lbl7;
    num_labels[7] = ui->num_lbl8;
    num_labels[8] = ui->num_lbl9;
    num_labels[9] = ui->num_lbl10;
    num_labels[10] = ui->num_lbl11;

    cmd_labels[0] = ui->cmd_lbl_1;
    cmd_labels[1] = ui->cmd_lbl_2;
    cmd_labels[2] = ui->cmd_lbl_3;
    cmd_labels[3] = ui->cmd_lbl_4;
    cmd_labels[4] = ui->cmd_lbl_5;
    cmd_labels[5] = ui->cmd_lbl_6;
    cmd_labels[6] = ui->cmd_lbl_7;
    cmd_labels[7] = ui->cmd_lbl_8;
    cmd_labels[8] = ui->cmd_lbl_9;
    cmd_labels[9] = ui->cmd_lbl_10;
    cmd_labels[10] = ui->cmd_lbl_11;

    //初始化动画对象
    human_ani = new QPropertyAnimation();
    above_ani = new QPropertyAnimation();
    human_ani->setTargetObject(ui->human_lbl);
    above_ani->setTargetObject(ui->current_llbl);
    human_ani->setEasingCurve(QEasingCurve::BezierSpline);
    above_ani->setEasingCurve(QEasingCurve::BezierSpline);

    //设置按钮可用
    ui->load_btn->setEnabled(true);
    ui->run_btn->setEnabled(true);


    //设置按钮背景
    QPixmap pixmap0("resources/run.png");//背景
    QPixmap fitpixmap0 = pixmap0.scaled(96, 96);//设置长宽
    ui->run_btn->setIcon(QIcon(fitpixmap0));
    ui->run_btn->setIconSize(QSize(96, 96));
    ui->run_btn->setStyleSheet("border: 0px");//取消边框

    QPixmap pixmap1("resources/loadfromfile.png");//背景
    QPixmap fitpixmap1 = pixmap1.scaled(354, 96);//设置长宽
    ui->load_btn->setIcon(QIcon(fitpixmap1));
    ui->load_btn->setIconSize(QSize(354, 96));
    ui->load_btn->setStyleSheet("border: 0px");//取消边框

    QPixmap pixmap2("resources/help.png");//背景
    QPixmap fitpixmap2 = pixmap2.scaled(173, 96);//设置长宽
    ui->help_btn->setIcon(QIcon(fitpixmap2));
    ui->help_btn->setIconSize(QSize(173, 96));
    ui->help_btn->setStyleSheet("border: 0px");//取消边框

    //初始化线程
    workingThread = new CoreThread(this);

    QObject::connect(workingThread, &CoreThread::refreshInbox, this, &mainWindow::freshInbox);
    QObject::connect(workingThread, &CoreThread::refreshOutbox, this, &mainWindow::freshOutbox);
    QObject::connect(workingThread, &CoreThread::refreshAbove, this, &mainWindow::freshAbove);
    QObject::connect(workingThread, &CoreThread::refreshCommand, this, &mainWindow::freshCommand);
    QObject::connect(workingThread, &CoreThread::animate, this, &mainWindow::animate);
    QObject::connect(workingThread, &CoreThread::refreshSpace, this, &mainWindow::freshSpace);
    QObject::connect(workingThread, &CoreThread::fireMessage, this, &mainWindow::fireMessage);
    QObject::connect(ui->load_btn, &QPushButton::clicked, this, &mainWindow::onLoadBtnClicked);
    QObject::connect(ui->run_btn, &QPushButton::clicked, this, &mainWindow::onRunBtnClicked);
    QObject::connect(ui->help_btn, &QPushButton::clicked, this, &mainWindow::onHelpBtnClicked);


}

void mainWindow::setInformation(int level0, std::string levelPath) {

    QString str0 = "Level ";
    str0.append(QString::number(level0));
    ui->level_lbl->setText(str0);//向关卡标签传送关卡编号

    //向关卡信息文本框写数据
    QString str;
    std::ifstream fin;
    fin.open(levelPath);//打开文件
    bool begin = false;
    char buffer[1500];
    int line = 0;
    while (fin.getline(buffer, 1500)) {
        line++;
        //逐行读取
        if (line % 6 == 1) {//是第一行
            if (atoi(buffer) == level0) {//如果对应关卡编号=用户输入
                begin = true;//开始写入变量
                continue;
            }
        }
        if (begin) {
            switch (line % 6) {
                case 3://inbox
                    str.append("输入序列:  ");
                    str.append(buffer);
                    str.append("\n");
                    str.append("-------------------\n");
                    break;
                case 4://standard
                    str.append("目标输出序列:  ");
                    str.append(buffer);
                    str.append("\n");
                    str.append("-------------------\n");
                    break;
                case 5://available space
                    str.append("可用空地数： ");
                    str.append(buffer);
                    str.append("\n");
                    str.append("-------------------\n");
                    break;
                case 2://information
                    str.append(buffer);
                    str.append("\n");
                    str.append("-------------------\n");
                    break;
                case 0://available commands
                    str.append("可用指令： ");
                    str.append(buffer);
                    str.append("\n");
                    str.append("-------------------\n");
                    str.append("请将您的指令集写在一个文本文档中，第一行为指令个数，随后每一行为一条指令");
                    fin.close();
                    ui->information_txt->setText(str);
                    return;
            }
        }
    }

}

//单击事件处理
void mainWindow::onLoadBtnClicked() {
    QString s = QFileDialog::getOpenFileName(this, "Choose your command file", QDir::currentPath(), "text file(*.txt)");
    if (!s.isEmpty()) {
        path = s;
        //读用户输入的指令集
        string string1 = path.toStdString();
        const char *address = string1.c_str();
        readCommands(address);
        freshCommand();
        QApplication::processEvents();
    } else {
        QMessageBox::critical(this, "Error", "File not found!");
    }
}

void mainWindow::onRunBtnClicked() {
    //使按钮不可再次被单击
    ui->load_btn->setEnabled(false);
    ui->run_btn->setEnabled(false);
    //开始运行
    haveStart= true;
    finishType=0;
    workingThread->start();
}

void mainWindow::onHelpBtnClicked() {
    //打开说明文件
    if (!QDesktopServices::openUrl(QUrl::fromLocalFile("resources/HumanResourceMachineReadMe.pdf")))
        QMessageBox::critical(this,"Error","请确保程序根路径不含有非英文字符且安装了默认PDF阅读器");
}

//刷新各部分
void mainWindow::freshInbox() {
    int len = inbox.size();
    if (len<=4){//长度小于4
        for (int i = 0; i < len; i++) {
            inbox_labels[i]->setText(QString::number(inbox.at(i)));//设置数字
            inbox_labels[i]->setVisible(true);
        }
        for (int i = len; i < 4; i++) {
            inbox_labels[i]->setText("");//设置空
            inbox_labels[i]->setVisible(false);
        }
    }else{//长度大于4，只设置前4个
        for (int i = 0; i < 4; i++) {
            inbox_labels[i]->setText(QString::number(inbox.at(i)));//设置数字
            inbox_labels[i]->setVisible(true);
        }
    }


}

void mainWindow::freshOutbox() {
    int len = outbox.size();
    if (len >= 4) {
        for (int i = 0; i < 4; i++) {
            outbox_labels[i]->setText(QString::number(outbox.at(len - i - 1)));
            outbox_labels[i]->setVisible(true);
        }
    } else {
        for (int i = 0; i < len; i++) {
            outbox_labels[i]->setText(QString::number(outbox.at(len - i - 1)));//设置数字
            outbox_labels[i]->setVisible(true);
        }
        for (int i = len; i < 4; i++) {
            outbox_labels[i]->setText("");//设置空
            outbox_labels[i]->setVisible(false);
        }
    }

}

void mainWindow::freshSpace() {

    for (int i = 0; i < available_space; i++) {
            //设置空地可见
            space_labels[i]->setVisible(true);

        if (space_state[i]) {//有木块
            space_labels[i]->setText(QString::number(spaces[i]));//设置数字
            space_labels[i]->setStyleSheet(
                    "background-color:rgb(172, 200, 103);border-radius:20px;padding:2px 4px;"//设置颜色
            );
        } else {
            space_labels[i]->setText("");//设置空
            space_labels[i]->setStyleSheet(
                    "background-color:rgb(127, 119, 65);border-radius:20px;padding:2px 4px;"//设置颜色
            );
        }
    }

    for(int i=available_space;i<8;i++){
        //设置空地不可见
        space_labels[i]->setVisible(false);
    }

}

void mainWindow::freshCommand() {
    vector<QString> commands;
    if (command_size>0){//有commands

        //将链表中的数据写到commands里
        command *p = head;
        do {
            QString s = p->description;
            commands.push_back(s);
        } while ((p = p->next) != nullptr);

        //一系列换算，保证跟随currentStep每次显示11条
        int a = (currentStep - 1) / 11;
        int b = (commands.size() - 1) / 11;
        int up = ((a < b) ? 11 : commands.size() - b * 11);
        for (int i = 0; i < up; i++) {
            int index = i + a * 11;
            QString numStr = (index < 9) ? "0" : "";
            numStr.append(QString::number(index+1));
            //设置当前执行语句高亮
            if (index == currentStep - 1) {
                num_labels[i]->setStyleSheet("background-color:rgb(199, 164, 50);");
                cmd_labels[i]->setStyleSheet("background-color:rgb(199, 164, 50);");
            } else {
                num_labels[i]->setStyleSheet("background-color:rgba(199, 164, 50,0);");
                cmd_labels[i]->setStyleSheet("background-color:rgba(199, 164, 50,0);");
            }
            num_labels[i]->setText(numStr);
            cmd_labels[i]->setText(commands.at(index));
        }
        for (int i = up; i < 11; i++) {
            num_labels[i]->setText("");
            cmd_labels[i]->setText("");
            num_labels[i]->setStyleSheet("background-color:rgba(199, 164, 50,0);");
            cmd_labels[i]->setStyleSheet("background-color:rgba(199, 164, 50,0);");
        }
    }else{//没有指令，提示用户选择文件
        for (int i = 0; i < 11; i++) {
            num_labels[i]->setText("");
            cmd_labels[i]->setText("");
            num_labels[i]->setStyleSheet("background-color:rgba(199, 164, 50,0);");
            cmd_labels[i]->setStyleSheet("background-color:rgba(199, 164, 50,0);");
        }
        num_labels[0]->setText("00");
        cmd_labels[0]->setText("请单击\"从文件中加载\"");
    }




}

void mainWindow::freshAbove() {
    ui->current_llbl->setText(QString::number(currentNumber));
    ui->current_llbl->setVisible(haveNumber);

}

mainWindow::~mainWindow() {
    delete ui;
}

//动画
void mainWindow::animate() {
    //设置动画
    human_ani->setPropertyName("pos");
    human_ani->setDuration(500);
    above_ani->setPropertyName("pos");
    above_ani->setDuration(500);
    human_ani->setStartValue(ui->human_lbl->pos());
    above_ani->setStartValue(ui->current_llbl->pos());
    human_ani->setEndValue(human_e);
    above_ani->setEndValue(above_e);
    human_ani->start();
    above_ani->start();

}

//运行时
void mainWindow::onStart() {

    maxLevel = readLevel();//已经通过的最高关卡


    //显示开始界面
    LevelChooseDialog levelSelectionDialog(nullptr, maxLevel);
    levelSelectionDialog.level = -1;
    levelSelectionDialog.exec();

    level = levelSelectionDialog.level;//记录选中的关卡
    if (level == -1)
        std::exit(-1);//程序退出

   if(level == 4){
       DIYPATH=levelSelectionDialog.diypath;
   }
    readInformation();//向全局变量写关卡信息

    for (int i = available_space; i < 8; i++) {//设置空地不可见
        space_labels[i]->setVisible(false);
    }

    //触发主UI
    show();
    //刷新UI
    if (level==4)
        setInformation(level,DIYPATH);
    else
        setInformation(level, INFORMATIONFILEPATH);
    freshSpace();
    freshInbox();
    freshOutbox();
    freshAbove();
    freshCommand();
}

void mainWindow::onFinish() {
    setVisible(false);
    //初始化数据
    inbox.clear();
    outbox.clear();
    standard.clear();
    head = nullptr;
    tail = head;
    command_size = 0;
    haveNumber = false;
    haveStart=false;
    available_space = 0;
    currentStep = 1;
    std::memset(spaces, 0, sizeof(spaces));
    std::memset(space_state, 0, sizeof(space_state));
    std::memset(available_command, 0, sizeof(available_command));
    human_e = INBOXLOC_HUMAN;
    above_e = INBOXLOC_ABOVE;
    animate();
    ui->load_btn->setEnabled(true);
    ui->run_btn->setEnabled(true);
    //重新开始
    onStart();
}

//功能部件
void mainWindow::readCommands(std::string filepath) {
    head = nullptr;//清空链表
    tail = head;
    ifstream fin;
    fin.open(filepath);//打开指令文件
    if (!fin) {
        QMessageBox::critical(this, "Error", "File not found!");
        exit(-1);
    } else {
        char sss[20];
        fin.getline(sss, 20);
        command_size = atoi(sss);//读取指令数
        for (int i = 0; i < command_size; i++) {
            command *c = new command;
            char str[20] = {0};
            fin.getline(str, 20); //从文件读取一行指令
            int index = -1;//如果最后还是-1 代表未定义指令
            bool needNumber = false;//是否需要指令数

            char cmd[20];//指令
            char num[20];//数字
            std::memset(cmd, 0, sizeof(char) * 20);
            std::memset(num, 0, sizeof(char) * 20);
            int h = 19;
            for (int q = 0; q < 20; q++) {
                if (str[q] == ' ') {
                    h = q;
                    break;
                }
            }//查找空格位置
            std::strncpy(cmd, str, h);//cmd
            for (int j = h + 1; j < 20; j++) {//num
                num[j - h - 1] = str[j];
            }

            char target[][20] = {"inbox", "outbox", "add", "sub", "copyto", "copyfrom", "jump", "jumpifzero"};
            for (int j = 0; j < 8; ++j) {
                if (strcmp(cmd, target[j]) == 0) {
                    index = j + 1;//转化
                    if (j != 0 && j != 1)
                        needNumber = true;//需要指令数
                }
            }

            if (needNumber) {
                if (std::strcspn(num, ".") == 20) {//操作数非整数
                    c->number = -1;//写入操作数
                } else if (std::strcspn(num, "0123456789") == 20) {//没有操作数
                    c->number = -1;//写入操作数
                } else {
                    c->number = std::atoi(num);//写入操作数
                }
            }
            c->index = index;
            c->description = QString(QLatin1String(str));//写入文字信息
            c->next = nullptr;
            push_to_command(c);//写入数据

        }
    }
}

void mainWindow::push_to_command(command *c) {
    if (head == nullptr) {//第一个元素
        head = c;
        tail = head;
    } else {
        tail->next = c;
        tail = c;//尾指针后移
    }
}

void mainWindow::readInformation() {
    /*
     * 文件规范：关卡信息储存在与源文件同一目录下的“information.txt”中，每一关卡分配六行
     * 第一行：一个正整数，代表关卡编号
     * 第二行：关卡的描述信息
     * 第三行：输入序列 一群正整数，用空格隔开
     * 第四行：输出序列 一群正整数，用空格隔开
     * 第五行：可用空地数 一个整数
     * 第六行：可用指令集 一群字符串，用空格隔开
     *
     * 注意：关卡与关卡之间不能有空行！
     * 注意：描述信息不能换行！
     *
     */
    ifstream fin;
    if (level==4){
        fin.open(DIYPATH);
    }else{
        fin.open(INFORMATIONFILEPATH);//打开文件
    }
    if (!fin) {
        QMessageBox::critical(this, "Error", "No level information file found!");
        fin.close();
        std::exit(0);//程序退出
    }
    int line = 0;
    bool begin = false;
    char buffer[1500];
    while (fin.getline(buffer, 1500)) {
        //逐行读取
        line++;
        if (line % 6 == 1) {//是第一行
            if (atoi(buffer) == level) {//如果对应关卡编号=用户输入
                begin = true;//开始写入变量
                continue;
            }
        }
        if (begin) {
            switch (line % 6) {
                case 3://inbox
                    char *p;
                    p = strtok(buffer, " ");
                    while (p) {
                        inbox.push_back(atoi(p));
                        p = strtok(nullptr, " ");
                    }
                    break;
                case 4://standard
                    char *q;
                    q = strtok(buffer, " ");
                    while (q) {
                        standard.push_back(atoi(q));
                        q = strtok(nullptr, " ");
                    }
                    break;
                case 5://available space
                    available_space = atoi(buffer);
                    break;
                case 2://information
                    strcpy(information, buffer);
                    break;
                case 0://available commands
                    char *t;
                    t = strtok(buffer, " ");
                    fill(available_command, available_command + 7, false);
                    while (t) {
                        if (stricmp(t, "inbox") == 0) {
                            available_command[0] = true;
                        } else if (stricmp(t, "outbox") == 0) {
                            available_command[1] = true;
                        } else if (stricmp(t, "add") == 0) {
                            available_command[2] = true;
                        } else if (stricmp(t, "sub") == 0) {
                            available_command[3] = true;
                        } else if (stricmp(t, "copyto") == 0) {
                            available_command[4] = true;
                        } else if (stricmp(t, "copyfrom") == 0) {
                            available_command[5] = true;
                        } else if (stricmp(t, "jump") == 0) {
                            available_command[6] = true;
                        } else if (stricmp(t, "jumpifzero") == 0) {
                            available_command[7] = true;
                        }
                        t = strtok(nullptr, " ");
                    }
                    fin.close();
                    return;
            }
        }
    }

    if (!begin) {
        QMessageBox::critical(this, "Error", "Wrong level information file format!");
    }
    fin.close();

}

int mainWindow::readLevel() {
    /*
     * 文件规范：只有一行，表示最高通关数
     */
    ifstream fin;
    fin.open(LEVELFILEPATH);
    if (!fin) {
        fin.close();
        return 0;
    }
    int i = 0;
    fin >> i;//读取最高通关数
    fin.close();
    return i;
}

void mainWindow::writeLevel() {
    ofstream fout;
    fout.open(LEVELFILEPATH);
    if (maxLevel < level)//如果当前通关数大于之前最高通关数
        fout << level << endl;//写入当前最高关卡数
    else
        fout << maxLevel << endl;//写入之前的最高通关数
    fout.close();
}

mainWindow::command *mainWindow::getCommandAt(int index) {
    int count = 1;
    mainWindow::command *result = head;

    if (head == nullptr) {
        QMessageBox::critical(this,"Error","指令异常");
    } else {
        while (index > count) {//循环
            if (result->next == nullptr) {
                QMessageBox::critical(this,"Error","指令异常");
            } else {
                result = result->next;
                count++;
            }
        }
    }
    return result;
}

void mainWindow::fireMessage() {
    //显示关卡结束时的提示
    if (message_type == 0) {
        QMessageBox::information(this, "Message", message);
    } else {
        QMessageBox::critical(this, "Error", message);
    }
    onFinish();
}






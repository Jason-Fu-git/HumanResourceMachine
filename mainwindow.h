//
// Created by Jason Fu on 2022/11/22.
//

#ifndef HUMANRESOURCEMACHINE_MAINWINDOW_H
#define HUMANRESOURCEMACHINE_MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QLabel>
#include <vector>
#include <QPushButton>
#include <cstring>
#include <QPropertyAnimation>


QT_BEGIN_NAMESPACE
namespace Ui { class mainWindow; }
QT_END_NAMESPACE

class mainWindow : public QMainWindow {
Q_OBJECT

public:
    struct command {
        int index = -1;
        QString description;//描述
        /*
         * 数字代表指令，存到index里
         * 1:inbox
         * 2:outbox
         * 3:add
         * 4:sub
         * 5:copyto
         * 6:copyfrom
         * 7:jump
         * 8:jumpifzero
         *
         */
        int number = -2;//操作数
        command *next;
    };

    explicit mainWindow(QWidget *parent = nullptr);
    void freshInbox();//刷新inbox
    void freshOutbox();//刷新outbox
    void freshSpace();//刷新space
    void freshCommand();//刷新command
    void freshAbove();//刷新机器人头顶的积木

    void onStart();//在主函数中调用，再次开始时调用
    void onLoadBtnClicked();//“从文件中加载”按钮单击时触发
    void onRunBtnClicked();//"运行"按钮单击时触发
    void onHelpBtnClicked();//"帮助"按钮单击时触发
    void animate();//动画

    command *getCommandAt(int i);//读表函数 i从1开始编号
    void writeLevel();//通关后写LEVEL
    void fireMessage();//显示对话框 type 0->message 1->critical

     std::string LEVELFILEPATH= "level.txt";//通关文件路径 要与源程序在同一路径中;
     std::string INFORMATIONFILEPATH="information.txt";//关卡信息路径 要与源程序在同一路径中
     std::string DIYPATH;

    //位置点，为动画做准备
    QPoint INBOXLOC_HUMAN={350,430};
    QPoint INBOXLOC_ABOVE={360,350};
    QPoint OUTBOXLOC_HUMAN={1050,430};
    QPoint OUTBOXLOC_ABOVE={1060,350};

    QPoint SPACELOC_HUMAN[4];
    QPoint SPACELOC_ABOVE[4];

    QPoint human_e,above_e;//signal
    QString message;//signal
    int message_type;//signal

    std::vector<int> inbox;//输入序列
    std::vector<int> outbox;//输出序列
    std::vector<int> standard;//输出标准序列


    command *head = nullptr;//指令集（链表）
    command *tail = head;//尾指针
    int command_size=0;//有几条指令

    int level;//当前关卡
    int maxLevel;//最高通关数
    char information[1500];//关卡描述

    int currentNumber;//手中积木
    bool haveNumber = false;//手上是否有积木

    int available_space;//可用空地数
    int spaces[8] = {0};//空地上积木的数字  空地从零开始编号
    bool space_state[8] = {0};//存储哪个空地被占

    bool available_command[8];//可用指令（对应位置为TRUE）
    int currentStep = 1;//现在执行到第几条指令(编号从1开始)
    int finishType = 0;//关卡结束的类型 0代表未结束 1代表正常结束 2代表失败 3代表异常

    bool haveStart=false;

    //GUI元素数组
    QLabel *inbox_labels[4];
    QLabel *outbox_labels[4];
    QLabel *space_labels[8];
    QLabel *num_labels[11];
    QLabel *cmd_labels[11];

    ~mainWindow() override;



private:
    Ui::mainWindow *ui;
    void setInformation(int level0, std::string);
    int readLevel();//读取已经通过的LEVEL
    void readInformation();//读取关卡信息  从1~4编号，4为自定义关卡
    void readCommands(std::string);//读取指令集  写表   写指令数  参数：文件路径
    void push_to_command(mainWindow::command *c);//写表函数
    void onFinish();//关卡结束

    //动画对象
    QPropertyAnimation *human_ani;
    QPropertyAnimation *above_ani;


};


#endif //HUMANRESOURCEMACHINE_MAINWINDOW_H

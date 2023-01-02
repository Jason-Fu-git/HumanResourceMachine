//
// Created by Jason Fu on 1/1/2023.
//

#include "CoreThread.h"

const int SLEEP = 1;


CoreThread::CoreThread(mainWindow *mainWindow0) {
    parent = mainWindow0;//设置父窗口
}

void CoreThread::run() {
    if (parent->haveStart)
        gameStart();
}

void CoreThread::gameStart() {
    //开始逐步模拟
    int count = 0;//已经执行的指令数

    while (parent->finishType == 0) {//关卡未结束
        emit refreshCommand();//释放UI刷新信号
        sleep(SLEEP);//线程休眠，UI刷洗
        robot();//执行该步
        if (parent->finishType == 0)
            count++;//步数统计
    }


    //处理成功或失败
    if (parent->finishType == 1) {//胜利
        QString s = "Success! \n Command count:";
        s.append(QString::number(parent->command_size));
        s.append("\n Step count:");
        s.append(QString::number(count));
        parent->message_type = 0;
        parent->message = s;
        emit fireMessage();//通知主窗口释放结束信息
        parent->writeLevel();
    } else if (parent->finishType == 2) {
        parent->message_type = 0;
        parent->message = "Fail!";
        emit fireMessage();//通知主窗口释放结束信息
    }
    parent->haveStart = false;
    exit(0);//退出


}


void CoreThread::robot() {
    if (parent->currentStep > parent->command_size) {//指令执行完毕
        parent->finishType = 2 - isVictory();//判断成功或失败
        return;
    }

    mainWindow::command *c = parent->getCommandAt(parent->currentStep);
    int index = c->index;//是哪一条指令
    int num = c->number;//操作数

    if (!parent->available_command[index - 1] || index == -1) {//该条指令不可用 或 指令格式不对
        QString mess = "Error on instruction ";
        mess.append(QString::number(parent->currentStep));
        parent->message_type = 1;
        parent->message = mess;
        emit fireMessage();//输出异常
        parent->finishType = 3;//失败
        return;
    }

    if (num == -1) {//操作数异常
        QString mess = "Error on instruction ";
        mess.append(QString::number(parent->currentStep));
        parent->message_type = 1;
        parent->message = mess;
        emit fireMessage();//输出异常
        parent->finishType = 3;//失败
        return;
    }

    switch (index) {//判断指令
        case 1://inbox
            parent->human_e = parent->INBOXLOC_HUMAN;
            parent->above_e = parent->INBOXLOC_ABOVE;
            emit animate();//释放动画信号
            sleep(SLEEP);//刷新UI
            if (parent->inbox.empty()) {//输入传送带已经没有积木
                if (isVictory()) {//如果成功
                    parent->finishType = 1;//成功
                } else {
                    parent->finishType = 2;//失败
                }
                return;
            } else {
                parent->currentNumber = parent->inbox.at(0);//读取inbox第一个元素
                parent->haveNumber = true;//手上有积木
                parent->inbox.erase(parent->inbox.begin());//删除inbox第一个元素
                parent->currentStep++;//下一步
            }
            emit refreshInbox();//释放信号
            emit refreshAbove();//释放信号
            sleep(SLEEP);//刷新UI
            break;
        case 2://outbox
            parent->human_e = parent->OUTBOXLOC_HUMAN;
            parent->above_e = parent->OUTBOXLOC_ABOVE;
            emit animate();//释放动画信号
            sleep(SLEEP);//刷新UI
            if (!parent->haveNumber) {//手上没有积木
                QString mess = "Error on instruction ";
                mess.append(QString::number(parent->currentStep));
                parent->message_type = 1;
                parent->message = mess;
                emit fireMessage();//输出异常
                parent->finishType = 3;//失败
                return;
            } else {
                parent->outbox.push_back(parent->currentNumber);//放到outbox
                parent->haveNumber = false;//手上没有积木
                parent->currentStep++;//下一步
            }
            emit refreshAbove();//释放信号
            emit refreshOutbox();//释放信号
            sleep(SLEEP);//刷新UI
            break;
        case 3://add
            if (parent->available_space <= num || num < 0) {//没有这个空地
                QString mess = "Error on instruction ";
                mess.append(QString::number(parent->currentStep));
                parent->message_type = 1;
                parent->message = mess;
                emit fireMessage();//输出异常
                parent->finishType = 3;//失败
                return;
            } else {
                if (!parent->haveNumber) {//手中没有积木
                    QString mess = "Error on instruction ";
                    mess.append(QString::number(parent->currentStep));
                    parent->message_type = 1;
                    parent->message = mess;
                    emit fireMessage();//输出异常
                    parent->finishType = 3;//失败
                    return;
                } else {
                    if (!parent->space_state[num]) {//空地上没有积木
                        QString mess = "Error on instruction ";
                        mess.append(QString::number(parent->currentStep));
                        parent->message_type = 1;
                        parent->message = mess;
                        emit fireMessage();//输出异常
                        parent->finishType = 3;//失败
                        return;
                    } else {
                        parent->human_e = parent->SPACELOC_HUMAN[num % 4];
                        parent->above_e = parent->SPACELOC_ABOVE[num % 4];
                        emit animate();//释放动画信号
                        sleep(SLEEP);
                        parent->currentNumber += parent->spaces[num];//执行
                        parent->currentStep++;//下一步
                    }
                }
            }
            emit refreshAbove();//释放信号
            sleep(SLEEP);//刷新UI
            break;
        case 4://sub
            if (parent->available_space <= num || num < 0) {//没有这个空地
                QString mess = "Error on instruction ";
                mess.append(QString::number(parent->currentStep));
                parent->message_type = 1;
                parent->message = mess;
                emit fireMessage();//输出异常
                parent->finishType = 3;//失败
                return;
            } else {
                if (!parent->haveNumber) {//手中没有积木
                    QString mess = "Error on instruction ";
                    mess.append(QString::number(parent->currentStep));
                    parent->message_type = 1;
                    parent->message = mess;
                    emit fireMessage();//输出异常
                    parent->finishType = 3;//失败
                    return;
                } else {
                    if (!parent->space_state[num]) {//空地上没有积木
                        QString mess = "Error on instruction ";
                        mess.append(QString::number(parent->currentStep));
                        parent->message_type = 1;
                        parent->message = mess;
                        emit fireMessage();//输出异常
                        parent->finishType = 3;//失败
                        return;
                    } else {
                        parent->human_e = parent->SPACELOC_HUMAN[num % 4];
                        parent->above_e = parent->SPACELOC_ABOVE[num % 4];
                        emit animate();//释放动画信号
                        sleep(SLEEP);
                        parent->currentNumber -= parent->spaces[num];//执行
                        parent->currentStep++;//下一步
                    }

                }
            }
            emit refreshAbove();//释放信号
            sleep(SLEEP);
            break;
        case 5://copyto
            if (!parent->haveNumber) {//手中没有积木
                QString mess = "Error on instruction ";
                mess.append(QString::number(parent->currentStep));
                parent->message_type = 1;
                parent->message = mess;
                emit fireMessage();//输出异常
                parent->finishType = 3;//失败
                return;
            } else {
                if (parent->available_space <= num || num < 0) {//没有这个空地
                    QString mess = "Error on instruction ";
                    mess.append(QString::number(parent->currentStep));
                    parent->message_type = 1;
                    parent->message = mess;
                    emit fireMessage();//输出异常
                    parent->finishType = 3;//失败
                    return;
                } else {
                    parent->human_e = parent->SPACELOC_HUMAN[num % 4];
                    parent->above_e = parent->SPACELOC_ABOVE[num % 4];
                    emit animate();//释放动画信号
                    sleep(SLEEP);
                    parent->space_state[num] = true;
                    parent->spaces[num] = parent->currentNumber;
                    parent->currentStep++;//下一步
                }
            }
            emit refreshSpace();//释放信号
            sleep(SLEEP);
            break;
        case 6://copyfrom
            if (parent->available_space <= num || num < 0) {//没有这个空地
                QString mess = "Error on instruction ";
                mess.append(QString::number(parent->currentStep));
                parent->message_type = 1;
                parent->message = mess;
                emit fireMessage();//输出异常
                parent->finishType = 3;//失败
                return;
            } else {
                if (!parent->space_state[num]) {//空地上没有积木
                    QString mess = "Error on instruction ";
                    mess.append(QString::number(parent->currentStep));
                    parent->message_type = 1;
                    parent->message = mess;
                    emit fireMessage();//输出异常
                    parent->finishType = 3;//失败
                    return;
                } else {
                    parent->human_e = parent->SPACELOC_HUMAN[num % 4];
                    parent->above_e = parent->SPACELOC_ABOVE[num % 4];
                    emit animate();//释放动画信号
                    sleep(SLEEP);
                    parent->currentNumber = parent->spaces[num];//执行
                    parent->haveNumber = true;
                    parent->currentStep++;//下一步
                }
            }
            emit refreshAbove();//释放信号
            sleep(SLEEP);
            break;
        case 7://jump
            //第 num 条
            if (num < 1 || num > parent->command_size || num == parent->currentStep) {//不存在指令或指向自己(死循环)
                QString mess = "Error on instruction ";
                mess.append(QString::number(parent->currentStep));
                parent->message_type = 1;
                parent->message = mess;
                emit fireMessage();//输出异常
                parent->finishType = 3;//失败
                return;
            } else {
                parent->currentStep = num;//跳至num
            }
            break;
        case 8://jumpifzero
            if (num < 1 || num > parent->command_size || num == parent->currentStep) {//不存在指令或指向自己(死循环)
                QString mess = "Error on instruction ";
                mess.append(QString::number(parent->currentStep));
                parent->message_type = 1;
                parent->message = mess;
                emit fireMessage();//输出异常
                parent->finishType = 3;//失败
                return;
            } else {
                if (!parent->haveNumber) {//手中没有积木
                    QString mess = "Error on instruction ";
                    mess.append(QString::number(parent->currentStep));
                    parent->message_type = 1;
                    parent->message = mess;
                    emit fireMessage();//输出异常
                    parent->finishType = 3;//失败
                    return;
                } else {
                    if (parent->currentNumber == 0) {
                        parent->currentStep = num;//跳至num
                        break;
                    }
                }
            }
            parent->currentStep++;//下一步
            break;

    }


}

bool CoreThread::isVictory() {//判断是否胜利
    bool result = false;
    if (parent->outbox.size() == parent->standard.size()) {//前提是大小相同
        result = true;//可能胜利
        for (int i = 0; i < parent->outbox.size(); i++) {
            if (parent->outbox.at(i) != parent->standard.at(i))
                result = false;
        }
    } else {
        result = false;
    }
    return result;
}
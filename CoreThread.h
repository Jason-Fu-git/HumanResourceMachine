//
// Created by Jason Fu on 1/1/2023.
//

#ifndef HUMANRESOURCEMACHINE_CORETHREAD_H
#define HUMANRESOURCEMACHINE_CORETHREAD_H

#include <QThread>
#include "mainwindow.h"

//线程类
class CoreThread : public QThread{
     Q_OBJECT
public:
    explicit CoreThread(mainWindow *mainWindow0);

protected:
    void run() override;

    signals:
    //通知界面刷新信号
    void refreshInbox();
    void refreshOutbox();
    void refreshSpace();
    void refreshAbove();
    void refreshCommand();
    void animate();
    void fireMessage();

private:
    mainWindow *parent;
    void gameStart();//在run函数中调用
    void robot();//机器人程序
    bool isVictory();//判断是否胜利


};


#endif //HUMANRESOURCEMACHINE_CORETHREAD_H

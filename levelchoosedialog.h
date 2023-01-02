//
// Created by Jason Fu on 2022/12/18.
//

#ifndef HUMANRESOURCEMACHINE_LEVELCHOOSEDIALOG_H
#define HUMANRESOURCEMACHINE_LEVELCHOOSEDIALOG_H

#include <QDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class LevelChooseDialog; }
QT_END_NAMESPACE

class LevelChooseDialog : public QDialog {
Q_OBJECT

public:
    explicit LevelChooseDialog(QWidget *parent = nullptr,int maxLevel=0);
    int level=0;//选择的关卡
    std::string diypath;

    //按钮响应
    void btn1clicked();

    void btn2clicked();

    void btn3clicked();

    void btn4clicked();

    void about_btnclicked();

    ~LevelChooseDialog() override;

private:
    Ui::LevelChooseDialog *ui;

    //设置按钮图片
    void setButtonIcon(QPushButton *btn, const QString &path);


};


#endif //HUMANRESOURCEMACHINE_LEVELCHOOSEDIALOG_H

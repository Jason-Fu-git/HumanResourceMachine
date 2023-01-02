#include <QApplication>
#include <QMessageBox>
#include "mainwindow.h"

using namespace std;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    mainWindow mainWindow;
    //开始运行
    mainWindow.onStart();
    return QApplication::exec();
}

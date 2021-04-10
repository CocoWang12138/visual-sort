#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.move ((QApplication::desktop()->width() - w.width())/2,(QApplication::desktop()->height() - w.height())/2);   //设置窗口自动居中显示
    return a.exec();
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"MaxHeap.h"
#include <QMainWindow>
#include<QPushButton>
#include<QTime>
#include<QPropertyAnimation>
#include<QDialog>
#include<QPainter>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);
    void Swap(int &a ,int &b)
    {
    int temp=a;
    a=b;
    b=temp;
    }
    void Bubble(int a[],int n)
    {//把数组中最大的元素通过冒泡移到右边
     for(int i=0;i<n-1;i++){
     if(a[i]>a[i+1])
      Swap(a[i],a[i+1]);
      }
    }
    void BubbleSort(int a[],int n)
    {
     for(int i=n;i>1;i--)
      Bubble(a,i);
    }
private:
    void open1();
    void open2();
    void open3();
    void open4();
    void open5();
    void open6();
    void open7();
    void open8();

    void sort1();
    void sort2();
    void sort3();
    void sort4();

    QAction *action1;
    QAction *action2;
    QAction *action3;
    QAction *action4;

    QPushButton *run1;
    QPushButton *run2;
    QPushButton *run3;
    QPushButton *run4;
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    QPushButton *button4;
    QPushButton *b1[9];
    QPushButton *b2[9];
    QPushButton *b3[9];
    QPushButton *b4[9];
    QPushButton *pb1[9];
    QPushButton *pb2[9];
    QPushButton *pb3[9];
    QPushButton *pb4[9];

    QDialog *d1;
    QDialog *d2;
    QDialog *d3;
    QDialog *d4;

    int number1[9];
    int number2[9];
    int number3[10];
    int number4[9];
};

#endif // MAINWINDOW_H

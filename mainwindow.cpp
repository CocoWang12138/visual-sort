#include "mainwindow.h"
#include"MaxHeap.h"
#include<QAction>
#include<QApplication>
#include<QMenuBar>
#include<QPushButton>
#include<QTime>
#include<QPropertyAnimation>
#include<QPainter>
#include<QKeyEvent>

void sleep(unsigned int msec)
{
QTime dieTime = QTime::currentTime().addMSecs(msec);
while( QTime::currentTime() < dieTime )
QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("四种排序过程的动态图形演示");    //设置窗口标题
    resize(1080,680);   //设置窗口的最小尺寸
    showMinimized();    //  最小化显示窗口
    QFont font; //定义字体句柄font
    font.setPointSize(25);  //设置字号为25

    QPushButton *qbutton1=new QPushButton(this);
    qbutton1->setText("冒泡排序");  //文本显示
    qbutton1->setStyleSheet("background-color:rgb(255,229,153);");   //颜色
    qbutton1->setGeometry(200,150,250,60);  //设置按钮的位置与大小
    connect(qbutton1,&QPushButton::clicked,this,&MainWindow::open1);    //绑定单击的动作
    qbutton1->setFont(font);    //设置字体为自定义的font
    qbutton1->show();   //显示按钮

    QPushButton *qbutton2=new QPushButton(this);    //同qbutton1
    qbutton2->setText("箱子排序");
    qbutton2->setStyleSheet("background-color:rgb(182,215,168);");
    qbutton2->setGeometry(600,150,250,60);
    connect(qbutton2,&QPushButton::clicked,this,&MainWindow::open2);
    qbutton2->setFont(font);
    qbutton2->show();

    QPushButton *qbutton3=new QPushButton(this);
    qbutton3->setText("堆排序");
    qbutton3->setStyleSheet("background-color:rgb(162,196,201);");
    qbutton3->setGeometry(200,350,250,60);
    connect(qbutton3,&QPushButton::clicked,this,&MainWindow::open3);
    qbutton3->setFont(font);
    qbutton3->show();


    QPushButton *qbutton4=new QPushButton(this);
    qbutton4->setText("归并排序");
    qbutton4->setStyleSheet("background-color:rgb(164,194,244);");
    qbutton4->setGeometry(600,350,250,60);
    connect(qbutton4,&QPushButton::clicked,this,&MainWindow::open4);
    qbutton4->setFont(font);
    qbutton4->show();

    QPushButton *quit=new QPushButton(this);    //退出按钮
    quit->setText("退出");
    quit->setStyleSheet("background-color:rgb(180,167,214);");
    quit->setGeometry(960,600,100,50);
    connect(quit,&QPushButton::clicked,this,&MainWindow::close);
    quit->setFont(font);
    quit->show();
}
MainWindow::~MainWindow()
{
}
void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.drawPixmap(0,0,width(),height(),QPixmap(":/background.jfif"));
}

void MainWindow::open1(){
    d1 =new QDialog(this);
    d1->setWindowTitle("冒泡排序");
    d1->setFixedSize(1080,400);   //设置窗体固定尺寸
    d1->show();
    button1=new QPushButton(d1);
    button1->setText("冒泡排序：点击产生数据");
    button1->setStyleSheet("border:2px groove blue;border-radius:10px;padding:2px 4px;");
    button1->setGeometry(440,40,200,40);
    connect(button1,&QPushButton::clicked,this,&MainWindow::open5);
    button1->show();
}
void MainWindow::open2(){
    d2 =new QDialog(this);
    d2->setWindowTitle("箱子排序");
    d2->setFixedSize(1080,880);   //设置窗体固定尺寸
    d2->show();
    button2=new QPushButton(d2);
    button2->setText("箱子排序：点击产生数据");
    button2->setStyleSheet("border:2px groove blue;border-radius:10px;padding:2px 4px;");
    button2->setGeometry(440,40,200,40);
    connect(button2,&QPushButton::clicked,this,&MainWindow::open6);
    button2->show();
}
void MainWindow::open3(){
    d3 =new QDialog(this);
    d3->setWindowTitle("堆排序");
    d3->setFixedSize(1080,680);   //设置窗体固定尺寸
    d3->show();
    button3=new QPushButton(d3);
    button3->setText("堆排序：点击产生数据");
    button3->setStyleSheet("border:2px groove blue;border-radius:10px;padding:2px 4px;");
    button3->setGeometry(440,40,200,40);
    connect(button3,&QPushButton::clicked,this,&MainWindow::open7);
    button3->show();
}
void MainWindow::open4(){
    d4 =new QDialog(this);
    d4->setWindowTitle("归并排序");
    d4->setFixedSize(1080,680);   //设置窗体固定尺寸
    d4->show();
    button4=new QPushButton(d4);
    button4->setText("归并排序：点击产生数据");
    button4->setStyleSheet("border:2px groove blue;border-radius:10px;padding:2px 4px;");
    button4->setGeometry(440,40,200,40);
    connect(button4,&QPushButton::clicked,this,&MainWindow::open8);
    button4->show();
}

void MainWindow::open5(){
  for(int i=0;i<9;i++){
     number1[i]=rand()%100; //生成随机数
     b1[i]=new QPushButton(d1); //生成一个新的按钮（数据）
     b1[i]->setGeometry(20+80*i,100,40,40);
     b1[i]->setText(QString::number(number1[i]));
     b1[i]->setStyleSheet("background-color:rgb(24,249,150);"); //未排序的数据为绿色
     b1[i]->show();
  }
     run1=new QPushButton(d1);
     run1->setText("点击进行冒泡排序");
     run1->setStyleSheet("border:2px groove blue;border-radius:10px;padding:2px 4px;");
     run1->setGeometry(440,150,200,40);
     connect(run1,&QPushButton::clicked,this,&MainWindow::sort1);   //点击排序，进行冒泡排序
     run1->show();
}
void MainWindow::open6(){
  for(int i=0;i<9;i++){
     number2[i]=rand()%9;
     b2[i]=new QPushButton(d2);
     b2[i]->setGeometry(20+80*i,100,40,40);
     b2[i]->setText(QString::number(number2[i]));
     b2[i]->setStyleSheet("background-color:rgb(24,249,150);"); //未排序的数据为绿色
     b2[i]->show();}
     run2=new QPushButton(d2);
     run2->setText("点击进行箱子排序");
     run2->setStyleSheet("border:2px groove blue;border-radius:10px;padding:2px 4px;");
     run2->setGeometry(440,150,200,40);
     connect(run2,&QPushButton::clicked,this,&MainWindow::sort2);   //点击排序，进行箱子排序
     run2->show();
}
void MainWindow::open7(){
  for(int i=0;i<9;i++){
     number3[i+1]=rand()%100;
     b3[i]=new QPushButton(d3);
     b3[i]->setGeometry(20+80*i,100,40,40);
     b3[i]->setText(QString::number(number3[i+1]));
     b3[i]->setStyleSheet("background-color:rgb(24,249,150);");
     b3[i]->show();}
     run3=new QPushButton(d3);
     run3->setText("点击进行堆排序");
     run3->setStyleSheet("border:2px groove blue;border-radius:10px;padding:2px 4px;");
     run3->setGeometry(440,150,200,40);
     connect(run3,&QPushButton::clicked,this,&MainWindow::sort3);
     run3->show();
}
void MainWindow::open8(){
  for(int i=0;i<9;i++){
     number4[i]=rand()%100;
     b4[i]=new QPushButton(d4);
     b4[i]->setGeometry(20+80*i,100,40,40);
     b4[i]->setText(QString::number(number4[i]));
     b4[i]->setStyleSheet("background-color:rgb(24,249,150);");
     b4[i]->show();}
     run4=new QPushButton(d4);
     run4->setText("点击进行归并排序");
     run4->setStyleSheet("border:2px groove blue;border-radius:10px;padding:2px 4px;");
     run4->setGeometry(440,150,200,40);
     connect(run4,&QPushButton::clicked,this,&MainWindow::sort4);
     run4->show();
}
void MainWindow::sort1(){   //冒泡排序
    for(int n=0;n<9;n++){
       pb1[n]=new QPushButton(d1);
       pb1[n]->setGeometry(20+80*n,200,40,40);
       pb1[n]->setText(QString::number(number1[n]));
       pb1[n]->setStyleSheet("background-color:rgb(24,249,150);");
       pb1[n]->show();
    }
     int tmp;
     for(int i=9;i>1;i--){
         for(int j=0;j<i-1;j++){
             if(pb1[j]->text().toInt()>pb1[j+1]->text().toInt()){
                 pb1[j]->setStyleSheet("background-color:rgb(250,120,10);");
                 sleep(200);
                 pb1[j]->setStyleSheet("background-color:rgb(24,249,150);");
                 pb1[j+1]->setStyleSheet("background-color:rgb(250,120,10);");
                 tmp=pb1[j]->text().toInt();
                 pb1[j]->setText(pb1[j+1]->text());
                 pb1[j+1]->setText(QString::number(tmp));
             }
             else{pb1[j]->setStyleSheet("background-color:rgb(24,249,150);");}
             sleep(500);
         }
         pb1[i-1]->setStyleSheet("background-color:rgb(250,120,10);");
         sleep(1000);
     }
}
void MainWindow::sort2(){   //箱子排序
    QPushButton *pb21[9];
    for(int n=0;n<9;n++){
       pb2[n]=new QPushButton(d2);
       pb2[n]->setGeometry(20,200+50*n,100,40);
       pb2[n]->setText("箱子"+QString::number(n));
       pb2[n]->setStyleSheet("background-color:rgb(250,120,10);");
       pb2[n]->show();
    }
    sleep(500);
    for(int i=0;i<9;i++){
        pb21[i]=new QPushButton(d2);
        pb21[i]->setText(QString::number(number2[i]));
        pb21[i]->setStyleSheet("background-color:rgb(24,249,150);");
        pb21[i]->setGeometry(150+80*i,200+50*number2[i],40,40);
        pb21[i]->show();
        sleep(1000);
    }
    int j1=0;
    for(int n1=0;n1<9;n1++){
      if(pb21[n1]->text().toInt()==0){
          QPropertyAnimation *animation1=new QPropertyAnimation(pb21[n1],"geometry");
          animation1->setDuration(1000);
          animation1->setStartValue(QRect(150+80*n1,200,40,40));
          animation1->setEndValue(QRect(20+80*j1,650,40,40));
          animation1->start();
          j1++;
          sleep(1000);
      }
    }
    int j2=0;
    for(int n2=0;n2<9;n2++){
      if(pb21[n2]->text().toInt()==1){
          QPropertyAnimation *animation2=new QPropertyAnimation(pb21[n2],"geometry");
          animation2->setDuration(1000);
          animation2->setStartValue(QRect(150+80*n2,250,40,40));
          animation2->setEndValue(QRect(20+80*j1+80*j2,650,40,40));
          animation2->start();
          j2++;
          sleep(1000);
      }
    }
    int j3=0;
    for(int n3=0;n3<9;n3++){
      if(pb21[n3]->text().toInt()==2){
          QPropertyAnimation *animation3=new QPropertyAnimation(pb21[n3],"geometry");
          animation3->setDuration(1000);
          animation3->setStartValue(QRect(150+80*n3,300,40,40));
          animation3->setEndValue(QRect(20+80*j1+80*j2+80*j3,650,40,40));
          animation3->start();
          j3++;
          sleep(1000);
      }
    }
    int j4=0;
    for(int n4=0;n4<9;n4++){
      if(pb21[n4]->text().toInt()==3){
          QPropertyAnimation *animation4=new QPropertyAnimation(pb21[n4],"geometry");
          animation4->setDuration(1000);
          animation4->setStartValue(QRect(150+80*n4,350,40,40));
          animation4->setEndValue(QRect(20+80*j1+80*j2+80*j3+80*j4,650,40,40));
          animation4->start();
          j4++;
          sleep(1000);
      }
    }
    int j5=0;
    for(int n5=0;n5<9;n5++){
      if(pb21[n5]->text().toInt()==4){
          QPropertyAnimation *animation5=new QPropertyAnimation(pb21[n5],"geometry");
          animation5->setDuration(1000);
          animation5->setStartValue(QRect(150+80*n5,400,40,40));
          animation5->setEndValue(QRect(20+80*j1+80*j2+80*j3+80*j4+80*j5,650,40,40));
          animation5->start();
          j5++;
          sleep(1000);
      }
    }
    int j6=0;
    for(int n6=0;n6<9;n6++){
      if(pb21[n6]->text().toInt()==5){
          QPropertyAnimation *animation6=new QPropertyAnimation(pb21[n6],"geometry");
          animation6->setDuration(1000);
          animation6->setStartValue(QRect(150+80*n6,450,40,40));
          animation6->setEndValue(QRect(20+80*j1+80*j2+80*j3+80*j4+80*j5+80*j6,650,40,40));
          animation6->start();
          j6++;
          sleep(1000);
      }
    }
    int j7=0;
    for(int n7=0;n7<9;n7++){
      if(pb21[n7]->text().toInt()==6){
          QPropertyAnimation *animation7=new QPropertyAnimation(pb21[n7],"geometry");
          animation7->setDuration(1000);
          animation7->setStartValue(QRect(150+80*n7,500,40,40));
          animation7->setEndValue(QRect(20+80*j1+80*j2+80*j3+80*j4+80*j5+80*j6+80*j7,650,40,40));
          animation7->start();
          j7++;
          sleep(1000);
      }
    }
    int j8=0;
    for(int n8=0;n8<9;n8++){
      if(pb21[n8]->text().toInt()==7){
          QPropertyAnimation *animation8=new QPropertyAnimation(pb21[n8],"geometry");
          animation8->setDuration(1000);
          animation8->setStartValue(QRect(150+80*n8,550,40,40));
          animation8->setEndValue(QRect(20+80*j1+80*j2+80*j3+80*j4+80*j5+80*j6+80*j7+80*j8,650,40,40));
          animation8->start();
          j8++;
          sleep(1000);
      }
    }
    int j9=0;
    for(int n9=0;n9<9;n9++){
      if(pb21[n9]->text().toInt()==8){
          QPropertyAnimation *animation9=new QPropertyAnimation(pb21[n9],"geometry");
          animation9->setDuration(1000);
          animation9->setStartValue(QRect(150+80*n9,600,40,40));
          animation9->setEndValue(QRect(20+80*j1+80*j2+80*j3+80*j4+80*j5+80*j6+80*j7+80*j8+80*j9,650,40,40));
          animation9->start();
          j9++;
          sleep(1000);
      }
    }


}
void MainWindow::sort3(){   //堆排序
    MaxHeap m(9);
    m.Initialize(number3,9,10);
    for(int j=0;j<9;j++){
       pb3[j]=new QPushButton(d3);
       pb3[j]->setGeometry(20+80*j,200,40,40);
       pb3[j]->setText(QString::number(m.heap[j+1]));
       pb3[j]->setStyleSheet("background-color:rgb(24,249,150);");
       pb3[j]->show();
       sleep(200);
    }
    sleep(1000);
    int x;
    m.DeleteMax(x);
    for(int n1=0;n1<9;n1++){
            if(pb3[n1]->text().toInt()==x){
                QPropertyAnimation *animation1=new QPropertyAnimation(pb3[n1],"geometry");
                animation1->setDuration(1000);
                animation1->setStartValue(QRect(20+80*n1,200,40,40));
                animation1->setEndValue(QRect(660,600,40,40));
                animation1->start();
            }
     }
    sleep(2000);
    QPushButton *pb31[8];
    for(int n2=0;n2<8;n2++){
        pb31[n2]=new QPushButton(d3);
        pb31[n2]->setGeometry(20+80*n2,250,40,40);
        pb31[n2]->setText(QString::number(m.heap[n2+1]));
        pb31[n2]->setStyleSheet("background-color:rgb(24,249,150);");
        pb31[n2]->show();
        sleep(200);}
    sleep(1000);
    m.DeleteMax(x);
    for(int n3=0;n3<8;n3++){
            if(pb31[n3]->text().toInt()==x){
                QPropertyAnimation *animation2=new QPropertyAnimation(pb31[n3],"geometry");
                animation2->setDuration(1000);
                animation2->setStartValue(QRect(20+80*n3,250,40,40));
                animation2->setEndValue(QRect(580,600,40,40));
                animation2->start();
            }
     }
    sleep(2000);
    QPushButton *pb32[7];
    for(int n4=0;n4<7;n4++){
        pb32[n4]=new QPushButton(d3);
        pb32[n4]->setGeometry(20+80*n4,300,40,40);
        pb32[n4]->setText(QString::number(m.heap[n4+1]));
        pb32[n4]->setStyleSheet("background-color:rgb(24,249,150);");
        pb32[n4]->show();
        sleep(200);}
    sleep(1000);
    m.DeleteMax(x);
    for(int n5=0;n5<7;n5++){
            if(pb32[n5]->text().toInt()==x){
                QPropertyAnimation *animation3=new QPropertyAnimation(pb32[n5],"geometry");
                animation3->setDuration(1000);
                animation3->setStartValue(QRect(20+80*n5,300,40,40));
                animation3->setEndValue(QRect(500,600,40,40));
                animation3->start();
            }
     }
    sleep(2000);
    QPushButton *pb33[6];
    for(int n6=0;n6<6;n6++){
        pb33[n6]=new QPushButton(d3);
        pb33[n6]->setGeometry(20+80*n6,350,40,40);
        pb33[n6]->setText(QString::number(m.heap[n6+1]));
        pb33[n6]->setStyleSheet("background-color:rgb(24,249,150);");
        pb33[n6]->show();
        sleep(200);}
    sleep(1000);
    m.DeleteMax(x);
    for(int n7=0;n7<6;n7++){
            if(pb33[n7]->text().toInt()==x){
                QPropertyAnimation *animation4=new QPropertyAnimation(pb33[n7],"geometry");
                animation4->setDuration(1000);
                animation4->setStartValue(QRect(20+80*n7,350,40,40));
                animation4->setEndValue(QRect(420,600,40,40));
                animation4->start();
            }
     }
    sleep(2000);
    QPushButton *pb34[5];
    for(int n8=0;n8<5;n8++){
        pb34[n8]=new QPushButton(d3);
        pb34[n8]->setGeometry(20+80*n8,400,40,40);
        pb34[n8]->setText(QString::number(m.heap[n8+1]));
        pb34[n8]->setStyleSheet("background-color:rgb(24,249,150);");
        pb34[n8]->show();
        sleep(200);}
    sleep(1000);
    m.DeleteMax(x);
    for(int n9=0;n9<5;n9++){
            if(pb34[n9]->text().toInt()==x){
                QPropertyAnimation *animation5=new QPropertyAnimation(pb34[n9],"geometry");
                animation5->setDuration(1000);
                animation5->setStartValue(QRect(20+80*n9,400,40,40));
                animation5->setEndValue(QRect(340,600,40,40));
                animation5->start();
            }
     }
    sleep(2000);
    QPushButton *pb35[4];
    for(int n10=0;n10<4;n10++){
        pb35[n10]=new QPushButton(d3);
        pb35[n10]->setGeometry(20+80*n10,450,40,40);
        pb35[n10]->setText(QString::number(m.heap[n10+1]));
        pb35[n10]->setStyleSheet("background-color:rgb(24,249,150);");
        pb35[n10]->show();
        sleep(200);}
    sleep(1000);
    m.DeleteMax(x);
    for(int n11=0;n11<4;n11++){
            if(pb35[n11]->text().toInt()==x){
                QPropertyAnimation *animation6=new QPropertyAnimation(pb35[n11],"geometry");
                animation6->setDuration(1000);
                animation6->setStartValue(QRect(20+80*n11,450,40,40));
                animation6->setEndValue(QRect(260,600,40,40));
                animation6->start();
            }
     }
    sleep(2000);
    QPushButton *pb36[3];
    for(int n12=0;n12<3;n12++){
        pb36[n12]=new QPushButton(d3);
        pb36[n12]->setGeometry(20+80*n12,500,40,40);
        pb36[n12]->setText(QString::number(m.heap[n12+1]));
        pb36[n12]->setStyleSheet("background-color:rgb(24,249,150);");
        pb36[n12]->show();
        sleep(200);}
    sleep(1000);
    m.DeleteMax(x);
    for(int n13=0;n13<3;n13++){
            if(pb36[n13]->text().toInt()==x){
                QPropertyAnimation *animation7=new QPropertyAnimation(pb36[n13],"geometry");
                animation7->setDuration(1000);
                animation7->setStartValue(QRect(20+80*n13,500,40,40));
                animation7->setEndValue(QRect(180,600,40,40));
                animation7->start();
            }
     }
    sleep(2000);
    QPushButton *pb37[2];
    for(int n14=0;n14<2;n14++){
        pb37[n14]=new QPushButton(d3);
        pb37[n14]->setGeometry(20+80*n14,550,40,40);
        pb37[n14]->setText(QString::number(m.heap[n14+1]));
        pb37[n14]->setStyleSheet("background-color:rgb(24,249,150);");
        pb37[n14]->show();
        sleep(200);}
    sleep(1000);
    m.DeleteMax(x);
    for(int n15=0;n15<2;n15++){
            if(pb37[n15]->text().toInt()==x){
                QPropertyAnimation *animation8=new QPropertyAnimation(pb37[n15],"geometry");
                animation8->setDuration(1000);
                animation8->setStartValue(QRect(20+80*n15,550,40,40));
                animation8->setEndValue(QRect(100,600,40,40));
                animation8->start();
                sleep(2000);
            }
            else{
                QPropertyAnimation *animation9=new QPropertyAnimation(pb37[n15],"geometry");
                animation9->setDuration(1000);
                animation9->setStartValue(QRect(20+80*n15,550,40,40));
                animation9->setEndValue(QRect(20,600,40,40));
                animation9->start();
            }
     }

}
void MainWindow::sort4(){   //归并排序
    for(int n=0;n<9;n++){
        pb4[n]=new QPushButton(d4);
        pb4[n]->setStyleSheet("background-color:rgb(24,249,150);");
        pb4[n]->setText(QString::number(number4[n]));
        if(n==0||n==1){
           pb4[n]->setGeometry(20+80*n,200,40,40);
           pb4[n]->show();
           sleep(200);
        }
        if(n==2||n==3){
           pb4[n]->setGeometry(70+80*n,200,40,40);
           pb4[n]->show();
           sleep(200);
        }
        if(n==4||n==5){
           pb4[n]->setGeometry(120+80*n,200,40,40);
           pb4[n]->show();
           sleep(200);
        }
        if(n==6||n==7){
           pb4[n]->setGeometry(170+80*n,200,40,40);
           pb4[n]->show();
           sleep(200);
        }
        if(n==8){
            pb4[n]->setGeometry(220+80*n,200,40,40);
            pb4[n]->show();
            sleep(200);
        }

    }
    sleep(1000);
    if(pb4[0]->text().toInt()>pb4[1]->text().toInt()){
        number4[0]=pb4[1]->text().toInt();
        number4[1]=pb4[0]->text().toInt();
        QPropertyAnimation *animation1=new QPropertyAnimation(pb4[0],"geometry");
        animation1->setDuration(500);
        animation1->setStartValue(QRect(20,200,40,40));
        animation1->setEndValue(QRect(100,200,40,40));
        animation1->start();
        QPropertyAnimation *animation2=new QPropertyAnimation(pb4[1],"geometry");
        animation2->setDuration(500);
        animation2->setStartValue(QRect(100,200,40,40));
        animation2->setEndValue(QRect(20,200,40,40));
        animation2->start();
    }
    if(pb4[2]->text().toInt()>pb4[3]->text().toInt()){
        number4[2]=pb4[3]->text().toInt();
        number4[3]=pb4[2]->text().toInt();
        QPropertyAnimation *animation3=new QPropertyAnimation(pb4[2],"geometry");
        animation3->setDuration(500);
        animation3->setStartValue(QRect(230,200,40,40));
        animation3->setEndValue(QRect(310,200,40,40));
        animation3->start();
        QPropertyAnimation *animation4=new QPropertyAnimation(pb4[3],"geometry");
        animation4->setDuration(500);
        animation4->setStartValue(QRect(310,200,40,40));
        animation4->setEndValue(QRect(230,200,40,40));
        animation4->start();
    }

    if(pb4[4]->text().toInt()>pb4[5]->text().toInt()){
        number4[4]=pb4[5]->text().toInt();
        number4[5]=pb4[4]->text().toInt();
        QPropertyAnimation *animation5=new QPropertyAnimation(pb4[4],"geometry");
        animation5->setDuration(500);
        animation5->setStartValue(QRect(440,200,40,40));
        animation5->setEndValue(QRect(520,200,40,40));
        animation5->start();
        QPropertyAnimation *animation6=new QPropertyAnimation(pb4[5],"geometry");
        animation6->setDuration(500);
        animation6->setStartValue(QRect(520,200,40,40));
        animation6->setEndValue(QRect(440,200,40,40));
        animation6->start(); }
    if(pb4[6]->text().toInt()>pb4[7]->text().toInt()){
        number4[6]=pb4[7]->text().toInt();
        number4[7]=pb4[6]->text().toInt();
        QPropertyAnimation *animation7=new QPropertyAnimation(pb4[6],"geometry");
        animation7->setDuration(500);
        animation7->setStartValue(QRect(650,200,40,40));
        animation7->setEndValue(QRect(730,200,40,40));
        animation7->start();
        QPropertyAnimation *animation8=new QPropertyAnimation(pb4[7],"geometry");
        animation8->setDuration(500);
        animation8->setStartValue(QRect(730,200,40,40));
        animation8->setEndValue(QRect(650,200,40,40));
        animation8->start();
    }
    sleep(2000);
    int number41[5];
    int number42[5];
    for(int i1=0;i1<4;i1++)
    {
        number41[i1+1]=number4[i1];
        number42[i1+1]=number4[i1+4];
    }
    MaxHeap m1(4);
    m1.Initialize(number41,4,10);
    MaxHeap m2(4);
    m2.Initialize(number42,4,10);
    int x;
    for(int i2=0;i2<4;i2++){
        m1.DeleteMax(x);
        number4[3-i2]=x;
        m2.DeleteMax(x);
        number4[7-i2]=x;
    }
    QPushButton *pb41[9];
     int number43[8];
    for(int i3=0;i3<9;i3++){
        pb41[i3]=new QPushButton(d4);
        pb41[i3]->setStyleSheet("background-color:rgb(24,249,150);");
        pb41[i3]->setText(QString::number(number4[i3]));
    if(i3!=8) number43[i3]=number4[i3];
    if(i3>=0&&i3<=3){
       pb41[i3]->setGeometry(20+80*i3,300,40,40);
       pb41[i3]->show();
       sleep(200);}

    if(i3>=4&&i3<=7){
       pb41[i3]->setGeometry(70+80*i3,300,40,40);
       pb41[i3]->show();
       sleep(200);}
    }
     pb41[8]->setGeometry(120+80*8,300,40,40);
     pb41[8]->show();
     sleep(2000);
     BubbleSort(number43,8);
     QPushButton *pb42[9];
     for(int i4=0;i4<9;i4++){
         pb42[i4]=new QPushButton(d4);
         pb42[i4]->setStyleSheet("background-color:rgb(24,249,150);");
       if(i4!=8){
         pb42[i4]->setText(QString::number(number43[i4]));
         pb42[i4]->setGeometry(20+80*i4,400,40,40);
         pb42[i4]->show();
         sleep(200);}
     }
     pb42[8]->setText(QString::number(number4[8]));
     pb42[8]->setGeometry(70+80*8,400,40,40);
     pb42[8]->show();
     sleep(2000);
     BubbleSort(number4,9);
     for(int j=0;j<9;j++){
        QPushButton *button=new QPushButton(d4);
        button->setGeometry(20+80*j,500,40,40);
        button->setText(QString::number(number4[j]));
        button->setStyleSheet("background-color:rgb(24,249,150);");
        button->show();
        sleep(200);}
}

#include "Start.h"
#include "ui_Start.h"
#include "mainwindow.h"

Start::Start(QWidget *parent):
    QWidget(parent), ui(new Ui::Start)
{
 ui->setupUi(this);
 setWindowTitle("Start");
 const int num=3; //关卡和按钮数量
 QPushButton*a[num]={ui->pushButton_1,ui->pushButton_2,ui->pushButton_3};
 for (int i=0;i<num;i++){
     connect(a[i],&QPushButton::clicked,[=](){
         MainWindow *mainwindow = new MainWindow(i);
         mainwindow->show();
     }); //根据被点击的按钮跳转对应关卡页面
 }
}

Start::~Start(){
    delete ui;
}

#include "startfrom.h"
#include "ui_startfrom.h"
#include "mainwindow.h"
#include <QPushButton>
#include <QPixmap>

Startfrom::Startfrom(QWidget *parent)
    :QWidget(parent)
  , ui(new Ui::Startfrom)
{
  ui->setupUi(this);
  this->setWindowTitle("Start");
  const int num=3; //关卡和按钮数量
  QPushButton*a[num]={ui->pushButton_1,ui->pushButton_2,ui->pushButton_3};
  for (int i=0;i<num;i++){
      connect(a[i],&QPushButton::clicked,[=](){
          MainWindow *mainwindow = new MainWindow(i);
          mainwindow->show();
      }); //根据被点击的按钮跳转对应关卡页面
 }
  QPixmap pixmap(QString(":/Back.png"));
}

Startfrom::~Startfrom(){
    delete ui;
}

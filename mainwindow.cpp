#include <bits/stdc++.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QDebug>
#include <QPushButton>
#include <QMediaPlayer>
#include <QLabel>
#include "Structure.h"
#include "StationOne.h"
#include "StationTwo.h"
#include "StationThree.h"
#include "StationFour.h"

using namespace std;

#define MouseClickPlace(X,Y,Width,Height) \
    (ev->x() >= (X) && ev->x() <= (X)+(Width) && \
     ev->y() >= (Y) && ev->y() <= (Y)+(Height)) //鼠标点击区域

#define DistanceBetween(X1,Y1,X2,Y2) \
    abs(sqrt(((X1)-(X2))*((X1)-(X2))+((Y1)-(Y2))*((Y1)-(Y2)))) //两点间距离

#define X_(X,Y)((X)-1)*50+10,((Y)-1)*50+10 //确定路径点坐标

#define InstallEnemy(PathNum,StartdNum,EnemyId) \
    EnemyVec.push_back(new Enemy(point[PathNum], \
    PathLength[PathNum],X_(startd[StartdNum].x,startd[StartdNum].y),EnemyId)); //插入敌舰

inline bool MainWindow::DeductionMoney(int money){
    if(this->money-money<0) return true; //判断金币是否充足
    this->money-=money; //扣除相应金币
    moneylable->setText(QString("金币：%1").arg(this->money));//刷新文本
    return false;
}

MainWindow::MainWindow(int LevelNum):LevelNum(LevelNum){
    setFixedSize(1200,800); //窗口大小
    setWindowTitle("Forest of Darkness"); //窗口标题
    QLabel *Winlable=new QLabel(this);
    Winlable->move(175,180);
    Winlable->setText(QString("You Win!"));
    Winlable->setFont(QFont("黑体",120));
    Winlable->hide(); //游戏胜利标签

    QTimer*timer0=new QTimer(this);
    timer0->start(2000); //定时器

    connet(timer0,&QTimer::timeout,[=](){ //执行不同关卡的路径方案
        switch(LevelNum){
        case1:
        {
            d*Routear1[]={new d(X_(8,6)),new d(X_(2,6)),new d(X_(2,13)),new d(X_(19,13)),new d(X_(19,9)),new d(homed->x,homed->y)};
            d*Routear2[]={new d(X_(20,5)),new d(X_(14,5)),new d(X_(14,9)),new d(X_(8,9)),new d(X_(8,6)),new d(X_(2,6)),new d(X_(2,13)),new d(X_(19,13)),new d(X_(19,9)),new d(homed->x,homed->y)};
            d startco[]={d(8,0),d(20,0),d(8,-1),d(20,-1)}; //四个起始点
            int PathLength[]={sizeof (Routear1)/sizeof (d*),sizeof (Routear1)/sizeof (d*)};
            IroEnemyProgDefa(Routear1,Routear2,startco,PathLength,Winlable); //使用预设方案
            break;
        }
        case 2:
        {
            d*Routear1[]={new d(X_(4,8)),new d(X_(20,8)),new d(X_(20,13)),new d(X_(6,13)),new d(homed->x,homed->y)};
            d*Routear2[]={new d(X_(11,8)),new d(X_(20,8)),new d(X_(20,13)),new d(X_(6,13)),new d(homed->x,homed->y)};
            d startco[]={d(4,0),d(11,0),d(4,-1),d(11,-1)}; //四个起始点
            int PathLength[]={sizeof (Routear1)/sizeof (d*),sizeof (Routear1)/sizeof (d*)};
            IroEnemyProgDefa(Routear1,Routear2,startco,PathLength,Winlable); //使用预设方案
            break;
        }
        case 3:
        {
            d*Routear1[]={new d(X_(12,9)),new d(X_(8,9)),new d(X_(8,0)),new d(homed->x,homed->y)};
            d*Routear2[]={new d(X_(12,9)),new d(X_(16,9)),new d(X_(16,0)),new d(homed->x,homed->y)};
            d startco[]={d(12,16),d(12,16),d(12,17),d(12,18)}; //四个起始点
            int PathLength[]={sizeof (Routear1)/sizeof (d*),sizeof (Routear1)/sizeof (d*)};
            IroEnemyProgDefa(Routear1,Routear2,startco,PathLength,Winlable); //使用预设方案
            break;
        }

    }
});

QPushButton* disranpush=new QPushButton(this);
disranpush->setStyleSheet("color:white");
disranpush->setFont(QFont("黑体",12));
disranpush->setText("全部显示");
disranpush->setGeometry(20,160,150,45); //显示防御站范围按钮

connect(disranpush,&QPushButton::clicked,[=](){ //改变标识，切换防御站攻击范围显示状态
    if(DisplayAllRange){
        DisplayAllRange=false;
        disranpush->setText("显示全部范围");
    }
    else{
        DisplayAllRange=true;
        disranpush->setText("隐藏全部范围");
    };
    update();
});

QLabel *hplable=new QLabel(this);
hplable->setText(QString("生命：%1").arg(life)); //生命值信息
hplable->setFont(QFont("黑体",24));
hplable->setGeometry(20,100,220,40); //生命值标签位置大小

moneylable->move(20,40); //金币标签位置
setStyleSheet("color:white"); //设置金币标签颜色
moneylable->setText(QString("金币：%1").arg(money)); //金币信息
moneylable->setFont(QFont("黑体",24));

QTimer *timer=new QTimer(this);
timer->start(120);
connect(timer,&QTimer::timeout,[=](){
    for(auto defei:StationVec){ //遍历
        if(!defei->GetGoalEnemy()){
            for(int i = EnemyVec.size() - 1; i >= 0; i--)
                                if (DistanceBetween(defei->GetUpLeftX() + 50, defei->GetUpLeftY() + 50,
                                    EnemyVec.at(i)->GetX() + (EnemyVec.at(i)->GetWidth() >> 1),
                                    EnemyVec.at(i)->GetY() + (EnemyVec.at(i)->GetHeight() >> 1)) <= defei->GetRange())
                                {
                                    defei->SetAimsMonster(EnemyVec.at(i));
    }
            break;
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPainter>
#include <QPushButton>
#include <QTimer>
#include <QLabel>
#include <QMouseEvent>
#include "Enemy.h"
#include "Selection.h"
#include "Stationparent.h"
#include "Stationpit.h"

class MainWindow:public QWidget
{
//  Q_OBJECT
public:
    MainWindow(int);
    ~MainWindow();
private:
    QVector<Enemy*>EnemyVec; //敌舰数组
    Selection*Selec=new Selection(":/Selection.png"); //选择框类
    QVector<Stationpit*>StationpitVec; //防御站坑数组
    QVector<Stationparent*>StationparVec; //防御站父类数组

    int DisplayRangeX,DisplayRangeY; //记录显示范围的防御站坐标
    int life=10; //一共有十条命
    int coins=1000; //金币初值1000
    int counter=0; //用于产生敌舰的计数器
    const int PlusCoins=30; //每次击败敌舰获得金币30
    const int LevelNum; //标识关卡

    bool DisplayRange=false; //防御站攻击范围显示状态(不点击按钮默认不显示)
    bool DisplayAllRange=false; //所有防御站攻击范围显示状态
    inline bool DeductionCoins(int); //判断金币是否足够，刷新标签

    d *home=new d(0,0); //记录总部的坐标
    void IronEnemProgDefa(d**,d**,d*,int*,QLabel*); //预设两种敌舰运动路线方案函数

    struct Explo{ //爆炸效果结构
        d dd; //记录坐标
        int index=1; //记录要显示的图片文件序号
        int ExplRangeWidth; int ExplRangeHeight; //显示宽度和高度
        Explo(d ed,int width,int height): dd(ed),ExplRangeWidth(width),ExplRangeHeight(height){}
    };

    void paintEvent(QPaintEvent *); //绘图事件
    void mousePressEvent(QMouseEvent *); //鼠标点击事件
    void DrawMap(QPainter&); //绘制地图函数
    void DrawSelection(QPainter&); //绘制选择框
    void DrawEnemy(QPainter&); //绘制敌舰
    void DrawStation(QPainter&); //绘制防御站
    void DrawExplosion(QPainter&); //绘制爆炸效果
    void DrawRangeUpgrade(QPainter&); //绘制防御站攻击范围以及升级按钮

    QVector<Explo*>ExploEffect; //爆炸效果坐标数组
    QLabel *coinslable=new QLabel(this); //金币标签控件
};

#endif // MAINWINDOW_H

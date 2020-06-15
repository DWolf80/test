#ifndef ENEMY_H
#define ENEMY_H
#include <QString>
#include <QVector>
#include "Structure.h"

class Enemy //敌人类
{
private:
    QVector<d*> Route; //敌舰路径点数组
    int ex,ey; //敌舰位置坐标
    int ewidth,eheight; //敌舰大小
    int id; //敌舰编号
    int hp; //敌舰生命值
    const int espeed=10; //敌舰运动速度10
    QString ImgPath; //敌舰图片路径

public:
    Enemy(d**point,int pointnum ,int x,int y,int eid); //敌舰路径点，路径点个数，位置，编号
    bool Move(); //敌舰移动函数
    int GetX() const; //获取横坐标
    int GetY() const; //获取纵坐标
    int GetWidth() const; //获取宽
    int GetHeight() const; //获取高
    int GetId() const; //获取编号
    int GetHp() const; //获取生命值
    void SetHp(int); //设置生命值
    QString GetImgPath() const; //获取图片路径
};

#endif // ENEMY_H

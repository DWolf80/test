#ifndef STATIONPARENT_H
#define STATIONPARENT_H
#include <QString>
#include "Enemy.h"

class Stationparent //防御站父类
{
protected:
    int sx,sy,width,height; //横纵坐标、宽度、高度
    int Angle=0; //防御站旋转角度
    int UpLeftX,UpLeftY; //防御站坑原坐标
    int Range; //射程
    int Power; //子弹威力
    int Bullwidth; int Bullheight; //子弹宽度高度
    int Counter=0;
    int Attack; //防御站攻击力
    int ExplRangeWidth;int ExplRangeHeight; //爆炸效果高度宽度
    Enemy*goal=NULL; //防御站目标敌人
    QVector<Bullet*>BulletVec; //子弹结构数组
    QString BaseImgPath; //防御站底座图片路径
    QString DefImgPath; //防御站图片路径
    QString BullPath; //子弹图片路径
public:
    int GetX() const; //获取横坐标
    int GetY() const; //获取纵坐标
    int GetWidth() const; //获取宽度
    int GetHeight() const; //获取高度
    int GetAngle() const; //获取旋转角度
    int GetUpLeftX() const; //防御站原位置左上角横坐标
    int GetUpLeftY() const; //防御站原位置左上角纵坐标
    int GetRange() const; //防御站射程
    int GetAttack() const; //防御站威力
    void SetWidthHeight(int,int); //设置防御站宽度高度
    void SetXY(int,int); //设置防御站坐标
    void SetAttack(int); //设置防御站威力
    int &SetRange(); //设置防御站攻击范围
    void SetAngle(int ang); //设置旋转角度
    QString GetBaseImgPath() const; //获取防御站底座图片路径
    QString GetDefImgPath() const; //获取防御站图片路径

    QString GetBulletPath() const; //子弹图片路径
    QVector<Bullet*>&GetBulletVec(); //返回到子弹数组
    int GetBulletWidth() const; //获取子弹的宽度
    int GetBulletHeight() const; //获取子弹的高度
    void NewBullet(); //生产子弹
    void BulletMove(); //子弹的移动

    int GetExplRangeWidth() const; //获取爆炸效果宽度
    int GetExplRangeHeight() const; //获取爆炸效果高度
    void SetExplRangeWidthHeight(int,int); //设置爆炸效果高度宽度（不同防御站）
    void SetBulletWidthHeight(int,int); //设置子弹宽度高度（不同子弹）

    Enemy* GetGoalsEnemy() const; //当前防御站目标敌舰
    void SetGoalEnemy(Enemy*); //设置当前防御站的目标敌舰
};

#endif // STATIONPARENT_H

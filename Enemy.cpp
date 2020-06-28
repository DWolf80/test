#include "Enemy.h"
#include <QDebug>

Enemy::Enemy(d**point,int pointnum,int x,int y,int eid):
    ex(x),ey(y),id(eid){
    for(int i=0;i<pointnum;i++)
        Route.push_back(point[i]);
    switch(id){ //不同敌舰的属性
        case 1: //战舰1
          hp=100;
          ewidth=65,eheight=65;
          ImgPath=":/Enemy1.png"; //战舰图片途径
          break;
        case 2: //战舰2
          hp=120;
          ewidth=85,eheight=85;
          ImgPath=":/Enemy2.png";
          break;
        case 3: //战舰3
          hp=150;
          ewidth=100,eheight=100;
          ImgPath=":/Enemy3.png";
          break;
        case 4: //战舰4
          hp=200;
          ewidth=120,eheight=120;
          ImgPath=":/Enemy4.png";
          break;
        case 5: //战舰5
          hp=500;
          ewidth=150,eheight=150;
          ImgPath=":/Enemy5.png";
          break;
        default:
          break;
    }
}

int Enemy::GetX() const{
    return ex;
} //获取横坐标
int Enemy::GetY() const{
    return ey;
} //获取纵坐标
int Enemy::GetHp() const{
    return hp;
} //获取生命值
int Enemy::GetId() const{
    return id;
} //获取编号
int Enemy::GetWidth() const{
    return ewidth;
} //获取宽度
int Enemy::GetHeight() const{
    return eheight;
} //获取高度
void Enemy::SetHp(int ehp){
    hp=ehp;
} //设置生命值
QString Enemy::GetImgPath() const{
    return ImgPath;
} //获取图片路径

bool Enemy::Move(){ //敌舰按照路径点运动
    if(Route.empty())
        return true;
    if(ex<Route.at(0)->x){ //路径点在敌舰坐标点右侧时，向右移动
        ex+=espeed;
        return false;
    }
    if(ex>Route.at(0)->x){ //向左移动
        ex-=espeed;
        return false;
    }
    if(ey<Route.at(0)->y){ //向下移动
        ey+=espeed;
        return false;
    }
    if(ey>Route.at(0)->y){ //向上移动
        ey-=espeed;
        return false;
    }
    if(Route.at(0)->x==ex && Route.at(0)->y==ey){ //敌舰坐标与设定路径点坐标重合，删除此路径点
        Route.erase(Route.begin());
    }
    return false;
}

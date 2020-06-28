#ifndef STRUCTURE_H
#define STRUCTURE_H
#include<QString>

struct d{
    int x;int y;
    d(int x1,int y1):x(x1),y(y1){}
}; //坐标结构

struct Bullet{
    d dd; //子弹坐标
    int p=0,q=0; //子弹路径函数参数
    bool direction=false;
    Bullet(d ed) : dd(ed){}
    int GetX() const{
        return dd.x;
    }
    int GetY() const{
        return dd.y;
    }
};

struct Subbut{
    int SubX; int SubY; //子按钮横纵坐标
    int SubWidth=60; int SubHeight=60; //子按钮宽度、高度
    QString SubImgPath; //子按钮图片路径
}; //子按钮结构

#endif // STRUCTURE_H

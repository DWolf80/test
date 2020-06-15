#ifndef STATIONPIT_H
#define STATIONPIT_H
#include<QVector>

class Stationpit //防御站坑类
{
private:
    const int sx,sy; //坐标
    const int swidth,sheight; //宽度高度
public:
    Stationpit(int x,int y,int swidth=80,int sheight=80);
    int GetX() const; //获取横坐标
    int GetY() const; //获取纵坐标
    int GetWidth() const; //获取宽度
    int GetHeight() const; //获取高度
};

#endif // STATIONPIT_H

#include "Stationpit.h"

Stationpit::Stationpit(int x,int y,int width,int height)
    :sx(x),sy(y),swidth(width),sheight(height){}

int Stationpit::GetX() const{
    return sx;
} //获取横坐标

int Stationpit::GetY() const{
    return sy;
} //获取纵坐标

int Stationpit::GetWidth() const{
    return swidth;
} //获取宽度

int Stationpit::GetHeight() const{
    return sheight;
} //获取高度

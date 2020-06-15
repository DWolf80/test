#include "Selection.h"

Selection::Selection(QString Path,int width,int height): SelecImgPath(Path),swidth(width),sheight(height)
{
}

int Selection::GetX() const{
    return sx;
} //获取横坐标

int Selection::GetY() const{
    return sy;
} //获取纵坐标

int Selection::GetWidth() const{
    return swidth;
} //获取宽度

int Selection::GetHeight() const{
    return sheight;
} //获取高度

QString Selection::GetImgPath() const{
    return SelecImgPath;
} //获取选择框图片路径

bool Selection::GetDisplay() const{
    return display;
} //获取显示状态

void Selection::SetDisplay(const bool Setplay){
    display=Setplay;
} //设置显示状态

Subbut* Selection::GetSelSubBut(){
    return SubBut;
} //获取子按钮结构数组

void Selection::ChooseStation(int x, int y){
    sx=x-100;
    sy=y-100; //选择框位置
    SubBut[0].SubX=sx+120;
    SubBut[0].SubY=sy+20;
    SubBut[0].SubImgPath=QString("");
    SubBut[1].SubX=sx+20;
    SubBut[1].SubY=sy+120;
    SubBut[1].SubImgPath=QString("");
    SubBut[2].SubX=sx+200;
    SubBut[2].SubY=sy+120;
    SubBut[2].SubImgPath=QString("");
    SubBut[3].SubX=sx+120;
    SubBut[3].SubY=sy+200;
    SubBut[3].SubImgPath=QString(""); //子按钮位置
    display=true; //显示
}

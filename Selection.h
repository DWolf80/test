#ifndef SELECTION_H
#define SELECTION_H
#include <QString>
#include "Structure.h"

class Selection //选择框
{
public:
    Selection(QString Path,int width=275,int height=275);
    int GetX() const; //获取横坐标
    int GetY() const; //获取纵坐标
    int GetWidth() const; //获取宽度
    int GetHeight() const; //获取高度
    bool GetDisplay() const; //获取显示状态
    QString GetImgPath() const; //获取图片路径
    void ChooseStation(int x,int y); //选中防御站
    void SetDisplay(const bool Setplay); //设置显示状态
    Subbut*GetSelSubBut(); //获取子按钮结构数组

private:
    bool display= false; //显示状态
    const int swidth,sheight; //大小
    int sx=0,sy=0; //确定位置：左上角坐标
    QString SelecImgPath; //选择框图片路径
    Subbut SubBut[4]; //子按钮
};

#endif // SELECTION_H

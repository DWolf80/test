#include "StationOne.h"

StationOne::StationOne(int x,int y,int SUpLeftX,int SUpLeftY,int Swidth,int Sheight){
  sx=x,sy=y;
  BaseImgPath=QString(":/Base1.png");
  DefImgPath=QString(":/Station1.png");
  width=Swidth,height=Sheight;
  UpLeftX=SUpLeftX,UpLeftY=SUpLeftY;
  Range=300; //射程
  BullPath=QString(":/Bullet1.png"); //子弹轨迹
  Bullwidth=50,Bullheight=50; //子弹大小
  Attack=90; //攻击数值
  ExplRangeWidth=75,ExplRangeHeight=70; //爆炸效果宽度、高度
 }

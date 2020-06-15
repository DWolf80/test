#include "StationOne.h"

StationOne::StationOne(int x,int y,int Swidth,int Sheight,int SUpLeftX,int SUpLeftY){
  sx=x,sy=y;
  BaseImgPath=QString("");
  DefImgPath=QString("");
  width=Swidth,height=Sheight;
  UpLeftX=SUpLeftX,UpLeftY=SUpLeftY;
  Range=300; //射程
  BullPath=QString(""); //子弹轨迹
  Bullwidth=50,Bullheight=50; //子弹大小
  Attack=40; //攻击数值
  ExplRangeWidth=75,ExplRangeHeight=75; //爆炸效果宽度、高度
 }

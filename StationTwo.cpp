#include "StationTwo.h"

StationTwo::StationTwo(int x,int y,int SUpLeftX,int SUpLeftY,int Swidth,int Sheight){
 sx=x,sy=y;
 BaseImgPath=QString(":/Base2.png");
 DefImgPath=QString(":/Station2.png");
 width=Swidth,height=Sheight;
 UpLeftX=SUpLeftX,UpLeftY=SUpLeftY;
 Range=200;
 BullPath=QString(":/Bullet2.png");
 Bullwidth=30,Bullheight=30;
 Attack=50;
 ExplRangeWidth=70,ExplRangeHeight=70;
}


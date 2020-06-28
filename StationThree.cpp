#include "StationThree.h"

StationThree::StationThree(int x,int y,int SUpLeftX,int SupLeftY,int Swidth,int Sheight)
{
 sx=x,sy=y;
 BaseImgPath=QString(":/Base3.png");
 DefImgPath=QString(":/Station3.png");
 width=Swidth,height=Sheight;
 UpLeftX=SUpLeftX,UpLeftY=SupLeftY;
 Range=150;
 BullPath=QString(":/Bullet3.png");
 Bullwidth=40,Bullheight=40;
 Attack=80;
 ExplRangeWidth=70,ExplRangeHeight=70;
}

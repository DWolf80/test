#include "MainStation.h"

MainStation::MainStation(int x,int y,int SUpLeftX,int SUpLeftY,int Swidth,int Sheight){
 sx=x,sy=y;
 BaseImgPath=QString(":/Base4.png");
 DefImgPath=QString(":/MainStation.png");
 width=Swidth;height=Sheight;
 UpLeftX=SUpLeftX;UpLeftY=SUpLeftY;
 Range=240;
 BullPath=QString(":/Bullet4.png");
 Bullwidth=60;Bullheight=60;
 Attack=120;
 ExplRangeWidth=85;ExplRangeHeight=85;
}

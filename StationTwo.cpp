#include "StationTwo.h"

StationTwo::StationTwo(int x,int y,int Swidth,int Sheight,int SUpLeftX,int SUpLeftY){
 sx=x,sy=y;
 BaseImgPath=QString("");
 DefImgPath=QString("");
 width=Swidth,height=Sheight;
 UpLeftX=SUpLeftX,UpLeftY=SUpLeftY;
 Range=200;
 BullPath=QString("");
 Bullwidth=30,Bullheight=30;
 Attack=50;
 ExplRangeWidth=70,ExplRangeHeight=70;
}


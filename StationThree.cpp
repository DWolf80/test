#include "StationThree.h"

StationThree::StationThree(int x,int y,int Swidth,int Sheight,int SUpLeftX,int SupLeftY)
{
 sx=x,sy=y;
 BaseImgPath=QString("");
 DefImgPath=QString("");
 width=Swidth,height=Sheight;
 UpLeftX=SUpLeftX,UpLeftY=SupLeftY;
 Range=150;
 BullPath=QString("");
 Bullwidth=40,Bullheight=40;
 Attack=80;
 ExplRangeWidth=70,ExplRangeHeight=70;
}

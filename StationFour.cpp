#include "StationFour.h"

StationFour::StationFour(int x,int y,int SUpLeftX,int SUpLeftY,int Swidth,int Sheight){
 sx=x,sy=y;
 BaseImgPath=QString("");
 DefImgPath=QString("");
 width=Swidth;height=Sheight;
 UpLeftX=SUpLeftX;UpLeftY=SUpLeftY;
 Range=135;
 BullPath=QString("");
 Bullwidth=60;Bullheight=60;
 Attack=100;
 ExplRangeWidth=85;ExplRangeHeight=85;
}

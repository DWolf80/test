#ifndef STATIONTHREE_H
#define STATIONTHREE_H
#include "Stationparent.h" //继承防御站父类

class StationThree:public Stationparent{ //第三类防御站
public:
    StationThree(int x,int y,int SUpLeftX,int SUpLeftY,int Swidth=80,int Sheight=80);
};

#endif // STATIONTHREE_H

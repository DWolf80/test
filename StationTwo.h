#ifndef STATIONTWO_H
#define STATIONTWO_H
#include "Stationparent.h" //继承防御站父类

class StationTwo:public Stationparent{ //第二类防御站
public:
    StationTwo(int x,int y,int SUpLeftX,int SUpLeftY,int Swidth=80,int Sheight=80);
};

#endif // STATIONTWO_H

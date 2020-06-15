#ifndef STATIONONE_H
#define STATIONONE_H
#include "Stationparent.h" //继承防御站父类

class StationOne:public Stationparent{//第一类防御站
public:
    StationOne(int x,int y,int SUpLeftX,int SUpLeftY,int Swidth=100,int Sheight=100);
};

#endif // STATIONONE_H

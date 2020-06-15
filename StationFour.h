#ifndef STATIONFOUR_H
#define STATIONFOUR_H
#include "Stationparent.h" //继承防御站父类

class StationFour:public Stationparent {//第四类防御站
public:
    StationFour(int x,int y,int SUpLeftX,int SUpLeftY,int Swidth=80,int Sheight=80);
};

#endif // STATIONFOUR_H

#ifndef MAINSTATION_H
#define MAINSTATION_H
#include "Stationparent.h" //最强防御站

class MainStation:public Stationparent{
public:
    MainStation(int x,int y,int SUpLeftX,int SUpLeftY,int Swidth=80,int Sheight=80);
};

#endif //MAINSTATION_H

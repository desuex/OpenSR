//
// Created by desuex on 09.05.2020.
//

#ifndef ABWORLD_TABZONE_H
#define ABWORLD_TABZONE_H


#include <QDataStream>
#include "windows.h"
#include "TabObj3D.h"

class TabZone {
public:
    TabZone *FPrev;
    TabZone *FNext;
    float FOrb;
    float FOrbAngle;
    float FRadiusAngle;
    float FRadius;
    TDxyz FPos;
    TDxyz FPosShow;
    int FType; // 0-normal 1-in 2,3,4-exit
    TabObj3D *FGraphLine;
    TabObj3D *FGraphCenter;
    QString FGraph;
    int FHitpoints;
    int FMass;
    int FDamage;

    uint32_t FItem;
    int FItemFreq;

    bool FSel;
    int FNo;

    void LoadWorld(QDataStream &buf, xyzV ab_WorldRadius);

    void CalcPos(xyzV ab_WorldRadius);

};


#endif //ABWORLD_TABZONE_H

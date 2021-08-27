//
// Created by desuex on 09.05.2020.
//

#ifndef ABWORLD_TPOINTAB_H
#define ABWORLD_TPOINTAB_H

#include <string>
#include <list>
#include "windows.h"
#include "TabObj3D.h"
#include "WorldUnit.h"

class TPointAB {
public:
    TPointAB *FPrev;
    TPointAB *FNext;
    TPointAB *FParent;
    int FParentNum;
    QString FId;
    QString FPortId;
    QString FPortType;
    QString FPortLink;
    QString FCopyPortId;
    QString FCopyPortType;
    QString FCopyPortLink;

    float FOrbit;
    float FOrbitAngle;
    float FRadius;

    D3DVECTOR FPos;
    D3DVECTOR FPosShow;
    TabObj3D FGraph;
    bool FSel;
    int FNo;
    std::list<TabWorldUnit *> FOwner;
    int FOwnerCount;
    int FTemp;

    void LoadWorld(QDataStream &buf, WorldUnit &worldUnit);
};


#endif //ABWORLD_TPOINTAB_H

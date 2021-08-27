//
// Created by desuex on 09.05.2020.
//

#ifndef ABWORLD_TLINEAB_H
#define ABWORLD_TLINEAB_H


#include "TPointAB.h"
#include "TKeyAB.h"
#include "ABPoint.h"

class TLineAB {
public:
    TLineAB *FNext;
    TLineAB *FPrev;
    bool FShow;
    bool FStopLine;
    TPointAB *FVerStart;
    TPointAB *FVerEnd;
    TKeyAB *FColorStart;
    TKeyAB *FColorEnd;
    QString WColorStart;
    QString WColorEnd;
    TabObj3D *FGraph;
    bool *FSel;
    TabWorldUnit *FOwner;
    int FNo;

    void LoadWorld(QDataStream &buf, WorldUnit &worldUnit, ABPoint &abPoint);
};


#endif //ABWORLD_TLINEAB_H

//
// Created by desuex on 09.05.2020.
//

#ifndef ABWORLD_ABLINE_H
#define ABWORLD_ABLINE_H


#include "ABKey.h"
#include "TLineAB.h"
#include "TPointAB.h"
#include "TKeyAB.h"
#include "ABPoint.h"


class ABLine {
public:

    TLineAB * Line_First;
    TLineAB * Line_Last;

    bool FShow;
    bool FStopLine;
    TPointAB *FVerStart;
    TPointAB *FVerEnd;
    TKeyAB *FColorStart;
    TKeyAB *FColorEnd;
    TabObj3D *FGraph;
    bool *FSel;
    //FOwner


    void Line_LoadWorld(QDataStream &buf, ABKey &abKey, ABPoint &abPoint, WorldUnit &worldUnit);
    TLineAB *Line_Add(TKeyGroupList* gl, int i);
};


#endif //ABWORLD_ABLINE_H

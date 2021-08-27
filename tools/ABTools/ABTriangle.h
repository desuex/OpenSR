//
// Created by desuex on 09.05.2020.
//

#ifndef ABWORLD_ABTRIANGLE_H
#define ABWORLD_ABTRIANGLE_H


#include "WorldUnit.h"
#include "TTriangleAB.h"
#include "TKeyGroupList.h"
#include "ABKey.h"
#include "ABPoint.h"

class ABTriangle {
public:
    TTriangleAB *Triangle_First;
    TTriangleAB *Triangle_Last;

    void Triangle_LoadWorld(QDataStream &buf, WorldUnit &worldUnit, ABKey &abKey, ABPoint &abPoint);

    TTriangleAB *Triangle_Add(TKeyGroupList *gl, int num);
};


#endif //ABWORLD_ABTRIANGLE_H

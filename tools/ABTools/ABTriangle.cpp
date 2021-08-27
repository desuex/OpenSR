//
// Created by desuex on 09.05.2020.
//

#include "ABTriangle.h"
#include "TTriangleAB.h"

void ABTriangle::Triangle_LoadWorld(QDataStream &buf, WorldUnit &worldUnit, ABKey &abKey, ABPoint &abPoint) {
    int cnt;
    buf>>cnt;
    TTriangleAB *el;

    for (int i = 0; i < cnt; i++) {
        int no;
        buf>>no;
        TKeyGroupList *gl = abKey.KeyGroupList_ByNom(no);
        el = Triangle_Add(gl, i);
        el->LoadWorld(buf, worldUnit, abPoint);
    }
}

TTriangleAB *ABTriangle::Triangle_Add(TKeyGroupList *gl, int num) {
    TTriangleAB *el;
    el = new TTriangleAB();
    el->FNo = num;
    if (Triangle_Last) {
        Triangle_Last->FNext = el;
    }
    el->FPrev = Triangle_Last;
    if (!Triangle_First) {
        Triangle_First = el;
    }
    Triangle_Last = el;
    return el;
}

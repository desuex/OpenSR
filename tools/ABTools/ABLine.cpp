//
// Created by desuex on 09.05.2020.
//

#include "ABLine.h"


void ABLine::Line_LoadWorld(QDataStream &buf, ABKey &abKey, ABPoint &abPoint, WorldUnit &worldUnit) {
    TLineAB *el;
    int cnt;
    buf>>cnt;

    for (int i = 0; i < cnt; i++) {
        int no;
        buf>>no;
        TKeyGroupList *gl = abKey.KeyGroupList_ByNom(no);
        el = Line_Add(gl, i);
        el->FNo = i;
        el->LoadWorld(buf, worldUnit, abPoint);
    }

}

TLineAB *ABLine::Line_Add(TKeyGroupList *gl, int i) {
    auto *el = new TLineAB();;
    if (Line_Last) {
        Line_Last->FNext = el;
    }
    el->FPrev = Line_Last;
    el->FNo = i;
    Line_Last = el;
    if (!Line_First) {
        Line_First = el;
    }
    return el;
}

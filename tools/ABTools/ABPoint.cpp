//
// Created by desuex on 09.05.2020.
//

#include "ABPoint.h"
#include "TPointAB.h"


void ABPoint::Point_LoadWorld(QDataStream &buf, WorldUnit &worldUnit) {
    TPointAB *el;
    uint32_t cnt ;
    buf>>cnt;
    for (int i = 0; i < cnt; i++) {
        el = Point_Add();
        el->FNo = i + 1;
        el->LoadWorld(buf, worldUnit);
    }
    //TODO: Stuff

    Point_ListBuild();
    el = Point_First;
    while (el) {
        if (el->FParentNum) {
            el->FParent = Point_ByNo(el->FParentNum);
        }
        el = el->FNext;
    }
}

TPointAB *ABPoint::Point_Add() {
    auto *el = new TPointAB();
    if (Point_Last) {
        Point_Last->FNext = el;
    }
    el->FPrev = Point_Last;
    Point_Last = el;
    if (!Point_First) {
        Point_First = el;
    }
    return el;
}

void ABPoint::Point_ListBuild() {
    TPointAB *el;
    int cnt = Point_Cnt() + 1;
    Point_List = new TPointAB*[cnt];
    int i = 1;
    el = Point_First;
    while (el) {
        Point_List[i] = el;
        el = el->FNext;
        i++;
    }
}

int ABPoint::Point_Cnt() const {
    TPointAB *el;
    int cnt = 0;
    el = Point_First;
    while (el) {
        cnt++;
        el = el->FNext;
    }
    return cnt;
}

TPointAB *ABPoint::Point_ByNo(int no) const {
    TPointAB *el;
    el = Point_First;
    while (el) {
        if (el->FNo == no) {
            return el;
        }
        el = el->FNext;
    }
    return nullptr;
}


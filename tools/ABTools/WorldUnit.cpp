//
// Created by desuex on 08.05.2020.
//

#include "WorldUnit.h"

void WorldUnit::LoadWorld(QDataStream &buf) {
    uint32_t cnt;
    buf>>cnt;
//    qDebug()<<"WU cnt: "<<cnt;
    for (int i = 0; i < cnt; i++) {
        WorldUnit_Add(buf, i);
    }
}

TabWorldUnit *WorldUnit::WorldUnit_Add(QDataStream &buf, int i) {
    auto *el = new TabWorldUnit();
    el->FNo = i;
    el->LoadWorld(buf);
    if (WorldUnit_Last_initialized) {
        WorldUnit_Last->FNext = el;
        el->FPrev = WorldUnit_Last;
    }
    WorldUnit_Last = el;
    WorldUnit_Last_initialized = true;
    if (!WorldUnit_First_initialized) {
        this->WorldUnit_First = el;
        this->WorldUnit_First_initialized = true;
    }

    return el;
}

TabWorldUnit *WorldUnit::WorldUnit_ByNo(uint32_t no) const {
    TabWorldUnit *el = this->WorldUnit_First;
    while (el) {
        if (el->FNo == no) {
            return el;
        }
        el = el->FNext;
    }

    return nullptr;
}

void WorldUnit::WorldUnit_CalcCenter() const {
    TabWorldUnit *el;
    el = WorldUnit_First;
    while (el) {
        el->CalcCenter();
        el = el->FNext;
    }
}

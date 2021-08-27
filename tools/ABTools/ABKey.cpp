//
// Created by desuex on 09.05.2020.
//

#include "ABKey.h"
#include "TKeyGroupList.h"

void ABKey::KeyGroupList_LoadWorld(QDataStream &buf, WorldUnit &worldUnit) {
    TKeyGroupList *el;
    uint32_t cnt;
    buf>>cnt;
    for (int i = 0; i < cnt; i++) {
        uint32_t no;
        buf>>no;

        TabWorldUnit *next = worldUnit.WorldUnit_ByNo(no);

        el = KeyGroupList_Add(next, no);
        el->FNo = i + 1;
        el->LoadWorld(buf);
    }
}

TKeyGroupList *ABKey::KeyGroupList_Add(TabWorldUnit *ow, uint32_t no) {
    auto *gl = new TKeyGroupList();
    gl->FOwner = ow;
    gl->FNo = no + 1;
    KeyGroupList_List.push_back(gl);
    return gl;
}

TKeyGroupList *ABKey::KeyGroupList_ByNom(uint32_t no) {
    for (auto const &k : KeyGroupList_List) {
        if (k->FNo == no) {
            return k;
        }
    }
}

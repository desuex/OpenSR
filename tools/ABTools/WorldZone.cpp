//
// Created by desuex on 09.05.2020.
//

#include "WorldZone.h"


void WorldZone::Zone_LoadWorld(QDataStream &buf, xyzV ab_WorldRadius) {
    TabZone *zone;
    TabZoneLink *zl;
    int cnt;
    buf>>cnt;

    for (int i = 0; i < cnt; i++) {
        zone = Zone_Add();
        zone->FNo = i + 1;
        zone->LoadWorld(buf, ab_WorldRadius);

    }
}

TabZone *WorldZone::Zone_Add() {
    TabZone *el;
    el = new TabZone();
    if (Zone_Last) {
        Zone_Last->FNext = el;
    }
    el->FPrev = Zone_Last;
    Zone_Last = el;
    if (!Zone_First) {
        Zone_First = el;
    }
    return el;
}

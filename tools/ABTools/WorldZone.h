//
// Created by desuex on 09.05.2020.
//

#ifndef ABWORLD_WORLDZONE_H
#define ABWORLD_WORLDZONE_H


#include <QDataStream>
#include "TabZone.h"
#include "TabZoneLink.h"

class WorldZone {
public:
    TabZone *Zone_First;
    TabZone *Zone_Last;
    TabZoneLink *ZoneLink_First;
    TabZoneLink *ZoneLink_Last;

    void Zone_LoadWorld(QDataStream &buf, xyzV ab_WorldRadius);

    TabZone *Zone_Add();
};


#endif //ABWORLD_WORLDZONE_H

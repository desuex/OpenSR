//
// Created by desuex on 09.05.2020.
//

#ifndef ABWORLD_TABZONELINK_H
#define ABWORLD_TABZONELINK_H


#include "TabZone.h"

class TabZoneLink {

public:
    TabZoneLink *FPrev;
    TabZoneLink *FNext;

    TabZone *FStart;
    TabZone *FEnd;

    TabObj3D *FGraph;
    int FType; // 0-normal 1-stop line
    bool FSel;


};


#endif //ABWORLD_TABZONELINK_H

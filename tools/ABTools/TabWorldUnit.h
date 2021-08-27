//
// Created by desuex on 08.05.2020.
//

#ifndef ABWORLD_TABWORLDUNIT_H
#define ABWORLD_TABWORLDUNIT_H

#include <QDataStream>
#include <string>
#include "TabObj3D.h"
//#include "TBufEC.h"

class TabWorldUnit {
public:
    TabWorldUnit *FPrev;
    TabWorldUnit *FNext;
    QString FFileName;
    bool FSel;

    TabObj3D FGraphSel;
    TabObj3D FGraphSelBB;

    uint32_t FNo;

    uint32_t FType;
    uint32_t FTimeOffset;
    uint32_t FTimeLength;
    uint32_t FKeyGroup;

    D3DVECTOR FCenter;
    bool FDraw;

    int FBBState; // 0=-1 0=rebuild 1=yes
    TabWorldUnitBB FBB[3];

    void LoadWorld(QDataStream &buf);

    TDxyz CalcCenter();

};


#endif //ABWORLD_TABWORLDUNIT_H

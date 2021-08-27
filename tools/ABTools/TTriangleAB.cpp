//
// Created by desuex on 09.05.2020.
//

#include "TTriangleAB.h"
#include "Utils.h"


void TTriangleAB::LoadWorld(QDataStream &buf, WorldUnit &worldUnit, ABPoint &abPoint) {
    FTexture=readLine(buf);

    buf>>FBackFace;

    int no ;
    buf>>no;

    FOwner = worldUnit.WorldUnit_ByNo(no);

    for (auto &i : FV) { //dabious magic High(FV)
        i = new TTriangleUnitAB();
        int pointNo;
        buf>>pointNo;

        i->FVer = abPoint.Point_ByNo(pointNo);
        buf>>i->FU;
        buf>>i->FV;
        QString fcolor = readLine(buf);

        //TODO: LOAD
        i->FColor.Load(fcolor);
        i->WColor = fcolor;
    }
}

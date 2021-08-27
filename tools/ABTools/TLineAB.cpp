//
// Created by desuex on 09.05.2020.
//

#include "TLineAB.h"
#include "Utils.h"

void TLineAB::LoadWorld(QDataStream &buf, WorldUnit &worldUnit, ABPoint &abPoint) {
    int verStartNo;
    buf>>verStartNo;

    FVerStart = abPoint.Point_ByNo(verStartNo);
    int verEndNo;
    buf>>verEndNo;

    FVerEnd = abPoint.Point_ByNo(verEndNo);
    QString colorStart = readLine(buf);
    WColorStart = colorStart;

    FColorStart->Load(colorStart);
    QString colorEnd = readLine(buf);
    WColorEnd = colorEnd;

    FColorEnd->Load(colorEnd);
    bool show;
    buf>>show;

    FShow = show;
    bool stopLine;
    buf>>stopLine;

    FStopLine = stopLine;
    int worldUnitNo;
    buf>>worldUnitNo;

    FOwner = worldUnit.WorldUnit_ByNo(worldUnitNo);

}

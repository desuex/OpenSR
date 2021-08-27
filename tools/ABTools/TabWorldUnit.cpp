//
// Created by desuex on 08.05.2020.
//


#include "TabWorldUnit.h"
#include "TPointAB.h"
#include "Utils.h"

void TabWorldUnit::LoadWorld(QDataStream &buf) {

    FFileName = readLine(buf);
    buf>>FType;
    buf>>FTimeOffset;
    buf>>FKeyGroup;



//    if GLoadVersion>=3 then
    buf>>FTimeLength;


}

TDxyz TabWorldUnit::CalcCenter() {
    TPointAB apo;
    TDxyz center = Utils::Dxyz(0, 0, 0);
    //TODO: something
    return TDxyz();
}

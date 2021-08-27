//
// Created by desuex on 09.05.2020.
//

#include "TPointAB.h"
#include "Utils.h"

void TPointAB::LoadWorld(QDataStream &buf, WorldUnit &worldUnit) {
    FId=readLine(buf);

    buf>>FOrbit;

    buf>>FOrbitAngle;

    buf>>FRadius ;

    FParent = new TPointAB();

    buf>>FParentNum ;

    FPortId=readLine(buf);

    FPortType=readLine(buf);

    FPortLink=readLine(buf);

    FCopyPortId=readLine(buf);

    FCopyPortType=readLine(buf);

    FCopyPortLink=readLine(buf);


    int cnt;
    buf>>cnt;

    FOwnerCount = cnt;
    for (int i = 0; i < cnt; i++) {
        int ownerNo;
        buf>>ownerNo;

        TabWorldUnit *unit = worldUnit.WorldUnit_ByNo(ownerNo);
        FOwner.push_front(unit);
    }

    auto vect = Utils::ab_CalcPos(Utils::Angle360ToRad(FOrbit), Utils::Angle360ToRad(FOrbitAngle), FRadius);
    FPos = vect;
}



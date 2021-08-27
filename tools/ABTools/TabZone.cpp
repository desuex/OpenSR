//
// Created by desuex on 09.05.2020.
//

#include <cmath>
#include "TabZone.h"
#include "Utils.h"

void TabZone::LoadWorld(QDataStream &buf, xyzV ab_WorldRadius) {
    buf>>FOrb ;

    buf>>FOrbAngle;

    buf>>FRadiusAngle ;

    buf>>FType;

    FGraph = readLine(buf);

    buf>>FHitpoints;

    buf>>FMass ;

    buf>>FDamage ;

    //if GLoadVersion>=2
    buf>>FItem;

    buf>>FItemFreq;

    //endif
    CalcPos(ab_WorldRadius);



}

void TabZone::CalcPos(xyzV ab_WorldRadius) {
    // l=((pi*r)/180)*n
    // n=l/((pi*r)/180)
    FRadius = M_PI * ab_WorldRadius * FRadiusAngle / 180;
    FPos = Utils::ab_CalcPos(Utils::Angle360ToRad(FOrb), Utils::Angle360ToRad(FOrbAngle), ab_WorldRadius);
}

//
// Created by desuex on 09.05.2020.
//

#ifndef ABWORLD_UTILS_H
#define ABWORLD_UTILS_H


#include <QDataStream>
#include "windows.h"

class Utils {
public:
    static TDxyz ab_CalcPos(float orb, float orban, xyzV radius);

    static float Angle360ToRad(float angle);

    static double Angle360ToRad(double angle);

    static TDxyz Dxyz(xyzV x, xyzV y, xyzV z);

};
QString readLine(QDataStream &buf);

#endif //ABWORLD_UTILS_H

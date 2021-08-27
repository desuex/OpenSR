//
// Created by desuex on 09.05.2020.
//

#ifndef ABWORLD_TKEYAB_H
#define ABWORLD_TKEYAB_H


#include "TKeyGroupList.h"

typedef std::function<void(int)> func;

class TKeyAB {
public:
    TKeyAB *FKeyPrev;
    TKeyAB *FKeyNext;
    TKeyGroupList FGroupList;
    int FCount;
    int FCur;
    int FUnitSize;
    //TODO: Not implemented
    /*
     * FUnit:array of array of Pointer;
        FUnitT:array of integer;

        FInterpolateVal:Pointer;

     */
//    Key_DefFunInterpolate FFunInterpolate;
    int FTimeFull;

    void Load(QString tstr);
};


#endif //ABWORLD_TKEYAB_H

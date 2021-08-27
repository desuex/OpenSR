//
// Created by desuex on 08.05.2020.
//

#ifndef ABWORLD_TABOBJ3DUNIT_H
#define ABWORLD_TABOBJ3DUNIT_H


#include "TabTex.h"

class TabObj3Dunit {
public:
    TabObj3Dunit* FPrev{};
    TabObj3Dunit* FNext{};

    int FVerCnt{};

    int FVerIndex{};

    DWORD FType{};
    int FCnt{};

    TabTex FTex;
    int FVer[];
};


#endif //ABWORLD_TABOBJ3DUNIT_H

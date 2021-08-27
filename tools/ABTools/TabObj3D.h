//
// Created by desuex on 08.05.2020.
//

#ifndef ABWORLD_TABOBJ3D_H
#define ABWORLD_TABOBJ3D_H


#include "TabObj3Dunit.h"

class TabObj3D {
public:
    TabObj3D* FPrev{};
    TabObj3D* FNext{};

    IDirect3DVertexBuffer8 FVer{};
    int FVerCnt{};
    int *FVerBuf{};
    int FVerOpen{};

    TabObj3Dunit *FUnitFirst{};
    TabObj3Dunit *FUnitLast{};

    IDirect3DIndexBuffer8 FIndex{};
    bool FIndexRebuild{};

    D3DVECTOR FPosOld{};

    bool FDrawFromObjLoop{};
    bool FZTest{};
    int FLoopDraw{};
};


#endif //ABWORLD_TABOBJ3D_H

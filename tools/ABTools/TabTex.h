//
// Created by desuex on 08.05.2020.
//

#ifndef ABWORLD_TABTEX_H
#define ABWORLD_TABTEX_H


#include <string>
#include "windows.h"

class TabTex {
public:
    TabTex *FPrev;
    TabTex *FNext;

    int FRefs;
    std::string FPath;
    IDirect3DTexture8 FTex;
};


#endif //ABWORLD_TABTEX_H

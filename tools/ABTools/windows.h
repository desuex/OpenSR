//
// Created by desuex on 08.05.2020.
//

#ifndef ABWORLD_WINDOWS_H
#define ABWORLD_WINDOWS_H


typedef unsigned short WORD;
typedef unsigned long DWORD;
typedef unsigned char BYTE;
typedef wchar_t WCHAR;
typedef float xyzV;

typedef struct D3DVECTOR {
    float x;
    float y;
    float z;
} D3DVECTOR;
typedef D3DVECTOR TDxyz;
typedef DWORD D3DCOLOR;
typedef struct TabWorldUnitBB {
    xyzV FOrbit;
    xyzV FOrbitAngle;
    TDxyz FPos;
} TabWorldUnitBB;
typedef int IDirect3DTexture8;
typedef int IDirect3DIndexBuffer8;
typedef int IDirect3DVertexBuffer8;

#endif //ABWORLD_WINDOWS_H
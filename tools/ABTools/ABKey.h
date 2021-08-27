//
// Created by desuex on 09.05.2020.
//

#ifndef ABWORLD_ABKEY_H
#define ABWORLD_ABKEY_H


#include "WorldUnit.h"
#include "TKeyGroupList.h"
#include <QDebug>
class ABKey {
public:
    std::list<TKeyGroupList *> KeyGroupList_List;

    void KeyGroupList_LoadWorld(QDataStream &buf, WorldUnit &worldUnit);

    TKeyGroupList *KeyGroupList_Add(TabWorldUnit *ow, uint32_t no);

    TKeyGroupList *KeyGroupList_ByNom(uint32_t no);
};


#endif //ABWORLD_ABKEY_H

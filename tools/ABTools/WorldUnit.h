//
// Created by desuex on 08.05.2020.
//

#ifndef ABWORLD_WORLDUNIT_H
#define ABWORLD_WORLDUNIT_H


#include <QDataStream>
#include <QDebug>
#include "TabWorldUnit.h"

class WorldUnit {
public:
    TabWorldUnit *WorldUnit_First{};
    bool WorldUnit_First_initialized = false;
    TabWorldUnit *WorldUnit_Last{};
    bool WorldUnit_Last_initialized = false;

    void LoadWorld(QDataStream &buf);

    TabWorldUnit *WorldUnit_ByNo(uint32_t no) const;

    TabWorldUnit *WorldUnit_Add(QDataStream &buf, int i);

    void WorldUnit_CalcCenter() const;
};


#endif //ABWORLD_WORLDUNIT_H

//
// Created by desuex on 09.05.2020.
//

#ifndef ABWORLD_TKEYGROUPLIST_H
#define ABWORLD_TKEYGROUPLIST_H


#include <list>
#include <string>
#include "TabWorldUnit.h"

typedef struct TKeyGroup {
    QString FName;
} TKeyGroup;

class TKeyGroupList {
public:
    uint32_t FNo{};
    std::list<TKeyGroup> FList;
    uint32_t FCur;
    void *FOwner;

    void LoadWorld(QDataStream &buf);
//    TKeyGroup Insert(int no);
};


#endif //ABWORLD_TKEYGROUPLIST_H

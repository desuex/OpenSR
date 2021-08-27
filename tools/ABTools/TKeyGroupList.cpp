//
// Created by desuex on 09.05.2020.
//

#include <QDataStream>
#include "TKeyGroupList.h"
#include "Utils.h"

void TKeyGroupList::LoadWorld(QDataStream &buf) {
    FCur = static_cast<TabWorldUnit *>(this->FOwner)->FKeyGroup;
    uint32_t cnt;
    buf>>cnt;

    for (int i = 0; i < cnt; i++) {
        QString elem;
        elem = readLine(buf);
        TKeyGroup group = {elem};
        FList.push_front(group);
    }

}



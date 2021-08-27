 /*
    OpenSR - opensource multi-genre game based upon "Space Rangers 2: Dominators"
    Copyright (C) 2015 Kosyak <ObKo@mail.ru>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "DatManager.h"

#include <QHash>
#include <QMap>
#include <QFile>
#include <QDebug>
#include <QDataStream>
#include <QMetaProperty>
#include <QUrl>
#include <QQmlEngine>

#include <OpenSR/Engine.h>
#include <iostream>

#include "DatObject.h"
#include "DatContext.h"

namespace OpenSR
{
namespace DatPlugin
{
namespace
{
static QMap<quint32, const QMetaObject*> metaMap;

struct ObjectHeader
{
    quint32 type;
    quint32 id;
    QString idName;
    quint32 parentId;
};

QDataStream& operator<<(QDataStream& stream, const ObjectHeader& h)
{
    return stream << h.type << h.id << h.idName << h.parentId;
}

QDataStream& operator>>(QDataStream& stream, ObjectHeader& h)
{
    return stream >> h.type >> h.id >> h.idName >> h.parentId;
}




}
DatManager* DatManager::m_staticInstance = 0;
DatManager::DatManager(QObject *parent): QObject(parent)
{
    if (DatManager::m_staticInstance)
        throw std::runtime_error("DatManager constructed twice");

    DatManager::m_staticInstance = this;

}

DatManager::~DatManager()
{
    DatManager::m_staticInstance = 0;
}


DatManager* DatManager::instance()
{
    return DatManager::m_staticInstance;
}

    bool DatManager::test(const QString &uri) {
        QString data = qobject_cast<Engine*>(qApp)->datValue(uri).toString();
        std::string str = data.toStdString();
        std::cout<<data.toStdString();
        return true;
    }


}
}

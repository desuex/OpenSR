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

#include "Artefact.h"

#include <QtQml>

namespace OpenSR
{
namespace World
{
const quint32 Artefact::m_staticTypeId = typeIdFromClassName(Artefact::staticMetaObject.className());

template<>
void WorldObject::registerType<Artefact>(QQmlEngine *qml, QJSEngine *script)
{
    qmlRegisterType<Artefact>("OpenSR.World", 1, 0, "Artefact");
}

template<>
Artefact* WorldObject::createObject(WorldObject *parent, quint32 id)
{
    return new Artefact(parent, id);
}

template<>
quint32 WorldObject::staticTypeId<Artefact>()
{
    return Artefact::m_staticTypeId;
}

template<>
const QMetaObject* WorldObject::staticTypeMeta<Artefact>()
{
    return &Artefact::staticMetaObject;
}

Artefact::Artefact(WorldObject *parent, quint32 id): Equipment(parent, id)
{
}

Artefact::~Artefact()
{
}

quint32 Artefact::typeId() const
{
    return Artefact::m_staticTypeId;
}

QString Artefact::namePrefix() const
{
    return tr("Artefact");
}
}
}

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

#include "DatContext.h"

#include <QMap>
#include <QDataStream>
#include <QtQml/QQmlEngine>
#include <QtQml>

namespace OpenSR
{
namespace DatPlugin
{
const quint32 DatContext::m_staticTypeId = typeIdFromClassName(DatContext::staticMetaObject.className());

template<>
void DatObject::registerType<DatContext>(QQmlEngine *qml, QJSEngine *script)
{
    qmlRegisterType<DatContext>("OpenSR.Dat", 1, 0, "DatContext");
}

template<>
DatContext* DatObject::createObject(DatObject *parent, quint32 id)
{
    return new DatContext(parent, id);
}

template<>
quint32 DatObject::staticTypeId<DatContext>()
{
    return DatContext::m_staticTypeId;
}

template<>
const QMetaObject* DatObject::staticTypeMeta<DatContext>()
{
    return &DatContext::staticMetaObject;
}

DatContext::DatContext(DatObject *parent, quint32 id): DatObject(parent, id)
{
}

DatContext::~DatContext()
{
}

quint32 DatContext::typeId() const
{
    return DatContext::m_staticTypeId;
}

QString DatContext::namePrefix() const
{
    return tr("DatPlugin");
}

QObject* DatContext::findObject(const QString& name) const
{
    return findChild<QObject*>(name);
}
}
}

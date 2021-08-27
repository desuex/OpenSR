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

#include "DatObject.h"
#include "DatManager.h"

#include <QtQml>

namespace OpenSR
{
namespace DatPlugin
{
const quint32 DatObject::m_staticTypeId = typeIdFromClassName(DatObject::staticMetaObject.className());

template<>
void DatObject::registerType<DatObject>(QQmlEngine *qml, QJSEngine *script)
{
    qmlRegisterType<DatObject>("OpenSR.DatPlugin", 1, 0, "DatObject");
}

template<>
DatObject* DatObject::createObject(DatObject *parent, quint32 id)
{
    return new DatObject(parent, id);
}

template<>
quint32 DatObject::staticTypeId<DatObject>()
{
    return DatObject::m_staticTypeId;
}

template<>
const QMetaObject* DatObject::staticTypeMeta<DatObject>()
{
    return &DatObject::staticMetaObject;
}

DatObject::DatObject(DatObject *parent, quint32 id): QObject(parent),
    m_id(id)
{
//    if (!m_id)
//        m_id = DatManager::instance()->getNextId();
}

DatObject::~DatObject()
{
}

quint32 DatObject::id() const
{
    return m_id;
}

quint32 DatObject::typeId() const
{
    return DatObject::m_staticTypeId;
}

QString DatObject::name() const
{
    return m_name;
}

QString DatObject::namePrefix() const
{
    return tr("Object");
}

void DatObject::setName(const QString& name)
{
    if (m_name != name)
    {
        m_name = name;
        emit(nameChanged());
    }
}

static QObject* childrenAtF(QQmlListProperty<QObject> *property, int index)
{
    return property->object->children().at(index);
}

static int childrenCountF(QQmlListProperty<QObject> *property)
{
    return property->object->children().count();
}

QQmlListProperty<QObject> DatObject::getChildren()
{
    return QQmlListProperty<QObject>(this, 0, childrenCountF, childrenAtF);
}






/*!
 * \brief Generate type ID from class name
 * \param className class name (usually, metaObject()->className)
 * \return type ID for class
 */
quint32 DatObject::typeIdFromClassName(const QString& className)
{
    quint32 h = 0;
    int n = className.length();

    while (n--)
    {
        h = (h << 4) + className[n].unicode();
        h ^= (h & 0xf0000000) >> 23;
        h &= 0x0fffffff;
    }
    return h;
}
}
}

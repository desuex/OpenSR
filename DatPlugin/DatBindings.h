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

#ifndef OPENSR_DATPLUGIN_DATBINDINGS_H
#define OPENSR_DATPLUGIN_DATBINDINGS_H

#include "DatObject.h"

#include <QJSEngine>
#include <QMetaObject>
#include <QQmlEngine>

class QQmlEngine;

#define DATPLUGIN_JS_DEFAULT_OBJECT_CONSTRUCTOR(Factory, Class)\
    OpenSR::DatPlugin::Class* Factory::new##Class(DatObject *parent) {\
        OpenSR::DatPlugin::Class *obj = DatObject::createObject<Dat::Class>(parent);\
        QQmlEngine::setObjectOwnership((QObject*)obj, QQmlEngine::JavaScriptOwnership);\
        return obj;\
    }

#define DATPLUGIN_JS_DEFAULT_GADGET_CONSTRUCTOR(Factory, Class)\
    Class Factory::new##Class() {\
        return Dat::Class();\
    }

namespace OpenSR
{
namespace DatPlugin
{
void bindDatTypes(QJSEngine *script, QQmlEngine *qml);

template<class T>
static void bindEnumsToJS(QJSEngine *script)
{
    QJSValue dat = script->globalObject().property("Dat");

    if (dat.isUndefined())
        return;

    const QMetaObject *obj = &T::staticMetaObject;
    int enumCount = obj->enumeratorCount();

    if (!enumCount)
        return;

    QString className = QString(obj->className()).replace("OpenSR::DatPlugin::", QString());

    QJSValue p;
    if (dat.hasProperty(className))
        p = dat.property(className);
    else
    {
        p = script->newObject();
        dat.setProperty(className, p);
    }

    for (int i = 0; i < enumCount; i++)
    {
        QMetaEnum e = obj->enumerator(i);

        int ec = e.keyCount();
        for (int j = 0; j < ec; j++)
            p.setProperty(e.key(j), e.value(j));
    }
}

}
}

#endif // OPENSR_DATPLUGIN_DATBINDINGS_H

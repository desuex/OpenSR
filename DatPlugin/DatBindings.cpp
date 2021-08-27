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

#include "DatBindings.h"
#include "DatManager.h"
#include <QtQml/QQmlEngine>
namespace OpenSR
{
namespace DatPlugin
{


static QObject *managerSingletonProvider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    QQmlEngine::setObjectOwnership(DatManager::instance(), QQmlEngine::CppOwnership);
    return DatManager::instance();
}

void bindDatTypes(QJSEngine *script, QQmlEngine *qml)
{
    script->globalObject().setProperty("DatPlugin", script->newQObject(DatManager::instance()));
    // @uri OpenSR.DatPlugin
    qmlRegisterSingletonType<DatManager>("OpenSR.DatPlugin", 1, 0, "DatManager", managerSingletonProvider);
}
}
}

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

#ifndef OPENSR_DATPLUGIN_DATCONTEXT_H
#define OPENSR_DATPLUGIN_DATCONTEXT_H

#include "DatObject.h"

//#include "PlanetarySystem.h"
//#include "ResourceManager.h"

namespace OpenSR
{
namespace DatPlugin
{
class OPENSR_DATPLUGIN_API DatContext: public DatObject
{
    Q_OBJECT
    OPENSR_DATPLUGIN_OBJECT

//    Q_PROPERTY(PlanetarySystem* currentSystem READ currentSystem WRITE setCurrentSystem NOTIFY currentSystemChanged STORED false)
//    Q_PROPERTY(ResourceManager* resources READ resources NOTIFY resourcesChanged STORED false)
//    Q_PROPERTY(DatObject* playerShip READ playerShip NOTIFY playerShipChanged STORED false WRITE setPlayerShip)

public:
    Q_INVOKABLE DatContext(DatObject *parent = 0, quint32 id = 0);
    virtual ~DatContext();


    Q_INVOKABLE QObject* findObject(const QString& name) const;


    virtual quint32 typeId() const;
    virtual QString namePrefix() const;


Q_SIGNALS:

private:
};
}
}

#endif // OPENSR_DATPLUGIN_DATCONTEXT_H

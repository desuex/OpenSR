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

#ifndef OPENSR_DATPLUGIN_DatManager_H
#define OPENSR_DATPLUGIN_DatManager_H

#include "Dat.h"

#include <QObject>
#include <QAbstractAnimation>

#include "DatContext.h"
#include "DatBindings.h"

// TODO: Move Constructors to Separate factory?

//#include "PlanetarySystem.h"
//#include "Race.h"
//#include "Asteroid.h"
//#include "Planet.h"
//#include "SpaceStation.h"
//#include "Ship.h"

namespace OpenSR
{
namespace DatPlugin
{




class OPENSR_DATPLUGIN_API DatManager: public QObject
{
    Q_OBJECT
//    Q_PROPERTY(DatContext* context READ context NOTIFY contextChanged)

public:
    DatManager(QObject *parent = 0);
    virtual ~DatManager();

//    quint32 getNextId() const;

    static DatManager *instance();

//    DatContext* context() const;
    Q_INVOKABLE bool test(const QString& uri);

//    Q_INVOKABLE QString typeName(quint32 type) const;



Q_SIGNALS:
    void contextChanged();

public Q_SLOTS:

private:
    QVariantMap datRoot;
//    DatContext* m_context;
//    TurnAnimation *m_animation;

    static DatManager* m_staticInstance;
    static quint32 m_idPool;

    Q_DISABLE_COPY(DatManager)
};
}
}

#endif // OPENSR_DATPLUGIN_DatManager_H

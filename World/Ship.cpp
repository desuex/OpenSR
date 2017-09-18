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

#include "Ship.h"
#include "WorldBindings.h"

#include <QtQml/QQmlEngine>
#include <QtMath>

namespace OpenSR
{
namespace World
{
const quint32 Ship::m_staticTypeId = typeIdFromClassName(Ship::staticMetaObject.className());

template<>
void WorldObject::registerType<Ship>(QQmlEngine *qml, QJSEngine *script)
{
    qRegisterMetaType<ShipStyle>();
    qRegisterMetaTypeStreamOperators<ShipStyle>();
    qRegisterMetaType<ShipStyle::Data>();
    qRegisterMetaTypeStreamOperators<ShipStyle::Data>();
    bindEnumsToJS<Ship>(script);
    qmlRegisterType<Ship>("OpenSR.World", 1, 0, "Ship");
}

template<>
Ship* WorldObject::createObject(WorldObject *parent, quint32 id)
{
    return new Ship(parent, id);
}

template<>
quint32 WorldObject::staticTypeId<Ship>()
{
    return Ship::m_staticTypeId;
}

template<>
const QMetaObject* WorldObject::staticTypeMeta<Ship>()
{
    return &Ship::staticMetaObject;
}

/**************************************************************************************************/

int ShipStyle::width() const
{
    return getData<Data>().width;
}

void ShipStyle::setWidth(int w)
{
    auto d = getData<Data>();
    d.width = w;
    setData(d);
}

QString ShipStyle::texture() const
{
    return getData<Data>().texture;
}

void ShipStyle::setTexture(const QString &texture)
{
    auto d = getData<Data>();
    d.texture = texture;
    setData(d);
}

bool operator==(const ShipStyle& one, const ShipStyle& another)
{
    return one.texture() == another.texture();
}

/*  Ship */
Ship::Ship(WorldObject *parent, quint32 id): MannedObject(parent, id)
{
}

Ship::~Ship()
{
}

quint32 Ship::typeId() const
{
    return Ship::m_staticTypeId;
}

QString Ship::namePrefix() const
{
    return tr("Ship");
}

Ship::ShipAffiliation Ship::affiliation() const
{
    return m_affiliation;
}

Ship::ShipRank Ship::rank() const
{
    return m_rank;
}

void Ship::setAffiliation(Ship::ShipAffiliation affiliation)
{
    if (m_affiliation == affiliation)
        return;

    m_affiliation = affiliation;
    emit affiliationChanged(m_affiliation);
}

void Ship::setRank(Ship::ShipRank rank)
{
    if (m_rank == rank)
        return;

    m_rank = rank;
    emit rankChanged(m_rank);
}

void Ship::evalTrajectoryTo(const QPointF &dest)
{
    qDebug() << Q_FUNC_INFO;
    auto startPos = this->position();

    qDebug() << "from" << startPos << "to" << dest;

    auto dx = qAbs(dest.x() - startPos.x());
    auto dy = qAbs(dest.y() - startPos.y());
    qDebug() << startPos << dest;
    qDebug() << QString("dx = %1, dy = %2").arg(dx).arg(dy);

    const int h = 20.0;
    const qreal avgSq = qSqrt(dx*dx + dy*dy);
    QList<BezierCurve> traj;
    if (dx>dy) {
        qreal alphaTan = dy / dx;
        auto dxStep = h * dx / avgSq;
        int fullSteps = static_cast<int>(dx/dxStep);
        for (int i=1; i<=fullSteps; ++i) {
            const qreal xx = dxStep * static_cast<qreal>(i);
            const qreal yy = xx * alphaTan;
            auto p = QPointF(xx,yy);
            auto curve = BezierCurve();
            curve.p0 = curve.p1 = curve.p2 = curve.p3 = startPos+p;
            traj.append(curve);
        }
    } else {
        qreal alphaTan = dx/dy;
        auto dyStep = h * dy / avgSq;
        int fullSteps = static_cast<int>(dy/dyStep);
        for (int i=1; i<=fullSteps; ++i) {
            const qreal yy = dyStep * static_cast<qreal>(i);
            const qreal xx = yy * alphaTan;
            auto p = QPointF(xx,yy);
            auto curve = BezierCurve();
            curve.p0 = curve.p1 = curve.p2 = curve.p3 = startPos+p;
            traj.append(curve);
        }
    }

    setTrajectory(traj);
    qDebug() << "new trajectory length = " << traj.size();
}


}
}

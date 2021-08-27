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

#ifndef OPENSR_DATPLUGIN_DatObject_H
#define OPENSR_DATPLUGIN_DatObject_H

#include "Dat.h"

#include <QObject>
#include <QQmlListProperty>

class QJSEngine;

namespace OpenSR
{
namespace DatPlugin
{
class OPENSR_DATPLUGIN_API DatObject: public QObject
{
    Q_OBJECT
    OPENSR_DATPLUGIN_OBJECT

    Q_PROPERTY(quint32 id READ id STORED false)
    Q_PROPERTY(quint32 typeId READ typeId STORED false)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString namePrefix READ namePrefix STORED false)
    //TODO: Use DatObject instead of QObject
    Q_PROPERTY(QQmlListProperty<QObject> children READ getChildren STORED false)

public: static const quint32 m_StationKindStaticTypeId;
public:
    Q_INVOKABLE DatObject(DatObject *parent = 0, quint32 id = 0);
    virtual ~DatObject();

    quint32 id() const;
    virtual quint32 typeId() const;
    QString name() const;
    virtual QString namePrefix() const;

    QQmlListProperty<QObject> getChildren();

    void setName(const QString& name);

   \

    static quint32 typeIdFromClassName(const QString& className);

    /*!
     * @brief Function to register class in meta & QML systems.
     * @note All subclasses should provide specialized version of this function.
     */
    template<class T>
    static void registerType(QQmlEngine *qml, QJSEngine *script);
    /*!
     * @brief Function to create object of class T.
     * Used in object factory for JavaScript & QML.
     * @note All subclasses should provide specialized version of this function.
     */
    template<class T>
    static T* createObject(DatObject* parent = 0, quint32 id = 0);
    /*!
     * @brief Function to get type id
     * Used in world serialization.
     * @note All subclasses should provide specialized version of this function.
     */
    template<class T>
    static quint32 staticTypeId();
    /*!
     * @brief Function to get type meta object
     * Used in world serialization.
     * @note All subclasses should provide specialized version of this function.
     */
    template<class T>
    static const QMetaObject* staticTypeMeta();

Q_SIGNALS:
    void nameChanged();

private:
    quint32 m_id;
    QString m_name;
};
}
}

#endif // OPENSR_DATPLUGIN_DatObject_H

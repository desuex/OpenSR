/*
    OpenSR - opensource multi-genre game based upon "Space Rangers 2: Dominators"
    Copyright (C) 2014 - 2017 Kosyak <ObKo@mail.ru>

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

#ifndef OPENSR_SOUND_MANAGER_P_H
#define OPENSR_SOUND_MANAGER_P_H

#include "OpenSR/SoundManager.h"

#ifdef WITH_OPENAL_SOUND
#include <AL/alc.h>
#endif

#include <QSharedPointer>
#include <QMap>
#include <QIODevice>

namespace OpenSR
{
struct SampleData
{
    SampleData();
    virtual ~SampleData();
#ifdef WITH_OPENAL_SOUND
    ALuint m_alID;
#endif
};

class SoundManager::SoundManagerPrivate
{
public:
    QSharedPointer<SampleData> loadWAVFile(QIODevice* d);
#ifdef WITH_OPENAL_SOUND
    ALCdevice *device;
    ALCcontext *context;
#endif
    QMap<QUrl, QSharedPointer<SampleData> > m_soundCache;
};
}

#endif // OPENSR_SOUND_MANAGER_P_H

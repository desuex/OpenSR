/*
    OpenSR - opensource multi-genre game based upon "Space Rangers 2: Dominators"
    Copyright (C) 2021 desuex <nnm043@gmail.com>

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

#include <OpenSR/libRangerQt.h>
#include <QBuffer>
#include <QVariantList>

namespace OpenSR
{
    namespace
    {

//        QVariantMap loadRAW(QIODevice *dev, bool isCache)
//        {
//            QVariantMap root;
//            uint32_t sig;
//            dev->peek((char *)&sig, 4);
//
//            if (sig == 0x31304c5a)
//            {
//                QByteArray whole = dev->readAll();
//                QByteArray datData = unpackZL(whole);
//                QBuffer dat(&datData);
//                dat.open(QIODevice::ReadOnly);
//                readDATTree(&dat, &root, isCache);
//                dat.close();
//            }
//            else
//                readDATTree(dev, &root, isCache);
//
//            return root;
//        }
//
//        void saveRAW(QIODevice *dev, const QVariant& root)
//        {
//            writeDATTree(dev, root, QString());
//        }
    }
}

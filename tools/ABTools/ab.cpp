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

#include <QCoreApplication>
#include <QStringList>
#include <QFile>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QDirIterator>
#include <iostream>
#include "WorldUnit.h"
#include "ABKey.h"
#include "ABPoint.h"
#include "ABTriangle.h"
#include "ABLine.h"
#include "WorldZone.h"
#include "Export.h"

void printHelp()
{
    std::cout << "OpenSR ABTool" << std::endl;
    std::cout << "Usage: opensr-ab-tool <command> <in> <out>" << std::endl;
    std::cout << "<command>:" << std::endl;
    std::cout << "  r2o - convert RAW file to TXT" << std::endl;
    std::cout << "  r2m - convert RAW file to MAP" << std::endl;
}
int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    if (app.arguments().count() != 4)
    {
        printHelp();
        return 0;
    }

    QString cmd = app.arguments()[1];
    QFile inf(app.arguments()[2]);
    QFile outf(app.arguments()[3]);
    inf.open(QIODevice::ReadOnly);
    {
        QDataStream data (&inf);
        data.setByteOrder(data.LittleEndian);
        data.setFloatingPointPrecision(QDataStream::SinglePrecision);
        uint32_t signature;
        uint32_t version;
        float ab_WorldRadius;
        data>>signature;
        if (signature != 0x57424152) {
            qCritical() << "Invalid signature";
            return -1;
        }
        qDebug()<<signature;
        data>>version;
        if (version > 3) {
            qCritical() << "Invalid version";
            return -1;
        }
        data>>ab_WorldRadius;
        Export exp;
        exp.openFileToSave(app.arguments()[3]);

        WorldUnit worldUnit = WorldUnit();
        worldUnit.LoadWorld(data);

        ABKey abKey = ABKey();
        abKey.KeyGroupList_LoadWorld(data, worldUnit);

        ABPoint abPoint = ABPoint();
        abPoint.Point_LoadWorld(data, worldUnit);

        ABTriangle abTriangle = ABTriangle();
        abTriangle.Triangle_LoadWorld(data, worldUnit, abKey, abPoint);

        ABLine abLine = ABLine();
        abLine.Line_LoadWorld(data, abKey, abPoint, worldUnit);

        WorldZone worldZone = WorldZone();
        worldZone.Zone_LoadWorld(data, ab_WorldRadius);

        exp.writeLineHex("Signature", signature);
        exp.writeLine("Version", version);
        exp.writeLine("WorldRadius", ab_WorldRadius);
        exp.openObject("WorldUnit");
        TabWorldUnit *u = worldUnit.WorldUnit_First;
        while (u) {
            exp.openObject(u->FNo);
            exp.writeLine("FFileName", u->FFileName);
            exp.writeLine("FType", u->FType);
            exp.writeLine("FTimeOffset", u->FTimeOffset);
            exp.writeLine("FKeyGroup", u->FKeyGroup);
            exp.writeLine("FTimeLength", u->FTimeLength);
            exp.closeObject();
            u = u->FNext;
        }
        exp.closeObject();
        exp.openObject("KeyGroupList"); //open KeyGroupList

        for (TKeyGroupList *const &i : abKey.KeyGroupList_List) {
            exp.openObject(i->FNo); //open TKeyGroupList
            exp.writeLine("ParentWorldUnit", static_cast<TabWorldUnit *>(i->FOwner)->FNo);
            exp.writeLine("FCur", i->FCur);
            exp.openObject("FList"); //open FList
            int counter = 0;
            for (auto const &k : i->FList) {
                exp.openObject(counter); //open TKeyGroup
                exp.writeLine("FName", k.FName);
                exp.closeObject(); //close TKeyGroup
            }
            exp.closeObject(); // close FList
            exp.closeObject(); // close TKeyGroupList
        }
        exp.closeObject(); // close KeyGroupList

        exp.openObject("Point"); //open Point
        TPointAB *p = abPoint.Point_First;
        while (p) {
            exp.openObject(p->FNo); //TPointAB
            exp.writeLine("FId", p->FId);
            exp.writeLine("FOrbit", p->FOrbit);
            exp.writeLine("FOrbitAngle", p->FOrbitAngle);
            exp.writeLine("FRadius", p->FRadius);
            exp.writeLine("FParent", p->FParent?p->FParent->FNo:p->FParentNum);

            exp.writeLine("FPortId", p->FPortId);
            exp.writeLine("FPortType", p->FPortType);
            exp.writeLine("FPortLink", p->FPortLink);

            exp.writeLine("FCopyPortId", p->FCopyPortId);
            exp.writeLine("FCopyPortType", p->FCopyPortType);
            exp.writeLine("FCopyPortLink", p->FCopyPortLink);
            exp.writeLine("FOwnerCount",(p->FOwnerCount));
            exp.openObject("FOwner"); //open FOwner
            for (TabWorldUnit *const &w : p->FOwner) {
                exp.writeLine("FNo", w->FNo);
            }
            exp.closeObject(); //close FOwner


            exp.openObject("FPos"); //open FPos
            exp.writeLine("x", (float) p->FPos.x);
            exp.writeLine("y", (float) p->FPos.y);
            exp.writeLine("z", (float) p->FPos.z);
            exp.closeObject(); //close FPos




            exp.closeObject(); //close TPointAB
            p = p->FNext;
        }

        exp.closeObject(); //close Point


        exp.openObject("Triangle"); //open Triangle
        TTriangleAB *tr = abTriangle.Triangle_First;
        while (tr) {
            exp.openObject(tr->FNo); //TTriangleAB
            exp.writeLine("FTexture", tr->FTexture);
            exp.writeLine("FBackFace", tr->FBackFace);
            exp.writeLine("FOwner", tr->FOwner->FNo);
            exp.openObject("FV"); //start FV
            for (int i = 0; i < 3; i++) {
                exp.openObject(i); //start TTriangleUnitAB
                exp.writeLine("FVer", tr->FV[i]->FVer->FNo);
                exp.writeLine("FV", tr->FV[i]->FV);
                exp.writeLine("FU", tr->FV[i]->FU);
                exp.writeLine("WColor", tr->FV[i]->WColor);
                exp.closeObject(); // close TTriangleUnitAB
            }

            exp.closeObject(); //close FV

            //TODO: FGraph



            exp.closeObject(); //close TTriangleAB


            tr = tr->FNext;
        }
        exp.closeObject(); //Triangle

        exp.openObject("Line"); //open Line
        TLineAB* li = abLine.Line_First;
        while (li) {
            exp.openObject(li->FNo); //TTriangleAB
            exp.writeLine("FVerStart",li->FVerStart->FNo);
            exp.writeLine("FVerEnd",li->FVerEnd->FNo);
            exp.writeLine("WColorStart", li->WColorStart);
            exp.writeLine("WColorEnd", li->WColorEnd);
            exp.writeLine("FShow", li->FShow);
            exp.writeLine("FStopLine", li->FStopLine);
            exp.writeLine("FOwner",li->FOwner->FNo);


            li = li->FNext;
            exp.closeObject(); //close TTriangleAB
        }
        exp.closeObject(); //close Line

        exp.openObject("WorldZone"); //open WorldZone
        TabZone* tz = worldZone.Zone_First;
        while (tz) {
            exp.openObject(tz->FNo); //TabZone
            exp.writeLine("FOrb", tz->FOrb);
            exp.writeLine("FOrbAngle", tz->FOrbAngle);
            exp.writeLine("FRadiusAngle", tz->FRadiusAngle);
            exp.writeLine("FRadius", tz->FRadius);
            exp.writeLine("FType", tz->FType);
            exp.writeLine("FGraph", tz->FGraph);
            exp.writeLine("FHitpoints", tz->FHitpoints);
            exp.writeLine("FMass", tz->FMass);
            exp.writeLine("FDamage", tz->FDamage);
            exp.writeLine("FItem", tz->FItem);
            exp.writeLine("FItemFreq", tz->FItemFreq);
            exp.openObject("FPos"); //open FPos
            exp.writeLine("x", (float) tz->FPos.x);
            exp.writeLine("y", (float) tz->FPos.y);
            exp.writeLine("z", (float) tz->FPos.z);
            exp.closeObject(); //close FPos
            tz = tz->FNext;
            exp.closeObject(); //close TabZone

        }

        exp.closeObject();// close WorldZone

        exp.Close();
//        qDebug()<<abKey.KeyGroupList_List;
    }
//    outf.open(QIODevice::WriteOnly);
//    if (cmd == "r2o")
//    {
//        QVariantMap root = OpenSR::loadRAW(&inf, false);
//        QJsonDocument doc;
//        doc.setObject(QJsonObject::fromVariantMap(root));
//        outf.write(doc.toJson());
//    }
//    if (cmd == "r2m")
//    {
//        QVariantMap root = OpenSR::loadRAW(&inf, false);
//        QJsonDocument doc;
//        doc.setObject(QJsonObject::fromVariantMap(root));
//        outf.write(doc.toJson());
//    }



    return 0;
}
import QtQuick 2.3
import OpenSR 1.0
import OpenSR.World 1.0 as World
import OpenSR.DatPlugin 1.0 as DatPlugin

Item {
    id: ab
    Button {
                id: newButton
                normalImage: "res:/DATA/FormMain2/2ButNewN.gi"
                hoveredImage: "res:/DATA/FormMain2/2ButNewA.gi"
                downImage: "res:/DATA/FormMain2/2ButNewD.gi"
                onClicked: newGame()
            }
    function newGame() {
            DatPlugin.DatManager.test("ML.R2.AB.Border");
//            changeScreen("qrc:/OpenSR/SpaceView.qml", {"system": World.WorldManager.context.currentSystem});
        }

}
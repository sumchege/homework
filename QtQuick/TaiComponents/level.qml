import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQml 2.2

import LevelGauge 1.0

Window {
    visible: true
    width: 600
    height: 400
    color: "#566178"

    TabView {
        id: tabView
        antialiasing: false
        transformOrigin: Item.Center
        tabsVisible: true
        anchors.fill: parent
        Tab {
                title: "Engine"
                Rectangle { color: "#566178" }
            }
        Tab {
                title: "Radio"
                Rectangle { color: "#566178" }
            }
        Tab {
                title: "Settings"
                Rectangle { color: "#566178" }
            }
    }

}

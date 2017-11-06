import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {

    Rectangle {
        id: item
        width: 100; height: 100
        signal qmlSignal(string msg)
        MouseArea {
            anchors.fill: parent
            onClicked: item.qmlSignal("Hello from QML")
        }
    }
}

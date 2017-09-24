import QtQuick 2.0

Rectangle {
    id: root
    width: 200
    height: 200

    Text{
        anchors.centerIn: parent
        text: "Hello world"
    }

    MouseArea{
        anchors.fill: parent
        onClicked: Qt.quit()
    }
}

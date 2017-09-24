import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Item {
    property alias textField1: textField1
    property alias button1: button1

    RowLayout {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 20
        anchors.top: parent.top

        TextField {
            id: textField1
            placeholderText: qsTr("Text Field")
        }

        Button {
            id: button1
            text: qsTr("Press Me")
        }
    }

    BusyIndicator {
        id: busyIndicator
        x: 295
        y: 163
    }

    Button {
        id: button
        x: 286
        y: 263
        text: qsTr("Button")
    }

    Dial {
        id: dial
        x: 42
        y: 119
    }
}

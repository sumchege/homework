import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    header: ToolBar{
        RowLayout{
            anchors.fill: parent
            ToolButton{
                text: "Open"
                onClicked: fileDialog.open()
            }
        }
    }

    FileDialog{
        id: fileDialog
        title: "Choose a file"
        folder: shortcuts.home
    }

    TextArea{
        id: textEdit
        anchors.fill : parent
        text: "Place holder text"
        BusyIndicator {
            id: busyIndicator
            x: 295
            y: 163
        }
    }


}

import QtQuick 2.6
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.0

ApplicationWindow{
    visible: true
    title: "Hello Serious"
    width: 500
    height: 600

    header: ToolBar{
        RowLayout{
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
        anchors.fill: parent
        text: "Placeholder text"
    }


}

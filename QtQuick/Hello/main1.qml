import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.0

Window {
    width: 400
    height: width
    visible: true

    ColumnLayout{
        anchors.fill: parent
        focus: true
        spacing: 3

        property real preferredHeight:  height/3 - 3
        function addText(text){
            edit.text += text + "\n"
            edit.cursorPosition = edit.text.length
        }

        MyButton{
            text:  "Button 1"
            imageSource: "qt.png"
            Layout.fillWidth: true
            Layout.preferredHeight: parent.preferredHeight
            onClicked: parent.addText(this.text)

        }

        MyButton{
            text:  "Button 2"
            imageSource: "play.png"
            Layout.fillWidth: true
            Layout.preferredHeight: parent.preferredHeight
            onClicked: parent.addText(this.text)

        }

        TextArea{
            id: edit
            readOnly: true
            Layout.fillWidth: true
            Layout.preferredHeight: parent.preferredHeight
        }
    }

}

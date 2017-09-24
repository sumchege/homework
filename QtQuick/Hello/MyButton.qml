import QtQuick 2.7

Rectangle {
    property alias text: text.text
    property  alias imageSource: image.source
    signal clicked
    id: root
    color: "lightgray"
    border{
        width: 3
        color: Qt.darker(color)
    }
    Image
    {
        id: image
        height: parent.height - 6
        width : height
        anchors{
            left: parent.left
            top : parent.top
            margins: 3
        }

    }

    Text{
        id:text
        horizontalAlignment: Text.AlignHCenter
        anchors{
            left: image.right
            right: parent.right
            verticalCenter: parent.verticalCenter
        }
    }

    MouseArea{
        anchors.fill: parent
        property color oldColor


    onPressed:
    {
        oldColor = root.color
        root.color = Qt.darker(oldColor)
    }

    onReleased: root.color = oldColor

    onClicked: root.clicked()

   }
}

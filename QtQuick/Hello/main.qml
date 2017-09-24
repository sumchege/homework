import QtQuick 2.0
import QtQuick.Window 2.0
import it.sam.counter 1.0


// import QtQuick.Controls 1.4

Rectangle
{
    id: root
    width: 400
    height: 400
    color: "steelblue"
    border.width: 5
    border.color: Qt.lighter(color)
    property bool ascending : true

    Text {
        id: text
        anchors.centerIn: parent
        text: counter.value
        color: "white"
        font{
            family:"arial"
            pointSize: 30
            bold: true
        }
    }
    MouseArea{
        anchors.fill: parent
        onClicked: {
            ascending = !ascending
            var direction = ascending ? Counter.Ascending: Counter.Descending
            counter.setDirection(direction)
        }
    }

    Counter{
        id: counter
        onValueChanged: root.color = Qt.rgba(Math.random(), .1, .5, 0.5)
    }
}

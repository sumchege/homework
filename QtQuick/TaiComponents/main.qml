import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQml 2.2
// Once an object is registered in the C ++ layer, it must be connected in QML
import ClockCircle 1.0

Window {
    id: window
    visible: true
    width: 400
    height: 400

    ClockCircle {
        id: clockCircle
        // Set its positioning and dimensions
        anchors.top: parent.top
        anchors.topMargin: 50
        anchors.horizontalCenter: parent.horizontalCenter
        width: 200
        height: 200
        z: 1

        // Determine the properties that Q_PROPERTY
        name: "clock"
        bgColor: "whiteSmoke"
        borderActiveColor: "LightSlateGray"
        borderNactiveColor: "LightSteelBlue"

        // Add the text that will be put up timer
        Text {
            id: textTimer
            anchors.centerIn: parent
            font.bold: true
            font.pixelSize: 24
        }

        // If you change the time, put the time on the timer
        onCircleTimeChanged: {
            textTimer.text = Qt.formatTime(circleTime, "mm:ss.zzz")
        }
    }

    Button {
        id: start
        text: "Start"
        onClicked: clockCircle.start(); // Start timer
        anchors {
            left: parent.left
            leftMargin: 20
            bottom: parent.bottom
            bottomMargin: 20
        }

    }

    Label{
        text: slider.value
    }

    ProgressBar {
        id: pb
        anchors.centerIn: parent
        orientation: 0
        value: slider.value
        style: ProgressBarStyle {
            background: Rectangle {
                radius: 2
                color: "lightgray"
                border.color: "LightSteelBlue"
                border.width: 1
                implicitWidth: 200
                implicitHeight: 24
            }
            progress: Rectangle {
                color: "lightsteelblue"
                border.color: "steelblue"
                radius: 2
            }
        }
    }



    Slider {
        id: slider
        x: 368
        y: 49
        orientation: Qt.Vertical
    }

    Button {
        id: clear
        x: 20
        y: 304
        text: "Clear"
        onClicked: clockCircle.clear(); // clean timer
        anchors {
            right: parent.right
            rightMargin: 0
            bottom: parent.bottom
            bottomMargin: 51
        }
    }

    Button {
        id: stop
        x: 339
        y: 204
        text: "Stop"
        onClicked:  clockCircle.stop(); // Stop timer
        anchors {
            horizontalCenter: parent.horizontalCenter
            bottom: parent.bottom
            bottomMargin: 20
        }
    }

    Flow {
        id: flow1
        x: 14
        y: 100
        width: 400
        height: 400
    }
}

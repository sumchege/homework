import QtQuick 2.0
import QtQuick.Window 2.0

Window{
    width: 400
    height: 400
    visible: true


Rectangle{
    id: root;
    width: 400
    height: 400
    focus: true
    state: "red"

    states: [
    State{
            name: "red"
            PropertyChanges {
                target: root
                color: "red"

            }
        },

     State{
                name: "yellow"
                PropertyChanges {
                    target: root
                    color: "yellow"

                }
            },
     State{
                name: "green"
                PropertyChanges {
                    target: root
                    color: "green"

                }
            }

    ]

    Keys.onPressed:
    {
        switch(event.key){
        case Qt.Key_Left:
            switch(state){
            case "red":
                state = "green"
                break;

            case "green":
                state = "yellow"
                break;
            case "yellow":
                state = "red"
                break;
            } // switch state
            break;
        } // switch event.key
    } //key on press

    Keys.onReturnPressed:
        state = "red"

}}

//import QtQuick 2.7

//Rectangle {
//    width : 400
//    height: width
//    color: "white"

//    ListView{
//        id: listView
//        anchors.fill: parent
//        anchors.margins: 4
//        spacing: 4
//        focus: true
//        clip: true

//        model: ListModel
//        delegate: delegateComponent
//        highlight: highlightComponent
//        header: headerComponent
//        footer: footerComponent
//    } // list View

//    ListModel{
//        id: listModel

//        ListElement
//        {
//            name: "Item Zero"
//        }

//        Component.onCompleted:
//        {
//            for(var i=1; i < 101; ++i)
//            {
//                listModel.append({"name": "item " + i})
//            }
//        } // ListModel

//        Component{
//            id: delegateComponent

//            Item{
//                width: parent.width
//                height: 20

//                Text{
//                    anchors.centerIn: parent
//                    text: index + ") " + modelData
//                } // Text
//            } // Item
//        } // Component

//        Component{
//            id: highlightComponent

//            Rectangle{
//                width: parent.width
//                color: "lightgreen"
//            }
//        } //

//        Component{
//            id: headerComponent
//            Rectangle{
//                width: ListView.view.width
//                height: 20
//                color: "silver"
//                Text{
//                    anchors.centerIn: parent
//                    text: "Items"
//                } // Text
//            } // Rectangle
//        } // Component

//        Component{
//            id: footerComponent
//            Rectangle{
//                width: ListView.view.width
//                height: 20
//                color: "lightyellow"
//                Text{
//                    anchors.centerIn: parent
//                    text: "Total: " + listView.count
//                } // Text
//            } // Rectangle
//        } // Component

//    }


//}


import QtQuick 2.0
import QtQuick.Window 2.0

Window{
    width: 240
    height: 320
    visible: true


Rectangle
{

width: 240
height: 320
color: "white"
//
ListView
{
id: listView
anchors.fill: parent
anchors.margins: 4
spacing: 4
focus: true
clip: true
//
model: listModel
delegate: delegateComponent
highlight: highlightComponent
header: headerComponent
footer: footerComponent
} // ListView
//
ListModel
{
id: listModel
//
ListElement
{
name: "Item Zero"
}
//
Component.onCompleted:
{
for (var i = 1; i < 101; ++ i)
listModel.append(
{ "name": "Item " + i })
}
} // ListModel
Component
{
id: delegateComponent
//
Item
{
width: parent.width
height: 20
Text
{
anchors.centerIn: parent
text:
index + ") " + modelData
} // Text
} // Item
} // Component
Component
{
id: highlightComponent
//
Rectangle
{
width: parent.width
color: "lightgreen"
}
}
Component
{
id: headerComponent
//
Rectangle
{
width: ListView.view.width
height: 20
color: "silver"
Text
{
anchors.centerIn: parent
text: "Items"
} // Text
} // Rectangle
} // Component
Component
{
id: footerComponent
//
Rectangle
{
width: ListView.view.width
height: 20
color: "lightyellow"
Text
{
anchors.centerIn: parent
text:
"Total: " +
listView.count
} // Text
} // Rectangle
} // Component
} // Rectangle
}

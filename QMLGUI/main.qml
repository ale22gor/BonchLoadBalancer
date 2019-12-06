
import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5

ApplicationWindow {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("BonchLoadBalancer")


    header:ToolBar {
        ToolButton {
            text:{
                if(view.currentItem.title === "Courses"){
                    return "Proffesors"
                }
                if(view.currentItem.title === "Proffesors"){
                    return "Courses"
                }
            }
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter
            onClicked: {
                if(view.currentItem.title === "Courses"){
                    view.currentIndex = 1
                }
                else if(view.currentItem.title === "Proffesors"){
                    view.currentIndex = 0
                }
            }
        }

        Label {
            text: view.currentItem.title
            anchors.leftMargin: 10
            anchors.horizontalCenter: parent.horizontalCenter
            padding: 10
            font.pixelSize: 20
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
        ToolButton {
            visible: {
                if(view.currentItem.title === "Proffesors"){
                    return true
                }
                return false
            }
            text:{
                if(view.currentItem.title === "Proffesors"){
                    return "Add"
                }
            }
            anchors.right:  parent.right
            anchors.rightMargin:  10
            anchors.verticalCenter: parent.verticalCenter
            onClicked: {
                var popupComponent = Qt.createComponent("AddProfWindow.qml")
                var popup2 = popupComponent.createObject(view, {"parent" : view});
                popup2.open()
            }
        }
    }
    SwipeView {
        id: view
        currentIndex: 0
        anchors.fill: parent
        interactive: false

        Page{

            title: qsTr("Courses")
            CourseWindow{
            }
        }
        Page{
            title: qsTr("Proffesors")
            ProffWindow{
            }
        }

    }
}

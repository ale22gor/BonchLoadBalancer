import QtQuick.Layouts 1.12
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
            text:"Back"
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter
            enabled: view.depth > 1
            onClicked: view.pop()
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
            enabled: view.depth > 1

            text:"Add"
            anchors.right:  parent.right
            anchors.rightMargin:  10
            anchors.verticalCenter: parent.verticalCenter
            onClicked: {
                var popupComponent
                if(view.currentItem.title === "Proffesors"){
                    popupComponent = Qt.createComponent("AddProfWindow.qml")
                }else if(view.currentItem.title === "Courses"){
                    popupComponent = Qt.createComponent("AddCourseWindow.qml")//add course

                }
                var popup = popupComponent.createObject(view, {"parent" : view});
                popup.open()
            }
        }
    }

    StackView {
        id: view
        anchors.fill: parent
        initialItem: Page {
            title: qsTr("Main window")

            RowLayout {
                anchors.fill: parent


                Button {
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    Layout.leftMargin: 24
                    Layout.topMargin: 24
                    Layout.bottomMargin: 24

                    text: "Course"
                    onClicked: view.push(courseWindow)
                }
                Button {
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    Layout.rightMargin: 24
                    Layout.topMargin: 24
                    Layout.bottomMargin: 24

                    text: "Proff"
                    onClicked: view.push(proffWindow)
                }

            }
        }

        Page{
            id:courseWindow
            title: qsTr("Courses")
            CourseWindow{
            }
        }

        Page{
            id:proffWindow
            title: qsTr("Proffesors")
            ProffWindow{
            }
        }


    }


}

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
        background: Rectangle {
            property int lBorderwidth : 1
            property int rBorderwidth : 1
            property int tBorderwidth : 1
            property int bBorderwidth : 1
            implicitWidth: 100
            implicitHeight: 40
            opacity: enabled ? 1 : 0.3
            color: "lavender"
            border.color: "black"

            anchors
            {
                left: parent.left
                right: parent.right
                top: parent.top
                bottom: parent.bottom

                topMargin    :  -tBorderwidth
                bottomMargin :  -bBorderwidth
                leftMargin   :  -lBorderwidth
                rightMargin  :  -rBorderwidth
            }
        }
        ToolButton {
            background: Rectangle {

                opacity: enabled ? 1 : 0.3
                color: "lavender"

            }
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
            background: Rectangle {

                opacity: enabled ? 1 : 0.3
                color: "lavender"
            }
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
            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 40
                opacity: enabled ? 1 : 0.3
                color: "lavender"
            }
            RowLayout {
                anchors.fill: parent


                Button {
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    Layout.leftMargin: 24
                    Layout.topMargin: 24
                    Layout.bottomMargin: 24

                    id:courseButton

                    text: qsTr("Course")
                    font.family: "Robotos"
                    font.pointSize: 28
                    font.weight:Font.Light

                    onClicked: view.push(Qt.createComponent("CourseWindow.qml").createObject())


                    contentItem:
                        Item{

                        Text {
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.horizontalCenter:  parent.horizontalCenter
                            text: myModel.getCoursecCount()
                            font.family: "Roboto"
                            font.pointSize: 72
                            font.weight:Font.Light
                            color: "dodgerblue"
                            opacity: enabled ? 1.0 : 0.3
                            horizontalAlignment: Text.AlignLeft
                            verticalAlignment: Text.AlignBottom
                            //elide: Text.ElideRight
                        }
                        Text {
                            anchors.bottom: parent.bottom
                            text: courseButton.text
                            font: courseButton.font
                            color: "Gray"
                            opacity: enabled ? 1.0 : 0.3
                            horizontalAlignment: Text.AlignLeft
                            verticalAlignment: Text.AlignBottom
                            elide: Text.ElideLeft
                        }
                    }

                    background: Rectangle {
                        implicitWidth: 100
                        implicitHeight: 25
                        opacity: enabled ? 1 : 0.3
                        color: courseButton.down?"powderblue":"aliceblue"
                        border.color: "black"
                        border.width: 0.5
                        radius: 2

                    }
                }
                Button {
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    Layout.topMargin: 24
                    Layout.bottomMargin: 24

                    id:proffButton

                    text: qsTr("Stuff")
                    font.family: "Robotos"
                    font.pointSize: 28
                    font.weight:Font.Light

                    onClicked: view.push(Qt.createComponent("ProffWindow.qml").createObject())

                    contentItem:
                        Item{

                        Text {
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.horizontalCenter:  parent.horizontalCenter
                            text: myModel.getProffSCount()
                            font.family: "Roboto"
                            font.pointSize: 72
                            font.weight:Font.Light
                            color: "dodgerblue"
                            opacity: enabled ? 1.0 : 0.3
                            horizontalAlignment: Text.AlignLeft
                            verticalAlignment: Text.AlignBottom
                            //elide: Text.ElideRight
                        }
                        Text {
                            anchors.bottom: parent.bottom
                            text: proffButton.text
                            font: proffButton.font
                            color: "Gray"
                            opacity: enabled ? 1.0 : 0.3
                            horizontalAlignment: Text.AlignLeft
                            verticalAlignment: Text.AlignBottom
                            elide: Text.ElideLeft
                        }
                    }

                    background: Rectangle {
                        implicitWidth: 100
                        implicitHeight: 25
                        opacity: enabled ? 1 : 0.3
                        color: proffButton.down?"powderblue":"aliceblue"
                        border.color: "black"
                        border.width: 0.5
                        radius: 2

                    }
                }
                Button {
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    Layout.rightMargin: 24
                    Layout.topMargin: 24
                    Layout.bottomMargin: 24

                    id:checkButton

                    text: qsTr("Check")
                    font.family: "Robotos"
                    font.pointSize: 28

                    onClicked:{
                        var popupComponent
                        popupComponent = Qt.createComponent("CheckWindow.qml")
                        var popup = popupComponent.createObject(view, {"parent" : view});
                        popup.open()
                    }


                    contentItem:
                        Item{

                        Text {
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.horizontalCenter:  parent.horizontalCenter
                            text: "0"
                            font.family: "Roboto"
                            font.pointSize: 72
                            font.weight:Font.Light
                            color: "dodgerblue"
                            opacity: enabled ? 1.0 : 0.3
                            horizontalAlignment: Text.AlignLeft
                            verticalAlignment: Text.AlignBottom
                            //elide: Text.ElideRight
                        }
                        Text {
                            anchors.bottom: parent.bottom
                            text: checkButton.text
                            font: checkButton.font
                            color: "Gray"
                            opacity: enabled ? 1.0 : 0.3
                            horizontalAlignment: Text.AlignLeft
                            verticalAlignment: Text.AlignBottom
                            elide: Text.ElideLeft
                        }
                    }

                    background: Rectangle {
                        implicitWidth: 100
                        implicitHeight: 25
                        opacity: enabled ? 1 : 0.3
                        color: checkButton.down?"powderblue":"aliceblue"
                        border.color: "black"
                        border.width: 0.5
                        radius: 2

                    }

                }
            }
        }


    }


}

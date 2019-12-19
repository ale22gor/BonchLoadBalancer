import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12


ListView {
    id: proffesorsSubCoursesList
    objectName: "proffesorsSubCoursesList"
    model: ProffesorsSubCoursesList
    delegate: ColumnLayout {
        width: parent.width
        spacing: 2
        Button {
            Layout.fillWidth: true
            height: courseName.height

            id:courseName
            text: name
            font.family: "Robotos"
            font.pointSize: 28
            font.weight:Font.Light

            onClicked: {
                header.visible = !header.visible
                body.visible = !body.visible
            }

            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 25
                opacity: enabled ? 1 : 0.3
                color: courseName.down?"powderblue":"aliceblue"
                border.color: "black"
                border.width: 0.5
                radius: 2

            }

        }

        RowLayout{
            id:header
            visible: false
            Layout.fillWidth: true

            Rectangle{
                Layout.fillWidth: true

                height: labHeader.height+5
                color: "lightBlue"

                Label {
                    anchors.centerIn: parent
                    id: labHeader
                    text: "Lab"
                    font.pixelSize: 30
                }
            }
            Rectangle{
                Layout.fillWidth: true

                height: seminarHeader.height+5
                color: "lightBlue"

                Label {
                    anchors.centerIn: parent
                    id: seminarHeader
                    text: "Seminar"
                    font.pixelSize: 30
                }
            }
            Rectangle{
                Layout.fillWidth: true

                height: lectureHeader.height+5
                color: "lightBlue"

                Label {
                    anchors.centerIn: parent
                    id: lectureHeader
                    text: "Lecture"
                    font.pixelSize: 30
                }
            }
        }

        RowLayout{
            id:body
            visible: false
            Layout.fillWidth: true

            ListView {
                Layout.fillWidth: true
                //Layout.preferredWidth: 200
                Layout.minimumHeight: 200
                model: Lab //the internal QVariantList
                orientation: ListView.Vertical
                spacing:10

                delegate:Label {
                    anchors.horizontalCenter: parent.horizontalCenter
                    id: labDATA
                    text: modelData
                    font.pixelSize: 30
                }


            }

            ListView {
                Layout.fillWidth: true
                //Layout.preferredWidth: 200
                Layout.minimumHeight: 200

                model: Seminar //the internal QVariantList
                orientation: ListView.Vertical
                spacing:10

                delegate:Label {
                    anchors.horizontalCenter: parent.horizontalCenter
                    id: seminarData
                    text: modelData
                    font.pixelSize: 30
                }

            }
            ListView {
                Layout.fillWidth: true
                //Layout.preferredWidth: 200
                Layout.minimumHeight: 200
                model: Lecture //the internal QVariantList
                orientation: ListView.Vertical
                spacing:10

                delegate:Label {
                    anchors.horizontalCenter: parent.horizontalCenter
                    id: lectureData
                    text: modelData
                    font.pixelSize: 30
                }

            }
        }
    }
}

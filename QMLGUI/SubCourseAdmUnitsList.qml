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
        Rectangle {
            Layout.fillWidth: true
            height: courseName.height
            color: "steelblue"
            border.color: "black"
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    header.visible = !header.visible
                    body.visible = !body.visible
                }
                Label {
                    anchors.centerIn: parent
                    id:courseName
                    text: name
                    font.pixelSize: 30
                }
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

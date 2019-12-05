import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12


ListView {
    id: proffesorsSubCoursesList
    objectName: "proffesorsSubCoursesList"
    model: ProffesorsSubCoursesList
    delegate: Column {
        width: parent.width
        spacing: 2
        Rectangle {
            width: parent.width
            height: courseName.height
            color: "lightgreen"
            Label {
                anchors.centerIn: parent
                id:courseName
                text: name
                font.pixelSize: 30
            }
        }
        RowLayout{
            width: parent.width

            Rectangle{
                Layout.fillWidth: true

                height: labHeader.height+5
                color: "lightBlue"

                Label {
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
                    id: lectureHeader
                    text: "Lecture"
                    font.pixelSize: 30
                }
            }
        }

        RowLayout{
            width: parent.width

            ListView {
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignLeft
                //Layout.preferredWidth: 200
                Layout.minimumHeight: 40

                model: Lab //the internal QVariantList
                orientation: ListView.Horizontal

                delegate:Label {
                    id: labDATA
                    text: modelData
                    font.pixelSize: 30
                }

            }

            ListView {
                Layout.fillWidth: true
                //Layout.preferredWidth: 200
                Layout.minimumHeight: 40
                Layout.alignment: Qt.AlignHCenter

                model: Seminar //the internal QVariantList
                orientation: ListView.Horizontal
                delegate:Label {
                    id: seminarData
                    text: modelData
                    font.pixelSize: 30
                }

            }
            ListView {
                Layout.fillWidth: true
                //Layout.preferredWidth: 200
                Layout.minimumHeight: 40
                Layout.alignment: Qt.AlignRight

                model: Lecture //the internal QVariantList
                orientation: ListView.Horizontal
                delegate:Label {
                    id: lectureData
                    text: modelData
                    font.pixelSize: 30
                }

            }
        }
    }
}

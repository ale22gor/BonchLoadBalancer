import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12




ListView {
    id: courseDetailList
    objectName: "courseDetailList"
    model: CourseDetail
    delegate:ColumnLayout {
        //fix width
        width: parent.width
        spacing: 2

        RowLayout{
            id:header
            Layout.fillWidth: true
            Layout.minimumHeight: labHeader.height+5


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
            Layout.fillWidth: true
            Layout.fillHeight: true



            ListView {
                Layout.fillWidth: true
                Layout.preferredHeight: 200
                // Layout.fillHeight: 40

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
                Layout.preferredHeight: 200

                //Layout.preferredWidth: 200
                //Layout.minimumHeight: 40

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
                Layout.preferredHeight: 200

                //Layout.preferredWidth: 200
                //Layout.minimumHeight: 40
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




import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12




ListView {
    id: courseDetailList
    objectName: "courseDetailList"
    model: CourseDetail
    delegate:Column {
        //fix width
        width: parent.width
        spacing: 2

        RowLayout{
            id:header
            width: parent.width

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
            width: parent.width
            Column{
                Layout.fillWidth: true
                //Layout.preferredWidth: 200
                Layout.minimumHeight: 40

                ListView {

                model: Lab //the internal QVariantList
                orientation: ListView.Horizontal
                spacing:10

                delegate:Label {
                    id: labDATA
                    text: modelData
                    font.pixelSize: 30
                }


            }
            }

            ListView {
                Layout.fillWidth: true
                //Layout.preferredWidth: 200
                Layout.minimumHeight: 40

                model: Seminar //the internal QVariantList
                orientation: ListView.Horizontal
                spacing:10

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
                model: Lecture //the internal QVariantList
                orientation: ListView.Horizontal
                spacing:10

                delegate:Label {
                    id: lectureData
                    text: modelData
                    font.pixelSize: 30
                }

            }
        }



    }
}




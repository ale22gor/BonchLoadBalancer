import QtQuick 2.0
import QtQuick.Controls 2.5




ListView {
    id: proffesorsSubCourseDetail
    objectName: "proffesorsSubCourseDetail"
    model: ProffesorsSubCoursesList
    spacing: 20
    delegate:Row{

        Rectangle {
            color: "lightgreen"
            width: subCourseName.width+10
            height: subCourseName.height + 5

            Label {
                id:subCourseName
                anchors.centerIn: parent
                text: name
                font.pixelSize: 30

            }

        }
    }

}

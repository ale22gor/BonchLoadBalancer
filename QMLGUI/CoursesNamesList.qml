import QtQuick 2.0
import QtQuick.Controls 2.5




ListView {
    id: coursesNamesList
    objectName: "coursesNamesList"
    model: CoursesNamesListModel
    spacing: 1
    delegate:Row{
        width: parent.width
        Rectangle {
            width: parent.width
            height: courseName.height + 5
            border.color: "black"

            Label {

                id:courseName
                anchors.centerIn: parent
                text: name
                font.pixelSize: 30

            }
            Label {
                id: id
                text: courseId
                visible: false
            }

        }
    }

}

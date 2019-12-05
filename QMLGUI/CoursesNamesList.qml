import QtQuick 2.0
import QtQuick.Controls 2.5




ListView {
    id: coursesNamesList
    objectName: "coursesNamesList"
    model: CoursesNamesListModel
    spacing: 20
    delegate:Row{

        Rectangle {
            color: "lightgreen"
            width: courseName.width+10
            height: courseName.height + 5

            Label {

                id:courseName
                anchors.centerIn: parent
                text: name
                font.pixelSize: 30

            }

        }
    }

}

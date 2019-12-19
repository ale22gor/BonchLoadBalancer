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
            color: "lavender"
            width: parent.width
            height: courseName.height + 5
            border.color: "black"

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    myModel.getCourse(model.courseId)
                    var popupComponent = Qt.createComponent("CourseDetailWindow.qml")
                    var popup = popupComponent.createObject(view, {"parent" : view});
                    popup.open()
                }
            }

            Label {
                id:courseName
                anchors.centerIn: parent
                text: name
                font.pixelSize: 30

            }
        }
    }

}

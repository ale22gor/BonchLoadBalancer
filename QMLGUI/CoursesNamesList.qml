import QtQuick 2.0
import QtQuick.Controls 2.5




ListView {
    id: coursesNamesList
    objectName: "coursesNamesList"
    model: CoursesNamesListModel
    spacing: 3
    delegate:Button{
        width: parent.width
        id:courseName
        anchors.centerIn: parent
        text: name
        font.family: "Robotos"
        font.pointSize: 28
        font.weight:Font.Light

        onClicked: {

            myModel.getCourse(model.courseId)
            view.push(Qt.createComponent("CourseDetailWindow.qml").createObject())

            //var popupComponent = Qt.createComponent("CourseDetailWindow.qml")
            //var popup = popupComponent.createObject(view, {"parent" : view});
            //popup.open()
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

}

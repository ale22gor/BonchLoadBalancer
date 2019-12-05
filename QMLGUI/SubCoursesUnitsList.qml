import QtQuick 2.0
import QtQuick.Controls 2.5


GridView {
    id: proffesorsSubCoursesList
    objectName: "proffesorsSubCoursesList"
    model: ProffesorsSubCoursesList

    delegate:
        Row {
          height: 100
          width: 100
          ListView {
            anchors.fill: parent
            model: Lab //the internal QVariantList
            delegate: Rectangle {
              width: 50
              height: 50
              color: "green"
              border.color: "black"
              Text {
                text: modelData //role to get data from internal model
              }
            }
          }
        }

}

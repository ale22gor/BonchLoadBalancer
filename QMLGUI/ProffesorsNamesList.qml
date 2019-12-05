import QtQuick 2.0
import QtQuick.Controls 2.5


ListView {
    id: proffesorsNamesList
    objectName: "proffesorsNamesList"
    model: ProffesorsNamesListModel
    spacing: 20
    delegate:Row{

        Rectangle {
            color: "lightgreen"
            width: proffesorName.width+10
            height: proffesorName.height + 5

            Label {
                id: proffesorName
                anchors.centerIn: parent
                text: name
                font.pixelSize: 30

            }

        }
    }
}

import QtQuick 2.0
import QtQuick.Controls 2.5


ListView {
    id: proffesorsNamesList
    objectName: "proffesorsNamesList"
    model: ProffesorsNamesListModel
    spacing: 1
    delegate:Row{
        width: parent.width
        Rectangle {
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    myModel.getProf(model.profId)
                    var popupComponent = Qt.createComponent("ProffDetailWindow.qml")
                    var popup = popupComponent.createObject(view, {"parent" : view});
                    popup.open()
                }


            }
            width: parent.width
            height: proffesorName.height + 5
            border.color: "black"
            Label {
                id: proffesorName
                anchors.centerIn: parent
                text: name
                font.pixelSize: 30

            }

        }
    }
}


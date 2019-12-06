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
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        myModel.getProf(id.text)
                        var popupComponent = Qt.createComponent("ProffDetailWindow.qml")
                        var popup = popupComponent.createObject(view, {"parent" : view});
                        popup.open()
                    }

                    Label {
                        id: id
                        text: profId
                        visible: false
                    }
                }

            }

        }
    }
}


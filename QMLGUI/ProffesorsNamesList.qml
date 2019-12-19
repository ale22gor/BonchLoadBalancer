import QtQuick 2.0
import QtQuick.Controls 2.5


ListView {
    id: proffesorsNamesList
    objectName: "proffesorsNamesList"
    model: ProffesorsNamesListModel
    spacing: 3
    delegate:Button{

        width: parent.width
        id: proffesorName
        text: name
        font.family: "Robotos"
        font.pointSize: 28
        font.weight:Font.Light
        onClicked: {
            myModel.getProf(model.profId)
            view.push(Qt.createComponent("ProffDetailWindow.qml").createObject())
        }
        background: Rectangle {
            implicitWidth: 100
            implicitHeight: 25
            opacity: enabled ? 1 : 0.3
            color: proffesorName.down?"powderblue":"aliceblue"
            border.color: "black"
            border.width: 0.5
            radius: 2

        }
    }

}


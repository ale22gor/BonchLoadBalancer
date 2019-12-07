import QtQuick 2.0
import QtQuick.Controls 2.5




ListView {
    id: admUnitsModel
    objectName: "admUnitsModel"
    model: AdmUnitsModel
    spacing: 1
    delegate:Row{
        width: parent.width
        Rectangle {
            height: facultyLabel.height + 5
            border.color: "black"

            Label {

                id:facultyLabel
                anchors.centerIn: parent
                text: faculty
                font.pixelSize: 30

            }
        }
        Rectangle {
            height: groupLabel.height + 5
            border.color: "black"

            Label {

                id:groupLabel
                anchors.centerIn: parent
                text: group
                font.pixelSize: 30

            }
        }
        Rectangle {
            height: amountLabel.height + 5
            border.color: "black"
            Label {
                id: amountLabel
                text: amount
                visible: false
            }
        }

    }
}



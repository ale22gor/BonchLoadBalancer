import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12




ListView {
    id: admUnitsModel
    objectName: "admUnitsModel"
    model: AdmUnitsModel
    spacing: 1
    delegate:Rectangle {
        //fix width
        width: admUnitsLayoute.width
        height: admUnitsLayoute.height
        border.color: "black"
        RowLayout{
            id: admUnitsLayoute
            height: facultyLabel.height + 5
            CheckBox{
                id:admUnitsCheckBox

            }

            Label {
                id:facultyLabel
                text: faculty
                font.pixelSize: 30
            }
            Label {
                id:groupLabel
                text: group
                font.pixelSize: 30
            }
            Label {
                id: amountLabel
                text: amount
                font.pixelSize: 30
            }
        }



    }
}




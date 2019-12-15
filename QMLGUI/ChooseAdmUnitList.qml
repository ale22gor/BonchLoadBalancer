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
                Component.onCompleted: {
                    if(selectPopup.objectName === "lab")
                        checked = labCheckStatus
                    else if(selectPopup.objectName === "lecture")
                        checked = lectureCheckStatus
                    else if(selectPopup.objectName === "seminar")
                        checked = seminarCheckStatus
                    else
                        checked = false
                }
                onCheckedChanged: {
                    if(selectPopup.objectName === "lab")
                        labCheckStatus = checked
                    else if(selectPopup.objectName === "lecture")
                        lectureCheckStatus = checked
                    else if(selectPopup.objectName === "seminar")
                        seminarCheckStatus = checked
                }

                //text: selectPopup.objectName

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




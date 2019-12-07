import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12

ColumnLayout {
    anchors.fill: parent

    TextField {
        Layout.fillWidth: true
        Layout.fillHeight: true
        id: name
        maximumLength:12
        placeholderText: "Course Name"
        onActiveFocusChanged:{
            inputMask: "Aaaaaaaaaaaa"
        }
    }
    RowLayout{
        Layout.fillWidth: true
        Layout.fillHeight: true

        Button {
            Layout.fillWidth: true
            Layout.fillHeight: true
            text:"Add People"
            onClicked:{
                var popupComponent
                popupComponent = Qt.createComponent("ChooseAdmUnitWindow.qml")
                var popup = popupComponent.createObject(view, {"parent" : view});
                popup.open()
            }
        }

        TextField {
            Layout.fillWidth: true
            Layout.fillHeight: true
            id: labHourAmount
            validator: RegExpValidator{regExp:{
                    var myRE = new RegExp (['([1-9]|[1-8][0-9]|9[0-9]|[1-8][0-9]{2}|9',
                                            '[0-8][0-9]|99[0-9]|[1-8][0-9]{3}|9[0-8][0-9]{2}|',
                                            '99[0-8][0-9]|999[0-9]|[1-5][0-9]{4}|6[0-4][0-9]{3}|',
                                            '65[0-4][0-9]{2}|655[0-2][0-9]|6553[0-5])'].join(''));
                    return myRE
                }
            }

            placeholderText: "Lab Hour Amount"

        }
    }
    RowLayout{
        Layout.fillWidth: true
        Layout.fillHeight: true

        Button {
            Layout.fillWidth: true
            Layout.fillHeight: true
            text:"Add People"
            onClicked:{
                var popupComponent
                popupComponent = Qt.createComponent("ChooseAdmUnitWindow.qml")
                var popup = popupComponent.createObject(view, {"parent" : view});
                popup.open()
            }
        }
        TextField {
            Layout.fillWidth: true
            Layout.fillHeight: true
            id: lectureHourAmount
            validator: RegExpValidator{regExp:{
                    var myRE = new RegExp (['([1-9]|[1-8][0-9]|9[0-9]|[1-8][0-9]{2}|9',
                                            '[0-8][0-9]|99[0-9]|[1-8][0-9]{3}|9[0-8][0-9]{2}|',
                                            '99[0-8][0-9]|999[0-9]|[1-5][0-9]{4}|6[0-4][0-9]{3}|',
                                            '65[0-4][0-9]{2}|655[0-2][0-9]|6553[0-5])'].join(''));
                    return myRE
                }
            }
            placeholderText: "Lecture Hour Amount"

        }
    }
    RowLayout{
        Layout.fillWidth: true
        Layout.fillHeight: true

        Button {
            Layout.fillWidth: true
            Layout.fillHeight: true
            text:"Add People"
            onClicked:{
                var popupComponent
                popupComponent = Qt.createComponent("ChooseAdmUnitWindow.qml")
                var popup = popupComponent.createObject(view, {"parent" : view});
                popup.open()
            }
        }
        TextField {
            Layout.fillWidth: true
            Layout.fillHeight: true
            id: seminarHourAmount
            validator: RegExpValidator{regExp:{
                    var myRE = new RegExp (['([1-9]|[1-8][0-9]|9[0-9]|[1-8][0-9]{2}|9',
                                            '[0-8][0-9]|99[0-9]|[1-8][0-9]{3}|9[0-8][0-9]{2}|',
                                            '99[0-8][0-9]|999[0-9]|[1-5][0-9]{4}|6[0-4][0-9]{3}|',
                                            '65[0-4][0-9]{2}|655[0-2][0-9]|6553[0-5])'].join(''));
                    return myRE
                }
            }
            placeholderText: "Seminar Hour Amount"

        }
    }
    Button {
        Layout.fillWidth: true
        Layout.fillHeight: true
        text:"add"
        onClicked:{
            myModel.addProf(name.text, labAmount.text, lectureAmount.text, seminarAmount.text,courseCombo.currentText)
            //onClicked: model.setupConnection(name.text,localPort.text,serverPort.text,serverIp.text)
            //accepted()
        }
    }
}




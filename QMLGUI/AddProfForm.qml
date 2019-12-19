import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.12

ColumnLayout {
    anchors.fill: parent

    TextField {
        Layout.fillWidth: true
        Layout.fillHeight: true
        id: name
        maximumLength:12
        placeholderText: "Prof Name"
        onActiveFocusChanged:{
            inputMask: "Aaaaaaaaaaaa"
        }
    }
    TextField {
        Layout.fillWidth: true
        Layout.fillHeight: true
        id: labAmount
        validator: RegExpValidator{regExp:{
                var myRE = new RegExp (['([1-9]|[1-8][0-9]|9[0-9]|[1-8][0-9]{2}|9',
                                        '[0-8][0-9]|99[0-9]|[1-8][0-9]{3}|9[0-8][0-9]{2}|',
                                        '99[0-8][0-9]|999[0-9]|[1-5][0-9]{4}|6[0-4][0-9]{3}|',
                                        '65[0-4][0-9]{2}|655[0-2][0-9]|6553[0-5])'].join(''));
                return myRE
            }
        }

        placeholderText: "Lab Amount"

    }
    TextField {
        Layout.fillWidth: true
        Layout.fillHeight: true
        id: lectureAmount
        validator: RegExpValidator{regExp:{
                var myRE = new RegExp (['([1-9]|[1-8][0-9]|9[0-9]|[1-8][0-9]{2}|9',
                                        '[0-8][0-9]|99[0-9]|[1-8][0-9]{3}|9[0-8][0-9]{2}|',
                                        '99[0-8][0-9]|999[0-9]|[1-5][0-9]{4}|6[0-4][0-9]{3}|',
                                        '65[0-4][0-9]{2}|655[0-2][0-9]|6553[0-5])'].join(''));
                return myRE
            }
        }
        placeholderText: "Lecture Amount"

    }
    TextField {
        Layout.fillWidth: true
        Layout.fillHeight: true
        id: seminarAmount
        validator: RegExpValidator{regExp:{
                var myRE = new RegExp (['([1-9]|[1-8][0-9]|9[0-9]|[1-8][0-9]{2}|9',
                                        '[0-8][0-9]|99[0-9]|[1-8][0-9]{3}|9[0-8][0-9]{2}|',
                                        '99[0-8][0-9]|999[0-9]|[1-5][0-9]{4}|6[0-4][0-9]{3}|',
                                        '65[0-4][0-9]{2}|655[0-2][0-9]|6553[0-5])'].join(''));
                return myRE
            }
        }
        placeholderText: "Seminar Amount"

    }
    ComboBox {
        id: control
        //editable: true
        Layout.fillWidth: true
        Layout.fillHeight: true

        textRole: "name"

        model: CoursesNamesListModel
        delegate: ItemDelegate {
            width: control.width
            contentItem: Text {
                text: name //+ model.courseId
                font: control.font
                elide: Text.ElideRight
                verticalAlignment: Text.AlignVCenter
            }
            highlighted: control.highlightedIndex === index
        }
        onFocusChanged:   {
            var currentItem = delegateModel.items.get(currentIndex)
            console.log("Read Model Value: " + currentItem.model.courseId);
            myModel.setCourseLessonsAmount(currentIndex,currentItem.model.courseId,labAmount.text, lectureAmount.text, seminarAmount.text)
        }
    }
    Button {
        Layout.fillWidth: true
        Layout.fillHeight: true
        text:"add"
        onClicked:{
            //myModel.setCourseLessonsAmount(control.currentIndex,control.model.courseId,labAmount.text, lectureAmount.text, seminarAmount.text)
            myModel.addProf(name.text)
            //console.debug(courseCombo.get(currentIndex).name + ", " + courseCombo.get(currentIndex).id)
            //onClicked: model.setupConnection(name.text,localPort.text,serverPort.text,serverIp.text)
            //accepted()
        }
    }
}




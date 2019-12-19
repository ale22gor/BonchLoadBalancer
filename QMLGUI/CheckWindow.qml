import QtQuick 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.5
Popup{
    width: parent.width/2
    height: parent.height/4
    anchors.centerIn: parent
    background: Rectangle{
        //color: myModel.getFreeLessons() > 0?"lightcoral":"lightgreen"
        border.color: myModel.getFreeLessons() > 0?"red":"springgreen"
        border.width: 3

    }
    Label {
        id:checkResult
        anchors.centerIn: parent
        text: "Free lessons:" + myModel.getFreeLessons()
        font.pixelSize: 30

    }
}

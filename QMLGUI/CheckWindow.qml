import QtQuick 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.5
Popup{
    width: parent.width/2
    height: parent.height/4
    anchors.centerIn: parent
    Label {
        id:checkResult
        anchors.centerIn: parent
        text: "Free lessons:" + myModel.getFreeLessons()
        font.pixelSize: 30

    }
}

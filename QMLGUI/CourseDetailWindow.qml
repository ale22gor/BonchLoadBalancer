import QtQuick 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.5
Page{
    title: qsTr("Course")
    background: Rectangle {
        implicitWidth: 100
        implicitHeight: 40
        opacity: enabled ? 1 : 0.3
        color: "lavender"
    }
    RowLayout{
        anchors.fill: parent
        CourseDetailList{
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.leftMargin: 24
            Layout.rightMargin: 24
            Layout.topMargin: 24
        }
    }
}

import QtQuick 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.5

RowLayout{
    anchors.fill: parent

    CoursesNamesList{
        Layout.fillHeight: true
        Layout.fillWidth: true
        Layout.leftMargin: 24
        Layout.topMargin: 24
    }
}

import QtQuick 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.5
Popup{
    width: parent.width
    height: parent.height
    ColumnLayout{
        anchors.fill: parent

        RowLayout{
            Layout.fillWidth: true

            ChooseAdmUnitList{
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.leftMargin: 24
                Layout.topMargin: 24
                Layout.rightMargin: 24

            }

        }
        Button{
            text: "Add"
            Layout.fillWidth: true

        }
    }

}

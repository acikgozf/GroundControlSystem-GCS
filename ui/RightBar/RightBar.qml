import QtQuick 2.15
import QtQuick.Controls 2.15


Rectangle {
    id: rectangle1
    x: 0
    y: 0
    width: 40
    height:480
    color: "#1d2232"
    border.color: "#4ba2ff"

    Column {
        id: column
        anchors.fill: parent
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
    }

    Button {
        id: control
        width: 40
        height: 40
        text: qsTr("P1")
        anchors.top: column.top
        anchors.topMargin: 0

        contentItem: Text {
            text: control.text
            font: control.font
            opacity: enabled ? 1.0 : 0.3
            color: control.down ? "#17a81a" : "#21be2b"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            elide: Text.ElideRight
        }

        background: Rectangle {
            implicitWidth: 100
            implicitHeight: 40
            opacity: enabled ? 1 : 0.3
            border.color: control.down ? "#17a81a" : "#21be2b"
            border.width: 1
            radius: 2
            color: "black"  // I update background color by this
        }
    }

    Button {
        id: control_p2
        x: 0
        width: 40
        height: 40
        text: qsTr("P2")
        anchors.top: parent.top
        anchors.topMargin: 40

        contentItem: Text {
            text: control_p2.text
            font: control_p2.font
            opacity: enabled ? 1.0 : 0.3
            color: control_p2.down ? "#17a81a" : "#21be2b"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            elide: Text.ElideRight
        }

        background: Rectangle {
            implicitWidth: 100
            implicitHeight: 40
            opacity: enabled ? 1 : 0.3
            border.color: control_p2.down ? "#17a81a" : "#21be2b"
            border.width: 1
            radius: 2
            color: "black"  // I update background color by this
        }
    }
}



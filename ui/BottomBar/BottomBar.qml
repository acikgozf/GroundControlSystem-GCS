import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15
import QtQuick.Dialogs 1.3


Rectangle{
    width: 480
    height: 40
    color: "#1d2232"

    Row {
        id: row
        x: 0
        y: 0
        width: 480
        height: 40
        antialiasing: true

        Text {
            id: text1
            x: 8
            y: 12
            color: "#57d658"
            text: qsTr("Enlem:")
            font.pixelSize: 12
        }

        TextInput {
            id: textInput1
            x: 131
            y: 12
            width: 35
            height: 16
            color: "#57d658"
            font.pixelSize: 12
            selectionColor: "#ffffff"
        }

        Text {
            id: text2
            x: 90
            y: 12
            color: "#57d658"
            text: qsTr("Boylam:")
            font.pixelSize: 12
        }
    }

    TextInput {
        id: textInput
        x: 116
        y: 12
        width: 35
        height: 16
        font.pixelSize: 12
    }



}

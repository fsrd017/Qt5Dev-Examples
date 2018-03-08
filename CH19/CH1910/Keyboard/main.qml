import QtQuick 2.7
import QtQuick.Window 2.2

Window {
    visible: true
    width: 450
    height: 240
    title: qsTr("Keyboard")

    MainForm {
        anchors.fill: parent
        mouseArea.onClicked: {
            console.log(qsTr('Clicked on background. Text: "' + textEdit.text + '"'))
        }
    }
}

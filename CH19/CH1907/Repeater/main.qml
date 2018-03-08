import QtQuick 2.7
import QtQuick.Window 2.2

Window {
    visible: true
    width: 300
    height: 250
    title: qsTr("Repeater")

    MainForm {
        anchors.fill: parent
        mouseArea.onClicked: {
            console.log(qsTr('Clicked on background. Text: "' + textEdit.text + '"'))
        }
    }
}

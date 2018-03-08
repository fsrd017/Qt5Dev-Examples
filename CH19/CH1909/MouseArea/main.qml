import QtQuick 2.7
import QtQuick.Window 2.2

Window {
    visible: true
    width: 390
    height: 100
    title: qsTr("MouseArea")

    MainForm {
        anchors.fill: parent
        mouseArea.onClicked: {
            console.log(qsTr('Clicked on background. Text: "' + textEdit.text + '"'))
        }
    }
}

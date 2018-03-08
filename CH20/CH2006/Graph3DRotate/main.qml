import QtQuick 2.7
import QtQuick.Window 2.2

Window {
    visible: true
    width: 420
    height: 320
    title: qsTr("Graph3DRotate")

    MainForm {
        anchors.fill: parent
        mouseArea.onClicked: {
            console.log(qsTr('Clicked on background. Text: "' + textEdit.text + '"'))
        }
    }
}

import QtQuick 2.7
import QtQuick.Window 2.2

Window {
    visible: true
    width: 160
    height: 160
    title: qsTr("JavaScript")

    MainForm {
        anchors.fill: parent
        mouseArea.onClicked: {
            //console.log(qsTr('Clicked on background. Text: "' + textEdit.text + '"'))
        }
    }
}

import QtQuick 2.7
import QtQuick.Window 2.2

Window {
    visible: true
    //width: 430
    //height: 290
    width: 200
    height: 200
    title: qsTr("Positioner")

    MainForm {
        anchors.fill: parent
        mouseArea.onClicked: {
            console.log(qsTr('Clicked on background. Text: "' + textEdit.text + '"'))
        }
    }
}

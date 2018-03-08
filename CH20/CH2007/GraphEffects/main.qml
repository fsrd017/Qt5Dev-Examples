import QtQuick 2.7
import QtQuick.Window 2.2

Window {
    visible: true
    width: 380
    height: 290
    title: qsTr("GraphEffects")

    MainForm {
        anchors.fill: parent
        mouseArea.onClicked: {
            console.log(qsTr('Clicked on background. Text: "' + textEdit.text + '"'))
        }
    }
}

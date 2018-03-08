import QtQuick 2.7
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("PropertyAnimation")

    MainForm {
        anchors.fill: parent
        mouseArea.onClicked: {
            //console.log(qsTr('Clicked on background. Text: "' + textEdit.text + '"'))
            /* 将鼠标单击位置的x、y坐标值设为矩形Rect4的新坐标 */
             rect4.x = mouseArea.mouseX;
             rect4.y = mouseArea.mouseY;
        }
    }
}

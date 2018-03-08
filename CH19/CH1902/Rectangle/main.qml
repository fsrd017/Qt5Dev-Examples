import QtQuick 2.7
import QtQuick.Window 2.2

Window {
    visible: true
    width: 250
    height: 220
    title: qsTr("Rectangle")

    MainForm {
        anchors.fill: parent
        mouseArea.onClicked: {
            topRect.visible = !topRect.visible          //控制矩形对象的可见性
        }
    }
}

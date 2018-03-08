import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Extras 1.4
import QtQuick.Controls 1.4

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("饼状菜单")

    MainForm {
        anchors.fill: parent
        mouseArea.onClicked: {
            //console.log(qsTr('Clicked on background. Text: "' + textEdit.text + '"'))
            pieMenu.popup(mouseArea.mouseX, mouseArea.mouseY)
        }
    }

    PieMenu {
        id: pieMenu
        triggerMode: TriggerMode.TriggerOnRelease
        MenuItem {
            text: "动作1"
            onTriggered: print("动作1")
        }
        MenuItem {
            text: "动作2"
            onTriggered: print("动作2")
        }
        MenuItem {
            text: "动作3"
            onTriggered: print("动作3")
        }
    }
}

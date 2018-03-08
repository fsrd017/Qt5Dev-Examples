import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Extras 1.4

ApplicationWindow {
    visible: true
    width: 320
    height: 240
    title: qsTr("汽车时速表")
/*
    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: console.log("Open action triggered");
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }
*/
    MainForm {
        anchors.fill: parent
        CircularGauge {
            value: accelerating ? maximumValue : 0
            anchors.centerIn: parent

            property bool accelerating: false

            Keys.onSpacePressed: accelerating = true
            Keys.onReleased: {
                if (event.key === Qt.Key_Space) {
                    accelerating = false;
                    event.accepted = true;
                }
            }

            Component.onCompleted: forceActiveFocus()

            Behavior on value {
                NumberAnimation {
                    duration: 1000
                }
            }
        }
        /*
        button1.onClicked: messageDialog.show(qsTr("Button 1 pressed"))
        button2.onClicked: messageDialog.show(qsTr("Button 2 pressed"))
        */
    }
/*
    MessageDialog {
        id: messageDialog
        title: qsTr("May I have your attention, please?")

        function show(caption) {
            messageDialog.text = caption;
            messageDialog.open();
        }
    }
    */
}

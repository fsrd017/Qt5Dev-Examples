import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

ApplicationWindow {
    id: window
    visible: true
    width: 840
    height: 660
    title: qsTr("世界艺术珍品")

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Page1 {
        }

        Page {
            Label {
                text: qsTr("Second page")
                anchors.centerIn: parent
            }
        }
    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex
        TabButton {
            text: qsTr("First")
        }
        TabButton {
            text: qsTr("Second")
        }
    }

    Drawer {
        id: drawer
        width: 0.618 * window.width
        height: window.height
        edge: Qt.RightEdge
        opacity: 0.618
        Label {
            id: details
            font.family: "楷体"
            font.bold: true
            font.pointSize: 18
            anchors.fill: parent
            verticalAlignment: Label.AlignVCenter
            horizontalAlignment: Label.AlignHCenter
        }
    }
}

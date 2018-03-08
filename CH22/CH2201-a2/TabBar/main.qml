import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

ApplicationWindow {
    visible: true
    width: 240
    height: 480
    title: qsTr("标签栏")

    header: TabBar {
        id: bar
        width: parent.width

        Repeater {
            model: ["第一页", "第二页", "第三页", "第四页", "第五页"]

            TabButton {
                text: modelData
                width: Math.max(100, bar.width / 5)
            }
        }
    }
/*
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
    */
}

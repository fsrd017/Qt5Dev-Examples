import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.0

ApplicationWindow {
    visible: true
    width: 240
    height: 480
    title: qsTr("工具栏")

    header: ToolBar {
        RowLayout {
            anchors.fill: parent
            ToolButton {
                text: qsTr("‹")
                onClicked: stack.pop()
            }
            Label {
                text: "主题"
                elide: Label.ElideRight
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
                Layout.fillWidth: true
            }
            ToolButton {
                text: qsTr("⋮")
                onClicked: menu.open()
            }
        }
    }

    StackView {
        id: stack
        anchors.fill: parent
    }

    Menu {
        id: menu
        MenuItem {
            text: qsTr("新建...")
        }
        MenuItem {
            text: qsTr("打开...")
        }
        MenuItem {
            text: qsTr("保存")
        }

        MenuSeparator {
            padding: 0
            topPadding: 12
            bottomPadding: 12
            contentItem: Rectangle {
                implicitWidth: 200
                implicitHeight: 1
                color: "#1E000000"
            }
        }

        MenuItem {
            text: qsTr("退出")
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

import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

ApplicationWindow {
    visible: true
    width: 330
    height: 200
    title: qsTr("部分控件的外观")

    ColumnLayout {
        anchors.centerIn: parent
        RowLayout {
            Label {
                text: "忙指示器：  "
            }
            BusyIndicator {
                running: image.status === Image.Loading
            }
        }
        RowLayout {
            Label {
                text: "进度条：    "
            }
            ProgressBar {
                indeterminate: true
            }
        }
        RowLayout {
            Label {
                text: "滑动条：    "
            }
            Slider {
                from: 1
                value: 25
                to: 100
                stepSize: 5
                snapMode : Slider.SnapOnRelease         //滑条的间断模式
            }
        }
        RowLayout {
            Label {
                text: "数值旋转框："
            }
            SpinBox {
                value: 50
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

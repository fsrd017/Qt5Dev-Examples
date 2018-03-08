import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.2
import QtQuick.Extras 1.4

ApplicationWindow {
    visible: true
    width: 400
    height: 200
    title: qsTr("翻选框")

    RowLayout {							//该行提供日期选择功能
        anchors.centerIn: parent
        Label {
            text: "日期："
        }
        TextField {
            id: date
        }
        Button {
            id: btnSelect
            text: qsTr("选择...")
            onClicked: dateDialog.open()
        }
    }


    Dialog {
        id: dateDialog
        title: "选择日期"
        width: 275
        height: 300
        standardButtons: StandardButton.Save | StandardButton.Cancel
        onAccepted: {
            date.text = year.model[year.currentIndex] + "年" + month.model[month.currentIndex] + day.model[day.currentIndex] + "日"
        }

        Tumbler {
            id: calendar
            anchors.centerIn: parent
            TumblerColumn {
                id: month
                model: ["1月", "2月", "3月", "4月", "5月", "6月", "7月", "8月", "9月", "10月", "11月", "12月"]
            }
            TumblerColumn {
                id: day
                model: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31]
            }
            TumblerColumn {
                id: year
                model: ["2010", "2011", "2012", "2013", "2014", "2015", "2016", "2017"]
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

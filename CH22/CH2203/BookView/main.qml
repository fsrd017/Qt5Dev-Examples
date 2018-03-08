import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("选择图书")

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Page1 {
            ListView {
                id: listTitle
                width: 200
                height: 240
                model: bookModel
                delegate: ItemDelegate {
                    text: modelData
                    width: parent.width
                    highlighted: ListView.isCurrentItem
                    onClicked: {
                        listTitle.currentIndex = index
                        switch(index) {
                            case 0: bookCover.source="images/java.jpg"; break;
                            case 1: bookCover.source="images/javaee.jpg"; break;
                            case 2: bookCover.source="images/mysql.jpg"; break;
                            case 3: bookCover.source="images/orcl.jpg"; break;
                            case 4: bookCover.source="images/php.jpg"; break;
                            case 5: bookCover.source="images/plc.jpg"; break;
                            case 6: bookCover.source="images/sqlsrv.jpg"; break;
                            default: break;
                        }
                    }
                }
                ScrollIndicator.vertical: ScrollIndicator { }
            }

            Image {
                id: bookCover
                width: 164
                height: 230
                source: "images/java.jpg"
                anchors.left: listTitle.right
                anchors.leftMargin: 120
            }

            ListModel {
                id: bookModel
                ListElement {
                    title: "Java实用教程(第3版)"
                }
                ListElement {
                    title: "JavaEE基础实用教程(第2版)"
                }
                ListElement {
                    title: "MySQL实用教程(第2版)"
                }
                ListElement {
                    title: "Oracle实用教程(第4版)"
                }
                ListElement {
                    title: "PHP实用教程(第2版)"
                }
                ListElement {
                    title: "施耐德PLC开发及实例(第2版)"
                }
                ListElement {
                    title: "SQLServer实用教程(第4版)"
                }
            }
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
}

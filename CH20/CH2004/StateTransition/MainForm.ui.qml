import QtQuick 2.7

Rectangle {
    property alias mouseArea: mouseArea

    width: 360
    height: 360

    MouseArea {
        id: mouseArea
        anchors.fill: parent
    }
    Row {
        anchors.centerIn: parent
        spacing: 10
        StateText { text: "I" }			//使用组件，要自定义其文本属性
        StateText { text: "love" }
        StateText { text: "QML"  }
    }
}

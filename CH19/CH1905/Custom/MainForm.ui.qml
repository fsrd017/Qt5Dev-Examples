import QtQuick 2.7

Rectangle {
    property alias mouseArea: mouseArea

    width: 360
    height: 360

    MouseArea {
        id: mouseArea
        anchors.fill: parent
    }

    Button {									//复用Button组件
        x: 25; y: 25
    }

}

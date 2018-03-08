import QtQuick 2.7

Rectangle {
    property alias mouseArea: mouseArea

    width: 360
    height: 360

    MouseArea {
        id: mouseArea
        anchors.fill: parent
    }

    Rect {										//复用定义好的矩形元素
        x:25;y:25								//初始坐标
        opacity:(360.0 - x)/360					//透明度设置
    }
}

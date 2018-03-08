import QtQuick 2.7

Rectangle {
    property alias mouseArea: mouseArea
    property alias textEdit: textEdit

    width: 360
    height: 360

    MouseArea {
        id: mouseArea
        anchors.fill: parent
    }
    TextEdit {
        id: textEdit
        visible: false
    }
    RotateRect {							//直接使用RotateRect组件
        x:50;y:50
    }
}

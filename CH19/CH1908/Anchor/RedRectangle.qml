import QtQuick 2.0

Rectangle {
    width: 64						//宽度
    height: 32						//高度
    color: "red"					//颜色
    border.color: Qt.lighter(color)	//边框色设置比填充色浅（默认是50%）
}


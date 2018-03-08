import QtQuick 2.0

Rectangle {								//将Rectangle自定义成按钮
    id:btn
    width: 100;height: 62				//按钮的尺寸
    color: "teal"						//按钮颜色
    border.color: "aqua"				//按钮边界色
    border.width: 3						//按钮边界宽度
    Text {								//Text元素作为按钮文本
        id: label
        anchors.centerIn: parent
        font.pointSize: 16
        text: "开始"
    }
    MouseArea {                         //MouseArea对象作为按钮单击事件响应区
        anchors.fill: parent
        onClicked: {
            label.text = "按钮已按下！"
            label.font.pointSize = 11
            btn.color = "aqua"
            btn.border.color = "teal"
            /* 改变changingRect1的右锚属性 */			//(a)
            chgRect1.anchors.left = undefined
            chgRect1.anchors.right = rRect.right
            /* 改变changingRect2的右锚属性 */			//(b)
            chgRect2.anchors.right = rRect.right
            chgRect2.anchors.left = undefined
        }
    }
}


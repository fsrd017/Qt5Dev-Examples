import QtQuick 2.0

Rectangle {
    id: rect3
    width: 80
    height: 80
    color: "aqua"
    radius: 10
    Text {
        anchors.centerIn: parent
        font.pointSize: 12
        text: "独立元素"
    }
    PropertyAnimation {						//(d)
        id: animation						//独立动画标识符
        target: rect3
        properties: "x,y"					//同时在x、y轴两个方向上运动
        duration: 1000						//运动时间为1秒
        easing.type: Easing.InOutBack		//运动到半程增加过冲，然后减少
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            animation.from = 20				//起点
            animation.to = 200				//终点
            animation.running = true		//开启动画
        }
    }
}


import QtQuick 2.0

Rectangle {
    width: 80
    height: 80
    color: "orange"
    radius: 10
    Text {
        anchors.centerIn: parent
        font.pointSize: 12
        text: "属性值源"
    }
    PropertyAnimation on x {					//(a)
        from: 50								//起点
        to: 500									//终点
        duration: 30000							//运动时间30秒
        loops: Animation.Infinite				//无限循环
        easing.type: Easing.OutBounce			//(b)
    }
}


import QtQuick 2.7

Rectangle {
    property alias mouseArea: mouseArea
    width: 360
    height: 360
    MouseArea {
        id: mouseArea
        anchors.fill: parent
    }
    Image {
       //图像在窗口的位置坐标
       x: 20
       y: 20
       //宽和高均为原图1/4
       width: 980/4;height: 751/4				//(a)
       source: "images/栖霞山枫叶.jpg"			//图片路径URL
       fillMode: Image.PreserveAspectCrop		//(b)
       clip: true                               //避免所要渲染的图片超出元素范围
    }
}

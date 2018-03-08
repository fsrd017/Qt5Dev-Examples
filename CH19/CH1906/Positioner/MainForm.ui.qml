import QtQuick 2.7

Rectangle {
    property alias mouseArea: mouseArea

    width: 200
    height: 200

    MouseArea {
        id: mouseArea
        anchors.fill: parent
    }

    Flow {
        anchors.fill: parent
        anchors.margins: 15				//元素与窗口左上角边距为15像素
        spacing: 5
        //以下添加被Flow定位的元素成员
        RedRectangle { }
        BlueRectangle { }
        GreenRectangle { }
    }

    /**
    Row {										//(a)
        x:25
        y:25
        spacing: 10								//元素间距为10像素
        layoutDirection:Qt.RightToLeft			//元素从右向左排列
        //以下添加被Row定位的元素成员
        RedRectangle { }
        GreenRectangle { }
        BlueRectangle { }
    }
    Column {									//(b)
        x:25
        y:120
        spacing: 2
        //以下添加被Column定位的元素成员
        RedRectangle { }
        GreenRectangle { }
        BlueRectangle { }
    }
    Grid {										//(c)
        x:140
        y:120
        columns: 3								//每行3个元素
        spacing: 5
        //以下添加被Grid定位的元素成员
        BlueRectangle { }
        BlueRectangle { }
        BlueRectangle { }
        BlueRectangle { }
        BlueRectangle { }
    }
    */
}

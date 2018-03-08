import QtQuick 2.7
import QtQuick.Controls 1.5
import QtQuick.Dialogs 1.2

ApplicationWindow {					//主应用窗口
    title: qsTr("世界艺术珍品")		//窗口标题
    width: 780
    height: 320
    visible: true
    MainForm {						 //主窗体
        anchors.fill: parent
        tableView.onClicked: {		 //单击选择列表项执行的代码
            tabView.currentIndex = tableView.currentRow;	//(a)
            scrolimg.source = "images/" + tabView.getTab(tabView.currentIndex).title + ".jpg";//(b)
        }
        tabView.onCurrentIndexChanged: {//切换TabView视图选项页执行的代码
            tableView.selection.clear();					//(c)
            tableView.selection.select(tabView.currentIndex);
            scrolimg.source = "images/" + tabView.getTab(tabView.currentIndex).title + ".jpg";
        }
    }
}

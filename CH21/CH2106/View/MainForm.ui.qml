import QtQuick 2.7
import QtQuick.Controls 1.5
import QtQuick.Layouts 1.3

Item {                                      //QML通用的根元素
    width: 780
    height: 320
    /* 定义属性别名，为在main.qml中引用各组件 */
    property alias tableView: tableView		//TableView视图（左区）
    property alias tabView: tabView			//TabView视图（中区）
    property alias scrolimg: scrolimg		//ScrollView视图的Image子元素（右区）
    RowLayout {								//行布局
        anchors.centerIn: parent
        SplitView {							//(a)
            anchors.fill: parent
            orientation: Qt.Horizontal
            TableView {						/* TableView视图 */
                id: tableView				//视图标识
                width: 300
                TableViewColumn {			//(b)
                    role: "title"
                    title: "名称"
                    horizontalAlignment: Text.AlignHCenter//列表项文字居中
                    width: 100
                }
                TableViewColumn {
                    role: "author"
                    title: "作者"
                    horizontalAlignment: Text.AlignHCenter
                    width: 200
                }
                model: libraryModel			//(c)
            }
            TabView {						/* TabView视图 */
                id: tabView					//视图标识
                width: 215; height: 300
                Tab {						//选项页
                    title: "蒙娜丽莎"			//该页的标签文本
                    Image {					//该页显示的图像元素
                        source: "images/蒙娜丽莎.jpg"	//图像路径
                    }
                }
                Tab {
                    title: "大卫"
                    Image {
                        source: "images/大卫.jpg"
                    }
                }
                Tab {
                    title: "圣母"
                    Image {
                        source: "images/圣母.jpg"
                    }
                }
            }
            ScrollView {					//(d)
                Image {
                    id: scrolimg
                    source: "images/蒙娜丽莎.jpg"
                }
            }
        }
    }
    ListModel {							//提供TableView视图所需数据
        id: libraryModel
        ListElement {					//定义列表项
            title: "蒙娜丽莎"				//数据项（与"title"角色绑定）
            author: "列奥纳多•达•芬奇"		//数据项（与"author"角色绑定）
        }
        ListElement {
            title: "大卫"
            author: "波纳罗蒂•米开朗琪罗"
        }
        ListElement {
            title: "西斯廷圣母"
            author: "拉斐尔•圣齐奥"
        }
    }
}


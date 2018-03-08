import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2
import QtQuick.Extras 1.4

Item {
    width: 320
    height: 270

    property alias button1: button1
    property alias button2: button2
    property alias thermometer: thermometer

    ColumnLayout {
        anchors.centerIn: parent

        Gauge {
            id: thermometer
            minimumValue: 0
            value: 30
            maximumValue: 100
            anchors.centerIn: parent
        }

        Label {
            height: 15
        }

        Label {
            height: 15
        }

        RowLayout {
            Button {
                id: button1
                text: qsTr("升温")
            }

            Button {
                id: button2
                text: qsTr("降温")
            }
        }
    }
}

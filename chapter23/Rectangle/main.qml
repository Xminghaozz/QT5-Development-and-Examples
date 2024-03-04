import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Rectangel")

    MainForm{
        anchors.fill: parent
        mouseArea.onClicked: {
            topRect.visible = !topRect.visible  //控制矩形对象的可见性
        }
    }
}

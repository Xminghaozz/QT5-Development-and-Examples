import QtQuick 2.15

Rectangle {
    property alias mouseArea: mouseArea
    width: 480
    height: 360

    MouseArea{
        id:mouseArea
        anchors.fill: parent
    }

    MyGraph{}   //使用组件
}

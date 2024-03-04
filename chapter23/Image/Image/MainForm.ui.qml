import QtQuick 2.12

Rectangle {

    property alias mouseArea: mouseArea
     width: 1920/4; height: 1080/4
     MouseArea {
        id: mouseArea
        anchors.fill: parent
    }
    Image{
        //图片在窗口中的坐标位置
        x:20
        y:20
        //宽和高均为原图的1/4
        width: 1920/4; height: 1080/4
        source: "images/01.png" //图片路径URL
        fillMode: Image.PreserveAspectCrop
        clip: true
    }
}

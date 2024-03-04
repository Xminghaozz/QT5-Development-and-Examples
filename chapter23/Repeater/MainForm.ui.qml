import QtQuick 2.12

Rectangle {
    property alias mouseArea: mouseArea
    width: 480
    height: 360

    MouseArea{
        id:mouseArea
        anchors.fill:parent
    }

    Grid{   //Grid定位器
        x:25;y:25
        spacing: 4
        //用重复器为Grid添加元素成员
        Repeater{
            model: 16   //要创建的元素的个数
            Rectangle{
                width: 48;height: 48
                color: "aqua"
                Text{   //显示矩形编号
                    anchors.centerIn: parent
                    color: "black"
                    font.pointSize: 20
                    text: index
                }
            }
        }
    }
}

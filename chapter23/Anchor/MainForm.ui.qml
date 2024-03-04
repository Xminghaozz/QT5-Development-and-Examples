import QtQuick 2.12

Rectangle {
    property alias mouseArea: mouseArea
    /*定义属性别名*/
    property alias chgRect1 : changingRect1 //矩形Rect1属性别名
    property alias chgRect2: changingRect2 //矩形 changingRect2 属性别名
    property alias rRect: redRect   //红矩形redRect属性别名
    width: 360
    height: 360

    MouseArea{
        id:mouseArea
        anchors.fill: parent
    }

    /*使用Anchor对三个矩形元素进行横向布局*/
    BlueRectangle{
        id:blueRect
        anchors.left: parent.left   //与窗口左锚线锚定
        anchors.top: parent.top //与窗口顶锚线锚定
        anchors.leftMargin: 25  //左锚边距（与窗口的左边距）
        anchors.topMargin: 25   //顶锚边距（与窗口的顶边距）
    }

    GreenRectangle{
        id:greenRect
        anchors.left: blueRect.right   //绿矩形左锚线与蓝矩形右锚线描定
        anchors.top: blueRect.top //绿矩形顶锚线与蓝矩形顶锚线错定
        anchors.leftMargin: 40  //左锚边距（与窗口的左边距）
    }

    RedRectangle{
        id:redRect
        anchors.left: greenRect.right   //红矩形左锚线与绿矩形右锚线锚定
        anchors.top: greenRect.top //红矩形顶锚线与绿矩形顶锚线锚定
        anchors.leftMargin: 40  //左锚边距（与绿矩形的间距）
    }

    /* 对比测试Anchor的性质 */
    RedRectangle {
        id:changingRect1
        anchors.left: parent.left           //矩形changingRect1初始与窗体左锚线锚定
        anchors.top: blueRect.bottom
        anchors.leftMargin: 25
        anchors.topMargin: 25
    }
    RedRectangle {
        id:changingRect2
        anchors.left: parent.left           //changingRect2与changingRect1左对齐
        anchors.top: changingRect1.bottom
        anchors.leftMargin: 25
        anchors.topMargin: 20
    }
    /* 复用按钮 */
    Button {
        width:95;height:35
        anchors.right: redRect.right
        anchors.top: changingRect2.bottom
        anchors.topMargin: 10
    }
}

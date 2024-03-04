import QtQuick 2.12

Rectangle {
    width: 640; height: 480

    Text{   //普通纯文本
        x:200
        y:300
        color: "green"  //设置颜色
        font.family: "Helvetica"    //设置字体
        font.pointSize: 24  //设置字号
        text:"Hello Qt Quick1!"  //输出文字内容
    }

    Text{   //富文本
        x:60
        y:100
        color: "green"  //设置颜色
        font.family: "Helvetica"    //设置字体
        font.pointSize: 24  //设置字号
        text:"<b>Hello</b> <i>Qt Quick2!</i>"
    }

     Text{   //带样式的文本
        x:60
        y:180
        color: "green"  //设置颜色
        font.family: "Helvetica"    //设置字体
        font.pointSize: 24  //设置字号
        style: Text.Outline; styleColor: "blue"
        text:"Hello Qt Quick3!"
    }

     Text{   //带省略的文本
        width: 200  //限制文本的宽度
        color: "green"  //设置颜色
        font.family: "Helvetica"    //设置字体
        font.pointSize: 24  //设置字号
        horizontalAlignment: Text.AlignLeft //在窗口左对齐
        verticalAlignment: Text.AlignTop    //在窗口顶端对齐
        elide: Text.ElideRight
        text:"Hello Qt Quick4!"
    }

     Text{   //换行的文本
        width: 200  //限制文本宽带
        y:30
        color: "green"  //设置颜色
        font.family: "Helvetica"    //设置字体
        font.pointSize: 24  //设置字号
        horizontalAlignment:Text.AlignLeft
        wrapMode:Text.WrapAnywhere
        text:"Hello Qt Quick5!"
    }
}

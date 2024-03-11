import QtQuick 2.7
import QtQuick.Controls
import QtQuick.Layouts
import Qt5Compat.GraphicalEffects   //导入图像特效元素库

Item {
    width: 890
    height: 460
    /*定义属性别名,为在main.qml中引用各个控件*/
    property alias img: img  //图像元素
    property alias desat: desat  //特效元素（控制色彩饱和度）
    property alias size1: size1 //尺寸滑动条
    property alias colourful: colourful //彩色开关
    property alias btn: btn  //灰度值按钮
    property alias progreBar: progreBar  //进度条

    Image{  //显示图片
        id:img
        x:10;y:10
        width: 614.4
        height: 384
        source: "images/Mermaid.jpg"
        fillMode: Image.Stretch //设置为拉伸模式才能调整尺寸
        clip: true
    }

    BusyIndicator {
     x: 317.2; y: 202
     running: image.width<614.4*0.4 //当画面宽度缩为原来的 0.4 时运行
    }

    Desaturate{ //"饱和度"特效元素
        id:desat
        anchors.fill: img
        source:img
    }

    RowLayout{  //行布局
        anchors.left: img.left  //与画面左描定
        y:399
        spacing: 5
        Label{
            text: "尺寸"
        }
        Slider{ //滑动条
            id:size1
            from: 0.1
            to:1.0
            stepSize: 0.1   //步进值
            value: 1.0  //初始值
        }
        Label{
            text: "彩色"
        }
        Switch{     //开关
            id:colourful
            checked: true   //初始状态未开启
        }
        Button{
            id:btn
            text: "灰度值>>"
        }
        ProgressBar{    //进度条
            id:progreBar
        }
    }

    ColumnLayout{   //列布局
        anchors.top: img.top    //与画面顶部锚定
        x:629.4
        spacing: 10
        RowLayout{
           spacing: 5
           Label{
                text:"美人鱼"
                font.pixelSize: 14
                font.bold: true
           }
           SpinBox{
               id:age
               value: 16
               from: 4
               to:24
               font.pixelSize: 14
           }

           Text {
                text: "岁" // 添加单位标签
           }
        }

        Label{
            anchors.horizontalCenter: img.right
            //文字与日历居中对齐
            text: "生日"
            font.pixelSize: 14
            font.bold: true
            color: "magenta"    //品红色
        }

        // Calendar{
        //      id:birthday
        // //     visibleYear: 2017 - age.value
        // //     visibleMonth: 8
        // }
        ColumnLayout {
            DayOfWeekRow {
                locale: grid.locale
                Layout.fillWidth: true
            }

            MonthGrid {
                id: grid
                month: Calendar.March
                year: 2024 - age.value
                locale: Qt.locale("en_US")
                Layout.fillWidth: true

                delegate: Text {
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    opacity: model.month === control.month ? 1 : 0
                    text: model.day
                    font: control.font

                required property var model
                }
            }
        }

    }

}

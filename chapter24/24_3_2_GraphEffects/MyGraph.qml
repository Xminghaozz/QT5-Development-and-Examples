import QtQuick 2.15
import Qt5Compat.GraphicalEffects

Rectangle {
    width: animg.width
    height: animg.height
    AnimatedImage{  //显示gif图像元素
        id:animg
        source: "images/insect.gif"    //图像路径
    }
    BrightnessContrast{
        id:bright
        anchors.fill: animg
        source:animg
    }
    SequentialAnimation{    //定义串行组合动画
        id:imgAnim
        NumberAnimation{    //用动画调整亮度
            target: bright
            property: "brightness"
            to:-0.5
            duration: 3000
        }
          NumberAnimation {				//用动画设置对比度
            target: bright
            property: "contrast"
            to: 0.25					//对比度增强
            duration: 2000
        }
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            imgAnim.running = true		//单击图像开启动画
        }
    }

}

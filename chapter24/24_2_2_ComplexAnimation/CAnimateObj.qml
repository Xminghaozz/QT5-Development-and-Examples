import QtQuick 2.7  //／使用最新 QtQuick 2.7 以支持 Animator 元素

Rectangle {
    id:rect
    width: 240
    height: 300
    color: "blue"

    SequentialAnimation on x{
        id:rectAnim
        running: false  //初始时关闭动画
        loops:Animation.Infinite
        /*实现往返运动*/
        NumberAnimation{from: 0;to:500;duration: 8000;easing.type: Easing.InOutQuad}
        NumberAnimation{from: 500;to:0;duration: 8000;easing.type: Easing.InOutQuad}

        PauseAnimation {
            duration: 1000
        }

    }
    Image {
        id: img
        source: "images/zhou.jpg"
        anchors.horizontalCenter: parent.horizontalCenter
        //照片沿垂直中线下落
        y:0     //初始时位于顶端
        scale: 0.1  //大小为原尺寸的1/10
        opacity: 0  //透明度为0 不可见
        rotation: 45    //初始放置的角度
    }

   SequentialAnimation {
        id: imgAnim
        loops: Animation.Infinite
        ParallelAnimation {
            ScaleAnimator { target: img; to: 1; duration: 1500 }
            OpacityAnimator { target: img; to: 1; duration: 2000 }
            RotationAnimator { target: img; to: 360; duration: 1500 }
            NumberAnimation {
                target: img
                property: "y"
                to: rect.height - img.height	//运动到矩形区的底部
                easing.type: Easing.OutBounce   //为造成照片落地后又“弹起”的效果
                duration: 5000
            }
        }
        PauseAnimation { duration: 2000 }
        ParallelAnimation {                     //重回初始状态
            NumberAnimation {
                target: img
                property: "y"
                to: 0
                easing.type: Easing.OutQuad
                duration: 1000
            }
            OpacityAnimator { target: img; to: 0; duration: 1000 }
        }
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            rectAnim.running = true             //开启水平方向（矩形往返）动画
            imgAnim.running = true              //开启垂直方向（照片掉落）动画
        }
    }
}

import QtQuick 2.7

Window {
    width: 900
    height: 500
    visible: true
    title: qsTr("Mermaid")

     MainForm {
        anchors.fill: parent
        size1.onValueChanged: {			//拖动滑块所要执行的代码
            var scale = size1.value;		//变量获取缩放比率
            img.width = 614.4*scale;	//宽度缩放
            img.height = 384*scale;		//高度缩放
        }
        colourful.onCheckedChanged: {	//开关切换彩色/黑白
            desat.desaturation = colourful.checked ? 0.0 : 1.0
        }
        btn.onClicked: {				//单击“灰度值>>”按钮所要执行的代码
            if(desat.desaturation < 0.9) {	//若灰度<0.9，则继续增加（变灰）
                desat.desaturation += 0.1;
            }else {						//重新变回彩色
                desat.desaturation = 0.0;
            }
            progreBar.value = desat.desaturation;//进度条的进度与灰度同步改变
        }
    }
}

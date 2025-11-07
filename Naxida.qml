import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15

Window {
    id: naxida
    width: 200
    height: 200
    visible: true
    color: "transparent"
    flags: Qt.FramelessWindowHint
    title: "Menu"
    Material.theme: Material.Dark
    Material.accent: Material.Blue

    Component.onCompleted: {
        handler.setWindowTranparent(naxida)
        handler.startRotateImage(naxida_image)
        handler.disableWindowMaximum(naxida)
    }

    Rectangle {
        id: root
        anchors.fill: parent
        color: "transparent"

        MouseArea {
            anchors.fill: parent
            onPressed: naxida.startSystemMove()
            hoverEnabled: true
                onEntered: {
                }

                onExited: {
                }
        }

        Image {
            id: naxida_image
            width: 200
            height: 200
            anchors.centerIn: parent
            source: "file://"+appPath+"/assets/nxd.png"

            Component.onCompleted: {
                //naxidaHandler.setNaxidaImg(naxida_image)
            }
        }
    }
}

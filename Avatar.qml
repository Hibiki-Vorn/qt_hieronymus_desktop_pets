import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15

Window {
    id: avatar
    width: 300
    height: 300
    visible: true
    color: "transparent"
    flags: Qt.FramelessWindowHint
    title: "Menu"
    Material.theme: Material.Dark
    Material.accent: Material.Blue

    Component.onCompleted: {
        handler.setWindowTranparent(avatar)
        handler.startRotateImage(avatr_image)
        handler.disableWindowMaximum(avatar)
    }

    Rectangle {
        id: root
        anchors.fill: parent
        color: "transparent"

        MouseArea {
            anchors.fill: parent
            onPressed: avatar.startSystemMove()
            hoverEnabled: true
                onEntered: {
                    avatr_image.shouldRotate = false
                }

                onExited: {
                    avatr_image.shouldRotate = true
                    handler.startRotateImage(avatr_image)
                }
        }

        Image {
            id: avatr_image
            width: 200
            height: 200
            anchors.centerIn: parent
            source: "file://"+appPath+"/assets/logo.png"

            property bool shouldRotate: false
            property int currentAngle: 0

            transform: Rotation {
                id: rot
                origin.x: avatr_image.width/2
                origin.y: avatr_image.height/2
                angle: avatr_image.currentAngle
            }

        }


    }
}

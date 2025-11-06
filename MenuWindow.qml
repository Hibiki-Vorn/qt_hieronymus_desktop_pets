import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15
import "."

Window {
    id: menuWindow
    title: "Menu"
    width: 305
    height: 500
    visible: false
    Material.theme: Material.Dark
    Material.accent: Material.Blue
    color: Material.background

    Component.onCompleted:{
        handler.disableWindowMaximum(menuWindow)
        handler.setWindowIcon(menuWindow, ":/qt/qml/qt_hieronymus_app/burger.svg")
    }

    Avatar {
        id: avatar
        visible: false
    }

    Column {
        anchors.centerIn: parent
        spacing: 15

        Rectangle {
            width: 200
            height: 240
            radius: 20
            color: "#2E2E2E" // Material.backgroundDimColor
            border.color: "#4A4A4A"
            border.width: 1

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                cursorShape: Qt.PointingHandCursor
                onClicked: avatar.visible = !avatar.visible
                onEntered: logoImage.opacity = 0.8
                onExited: logoImage.opacity = 1.0
            }

            Column {
                anchors.centerIn: parent
                spacing: 12
                anchors.horizontalCenter: parent.horizontalCenter

                Item {
                    width: 160
                    height: 160

                    Image {
                        id: logoImage
                        anchors.fill: parent
                        source: "logo.svg"
                        fillMode: Image.PreserveAspectFit
                    }
                }

                Text {
                    width: parent.width
                    text: qsTr("Hieronymus")
                    font.bold: true
                    font.pixelSize: 22
                    color: "#FFFFFF"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }
        }
    }
}

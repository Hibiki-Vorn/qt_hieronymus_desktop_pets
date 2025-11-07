import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15
import "."

ApplicationWindow {
    id: mainWindow
    title: "Hieronymus"
    Material.theme: Material.Dark
    Material.accent: Material.Blue
    color: Material.background
    visible: true
    width: 305
    height: 500
    minimumWidth: 305
    maximumWidth: 305
    minimumHeight: 500
    maximumHeight: 500

    Component.onCompleted: {
        handler.disableWindowMaximum(mainWindow)
        handler.setWindowIcon(mainWindow, "assets/logo.png")
    }

    MenuWindow {
        id: menuWindow
        visible: false
    }

    Column {
        anchors.centerIn: parent
        spacing: 10

        Item {
            width: 230
            height: 200

            Image {
                source: "file://"+appPath+"/assets/logo.svg"
                smooth: true
                width: 200
                height: 200
                anchors.centerIn: parent
            }
        }

        Item {
            width: 230
            height: 30
            Text {
                font.bold: true
                color: "#FFFFFF"
                font.pixelSize: 19
                anchors.centerIn: parent
                text: qsTr("Hieronymus Desktop Pets")
            }
        }

        Item {
            height: 70
            width: 230
            Button {
                height: 60
                width: 180
                font.bold: true
                font.pixelSize: 17
                text: "Open App Now"
                anchors.centerIn: parent
                onClicked: {
                    menuWindow.visible = !menuWindow.visible
                }
            }
        }
    }
}


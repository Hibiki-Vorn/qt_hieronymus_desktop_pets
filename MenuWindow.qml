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
        id:avatar
        visible: false
    }

    Column {
        anchors.centerIn: parent
        spacing: 10



        Image {
            width: 100
            height: 100
            source: "logo.svg"
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        avatar.visible = !avatar.visible
                    }
                }
        }
    }
}

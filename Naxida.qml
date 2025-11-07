import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15

ApplicationWindow {
    id: naxida
    width: 200
    height: 200
    minimumWidth: 200
    minimumHeight: 200
    maximumWidth: 200
    maximumHeight: 200
    visible: true
    title: "Menu"
    color: "transparent"

    MouseArea {
        anchors.fill: parent
        onPressed: {
            naxida.startSystemMove()
        }
    }

    Image {
        id: naxida_image
        objectName: "naxida_image"
        width: 200
        height: 200
        anchors.centerIn: parent
        source: "file://"+appPath+"/assets/nxd.png"
    }
}

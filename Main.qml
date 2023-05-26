import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15 // ColumnLayout
import QtQuick.Controls 2.15 // Buttons

import com.weathercompass 1.0

Window {
    width: 400
    height: 700
    visible: true
    title: qsTr("Geo Data Viewer")

    property var cities: Controller.cities

    Connections {
        target: Controller
        onParsingFinished: loadingMessage.text = "Loading Completed"
    }

    Text {
        id: title
        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
        }

        text: "Geo Data Viewer"
        horizontalAlignment: Text.AlignCenter
    }

    Text {
        id: loadingMessage
        anchors {
            top: title.bottom
            left: parent.left
            right: parent.right
        }

        text: "Loading ..."
        horizontalAlignment: Text.AlignCenter
    }

    Text {
        id: citiesCount
        text: "Information about " + cities.length + " cities has bene acquired"
        anchors {
            top: loadingMessage.bottom
            left: parent.left
            right: parent.right
        }

        visible: cities.length !== 0
    }

}

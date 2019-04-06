import QtQuick.Controls 2.5
import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtGraphicalEffects 1.12

import SAK.Controls 1.0

Item {
    id: root

    ScrollView {
        width: parent.width
        height: parent.height
        clip: true

        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
//        ScrollBar.horizontal.interactive: false
//        ScrollBar.vertical.interactive: false

        ColumnLayout {
            width: root.width
            spacing: 30

            Item {width: 1; height: 1}

            Repeater {
                model: 10

                GroupBox {
                    id: groupBox
                    title: qsTr("关于")

                    Layout.preferredWidth: root.width*0.7
                    Layout.alignment: Qt.AlignHCenter

                    ColumnLayout {
                        anchors.fill: parent
                        CheckBox { text: qsTr("E-mail") }
                        CheckBox { text: qsTr("Calendar") }
                        CheckBox { text: qsTr("Contactdddddddddddddddddddddddddddddds") }
                    }
                }
            }
        }
    }
}

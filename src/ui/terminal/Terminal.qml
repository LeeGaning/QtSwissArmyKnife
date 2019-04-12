import QtQuick.Controls 2.5
import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

import SAK.Controls 1.0

Item {
    id: root

    property var _messageManager: AppMessageManager

    ScrollView {
        width: parent.width
        height: parent.height

        ListView {
            anchors.fill: parent
            spacing: 5
            model: _messageManager.appMessages

            delegate: RowLayout{
                spacing: 10
                width: root.width

                property AppMessage appMessage: modelData

                Label {
                    id: timeLabel
                    text: parent.appMessage.msgTime
                    color: parent.appMessage.timeColor
                    verticalAlignment: Qt.AlignVCenter
                }

                Label {
                    id: msgLabel
                    text: parent.appMessage.msg;
                    color: parent.appMessage.msgColor
                    wrapMode: Text.WrapAnywhere
                    Layout.fillWidth: true
                }
            }
        }
    }
}

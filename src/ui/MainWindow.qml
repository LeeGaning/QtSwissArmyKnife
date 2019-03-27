import QtQuick.Controls 2.5
import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

import SAK.Controls 1.0
ApplicationWindow {
    id: window
    width: 1024
    height: 600
    visible:true

    property ToolBarController _toolBarController: SAKApp.toolBarController

    ButtonGroup {id: toolButtonGround}

    Item {
        anchors.fill: parent

        Item {
            width: parent.width
            height: 64

            RowLayout {
                anchors.fill: parent

                Repeater {
                    model: _toolBarController.devices

                    ToolButton {
                        width: 64
                        height: 64
                        text: _toolButtonController.title
                        icon.source: _toolButtonController.iconUrl
                        checkable: true
                        ButtonGroup.group: toolButtonGround

                        Component.onCompleted: {
                            if (index == 0){
                                checked = true
                            }
                        }

                        property ToolButtonController _toolButtonController: modelData
                    }
                }

                Item {
                    Layout.fillWidth: true
                }

                Repeater {
                    model: _toolBarController.others

                    ToolButton {
                        width: 64
                        height: 64
                        text: _toolButtonController.title
                        icon.source: _toolButtonController.iconUrl
                        checkable: true
                        ButtonGroup.group: toolButtonGround

                        property ToolButtonController _toolButtonController: modelData
                    }
                }
            }

            Rectangle {
                width: parent.width
                height: 1
                anchors.bottom: parent.bottom
            }
        }   /// Item (ToolBar)
    }
 }

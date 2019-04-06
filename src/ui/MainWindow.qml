import QtQuick.Controls 2.5
import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

import SAK.Controls 1.0
ApplicationWindow {
    id: root
    width: 1024
    height: 600
    visible:true

    property ToolBarController _toolBarController: SAKApp.toolBarController
    property string _centerAreaPageUrl: ""

    ButtonGroup {id: toolButtonGround}

    Item {
        anchors.fill: parent

        ToolBar {
            id: toolBar
            width: parent.width
            height: 48

            ScrollView {
                anchors.left: parent.left
                anchors.right: rightButtons.left
                height: parent.height
                clip: true
                ScrollBar.vertical.policy: ScrollBar.AlwaysOff
                ScrollBar.vertical.interactive: false

                RowLayout {
                    height: toolBar.height
                    Repeater {
                        model: _toolBarController.devices

                        ToolButton {
                            id: toolButton
                            text: _toolButtonController.title
                            icon.source: _toolButtonController.iconUrl
                            checkable: true
                            ButtonGroup.group: toolButtonGround
                            Layout.alignment: Qt.AlignVCenter

                            property ToolButtonController _toolButtonController: modelData

                            Component.onCompleted: {
                                if (index == 0){
                                    checked = true
                                    _centerAreaPageUrl = _toolButtonController.pageUrl
                                }
                            }

                            onClicked: {
                                _centerAreaPageUrl = _toolButtonController.pageUrl
                            }
                        }
                    }

                    Item {
                        height: 1
                        Layout.fillWidth: true
                    }
                }
            }

            RowLayout {
                id: rightButtons
                anchors.right: parent.right
                height: toolBar.height
                Repeater {
                    model: _toolBarController.others
                    ToolButton {
                        text: _toolButtonController.title
                        icon.source: _toolButtonController.iconUrl
                        checkable: true
                        ButtonGroup.group: toolButtonGround

                        property ToolButtonController _toolButtonController: modelData

                        onClicked: {
                            _centerAreaPageUrl = _toolButtonController.pageUrl
                        }
                    }
                }
            }
        }   /// Item (ToolBar)


        Item {
            id: centerArea

            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: toolBar.bottom
            anchors.bottom: parent.bottom

            Loader {
                anchors.fill: parent
                source: _centerAreaPageUrl
            }
        }
    }
 }

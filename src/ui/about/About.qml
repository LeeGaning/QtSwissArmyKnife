import QtQuick.Controls 2.5
import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtGraphicalEffects 1.12

import SAK.Controls 1.0

Item {
    id: root

    About {id: _aboutController}

    ScrollView {
        width: parent.width
        height: parent.height
        clip: true

        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff

        ColumnLayout {
            width: root.width
            spacing: 30

            Item {width: 1; height: 1}

            Repeater {
                model: _aboutController.categories

                GroupBox {
                    id: groupBox
                    title: modelData
                    Layout.preferredWidth: root.width*0.7
                    Layout.alignment: Qt.AlignHCenter

                    property string category: modelData

                    Grid {
                        anchors.fill: parent
                        columns: 3
                        columnSpacing: 10
                        rowSpacing: 10

                        Repeater {
                            id: items
                            model: _aboutController.items(groupBox.category)

                            Label {
                                text: modelData

                                MouseArea {
                                    anchors.fill: parent
                                    visible: _aboutController.isButton(modelData)
                                    cursorShape: Qt.PointingHandCursor

                                    onClicked: {
                                        if (_aboutController.isButton(modelData)){
                                            _aboutController.executeAction(modelData, items.model[index-1])
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

            GroupBox {
                title: _aboutController.historyTitle
                Layout.preferredWidth: root.width*0.7
                Layout.alignment: Qt.AlignHCenter

                TextArea {
                    Layout.columnSpan: 3
                    text: _aboutController.history
                    readOnly: true
                    selectByMouse: true
                }
            }
        }
    }
}

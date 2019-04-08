/*
* The file is encoding with utf-8 (with BOM)
*
* I write the comment with English, it's not because that I'm good at English,
* but for "installing B".
*
* Copyright (C) 2018-2018 wuhai persionnal. All rights reserved.
*/
#ifdef _MSC_VER
#pragma execution_character_set("utf-8")
#endif

#include "SAKToolButton.h"

SAKToolButton::SAKToolButton(SAKGlobal::ToolButtonType type, QObject* parent)
    :QObject (parent)
    ,buttonType(type)
{
    init();
}

void SAKToolButton::init()
{
    switch (buttonType) {
    case SAKGlobal::TypeTool:
        _iconUrl = "qrc:/images/tool.png";
        _title = tr("工具");
        _pageUrl = "qrc:/ui/Tools.qml";
        break;
    case SAKGlobal::TypeAbout:
        _iconUrl = "qrc:/images/about.png";
        _title = tr("关于");
        _pageUrl = "qrc:/ui/about/About.qml";
        break;
    case SAKGlobal::TypeSetting:
        _iconUrl = "qrc:/images/setting.png";
        _title = tr("设置");
        _pageUrl = "qrc:/ui/Setting.qml";
        break;
    case SAKGlobal::TypeTerminal:
        _iconUrl = "qrc:/images/terminal.png";
        _title = tr("终端");
        _pageUrl = "qrc:/ui/terminal/Terminal.qml";
        break;
    case SAKGlobal::TypeUdpDebug:
        _iconUrl = "qrc:/images/udp.png";
        _title = tr("UDP");
        _pageUrl = "qrc:/ui/Tools.qml";
        break;
    case SAKGlobal::TypeTcpDebug:
        _iconUrl = "qrc:/images/tcp.png";
        _title = tr("TCP");
        _pageUrl = "qrc:/ui/about/About.qml";
        break;
    case SAKGlobal::TypeBlueToothDebug:
        _iconUrl = "qrc:/images/bluetooth.png";
        _title = tr("蓝牙");
        _pageUrl = "qrc:/ui/Setting.qml";
        break;
    case SAKGlobal::TypeSerialPortDebug:
        _iconUrl = "qrc:/images/serialport.png";
        _title = tr("串口");
        _pageUrl = "qrc:/ui/terminal/Terminal.qml";
        break;
    }
}

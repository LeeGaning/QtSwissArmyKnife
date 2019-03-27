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
        break;
    case SAKGlobal::TypeAbout:
        _iconUrl = "qrc:/images/about.png";
        _title = tr("关于");
        break;
    case SAKGlobal::TypeSetting:
        _iconUrl = "qrc:/images/setting.png";
        _title = tr("设置");
        break;
    case SAKGlobal::TypeTcpClient:
        _iconUrl = "qrc:/images/net.png";
        _title = tr("TCP客户端");
        break;
    case SAKGlobal::TypeTcpServer:
        _iconUrl = "qrc:/images/server.png";
        _title = tr("TCP服务器");
        break;
    case SAKGlobal::TypeUdpClient:
        _iconUrl = "qrc:/images/net.png";
        _title = tr("UDP客户端");
        break;
    case SAKGlobal::TypeBlueToothClient:
        _iconUrl = "qrc:/images/bluetooth.png";
        _title = tr("蓝牙客户端");
        break;
    case SAKGlobal::TypeBlueToothServer:
        _iconUrl = "qrc:/images/bluetooth.png";
        _title = tr("蓝牙服务器");
        break;
    case SAKGlobal::TypeSerialPortAssistant:
        _iconUrl = "qrc:/images/serialport.png";
        _title = tr("串口助手");
        break;
    }
}

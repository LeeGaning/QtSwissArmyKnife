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

#include <QVariant>
#include <QDebug>

#include "SAKGlobal.h"
#include "SAKToolBar.h"
#include "SAKToolButton.h"

SAKToolBar::SAKToolBar(QObject* parent)
    :QObject (parent)
{
    initDevices();
    initOthers();
}

void SAKToolBar::initDevices()
{
    SAKToolButton* button = nullptr;

    button = new SAKToolButton(SAKGlobal::TypeTcpDebug, this);
    _devicesToolButton.append(button);


    button = new SAKToolButton(SAKGlobal::TypeUdpDebug, this);
    _devicesToolButton.append(button);

    button = new SAKToolButton(SAKGlobal::TypeBlueToothDebug, this);
    _devicesToolButton.append(button);

    button = new SAKToolButton(SAKGlobal::TypeSerialPortDebug, this);
    _devicesToolButton.append(button);

    QVariant temp;
    for(auto var:_devicesToolButton){
        temp = QVariant::fromValue(var);
        _devices.append(temp);
    }
}

void SAKToolBar::initOthers()
{
    SAKToolButton* button = nullptr;

    button = new SAKToolButton(SAKGlobal::TypeTool, this);
    _othersToolButton.append(button);

    button = new SAKToolButton(SAKGlobal::TypeTerminal, this);
    _othersToolButton.append(button);

    button = new SAKToolButton(SAKGlobal::TypeSetting, this);
    _othersToolButton.append(button);

    button = new SAKToolButton(SAKGlobal::TypeAbout, this);
    _othersToolButton.append(button);

    QVariant temp;
    for(auto var:_othersToolButton){
        temp = QVariant::fromValue(var);
        _others.append(temp);
    }
}

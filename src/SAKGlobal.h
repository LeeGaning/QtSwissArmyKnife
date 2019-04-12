/*
* The file is encoding with utf-8 (with BOM)
*
* I write the comment with English, it's not because that I'm good at English,
* but for "installing B".
*
* Copyright (C) 2018-2018 wuhai persionnal. All rights reserved.
*/
#ifndef SAKGLOBAL_H
#define SAKGLOBAL_H

#include <QObject>

class SAKGlobal:public QObject
{
    Q_OBJECT
public:
    SAKGlobal(QObject* parent = nullptr);

    enum ToolButtonType {
        TypeTool,
        TypeAbout,
        TypeSetting,
        TypeTerminal,
        TypeUdpDebug,
        TypeTcpDebug,
        TypeBlueToothDebug,
        TypeSerialPortDebug
    };
    Q_ENUM(ToolButtonType)

    /**
     * @brief logFile   -- 获取日志文件（全路径）
     * @return          -- 日志文件全路径
     */
    static QString logFile();
};

#endif

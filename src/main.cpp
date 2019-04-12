/*******************************************************************************
* The file is encoding with utf-8 (with BOM)
*
* I write the comment with English, it's not because that I'm good at English,
* but for "installing B".
*
* Copyright (C) 2018-2018 wuhai persionnal. All rights reserved.
*******************************************************************************/
#include "SAKApplication.h"

#include <QMessageLogContext>
#include <QDateTime>
#include <QDebug>
#include <QSettings>
#include <QLoggingCategory>

#include "AppMessageManager.hpp"

int main(int argc, char *argv[])
{
    /*
     * debug版本直不重定向消息，release版本将消息输出到UI显示并保存到日志文件
     */
#if 1
    qInstallMessageHandler(AppMessageManager::messageRedirection);
#endif

    /*
     * 启用高分屏适配
     */
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    SAKApplication a(argc, argv);
    qInfo("Application started!");
    return a.exec();
}

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

#include "AppMessageOutput.hpp"
#include "SAKGlobal.h"

#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QMetaEnum>

AppMessageOutput::AppMessageOutput(QObject *parent)
    :QThread (parent)
{
    moveToThread(this);
}

void AppMessageOutput::outputMessage(QString msg)
{
    QFile file(SAKGlobal::logFile());

    /*
     * 日志文件大于1M则清空
     */
    if (file.size() > 10240){
        file.open(QFile::ReadWrite | QFile::Truncate);
        file.close();
    }

    /*
     * 消息内容写入文件
     */
    if (file.open(QFile::WriteOnly | QFile::Append | QFile::Text)){
        QTextStream outstream(&file);
        outstream << msg << endl;
        file.close();
    }else{
        Q_ASSERT_X(false, __FUNCTION__, "Can not open log file.");
    }
}

void AppMessageOutput::run()
{
    exec();
}



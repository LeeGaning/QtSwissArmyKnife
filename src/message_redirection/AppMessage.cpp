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

#include "AppMessage.hpp"
#include <QDateTime>

AppMessage::AppMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg, QObject *parent)
    :QObject (parent)
{
    _msgColor = messageColor(type);
    _msg = QString(context.category) + ":" + msg;
    _msgTime = QDateTime::currentDateTime().toString("hh:mm:ss");
    _timeColor = QString("silver");
}

QString AppMessage::messageColor(QtMsgType type)
{
    QString string;
    switch (type) {
    case QtDebugMsg:
    case QtInfoMsg:
        string =  QString("green");
        break;
    case QtWarningMsg:
    case QtCriticalMsg:
    case QtFatalMsg:
        string = QString("red");
        break;
    }

    return string;
}

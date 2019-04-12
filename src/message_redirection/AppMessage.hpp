/*
* The file is encoding with utf-8 (with BOM)
*
* I write the comment with English, it's not because that I'm good at English,
* but for "installing B".
*
* Copyright (C) 2018-2018 wuhai persionnal. All rights reserved.
*/
#ifndef APPMESSAGE_H
#define APPMESSAGE_H

#include <QObject>

class AppMessage:public QObject
{
    Q_OBJECT
public:
    Q_PROPERTY(QString msgColor     READ msgColor   CONSTANT)
    Q_PROPERTY(QString msgTime      READ msgTime    CONSTANT)
    Q_PROPERTY(QString msg          READ msg        CONSTANT)
    Q_PROPERTY(QString timeColor    READ timeColor  CONSTANT)

    /**
     * @brief AppMessage    -- 构造函数， nothing to say...
     * @param type          -- Qt消息类型
     * @param context       -- 消息上下文
     * @param msg           -- 消息具体内容
     */
    AppMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg, QObject *parent = nullptr);
private:
    QString _msgColor;
    QString msgColor(){return _msgColor;}

    QString _msgTime;
    QString msgTime(){return _msgTime;}

    QString _msg;
    QString msg(){return _msg;}

    QString _timeColor;
    QString timeColor(){return _timeColor;}
private:
    QString messageColor(QtMsgType type);
};

#endif

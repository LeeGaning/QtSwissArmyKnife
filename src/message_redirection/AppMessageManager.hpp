/*
* The file is encoding with utf-8 (with BOM)
*
* I write the comment with English, it's not because that I'm good at English,
* but for "installing B".
*
* Copyright (C) 2018-2018 wuhai persionnal. All rights reserved.
*/
#ifndef APPMESSAGEMANAGER_H
#define APPMESSAGEMANAGER_H

#include <QObject>
#include <QVariantList>

class AppMessage;
class AppMessageOutput;

class AppMessageManager:public QObject
{
    Q_OBJECT
public:
    Q_PROPERTY(QVariantList appMessages READ appMessages NOTIFY appMessagesChanged)

    /**
     * @brief AppMessageManager -- 构造函数，nothing to say...
     * @param parent            -- 父控件，用于资源管理
     */
    AppMessageManager(QObject *parent = nullptr);

    /**
     * @brief messageRedirection    -- 消息重定向
     * @param type                  -- Qt消息类型
     * @param context               -- 消息上下文
     * @param msg                   -- 消息具体内容
     */
    static void messageRedirection(QtMsgType type, const QMessageLogContext &context, const QString &msg);

    static AppMessageManager *instance;
private:
    QList<AppMessage*> _appMessages;
    QVariantList appMessages();
private:
    AppMessageOutput *appMessageOutput;

    /**
     * @brief qtMsgTypeString   -- 消息类型（调试、警告...）
     * @param type              -- Qt消息类型
     * @return                  -- 消息类型（字符串，便于理解）
     */
    QString qtMsgTypeString(QtMsgType type);

    /**
     * @brief cookingMsg    -- 将消息加工处理（便于阅读）
     * @param type          -- Qt消息类型
     * @param context       -- 消息上下文
     * @param msg           -- 消息具体内容
     */
    void cookingMsg(QtMsgType type, const QMessageLogContext &context, const QString &msg);

    /**
     * @brief addMessage    -- 添加消息，用于在ui显示（终端显示）
     * @param type          -- Qt消息类型
     * @param context       -- 消息上下文
     * @param msg           -- 消息具体内容
     */
    void addMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg);
signals:
    void outputMessage(QString cookedMsg);
    void appMessagesChanged();
};

#endif

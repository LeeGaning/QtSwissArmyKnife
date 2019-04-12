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

#include "AppMessageManager.hpp"
#include "AppMessageOutput.hpp"
#include "SAKGlobal.h"
#include "AppMessage.hpp"

#include <QFile>
#include <QDateTime>
#include <QQmlEngine>

QObject *appMessageManagerSingleton(QQmlEngine *qmlEngine, QJSEngine *jsEngine)
{
    Q_UNUSED(qmlEngine);
    Q_UNUSED(jsEngine);

    return AppMessageManager::instance;
}

AppMessageManager* AppMessageManager::instance = nullptr;
AppMessageManager::AppMessageManager(QObject *parent)
    :QObject (parent)
    ,appMessageOutput (nullptr)
{
    instance = this;

    qmlRegisterUncreatableType<AppMessage>  ("SAK.Controls", 1, 0, "AppMessage", "Uncreatable object(AppMessage).");
    qmlRegisterSingletonType<AppMessageManager>  ("SAK.Controls", 1, 0, "AppMessageManager", appMessageManagerSingleton);

    appMessageOutput = new AppMessageOutput;
    connect(this, &AppMessageManager::outputMessage, appMessageOutput, &AppMessageOutput::outputMessage);
    appMessageOutput->start();
}

void AppMessageManager::messageRedirection(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    if (instance){
        instance->addMessage(type, context, msg);
        emit instance->cookingMsg(type, context, msg);
    }  
}

void AppMessageManager::cookingMsg(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QString category = qtMsgTypeString(type);

    QString log = QDateTime::currentDateTime().toString("yyyyMMdd-hh:mm:ss");
    log.append(" ");
    log.append(QString(category));
    log.append(" ");
    log.append(context.category);
    log.append(":");
    log.append(msg);

    emit outputMessage(log);
}

QString AppMessageManager::qtMsgTypeString(QtMsgType type)
{
    QString string;
    switch (type) {
    case QtDebugMsg:
        string = QString("QtDebugMsg");
        break;
    case QtInfoMsg:
        string =  QString("QtInfoMsg");
        break;
    case QtWarningMsg:
        string = QString("QtWarningMsg");
        break;
    case QtCriticalMsg:
        string = QString("QtCriticalMsg");
        break;
    case QtFatalMsg:
        string = QString("QtFatalMsg");
        break;
    }

    string.resize(12, ' ');
    string.prepend("[");
    string.append("]");

    return string;
}

void AppMessageManager::addMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    while (_appMessages.length() > 500) {
        AppMessage *msgTemp = _appMessages.takeLast();
        msgTemp->deleteLater();
    }

    AppMessage *msgPtr = new AppMessage(type, context, msg, this);
    _appMessages.prepend(msgPtr);
    emit appMessagesChanged();
}

QVariantList AppMessageManager::appMessages()
{
    QVariantList list;

    for (auto var:_appMessages){
        QVariant temp = QVariant::fromValue(var);
        list.append(temp);
    }

    return list;
}

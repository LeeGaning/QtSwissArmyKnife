/*
* The file is encoding with utf-8 (with BOM)
*
* I write the comment with English, it's not because that I'm good at English,
* but for "installing B".
*
* Copyright (C) 2018-2018 wuhai persionnal. All rights reserved.
*/

#ifndef SAKTOOLBUTTON_H
#define SAKTOOLBUTTON_H

#include <QObject>
#include "SAKGlobal.h"

class SAKToolButton:public QObject
{
    Q_OBJECT
public:
    SAKToolButton(SAKGlobal::ToolButtonType type, QObject* parent = nullptr);

    Q_PROPERTY(QString iconUrl  READ iconUrl    CONSTANT)
    Q_PROPERTY(QString pageUrl  READ pageUrl    CONSTANT)
    Q_PROPERTY(QString title    READ title      CONSTANT)
private:
    QString _iconUrl;
    QString iconUrl(){return _iconUrl;}

    QString _pageUrl;
    QString pageUrl(){return _pageUrl;}

    QString _title;
    QString title(){return _title;}

    SAKGlobal::ToolButtonType buttonType;

    void init();
};

#endif

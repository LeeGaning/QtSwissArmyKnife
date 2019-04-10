/*
* The file is encoding with utf-8 (with BOM)
*
* I write the comment with English, it's not because that I'm good at English,
* but for "installing B".
*
* Copyright (C) 2018-2018 wuhai persionnal. All rights reserved.
*/
#ifndef SAKTOOLBAR_H
#define SAKTOOLBAR_H

#include <QObject>
#include <QList>
#include <QVariantList>

class SAKToolButton;

class SAKToolBar:public QObject
{
    Q_OBJECT
public:
    SAKToolBar(QObject* parent = nullptr);

    Q_PROPERTY(QVariantList devices READ devices CONSTANT)
    Q_PROPERTY(QVariantList others READ others CONSTANT)
private:
    QVariantList _devices;
    QList<SAKToolButton*> _devicesToolButton;
    QVariantList devices(){return _devices;}

    QVariantList _others;
    QList<SAKToolButton*> _othersToolButton;
    QVariantList others(){return _others;}
private:
    void initDevices();
    void initOthers();
};

#endif

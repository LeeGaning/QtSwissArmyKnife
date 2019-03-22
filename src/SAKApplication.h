/*******************************************************************************
* The file is encoding with utf-8 (with BOM)
*
* I write the comment with English, it's not because that I'm good at English,
* but for "installing B".
*
* Copyright (C) 2018-2018 wuhai persionnal. All rights reserved.
*******************************************************************************/
#ifndef SAKAPPLICATION_H
#define SAKAPPLICATION_H

#include <QApplication>
#include <QStyleFactory>
#include <QQmlApplicationEngine>

class MainWindow;

class SAKApplication:public QApplication
{
    Q_OBJECT
public:
    SAKApplication(int argc, char **argv);
    ~SAKApplication();
private:
    QQmlApplicationEngine qmlAppEngine;
private:
    void installUI();
};

#endif

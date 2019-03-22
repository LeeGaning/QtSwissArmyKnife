/*******************************************************************************
* The file is encoding with utf-8 (with BOM)
*
* I write the comment with English, it's not because that I'm good at English,
* but for "installing B".
*
* Copyright (C) 2018-2018 wuhai persionnal. All rights reserved.
*******************************************************************************/
#ifdef _MSC_VER
#pragma execution_character_set("utf-8")
#endif

#include "SAKApplication.h"

#include <QDebug>
#include <QSettings>

#include "MainWindow.h"

SAKApplication::SAKApplication(int argc, char **argv)
    :QApplication(argc, argv)
    ,mainWindow(nullptr)
{

    installUI();
}

SAKApplication::~SAKApplication()
{

}

void SAKApplication::installUI()
{
    mainWindow = new MainWindow;
#ifndef Q_OS_ANDROID
    mainWindow->resize(1024, 768);
#endif
    mainWindow->show();
}

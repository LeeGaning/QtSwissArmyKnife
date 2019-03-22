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
#include <QQuickStyle>

SAKApplication::SAKApplication(int argc, char **argv)
    :QApplication(argc, argv)
{

    installUI();
}

SAKApplication::~SAKApplication()
{

}

void SAKApplication::installUI()
{
    qDebug() << QQuickStyle::availableStyles();
    QQuickStyle::setStyle("Material");

    qmlAppEngine.load(QUrl("qrc:/qml/MainWindow.qml"));
}

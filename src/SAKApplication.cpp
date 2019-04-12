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
#include "SAKToolBar.h"
#include "SAKToolButton.h"
#include "About.hpp"
#include "AppMessageManager.hpp"

#include <QDebug>
#include <QSettings>
#include <QQuickStyle>

QObject* applicationInstance(QQmlEngine* qmlEngine, QJSEngine* jsEngine)
{
    Q_UNUSED(jsEngine);

    qmlEngine->setObjectOwnership(sakApp(), QQmlEngine::CppOwnership);
    return sakApp();
}

SAKApplication* sakApp(){return SAKApplication::instance();}

SAKApplication* SAKApplication::_app = nullptr;
SAKApplication::SAKApplication(int argc, char **argv)
    :QApplication (argc, argv)
    ,toolBar (nullptr)
    ,messageManager (nullptr)
{
    _app = this;
    toolBar = new SAKToolBar(this);

    messageManager = new AppMessageManager;

    registerQmlType();
    /// --------------------------------------
    installUI();
}

SAKApplication::~SAKApplication()
{

}

void SAKApplication::installUI()
{
    qDebug() << QQuickStyle::availableStyles();
    QQuickStyle::setStyle("Material");

    qmlAppEngine.load(QUrl("qrc:/ui/MainWindow.qml"));
}

void SAKApplication::registerQmlType()
{
    qmlRegisterType<About>("SAK.Controls", 1, 0, "About");
    qmlRegisterSingletonType<SAKApplication>    ("SAK.Controls", 1, 0, "SAKApp", applicationInstance);

    qmlRegisterUncreatableType<SAKToolBar>      ("SAK.Controls", 1, 0, "ToolBarController", "Can not create the qml type that named SAKToolBar");
    qmlRegisterUncreatableType<SAKToolButton>   ("SAK.Controls", 1, 0, "ToolButtonController", "Can not create the qml type that named SAKToolButton");
}

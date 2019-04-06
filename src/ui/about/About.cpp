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

#include "About.hpp"
#include <QQmlEngine>

About::About(QObject* parent)
    :QObject (parent)
{
    QQmlEngine::setObjectOwnership(this, QQmlEngine::JavaScriptOwnership);
}

void About::initCategory()
{
    categoriesStr.aboutAuthor = tr("关于软件");
    categoriesStr.abouSoftware = tr("软件信息");
}

QStringList About::items(QString categoryName)
{
    if (categoryName.compare(categoriesStr.aboutAuthor) == 0){
        return _authorInfos;
    }else if (categoryName.compare(categoriesStr.abouSoftware) == 0){
        return _softwareInfos;
    }else{
        Q_ASSERT_X(false, __FUNCTION__, "Unknown category name!");
        return QStringList("");
    }
}

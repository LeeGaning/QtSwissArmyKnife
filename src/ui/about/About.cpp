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
#include <QDesktopServices>
#include <QApplication>
#include <QClipboard>
#include <QFile>

#define GITHUB_URL  "https://github.com/Qter1024/QtSwissArmyKnife"
#define GITTEE_URL  "https://gitee.com/woohii/QtSwissArmyKnife"
#define GOGS_URL    "http://gogs.wuhai.pro"
#define BLOG_URL    "http://wuhai.pro"

#define COPY_STR    QObject::tr("复制")
#define VISIT_STR   QObject::tr("访问")

About::About(QObject* parent)
    :QObject (parent)
{
    QQmlEngine::setObjectOwnership(this, QQmlEngine::JavaScriptOwnership);

    initCategory();
    _historyTitle = tr("发布历史");
}

void About::initCategory()
{
    categoriesStr.aboutAuthor = tr("关于软件");
    categoriesStr.abouSoftware = tr("软件信息");
    categoriesStr.othiers = tr("其他信息");
    categoriesStr.resources = tr("相关资源");

    _categories << categoriesStr.aboutAuthor
                << categoriesStr.abouSoftware
                << categoriesStr.othiers
                << categoriesStr.resources;


    _authorInfos << tr("软件作者") << QString("woohii") << COPY_STR
                 << tr("联系邮箱") << QString("woohii@126.com") << COPY_STR
                 << tr("博客主页") << QString(BLOG_URL) << VISIT_STR;

    _softwareInfos << tr("软件版本") << QString("1.0.1") << COPY_STR
                   << QString("Github") << QString(GITHUB_URL) << VISIT_STR
                   << QString("Gitee") << QString(GITTEE_URL) << VISIT_STR
                   << QString("Gogs") << QString(GOGS_URL) << VISIT_STR;

    _others << tr("QQ交流群") << QString("952218522") << COPY_STR;

    _resources << QString("Qt") << QString("http://download.qt.io/official_releases/qt"
                                           "") << VISIT_STR;
}

QStringList About::items(QString categoryName)
{
    if (categoryName.compare(categoriesStr.aboutAuthor) == 0){
        return _authorInfos;
    }else if (categoryName.compare(categoriesStr.abouSoftware) == 0){
        return _softwareInfos;
    }else if (categoryName.compare(categoriesStr.othiers) == 0){
        return _others;
    }else if (categoryName.compare(categoriesStr.resources) == 0){
        return _resources;
    }else{
        Q_ASSERT_X(false, __FUNCTION__, "Unknown category name!");
        return QStringList("");
    }
}

void About::executeAction(QString actionStr, QString str)
{
    if (actionStr.compare(COPY_STR) == 0){
        QApplication::clipboard()->setText(str);
    }else{
        QDesktopServices::openUrl(QUrl(str));
    }
}

bool About::isButton(QString str)
{
    QStringList list;
    list << COPY_STR
         << VISIT_STR;

    if (list.contains(str)){
        return true;
    }else{
        return false;
    }
}

QString About::history()
{
    QFile file(":/fires/history.txt");
    if (file.open(QFile::ReadOnly)){
        QString str = file.readAll();
        file.close();
        return str;
    }else{
        return QString("");
    }
}

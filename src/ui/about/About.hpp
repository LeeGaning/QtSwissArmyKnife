/*
* The file is encoding with utf-8 (with BOM)
*
* I write the comment with English, it's not because that I'm good at English,
* but for "installing B".
*
* Copyright (C) 2018-2018 wuhai persionnal. All rights reserved.
*/
#ifndef ABOUT_H
#define ABOUT_H

#include <QObject>

class About:public QObject
{
    Q_OBJECT
public:
    About(QObject* parent = nullptr);

    Q_PROPERTY(QStringList categories       READ categories     CONSTANT)
    Q_PROPERTY(QString     history          READ history        CONSTANT)
    Q_PROPERTY(QString     historyTitle     READ historyTitle   CONSTANT)

    struct Categories {
        QString aboutAuthor;
        QString abouSoftware;
        QString othiers;
        QString resources;
    };

    Q_INVOKABLE QStringList items(QString categoryName);
    Q_INVOKABLE bool isButton(QString str);
    Q_INVOKABLE void executeAction(QString actionStr, QString str);
private:
    QStringList _categories;
    QStringList categories(){return _categories;}

    QStringList _authorInfos;
    QStringList authorInfos(){return _authorInfos;}

    QStringList _softwareInfos;
    QStringList softwareInfos(){return _softwareInfos;}

    QStringList _others;
    QStringList others(){return _others;}

    QStringList _resources;
    QStringList resources(){return _resources;}

    QString history();

    QString _historyTitle;
    QString historyTitle(){return _historyTitle;}
private:
    struct Categories categoriesStr;

    void initCategory();
};

#endif

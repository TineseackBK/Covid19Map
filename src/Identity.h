#ifndef IDENTITY_H
#define IDENTITY_H

#endif // IDENTITY_H
#pragma once
#include <iostream>
#include <QString>
#include <fstream>
#include "GlobalFile.h"
//#include "GuangZhouMap.h"
#include <cstring>
#include <cmath>
//#include "covidmapsystem.h"
//#include "BaiYunArea.h"
//#include "PanYuArea.h"
//#include "TianHeArea.h"
//#include "CongHuaArea.h"
//#include "HaiZhuArea.h"
//#include "HuaDuArea.h"
//#include "HuangPuArea.h"
//#include "LiWanArea.h"
//#include "NanShaArea.h"
//#include "YueXiuArea.h"
//#include "ZengChengArea.h"
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
using namespace std;

class Identity
{
public:
    QString m_UserName;
    QString m_UserPassword;
    virtual void OpenMenu() = 0;
    virtual void EnterMap() = 0;
    virtual bool IsExist(QString name,QString password) = 0;
};

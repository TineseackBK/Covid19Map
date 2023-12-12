#ifndef AREA_H
#define AREA_H

#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "GlobalFile.h"

using namespace std;

class CovidMap
{
public:
    string m_PlaceName;//地区名称
    int m_ConfirmedCases;//确诊人数
    int m_AboardConfirmedCases;//境外输入人数
    int m_InternalConfirmedCases;//境内输入人数
    int m_LocalConfirmedCases;//本地输入人数
    int m_CovidLevel;//风险等级
    string m_Weather;//天气
    int m_Tempture;//温度
    bool m_IfFourteenDay;//是否14天内有病例

    virtual void ShowMapInfomation() = 0;//展示地图基本信息

    virtual void ShowMapMenu() = 0;//展示地图选项

    virtual bool IsGoThrough() = 0;//是否被途经

    virtual bool InFourteenDay() = 0;//是否有疫情14天内

    virtual string CalculateLevel() = 0;//计算疫情等级

    virtual void ChangeAboardConfirmedCases() = 0; //修改境外输入人数

    virtual void ChangeInternalConfirmedCases() = 0; //修改境内输入人数

    virtual void ChangeLocalConfirmedCases() = 0; //修改本地输入人数

    virtual void ChangeConfirmedCases() = 0; //修改确诊人数

    virtual void ChangeWeather() = 0; //修改天气

};

class GuangZhouMap :
    public CovidMap
{
public:

    GuangZhouMap();
    GuangZhouMap(string placename, int confirmedcases, int aboardconfirmedcases, int Internalconfirmercases, int localconfirmedcases,
        int covidlevel, string weather, int tempture, bool iffourteenday);

    virtual void ShowMapInfomation();//展示地图基本信息

    virtual void ShowMapMenu();//展示地图选项

    virtual bool IsGoThrough();//是否被途经

    virtual bool InFourteenDay();//是否有疫情14天内

    virtual string CalculateLevel();//计算疫情等级

    virtual void ChangeAboardConfirmedCases(); //修改境外输入人数

    virtual void ChangeInternalConfirmedCases(); //修改境内输入人数

    virtual void ChangeLocalConfirmedCases(); //修改本地输入人数

    virtual void ChangeConfirmedCases(); //修改确诊人数

    virtual void ChangeWeather(); //修改天气

    void ShowRegionalMenu();//进入地区菜单

};

class BaiYunArea :
    public GuangZhouMap
{
public:
    string m_StreetName;
    BaiYunArea();
    BaiYunArea(string placename, int confirmedcases, int aboardconfirmedcases, int Internalconfirmercases, int localconfirmedcases,
        int covidlevel, string weather, int tempture, bool iffourteenday, string streetname);

    virtual void ShowMapInfomation();//展示地图基本信息

    virtual void ShowMapMenu();//展示地图选项

    virtual bool IsGoThrough();//是否被途经

    virtual bool InFourteenDay();//是否有疫情14天内

    virtual string CalculateLevel();//计算疫情等级

    virtual void ChangeAboardConfirmedCases(); //修改境外输入人数

    virtual void ChangeInternalConfirmedCases(); //修改境内输入人数

    virtual void ChangeLocalConfirmedCases(); //修改本地输入人数

    virtual void ChangeConfirmedCases(); //修改确诊人数

    virtual void ChangeWeather(); //修改天气

    void ChangeAboardConfirmedCasesWithFirstMap(int confirmedcases, int number , int aod); //链接一级地图修改境外输入人数

    void ChangeInternalConfirmedCasesWithFirstMap(int confirmedcases, int number, int aod); //链接一级地图修改境内输入人数

    void ChangeLocalConfirmedCasesWithFirstMap(int confirmedcases, int number, int aod); //链接一级地图修改本地输入人数

    void ChangeStreetAboardConfirmedCases(); //修改街道境外输入人数

    void ChangeStreetInternalConfirmedCases(); //修改街道境内输入人数

    void ChangeStreetLocalConfirmedCases(); //修改街道本地输入人数

    void ChangeStreetConfirmedCases(); //修改街道确诊人数

    void AddStreet();//添加街道

    void DeleteStreet();//删除街道

    void SearchStreet();//查询街道

    void ShowAllStreet();//显示所有街道

    bool StreetIs_Exist(string name);//判断街道是否存在

    void ShowStreetInfomation();//展示街道基本信息

    void ShowStreetMenu();//展示街道选项

    void ChangeAboardConfirmedCasesWithSecondMap(int confirmedcases, int number, int aod); //链接二级地图修改境外输入人数

    void ChangeInternalConfirmedCasesWithSecondMap(int confirmedcases, int number, int aod); //链接二级地图修改境内输入人数

    void ChangeLocalConfirmedCasesWithSecondMap(int confirmedcases, int number, int aod); //链接二级地图修改本地输入人数
};

class CongHuaArea :
    public GuangZhouMap
{
public:
    string m_StreetName;
    CongHuaArea();
    CongHuaArea(string placename, int confirmedcases, int aboardconfirmedcases, int Internalconfirmercases, int localconfirmedcases,
        int covidlevel, string weather, int tempture, bool iffourteenday, string streetname);

    virtual void ShowMapInfomation();//展示地图基本信息

    virtual void ShowMapMenu();//展示地图选项

    virtual bool IsGoThrough();//是否被途经

    virtual bool InFourteenDay();//是否有疫情14天内

    virtual string CalculateLevel();//计算疫情等级

    virtual void ChangeAboardConfirmedCases(); //修改境外输入人数

    virtual void ChangeInternalConfirmedCases(); //修改境内输入人数

    virtual void ChangeLocalConfirmedCases(); //修改本地输入人数

    virtual void ChangeConfirmedCases(); //修改确诊人数

    virtual void ChangeWeather(); //修改天气

    void ChangeAboardConfirmedCasesWithFirstMap(int confirmedcases, int number, int aod); //链接一级地图修改境外输入人数

    void ChangeInternalConfirmedCasesWithFirstMap(int confirmedcases, int number, int aod); //链接一级地图修改境内输入人数

    void ChangeLocalConfirmedCasesWithFirstMap(int confirmedcases, int number, int aod); //链接一级地图修改本地输入人数

    void ChangeStreetAboardConfirmedCases(); //修改街道境外输入人数

    void ChangeStreetInternalConfirmedCases(); //修改街道境内输入人数

    void ChangeStreetLocalConfirmedCases(); //修改街道本地输入人数

    void ChangeStreetConfirmedCases(); //修改街道确诊人数

    void AddStreet();//添加街道

    void DeleteStreet();//删除街道

    void SearchStreet();//查询街道

    void ShowAllStreet();//显示所有街道

    bool StreetIs_Exist(string name);//判断街道是否存在

    void ShowStreetInfomation();//展示街道基本信息

    void ShowStreetMenu();//展示街道选项

    void ChangeAboardConfirmedCasesWithSecondMap(int confirmedcases, int number, int aod); //链接二级地图修改境外输入人数

    void ChangeInternalConfirmedCasesWithSecondMap(int confirmedcases, int number, int aod); //链接二级地图修改境内输入人数

    void ChangeLocalConfirmedCasesWithSecondMap(int confirmedcases, int number, int aod); //链接二级地图修改本地输入人数
};

class HaiZhuArea :
    public GuangZhouMap
{
public:
    string m_StreetName;
    HaiZhuArea();
    HaiZhuArea(string placename, int confirmedcases, int aboardconfirmedcases, int Internalconfirmercases, int localconfirmedcases,
        int covidlevel, string weather, int tempture, bool iffourteenday, string streetname);

    virtual void ShowMapInfomation();//展示地图基本信息

    virtual void ShowMapMenu();//展示地图选项

    virtual bool IsGoThrough();//是否被途经

    virtual bool InFourteenDay();//是否有疫情14天内

    virtual string CalculateLevel();//计算疫情等级

    virtual void ChangeAboardConfirmedCases(); //修改境外输入人数

    virtual void ChangeInternalConfirmedCases(); //修改境内输入人数

    virtual void ChangeLocalConfirmedCases(); //修改本地输入人数

    virtual void ChangeConfirmedCases(); //修改确诊人数

    virtual void ChangeWeather(); //修改天气

    void ChangeAboardConfirmedCasesWithFirstMap(int confirmedcases, int number, int aod); //链接一级地图修改境外输入人数

    void ChangeInternalConfirmedCasesWithFirstMap(int confirmedcases, int number, int aod); //链接一级地图修改境内输入人数

    void ChangeLocalConfirmedCasesWithFirstMap(int confirmedcases, int number, int aod); //链接一级地图修改本地输入人数

    void ChangeStreetAboardConfirmedCases(); //修改街道境外输入人数

    void ChangeStreetInternalConfirmedCases(); //修改街道境内输入人数

    void ChangeStreetLocalConfirmedCases(); //修改街道本地输入人数

    void ChangeStreetConfirmedCases(); //修改街道确诊人数

    void AddStreet();//添加街道

    void DeleteStreet();//删除街道

    void SearchStreet();//查询街道

    void ShowAllStreet();//显示所有街道

    bool StreetIs_Exist(string name);//判断街道是否存在

    void ShowStreetInfomation();//展示街道基本信息

    void ShowStreetMenu();//展示街道选项

    void ChangeAboardConfirmedCasesWithSecondMap(int confirmedcases, int number, int aod); //链接二级地图修改境外输入人数

    void ChangeInternalConfirmedCasesWithSecondMap(int confirmedcases, int number, int aod); //链接二级地图修改境内输入人数

    void ChangeLocalConfirmedCasesWithSecondMap(int confirmedcases, int number, int aod); //链接二级地图修改本地输入人数
};

class HuaDuArea :
    public GuangZhouMap
{
public:
    string m_StreetName;
    HuaDuArea();
    HuaDuArea(string placename, int confirmedcases, int aboardconfirmedcases, int Internalconfirmercases, int localconfirmedcases,
        int covidlevel, string weather, int tempture, bool iffourteenday, string streetname);

    virtual void ShowMapInfomation();//展示地图基本信息

    virtual void ShowMapMenu();//展示地图选项

    virtual bool IsGoThrough();//是否被途经

    virtual bool InFourteenDay();//是否有疫情14天内

    virtual string CalculateLevel();//计算疫情等级

    virtual void ChangeAboardConfirmedCases(); //修改境外输入人数

    virtual void ChangeInternalConfirmedCases(); //修改境内输入人数

    virtual void ChangeLocalConfirmedCases(); //修改本地输入人数

    virtual void ChangeConfirmedCases(); //修改确诊人数

    virtual void ChangeWeather(); //修改天气

    void ChangeAboardConfirmedCasesWithFirstMap(int confirmedcases, int number, int aod); //链接一级地图修改境外输入人数

    void ChangeInternalConfirmedCasesWithFirstMap(int confirmedcases, int number, int aod); //链接一级地图修改境内输入人数

    void ChangeLocalConfirmedCasesWithFirstMap(int confirmedcases, int number, int aod); //链接一级地图修改本地输入人数

    void ChangeStreetAboardConfirmedCases(); //修改街道境外输入人数

    void ChangeStreetInternalConfirmedCases(); //修改街道境内输入人数

    void ChangeStreetLocalConfirmedCases(); //修改街道本地输入人数

    void ChangeStreetConfirmedCases(); //修改街道确诊人数

    void AddStreet();//添加街道

    void DeleteStreet();//删除街道

    void SearchStreet();//查询街道

    void ShowAllStreet();//显示所有街道

    bool StreetIs_Exist(string name);//判断街道是否存在

    void ShowStreetInfomation();//展示街道基本信息

    void ShowStreetMenu();//展示街道选项

    void ChangeAboardConfirmedCasesWithSecondMap(int confirmedcases, int number, int aod); //链接二级地图修改境外输入人数

    void ChangeInternalConfirmedCasesWithSecondMap(int confirmedcases, int number, int aod); //链接二级地图修改境内输入人数

    void ChangeLocalConfirmedCasesWithSecondMap(int confirmedcases, int number, int aod); //链接二级地图修改本地输入人数
};

class HuangPuArea :
    public GuangZhouMap
{
public:
    string m_StreetName;
    HuangPuArea();
    HuangPuArea(string placename, int confirmedcases, int aboardconfirmedcases, int Internalconfirmercases, int localconfirmedcases,
        int covidlevel, string weather, int tempture, bool iffourteenday, string streetname);

    virtual void ShowMapInfomation();//展示地图基本信息

    virtual void ShowMapMenu();//展示地图选项

    virtual bool IsGoThrough();//是否被途经

    virtual bool InFourteenDay();//是否有疫情14天内

    virtual string CalculateLevel();//计算疫情等级

    virtual void ChangeAboardConfirmedCases(); //修改境外输入人数

    virtual void ChangeInternalConfirmedCases(); //修改境内输入人数

    virtual void ChangeLocalConfirmedCases(); //修改本地输入人数

    virtual void ChangeConfirmedCases(); //修改确诊人数

    virtual void ChangeWeather(); //修改天气

    void ChangeAboardConfirmedCasesWithFirstMap(int confirmedcases, int number, int aod); //链接一级地图修改境外输入人数

    void ChangeInternalConfirmedCasesWithFirstMap(int confirmedcases, int number, int aod); //链接一级地图修改境内输入人数

    void ChangeLocalConfirmedCasesWithFirstMap(int confirmedcases, int number, int aod); //链接一级地图修改本地输入人数

    void ChangeStreetAboardConfirmedCases(); //修改街道境外输入人数

    void ChangeStreetInternalConfirmedCases(); //修改街道境内输入人数

    void ChangeStreetLocalConfirmedCases(); //修改街道本地输入人数

    void ChangeStreetConfirmedCases(); //修改街道确诊人数

    void AddStreet();//添加街道

    void DeleteStreet();//删除街道

    void SearchStreet();//查询街道

    void ShowAllStreet();//显示所有街道

    bool StreetIs_Exist(string name);//判断街道是否存在

    void ShowStreetInfomation();//展示街道基本信息

    void ShowStreetMenu();//展示街道选项

    void ChangeAboardConfirmedCasesWithSecondMap(int confirmedcases, int number, int aod); //链接二级地图修改境外输入人数

    void ChangeInternalConfirmedCasesWithSecondMap(int confirmedcases, int number, int aod); //链接二级地图修改境内输入人数

    void ChangeLocalConfirmedCasesWithSecondMap(int confirmedcases, int number, int aod); //链接二级地图修改本地输入人数
};

class LiWanArea :
    public GuangZhouMap
{
public:
    string m_StreetName;
    LiWanArea();
    LiWanArea(string placename, int confirmedcases, int aboardconfirmedcases, int Internalconfirmercases, int localconfirmedcases,
        int covidlevel, string weather, int tempture, bool iffourteenday, string streetname);

    virtual void ShowMapInfomation();//展示地图基本信息

    virtual void ShowMapMenu();//展示地图选项

    virtual bool IsGoThrough();//是否被途经

    virtual bool InFourteenDay();//是否有疫情14天内

    virtual string CalculateLevel();//计算疫情等级

    virtual void ChangeAboardConfirmedCases(); //修改境外输入人数

    virtual void ChangeInternalConfirmedCases(); //修改境内输入人数

    virtual void ChangeLocalConfirmedCases(); //修改本地输入人数

    virtual void ChangeConfirmedCases(); //修改确诊人数

    virtual void ChangeWeather(); //修改天气

    void ChangeAboardConfirmedCasesWithFirstMap(int confirmedcases, int number, int aod); //链接一级地图修改境外输入人数

    void ChangeInternalConfirmedCasesWithFirstMap(int confirmedcases, int number, int aod); //链接一级地图修改境内输入人数

    void ChangeLocalConfirmedCasesWithFirstMap(int confirmedcases, int number, int aod); //链接一级地图修改本地输入人数

    void ChangeStreetAboardConfirmedCases(); //修改街道境外输入人数

    void ChangeStreetInternalConfirmedCases(); //修改街道境内输入人数

    void ChangeStreetLocalConfirmedCases(); //修改街道本地输入人数

    void ChangeStreetConfirmedCases(); //修改街道确诊人数

    void AddStreet();//添加街道

    void DeleteStreet();//删除街道

    void SearchStreet();//查询街道

    void ShowAllStreet();//显示所有街道

    bool StreetIs_Exist(string name);//判断街道是否存在

    void ShowStreetInfomation();//展示街道基本信息

    void ShowStreetMenu();//展示街道选项

    void ChangeAboardConfirmedCasesWithSecondMap(int confirmedcases, int number, int aod); //链接二级地图修改境外输入人数

    void ChangeInternalConfirmedCasesWithSecondMap(int confirmedcases, int number, int aod); //链接二级地图修改境内输入人数

    void ChangeLocalConfirmedCasesWithSecondMap(int confirmedcases, int number, int aod); //链接二级地图修改本地输入人数
};

class NanShaArea :
    public GuangZhouMap
{
public:
    string m_StreetName;
    NanShaArea();
    NanShaArea(string placename, int confirmedcases, int aboardconfirmedcases, int Internalconfirmercases, int localconfirmedcases,
        int covidlevel, string weather, int tempture, bool iffourteenday, string streetname);

    virtual void ShowMapInfomation();//展示地图基本信息

    virtual void ShowMapMenu();//展示地图选项

    virtual bool IsGoThrough();//是否被途经

    virtual bool InFourteenDay();//是否有疫情14天内

    virtual string CalculateLevel();//计算疫情等级

    virtual void ChangeAboardConfirmedCases(); //修改境外输入人数

    virtual void ChangeInternalConfirmedCases(); //修改境内输入人数

    virtual void ChangeLocalConfirmedCases(); //修改本地输入人数

    virtual void ChangeConfirmedCases(); //修改确诊人数

    virtual void ChangeWeather(); //修改天气

    void ChangeAboardConfirmedCasesWithFirstMap(int confirmedcases, int number, int aod); //链接一级地图修改境外输入人数

    void ChangeInternalConfirmedCasesWithFirstMap(int confirmedcases, int number, int aod); //链接一级地图修改境内输入人数

    void ChangeLocalConfirmedCasesWithFirstMap(int confirmedcases, int number, int aod); //链接一级地图修改本地输入人数

    void ChangeStreetAboardConfirmedCases(); //修改街道境外输入人数

    void ChangeStreetInternalConfirmedCases(); //修改街道境内输入人数

    void ChangeStreetLocalConfirmedCases(); //修改街道本地输入人数

    void ChangeStreetConfirmedCases(); //修改街道确诊人数

    void AddStreet();//添加街道

    void DeleteStreet();//删除街道

    void SearchStreet();//查询街道

    void ShowAllStreet();//显示所有街道

    bool StreetIs_Exist(string name);//判断街道是否存在

    void ShowStreetInfomation();//展示街道基本信息

    void ShowStreetMenu();//展示街道选项

    void ChangeAboardConfirmedCasesWithSecondMap(int confirmedcases, int number, int aod); //链接二级地图修改境外输入人数

    void ChangeInternalConfirmedCasesWithSecondMap(int confirmedcases, int number, int aod); //链接二级地图修改境内输入人数

    void ChangeLocalConfirmedCasesWithSecondMap(int confirmedcases, int number, int aod); //链接二级地图修改本地输入人数
};

class PanYuArea :
    public GuangZhouMap
{
public:
    string m_StreetName;
    PanYuArea();
    PanYuArea(string placename, int confirmedcases, int aboardconfirmedcases, int Internalconfirmercases, int localconfirmedcases,
        int covidlevel, string weather, int tempture, bool iffourteenday, string streetname);

    virtual void ShowMapInfomation();//展示地图基本信息

    virtual void ShowMapMenu();//展示地图选项

    virtual bool IsGoThrough();//是否被途经

    virtual bool InFourteenDay();//是否有疫情14天内

    virtual string CalculateLevel();//计算疫情等级

    virtual void ChangeAboardConfirmedCases(); //修改境外输入人数

    virtual void ChangeInternalConfirmedCases(); //修改境内输入人数

    virtual void ChangeLocalConfirmedCases(); //修改本地输入人数

    virtual void ChangeConfirmedCases(); //修改确诊人数

    virtual void ChangeWeather(); //修改天气

    void ChangeAboardConfirmedCasesWithFirstMap(int confirmedcases, int number, int aod); //链接一级地图修改境外输入人数

    void ChangeInternalConfirmedCasesWithFirstMap(int confirmedcases, int number, int aod); //链接一级地图修改境内输入人数

    void ChangeLocalConfirmedCasesWithFirstMap(int confirmedcases, int number, int aod); //链接一级地图修改本地输入人数

    void ChangeStreetAboardConfirmedCases(); //修改街道境外输入人数

    void ChangeStreetInternalConfirmedCases(); //修改街道境内输入人数

    void ChangeStreetLocalConfirmedCases(); //修改街道本地输入人数

    void ChangeStreetConfirmedCases(); //修改街道确诊人数

    void AddStreet();//添加街道

    void DeleteStreet();//删除街道

    void SearchStreet();//查询街道

    void ShowAllStreet();//显示所有街道

    bool StreetIs_Exist(string name);//判断街道是否存在

    void ShowStreetInfomation();//展示街道基本信息

    void ShowStreetMenu();//展示街道选项

    void ChangeAboardConfirmedCasesWithSecondMap(int confirmedcases, int number, int aod); //链接二级地图修改境外输入人数

    void ChangeInternalConfirmedCasesWithSecondMap(int confirmedcases, int number, int aod); //链接二级地图修改境内输入人数

    void ChangeLocalConfirmedCasesWithSecondMap(int confirmedcases, int number, int aod); //链接二级地图修改本地输入人数
};

class TianHeArea :
    public GuangZhouMap
{
public:
    string m_StreetName;
    TianHeArea();
    TianHeArea(string placename, int confirmedcases, int aboardconfirmedcases, int Internalconfirmercases, int localconfirmedcases,
        int covidlevel, string weather, int tempture, bool iffourteenday, string streetname);

    virtual void ShowMapInfomation();//展示地图基本信息

    virtual void ShowMapMenu();//展示地图选项

    virtual bool IsGoThrough();//是否被途经

    virtual bool InFourteenDay();//是否有疫情14天内

    virtual string CalculateLevel();//计算疫情等级

    virtual void ChangeAboardConfirmedCases(); //修改境外输入人数

    virtual void ChangeInternalConfirmedCases(); //修改境内输入人数

    virtual void ChangeLocalConfirmedCases(); //修改本地输入人数

    virtual void ChangeConfirmedCases(); //修改确诊人数

    virtual void ChangeWeather(); //修改天气

    void ChangeAboardConfirmedCasesWithFirstMap(int confirmedcases, int number, int aod); //链接一级地图修改境外输入人数

    void ChangeInternalConfirmedCasesWithFirstMap(int confirmedcases, int number, int aod); //链接一级地图修改境内输入人数

    void ChangeLocalConfirmedCasesWithFirstMap(int confirmedcases, int number, int aod); //链接一级地图修改本地输入人数

    void ChangeStreetAboardConfirmedCases(); //修改街道境外输入人数

    void ChangeStreetInternalConfirmedCases(); //修改街道境内输入人数

    void ChangeStreetLocalConfirmedCases(); //修改街道本地输入人数

    void ChangeStreetConfirmedCases(); //修改街道确诊人数

    void AddStreet();//添加街道

    void DeleteStreet();//删除街道

    void SearchStreet();//查询街道

    void ShowAllStreet();//显示所有街道

    bool StreetIs_Exist(string name);//判断街道是否存在

    void ShowStreetInfomation();//展示街道基本信息

    void ShowStreetMenu();//展示街道选项

    void ChangeAboardConfirmedCasesWithSecondMap(int confirmedcases, int number, int aod); //链接二级地图修改境外输入人数

    void ChangeInternalConfirmedCasesWithSecondMap(int confirmedcases, int number, int aod); //链接二级地图修改境内输入人数

    void ChangeLocalConfirmedCasesWithSecondMap(int confirmedcases, int number, int aod); //链接二级地图修改本地输入人数
};

class YueXiuArea :
    public GuangZhouMap
{
public:
    string m_StreetName;
    YueXiuArea();
    YueXiuArea(string placename, int confirmedcases, int aboardconfirmedcases, int Internalconfirmercases, int localconfirmedcases,
        int covidlevel, string weather, int tempture, bool iffourteenday, string streetname);

    virtual void ShowMapInfomation();//展示地图基本信息

    virtual void ShowMapMenu();//展示地图选项

    virtual bool IsGoThrough();//是否被途经

    virtual bool InFourteenDay();//是否有疫情14天内

    virtual string CalculateLevel();//计算疫情等级

    virtual void ChangeAboardConfirmedCases(); //修改境外输入人数

    virtual void ChangeInternalConfirmedCases(); //修改境内输入人数

    virtual void ChangeLocalConfirmedCases(); //修改本地输入人数

    virtual void ChangeConfirmedCases(); //修改确诊人数

    virtual void ChangeWeather(); //修改天气

    void ChangeAboardConfirmedCasesWithFirstMap(int confirmedcases, int number, int aod); //链接一级地图修改境外输入人数

    void ChangeInternalConfirmedCasesWithFirstMap(int confirmedcases, int number, int aod); //链接一级地图修改境内输入人数

    void ChangeLocalConfirmedCasesWithFirstMap(int confirmedcases, int number, int aod); //链接一级地图修改本地输入人数

    void ChangeStreetAboardConfirmedCases(); //修改街道境外输入人数

    void ChangeStreetInternalConfirmedCases(); //修改街道境内输入人数

    void ChangeStreetLocalConfirmedCases(); //修改街道本地输入人数

    void ChangeStreetConfirmedCases(); //修改街道确诊人数

    void AddStreet();//添加街道

    void DeleteStreet();//删除街道

    void SearchStreet();//查询街道

    void ShowAllStreet();//显示所有街道

    bool StreetIs_Exist(string name);//判断街道是否存在

    void ShowStreetInfomation();//展示街道基本信息

    void ShowStreetMenu();//展示街道选项

    void ChangeAboardConfirmedCasesWithSecondMap(int confirmedcases, int number, int aod); //链接二级地图修改境外输入人数

    void ChangeInternalConfirmedCasesWithSecondMap(int confirmedcases, int number, int aod); //链接二级地图修改境内输入人数

    void ChangeLocalConfirmedCasesWithSecondMap(int confirmedcases, int number, int aod); //链接二级地图修改本地输入人数
};

class ZengChengArea :
    public GuangZhouMap
{
public:
    string m_StreetName;
    ZengChengArea();
    ZengChengArea(string placename, int confirmedcases, int aboardconfirmedcases, int Internalconfirmercases, int localconfirmedcases,
        int covidlevel, string weather, int tempture, bool iffourteenday, string streetname);

    virtual void ShowMapInfomation();//展示地图基本信息

    virtual void ShowMapMenu();//展示地图选项

    virtual bool IsGoThrough();//是否被途经

    virtual bool InFourteenDay();//是否有疫情14天内

    virtual string CalculateLevel();//计算疫情等级

    virtual void ChangeAboardConfirmedCases(); //修改境外输入人数

    virtual void ChangeInternalConfirmedCases(); //修改境内输入人数

    virtual void ChangeLocalConfirmedCases(); //修改本地输入人数

    virtual void ChangeConfirmedCases(); //修改确诊人数

    virtual void ChangeWeather(); //修改天气

    void ChangeAboardConfirmedCasesWithFirstMap(int confirmedcases, int number, int aod); //链接一级地图修改境外输入人数

    void ChangeInternalConfirmedCasesWithFirstMap(int confirmedcases, int number, int aod); //链接一级地图修改境内输入人数

    void ChangeLocalConfirmedCasesWithFirstMap(int confirmedcases, int number, int aod); //链接一级地图修改本地输入人数

    void ChangeStreetAboardConfirmedCases(); //修改街道境外输入人数

    void ChangeStreetInternalConfirmedCases(); //修改街道境内输入人数

    void ChangeStreetLocalConfirmedCases(); //修改街道本地输入人数

    void ChangeStreetConfirmedCases(); //修改街道确诊人数

    void AddStreet();//添加街道

    void DeleteStreet();//删除街道

    void SearchStreet();//查询街道

    void ShowAllStreet();//显示所有街道

    bool StreetIs_Exist(string name);//判断街道是否存在

    void ShowStreetInfomation();//展示街道基本信息

    void ShowStreetMenu();//展示街道选项

    void ChangeAboardConfirmedCasesWithSecondMap(int confirmedcases, int number, int aod); //链接二级地图修改境外输入人数

    void ChangeInternalConfirmedCasesWithSecondMap(int confirmedcases, int number, int aod); //链接二级地图修改境内输入人数

    void ChangeLocalConfirmedCasesWithSecondMap(int confirmedcases, int number, int aod); //链接二级地图修改本地输入人数
};

#endif // AREA_H

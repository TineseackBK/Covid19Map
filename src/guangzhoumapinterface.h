#ifndef GUANGZHOUMAPINTERFACE_H
#define GUANGZHOUMAPINTERFACE_H

#include <QDialog>
#include <QPushButton>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include "regionalareaselect.h"
#include "login.h"
#include "book.h"
#include "gzmapchangeperson.h"

class Manager;
class User;
class Vister;
namespace Ui {
class GuangZhouMapInterface;
}

class GuangZhouMapInterface : public QDialog
{
    Q_OBJECT

public:
    explicit GuangZhouMapInterface(QWidget *parent = nullptr);
    ~GuangZhouMapInterface();
    RegionalAreaSelect*rasPage = NULL;//地区级地图页面
    RegionalAreaSelect*displayPage = NULL;//修改人数界面
    gzmapchangeperson*streetPage = NULL;//进入地区页面
    static QString m_ConfirmedCases,m_AboardConfirmedCases,
        m_InternalConfirmedCases,m_LocalConfirmedCases,weather,level,tempture,line;

private slots:

    void count_0_edit();
    void count_0_edit_back();

    void count_1_edit();
    void count_1_edit_back();

    void count_2_edit();
    void count_2_edit_back();

    void count_3_edit();
    void count_3_edit_back();

    void count_4_edit();
    void count_4_edit_back();

    void count_5_edit();
    void count_5_edit_back();

    void count_6_edit();
    void count_6_edit_back();

    void count_7_edit();
    void count_7_edit_back();

    void weather_edit();
    void weather_edit_back();

    void temperature_edit();
    void temperature_edit_back();

    //切换页面
    void switchPage();
    void switchPageBack();

    //打开街道
    void streetEdit();

    //隐藏所有街道
    void hideAllStreet();

    //标记广州市页面
    void markThis();

public slots:

    void on_count_0_linkActivated(const QString &link);
    void on_count_1_linkActivated(const QString &link);
    void on_count_2_linkActivated(const QString &link);
    void on_count_3_linkActivated(const QString &link);
    void on_count_4_linkActivated(const QString &link);
    void on_count_5_linkActivated(const QString &link);
    void on_count_6_linkActivated(const QString &link);
    void on_count_7_linkActivated(const QString &link);

    void on_weather_linkActivated(const QString &link);
    void on_temperature_linkActivated(const QString &link);
    void on_riskLvl_linkActivated(const QString &link);

    void on_weather_2_linkActivated(const QString &link);
    void on_temperature_2_linkActivated(const QString &link);
    void on_riskLvl_2_linkActivated(const QString &link);

    //整合数据
    void readData_gz(QFile &fileDataC, int &gzCount_n1, int &gzCount_n2, int &gzCount_n3, int &gzCount_n4);
    void mergeData();
    void mergeDataStreet();

signals:
    void back();//返回上一级信号

private:
    Ui::GuangZhouMapInterface *ui;

};

#endif // GUANGZHOUMAPINTERFACE_H

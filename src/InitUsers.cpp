#include <QDialog>
#include <QPushButton>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include "GlobalFile.h"
#include <QString>
#include "Identity.h"
#include "GlobalFile.h"
#include <cmath>

using namespace std;

void InitUsers()
{
    QFile file(OrdinaryFile);
    QTextStream ofs(&file);
    file.open( QIODevice::NewOnly | QIODevice::Text | QIODevice::WriteOnly);
    ofs<<"ordinaryuser 000000"<<endl;
    file.flush();
    file.close();

    QFile file1(ManagerFile);
    QTextStream ofs1(&file1);
    file1.open( QIODevice::NewOnly | QIODevice::Text | QIODevice::WriteOnly);
    ofs1<<"manageruser 000000"<<endl;
    file1.flush();
    file1.close();

    QFile file2(SecertCodeFile);
    QTextStream ofs2(&file2);
    file2.open( QIODevice::NewOnly | QIODevice::Text | QIODevice::WriteOnly);
    ofs2<<"000000"<<endl;
    file2.flush();
    file2.close();
    //登录文件判断

    QFile file3(GuangZhouMapFile);
    QTextStream ofs3(&file3);
    file3.open( QIODevice::NewOnly | QIODevice::Text | QIODevice::WriteOnly);
    ofs3<<QString("0 0 0 0 晴 25 0")<<endl;
    file3.flush();
    file3.close();
    //一级地图判断

    QFile file4(BaiYunAreaFile);
    QTextStream ofs4(&file4);
    file4.open( QIODevice::NewOnly | QIODevice::Text | QIODevice::WriteOnly);
    ofs4<<QString("0 0 0 0 晴 25 0")<<endl;
    file4.flush();
    file4.close();

    QFile file5(PanYuAreaFile);
    QTextStream ofs5(&file5);
    file5.open( QIODevice::NewOnly | QIODevice::Text | QIODevice::WriteOnly);
    ofs5<<QString("0 0 0 0 晴 25 0")<<endl;
    file5.flush();
    file5.close();

    QFile file6(TianHeAreaFile);
    QTextStream ofs6(&file6);
    file6.open( QIODevice::NewOnly | QIODevice::Text | QIODevice::WriteOnly);
    ofs6<<QString("0 0 0 0 晴 25 0")<<endl;
    file6.flush();
    file6.close();

    QFile file7(NanShaAreaFile);
    QTextStream ofs7(&file7);
    file7.open( QIODevice::NewOnly | QIODevice::Text | QIODevice::WriteOnly);
    ofs7<<QString("0 0 0 0 晴 25 0")<<endl;
    file7.flush();
    file7.close();

    QFile file8(ZengChengAreaFile);
    QTextStream ofs8(&file8);
    file8.open( QIODevice::NewOnly | QIODevice::Text | QIODevice::WriteOnly);
    ofs8<<QString("0 0 0 0 晴 25 0")<<endl;
    file8.flush();
    file8.close();

    QFile file9(CongHuaAreaFile);
    QTextStream ofs9(&file9);
    file9.open( QIODevice::NewOnly | QIODevice::Text | QIODevice::WriteOnly);
    ofs9<<QString("0 0 0 0 晴 25 0")<<endl;
    file9.flush();
    file9.close();

    QFile file10(HuaDuAreaFile);
    QTextStream ofs10(&file10);
    file10.open( QIODevice::NewOnly | QIODevice::Text | QIODevice::WriteOnly);
    ofs10<<QString("0 0 0 0 晴 25 0")<<endl;
    file10.flush();
    file10.close();

    QFile file11(HaiZhuAreaFile);
    QTextStream ofs11(&file11);
    file11.open( QIODevice::NewOnly | QIODevice::Text | QIODevice::WriteOnly);
    ofs11<<QString("0 0 0 0 晴 25 0")<<endl;
    file11.flush();
    file11.close();

    QFile file12(HuangPuAreaFile);
    QTextStream ofs12(&file12);
    file12.open( QIODevice::NewOnly | QIODevice::Text | QIODevice::WriteOnly);
    ofs12<<QString("0 0 0 0 晴 25 0")<<endl;
    file12.flush();
    file12.close();

    QFile file13(LiWanAreaFile);
    QTextStream ofs13(&file13);
    file13.open( QIODevice::NewOnly | QIODevice::Text | QIODevice::WriteOnly);
    ofs13<<QString("0 0 0 0 晴 25 0")<<endl;
    file13.flush();
    file13.close();

    QFile file14(YueXiuAreaFile);
    QTextStream ofs14(&file14);
    file14.open( QIODevice::NewOnly | QIODevice::Text | QIODevice::WriteOnly);
    ofs14<<QString("0 0 0 0 晴 25 0")<<endl;
    file14.flush();
    file14.close();

    //二级地图判断

//    QFile file15(BaiYunAreaStreetFile);
//    QTextStream ofs15(&file15);
//    file15.open( QIODevice::NewOnly | QIODevice::Text | QIODevice::WriteOnly);
//    ofs15<<QString("0 0 0 0 晴 25 0")<<endl;
//    file15.flush();
//    file15.close();

//    QFile file16(PanYuAreaStreetFile);
//    QTextStream ofs16(&file16);
//    file16.open( QIODevice::NewOnly | QIODevice::Text | QIODevice::WriteOnly);
//    ofs16<<QString("0 0 0 0 晴 25 0")<<endl;
//    file16.flush();
//    file16.close();

//    QFile file17(TianHeAreaStreetFile);
//    QTextStream ofs17(&file17);
//    file17.open( QIODevice::NewOnly | QIODevice::Text | QIODevice::WriteOnly);
//    ofs17<<"0 0 0 0 1 5 0"<<endl;
//    file17.flush();
//    file17.close();

//    QFile file18(NanShaAreaStreetFile);
//    QTextStream ofs18(&file18);
//    file18.open( QIODevice::NewOnly | QIODevice::Text | QIODevice::WriteOnly);
//    ofs18<<QString("0 0 0 0 晴 25 0")<<endl;
//    file18.flush();
//    file18.close();

//    QFile file19(ZengChengAreaStreetFile);
//    QTextStream ofs19(&file19);
//    file19.open( QIODevice::NewOnly | QIODevice::Text | QIODevice::WriteOnly);
//    ofs19<<QString("0 0 0 0 晴 25 0")<<endl;
//    file19.flush();
//    file19.close();

//    QFile file20(CongHuaAreaStreetFile);
//    QTextStream ofs20(&file20);
//    file20.open( QIODevice::NewOnly | QIODevice::Text | QIODevice::WriteOnly);
//    ofs20<<QString("0 0 0 0 晴 25 0")<<endl;
//    file20.flush();
//    file20.close();

//    QFile file21(HuaDuAreaStreetFile);
//    QTextStream ofs21(&file21);
//    file21.open( QIODevice::NewOnly | QIODevice::Text | QIODevice::WriteOnly);
//    ofs21<<QString("0 0 0 0 晴 25 0")<<endl;
//    file21.flush();
//    file21.close();

//    QFile file22(HaiZhuAreaStreetFile);
//    QTextStream ofs22(&file22);
//    file22.open( QIODevice::NewOnly | QIODevice::Text | QIODevice::WriteOnly);
//    ofs22<<QString("0 0 0 0 晴 25 0")<<endl;
//    file22.flush();
//    file22.close();

//    QFile file23(HuangPuAreaStreetFile);
//    QTextStream ofs23(&file23);
//    file23.open( QIODevice::NewOnly | QIODevice::Text | QIODevice::WriteOnly);
//    ofs23<<QString("0 0 0 0 晴 25 0")<<endl;
//    file23.flush();
//    file23.close();

//    QFile file24(LiWanAreaStreetFile);
//    QTextStream ofs24(&file24);
//    file24.open( QIODevice::NewOnly | QIODevice::Text | QIODevice::WriteOnly);
//    ofs24<<QString("0 0 0 0 晴 25 0")<<endl;
//    file24.flush();
//    file24.close();

//    QFile file25(YueXiuAreaStreetFile);
//    QTextStream ofs25(&file25);
//    file25.open( QIODevice::NewOnly | QIODevice::Text | QIODevice::WriteOnly);
//    ofs25<<QString("0 0 0 0 晴 25 0")<<endl;
//    file25.flush();
//    file25.close();

    //三级地图判断
    for (int i=1; i<=9; i++)
    {
        QString dIndex = QString::number(i);

        QFile file_ns("ns" + dIndex + ".txt");
        QTextStream ofs_ns(&file_ns);
        file_ns.open(QIODevice::NewOnly | QIODevice::Text | QIODevice::WriteOnly);
        ofs_ns<<QString("0 0 0 0 晴 25 0")<<endl;
        file_ns.flush();
        file_ns.close();
    }
    for (int i=1; i<=16; i++)
    {
        QString dIndex = QString::number(i);

        QFile file_py("py" + dIndex + ".txt");
        QTextStream ofs_py(&file_py);
        file_py.open(QIODevice::NewOnly | QIODevice::Text | QIODevice::WriteOnly);
        ofs_py<<QString("0 0 0 0 晴 25 0")<<endl;
        file_py.flush();
        file_py.close();
    }
    for (int i=1; i<=17; i++)
    {
        QString dIndex = QString::number(i);

        QFile file_hz("hz" + dIndex + ".txt");
        QTextStream ofs_hz(&file_hz);
        file_hz.open(QIODevice::NewOnly | QIODevice::Text | QIODevice::WriteOnly);
        ofs_hz<<QString("0 0 0 0 晴 25 0")<<endl;
        file_hz.flush();
        file_hz.close();
    }
    for (int i=1; i<=22; i++)
    {
        QString dIndex = QString::number(i);

        QFile file_lw("lw" + dIndex + ".txt");
        QTextStream ofs_lw(&file_lw);
        file_lw.open(QIODevice::NewOnly | QIODevice::Text | QIODevice::WriteOnly);
        ofs_lw<<QString("0 0 0 0 晴 25 0")<<endl;
        file_lw.flush();
        file_lw.close();
    }
    for (int i=1; i<=18; i++)
    {
        QString dIndex = QString::number(i);

        QFile file_yx("yx" + dIndex + ".txt");
        QTextStream ofs_yx(&file_yx);
        file_yx.open(QIODevice::NewOnly | QIODevice::Text | QIODevice::WriteOnly);
        ofs_yx<<QString("0 0 0 0 晴 25 0")<<endl;
        file_yx.flush();
        file_yx.close();
    }
    for (int i=1; i<=21; i++)
    {
        QString dIndex = QString::number(i);

        QFile file_th("th" + dIndex + ".txt");
        QTextStream ofs_th(&file_th);
        file_th.open(QIODevice::NewOnly | QIODevice::Text | QIODevice::WriteOnly);
        ofs_th<<QString("0 0 0 0 晴 25 0")<<endl;
        file_th.flush();
        file_th.close();
    }
    for (int i=1; i<=17; i++)
    {
        QString dIndex = QString::number(i);

        QFile file_hp("hp" + dIndex + ".txt");
        QTextStream ofs_hp(&file_hp);
        file_hp.open(QIODevice::NewOnly | QIODevice::Text | QIODevice::WriteOnly);
        ofs_hp<<QString("0 0 0 0 晴 25 0")<<endl;
        file_hp.flush();
        file_hp.close();
    }
    for (int i=1; i<=22; i++)
    {
        QString dIndex = QString::number(i);

        QFile file_by("by" + dIndex + ".txt");
        QTextStream ofs_by(&file_by);
        file_by.open(QIODevice::NewOnly | QIODevice::Text | QIODevice::WriteOnly);
        ofs_by<<QString("0 0 0 0 晴 25 0")<<endl;
        file_by.flush();
        file_by.close();
    }
    for (int i=1; i<=10; i++)
    {
        QString dIndex = QString::number(i);

        QFile file_hd("hd" + dIndex + ".txt");
        QTextStream ofs_hd(&file_hd);
        file_hd.open(QIODevice::NewOnly | QIODevice::Text | QIODevice::WriteOnly);
        ofs_hd<<QString("0 0 0 0 晴 25 0")<<endl;
        file_hd.flush();
        file_hd.close();
    }
    for (int i=1; i<=11; i++)
    {
        QString dIndex = QString::number(i);

        QFile file_zc("zc" + dIndex + ".txt");
        QTextStream ofs_zc(&file_zc);
        file_zc.open(QIODevice::NewOnly | QIODevice::Text | QIODevice::WriteOnly);
        ofs_zc<<QString("0 0 0 0 晴 25 0")<<endl;
        file_zc.flush();
        file_zc.close();
    }
    for (int i=1; i<=8; i++)
    {
        QString dIndex = QString::number(i);

        QFile file_ch("ch" + dIndex + ".txt");
        QTextStream ofs_ch(&file_ch);
        file_ch.open(QIODevice::NewOnly | QIODevice::Text | QIODevice::WriteOnly);
        ofs_ch<<QString("0 0 0 0 晴 25 0")<<endl;
        file_ch.flush();
        file_ch.close();
    }
}

#include "regionalareaselect.h"
#include "ui_regionalareaselect.h"
#include "guangzhoumapinterface.h"

RegionalAreaSelect::RegionalAreaSelect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegionalAreaSelect)
{
    ui->setupUi(this);

    //返回
    connect(ui->exitButton,SIGNAL(clicked()),this,SIGNAL(back()));
    ui->exitButton->setStyleSheet("QPushButton{border-image: url(:/GUI/UI_btn_cancel_round.png);}"
                                   "QPushButton:pressed{border-image: url(:/GUI/UI_btn_cancel_round_1.png);}");
}

//地区名标签
//从 guangzhoumapinterface.cpp 读入，点击地区按钮时即分配
void RegionalAreaSelect::on_placeName_linkActivated(const QString &link)
{
    ui->placeName->setText(link);
}

//显示类型标签
void RegionalAreaSelect::on_nameLabel_linkActivated(const QString &link)
{
    ui->nameLabel->setText(link);
}

//将文件数据读入
/*
 * ns = 9
 * py = 16
 * hz = 17
 * lw = 22
 * yx = 18
 * th = 21
 * hp = 17
 * by = 22
 * hd = 10
 * zc = 11
 * ch = 8
*/
void RegionalAreaSelect::readData_gz(QFile &fileDataC, QString &fStr)
{
    QTextStream ifsDC(&fileDataC);
    fileDataC.open(QIODevice::ReadOnly|QIODevice::Text);
    QString n1, n2, n3, n4, wr, te;
    ifsDC >> n1 >> n2 >> n3 >> n4 >> wr >> te;

    if (ui->nameLabel->text() == "确诊人数") fStr += n1;
    if (ui->nameLabel->text() == "境外输入人数") fStr += n2;
    if (ui->nameLabel->text() == "境内输入人数") fStr += n3;
    if (ui->nameLabel->text() == "本地输入人数") fStr += n4;
    if (ui->nameLabel->text() == "天气") fStr += wr;
    if (ui->nameLabel->text() == "温度") fStr += te;

    fStr += '\n';
}
void RegionalAreaSelect::readData()
{
    QString fStr;
    int fileCount = 1;

    if (ui->placeName->text() == "gz") fileCount = 11;

    if (ui->placeName->text() == "ns") fileCount = 9;
    if (ui->placeName->text() == "py") fileCount = 16;
    if (ui->placeName->text() == "hz") fileCount = 17;
    if (ui->placeName->text() == "lw") fileCount = 22;
    if (ui->placeName->text() == "yx") fileCount = 18;
    if (ui->placeName->text() == "th") fileCount = 21;
    if (ui->placeName->text() == "hp") fileCount = 17;
    if (ui->placeName->text() == "by") fileCount = 22;
    if (ui->placeName->text() == "hd") fileCount = 10;
    if (ui->placeName->text() == "zc") fileCount = 11;
    if (ui->placeName->text() == "ch") fileCount = 8;

    if (ui->placeName->text() == "gz")
    {
        ui->plainText->clear();

        fStr = "南沙区     ";
        QFile fileDataC1("nanshaareafile.txt");
        readData_gz(fileDataC1, fStr);

        fStr += "番禺区     ";
        QFile fileDataC2("panyuareafile.txt");
        readData_gz(fileDataC2, fStr);

        fStr += "海珠区     ";
        QFile fileDataC3("haizhuareafile.txt");
        readData_gz(fileDataC3, fStr);

        fStr += "荔湾区     ";
        QFile fileDataC4("liwanareafile.txt");
        readData_gz(fileDataC4, fStr);

        fStr += "越秀区     ";
        QFile fileDataC5("yuexiuareafile.txt");
        readData_gz(fileDataC5, fStr);

        fStr += "天河区     ";
        QFile fileDataC6("tianheareafile.txt");
        readData_gz(fileDataC6, fStr);

        fStr += "黄浦区     ";
        QFile fileDataC7("huangpuareafile.txt");
        readData_gz(fileDataC7, fStr);

        fStr += "白云区     ";
        QFile fileDataC8("baiyunareafile.txt");
        readData_gz(fileDataC8, fStr);

        fStr += "花都区     ";
        QFile fileDataC9("huaduareafile.txt");
        readData_gz(fileDataC9, fStr);

        fStr += "从化区     ";
        QFile fileDataC10("conghuaareafile.txt");
        readData_gz(fileDataC10, fStr);

        fStr += "增城区     ";
        QFile fileDataC11("zengchengareafile.txt");
        readData_gz(fileDataC11, fStr);

        ui->plainText->setPlainText(fStr);
    }

    else
        for (int i=1; i<=fileCount; i++)
        {
            QString dIndex = QString::number(i);

            fStr += "街道";
            fStr += dIndex;
            fStr += "    ";

            QFile fileData(ui->placeName->text() + dIndex + ".txt");
            QTextStream ifsD(&fileData);
            fileData.open(QIODevice::ReadOnly|QIODevice::Text);

            QString n1, n2, n3, n4;
            ifsD >> n1 >> n2 >> n3 >> n4;

            if (ui->nameLabel->text() == "确诊人数") fStr += n1;
            if (ui->nameLabel->text() == "境外输入人数") fStr += n2;
            if (ui->nameLabel->text() == "境内输入人数") fStr += n3;
            if (ui->nameLabel->text() == "本地输入人数") fStr += n4;

            fStr += '\n';

            ui->plainText->clear();
            ui->plainText->setPlainText(fStr);
        }
}

RegionalAreaSelect::~RegionalAreaSelect()
{
    delete ui;
}

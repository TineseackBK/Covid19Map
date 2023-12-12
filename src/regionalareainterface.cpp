#include "regionalareainterface.h"
#include "ui_regionalareainterface.h"
#include "regionalareaselect.h"

RegionalAreaInterface::RegionalAreaInterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegionalAreaInterface)
{
    ui->setupUi(this);
}

RegionalAreaInterface::~RegionalAreaInterface()
{
    delete ui;
}
//进入街道级地图按钮
void RegionalAreaInterface::on_EnterStreetButton_clicked()
{

}
//修改确诊人数按钮
void RegionalAreaInterface::on_ccButton_clicked()
{
    this->gzchangePage = new gzmapchangeperson(this);
    connect(ui->ccButton,&QPushButton::clicked,[=](){
        this->hide();
        this->gzchangePage->on_placeName_linkActivated(ui->palceNameLabel->text());
        this->gzchangePage->on_nameLabel_linkActivated("确诊人数");
        this->gzchangePage->show();
    });
    connect(this->gzchangePage,&gzmapchangeperson::back,[=](){
        this->gzchangePage->hide();
        this->show();
    });
}
//修改境外输入人数按钮
void RegionalAreaInterface::on_accButton_clicked()
{
    this->gzchangePage = new gzmapchangeperson(this);
    connect(ui->accButton,&QPushButton::clicked,[=](){
        this->hide();
        this->gzchangePage->on_placeName_linkActivated(ui->palceNameLabel->text());
        this->gzchangePage->on_nameLabel_linkActivated("境外输入人数");
        this->gzchangePage->show();
    });
    connect(this->gzchangePage,&gzmapchangeperson::back,[=](){
        this->gzchangePage->hide();
        this->show();
    });
}
//修改境内输入人数按钮
void RegionalAreaInterface::on_iccButton_clicked()
{
    this->gzchangePage = new gzmapchangeperson(this);
    connect(ui->iccButton,&QPushButton::clicked,[=](){
        this->hide();
        this->gzchangePage->on_placeName_linkActivated(ui->palceNameLabel->text());
        this->gzchangePage->on_nameLabel_linkActivated("境内输入人数");
        this->gzchangePage->show();
    });
    connect(this->gzchangePage,&gzmapchangeperson::back,[=](){
        this->gzchangePage->hide();
        this->show();
    });
}
//修改本地输入人数按钮
void RegionalAreaInterface::on_lccButton_clicked()
{
    this->gzchangePage = new gzmapchangeperson(this);
    connect(ui->lccButton,&QPushButton::clicked,[=](){
        this->hide();
        this->gzchangePage->on_placeName_linkActivated(ui->palceNameLabel->text());
        this->gzchangePage->on_nameLabel_linkActivated("本地输入人数");
        this->gzchangePage->show();
    });
    connect(this->gzchangePage,&gzmapchangeperson::back,[=](){
        this->gzchangePage->hide();
        this->show();
    });
}
//修改天气按钮
void RegionalAreaInterface::on_wButton_clicked()
{
    this->gzchangePage = new gzmapchangeperson(this);
    connect(ui->wButton,&QPushButton::clicked,[=](){
        this->hide();
        this->gzchangePage->on_placeName_linkActivated(ui->palceNameLabel->text());
        this->gzchangePage->on_nameLabel_linkActivated("天气");
        this->gzchangePage->show();
    });
    connect(this->gzchangePage,&gzmapchangeperson::back,[=](){
        this->gzchangePage->hide();
        this->show();
    });
}
//温度修改按钮
void RegionalAreaInterface::on_tempButton_clicked()
{
    this->gzchangePage = new gzmapchangeperson(this);
    connect(ui->tempButton,&QPushButton::clicked,[=](){
        this->hide();
        this->gzchangePage->on_placeName_linkActivated(ui->palceNameLabel->text());
        this->gzchangePage->on_nameLabel_linkActivated("温度");
        this->gzchangePage->show();
    });
    connect(this->gzchangePage,&gzmapchangeperson::back,[=](){
        this->gzchangePage->hide();
        this->show();
    });
}
//返回上一级按钮
void RegionalAreaInterface::on_exitButton_clicked()
{
    connect(ui->exitButton,&QPushButton::clicked,[=](){
        emit this->back();
    });
}
//修改标签
void RegionalAreaInterface::on_palceNameLabel_linkActivated(const QString &link)
{
    ui->palceNameLabel->setText(link);
}
//改变风险等级
void RegionalAreaInterface::on_covidLabel_linkActivated(const QString &link)
{
    ui->covidLabel->setText(link);
}
//修改确诊人数
void RegionalAreaInterface::on_ccShowLabel_linkActivated(const QString &link)
{
    ui->ccShowLabel->setText(link);
}
//修改境外输入人数
void RegionalAreaInterface::on_accShowLabel_linkActivated(const QString &link)
{
    ui->accShowLabel->setText(link);
}
//修改境内输入人数
void RegionalAreaInterface::on_iccShowLabel_linkActivated(const QString &link)
{
    ui->iccShowLabel->setText(link);
}
//修改本地输入人数
void RegionalAreaInterface::on_lccShowLabel_linkActivated(const QString &link)
{
    ui->lccShowLabel->setText(link);
}
//修改天气
void RegionalAreaInterface::on_weatherShowLabel_linkActivated(const QString &link)
{
    ui->weatherShowLabel->setText(link);
}
//修改温度
void RegionalAreaInterface::on_tempShowLabel_linkActivated(const QString &link)
{
    ui->tempShowLabel->setText(link);
}

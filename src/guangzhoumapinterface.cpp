#include "guangzhoumapinterface.h"
#include "ui_guangzhoumapinterface.h"
#include "gzmapchangeperson.h"
#include "ui_gzmapchangeperson.h"
#include "vister.h"
#include "user.h"
#include "manager.h"

GuangZhouMapInterface::GuangZhouMapInterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GuangZhouMapInterface)
{
    ui->setupUi(this);

    //默认数据
    ui->regionName->setText("<html><head/><body><p align=\"center\"><span style=\" color:#2284d4;\">广 州 市</span></p></body></html>");
    ui->regionName_2->setText("<html><head/><body><p align=\"center\"><span style=\" font-size:28pt; color:#8b8b8b;\">广 州 市</span></p></body></html>");

    //隐藏所有街道
    hideAllStreet();

    //修改确诊人数
    this->displayPage = new RegionalAreaSelect(this);
    connect(ui->count_0_edit,SIGNAL(clicked()),this,SLOT(count_0_edit()));
    connect(this->displayPage,SIGNAL(back()),this,SLOT(count_0_edit_back()));

    this->displayPage = new RegionalAreaSelect(this);
    connect(ui->count_4_edit,SIGNAL(clicked()),this,SLOT(count_4_edit()));
    connect(this->displayPage,SIGNAL(back()),this,SLOT(count_4_edit_back()));

    //修改境外输入人数
    this->displayPage = new RegionalAreaSelect(this);
    connect(ui->count_1_edit,SIGNAL(clicked()),this,SLOT(count_1_edit()));
    connect(this->displayPage,SIGNAL(back()),this,SLOT(count_1_edit_back()));

    this->displayPage = new RegionalAreaSelect(this);
    connect(ui->count_5_edit,SIGNAL(clicked()),this,SLOT(count_5_edit()));
    connect(this->displayPage,SIGNAL(back()),this,SLOT(count_5_edit_back()));

    //修改境内输入人数
    this->displayPage = new RegionalAreaSelect(this);
    connect(ui->count_2_edit,SIGNAL(clicked()),this,SLOT(count_2_edit()));
    connect(this->displayPage,SIGNAL(back()),this,SLOT(count_2_edit_back()));

    this->displayPage = new RegionalAreaSelect(this);
    connect(ui->count_6_edit,SIGNAL(clicked()),this,SLOT(count_6_edit()));
    connect(this->displayPage,SIGNAL(back()),this,SLOT(count_6_edit_back()));

    //修改本地输入人数
    this->displayPage = new RegionalAreaSelect(this);
    connect(ui->count_3_edit,SIGNAL(clicked()),this,SLOT(count_3_edit()));
    connect(this->displayPage,SIGNAL(back()),this,SLOT(count_3_edit_back()));

    this->displayPage = new RegionalAreaSelect(this);
    connect(ui->count_7_edit,SIGNAL(clicked()),this,SLOT(count_7_edit()));
    connect(this->displayPage,SIGNAL(back()),this,SLOT(count_7_edit_back()));

    //修改天气
    this->displayPage = new RegionalAreaSelect(this);
    connect(ui->weather_edit,SIGNAL(clicked()),this,SLOT(weather_edit()));
    connect(this->displayPage,SIGNAL(back()),this,SLOT(weather_edit_back()));

    //修改气温
    this->displayPage = new RegionalAreaSelect(this);
    connect(ui->temperature_edit,SIGNAL(clicked()),this,SLOT(temperature_edit()));
    connect(this->displayPage,SIGNAL(back()),this,SLOT(temperature_edit_back()));

    //返回
    connect(ui->exitButton,SIGNAL(clicked()),this,SIGNAL(back()));

    //进入区
    connect(ui->BaiYunButton,SIGNAL(clicked()),this,SLOT(switchPage()));
    connect(ui->CongHuaButton,SIGNAL(clicked()),this,SLOT(switchPage()));
    connect(ui->HaiZhuButton,SIGNAL(clicked()),this,SLOT(switchPage()));
    connect(ui->HuaDuButton,SIGNAL(clicked()),this,SLOT(switchPage()));
    connect(ui->HuangPuButton,SIGNAL(clicked()),this,SLOT(switchPage()));
    connect(ui->LiWanButton,SIGNAL(clicked()),this,SLOT(switchPage()));
    connect(ui->NanShaButton,SIGNAL(clicked()),this,SLOT(switchPage()));
    connect(ui->PanYuButton,SIGNAL(clicked()),this,SLOT(switchPage()));
    connect(ui->TianHeButton,SIGNAL(clicked()),this,SLOT(switchPage()));
    connect(ui->YueXiuButton,SIGNAL(clicked()),this,SLOT(switchPage()));
    connect(ui->ZengChengButton,SIGNAL(clicked()),this,SLOT(switchPage()));

    //返回广州市地图
    connect(ui->returnButton,SIGNAL(clicked()),this,SLOT(switchPageBack()));

    //街道
    connect(ui->ns1,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->ns2,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->ns3,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->ns4,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->ns5,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->ns6,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->ns7,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->ns8,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->ns9,SIGNAL(clicked()),this,SLOT(streetEdit()));

    connect(ui->py1,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->py2,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->py3,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->py4,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->py5,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->py6,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->py7,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->py8,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->py9,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->py10,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->py11,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->py12,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->py13,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->py14,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->py15,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->py16,SIGNAL(clicked()),this,SLOT(streetEdit()));

    connect(ui->hz1,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->hz2,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->hz3,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->hz4,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->hz5,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->hz6,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->hz7,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->hz8,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->hz9,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->hz10,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->hz11,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->hz12,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->hz13,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->hz14,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->hz15,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->hz16,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->hz17,SIGNAL(clicked()),this,SLOT(streetEdit()));

    connect(ui->lw1,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->lw2,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->lw3,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->lw4,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->lw5,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->lw6,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->lw7,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->lw8,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->lw9,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->lw10,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->lw11,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->lw12,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->lw13,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->lw14,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->lw15,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->lw16,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->lw17,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->lw18,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->lw19,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->lw20,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->lw21,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->lw22,SIGNAL(clicked()),this,SLOT(streetEdit()));
    
    connect(ui->yx1,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->yx2,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->yx3,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->yx4,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->yx5,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->yx6,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->yx7,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->yx8,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->yx9,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->yx10,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->yx11,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->yx12,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->yx13,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->yx14,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->yx15,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->yx16,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->yx17,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->yx18,SIGNAL(clicked()),this,SLOT(streetEdit()));

    connect(ui->th1,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->th2,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->th3,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->th4,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->th5,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->th6,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->th7,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->th8,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->th9,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->th10,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->th11,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->th12,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->th13,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->th14,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->th15,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->th16,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->th17,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->th18,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->th19,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->th20,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->th21,SIGNAL(clicked()),this,SLOT(streetEdit()));

    connect(ui->hp1,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->hp2,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->hp3,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->hp4,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->hp5,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->hp6,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->hp7,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->hp8,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->hp9,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->hp10,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->hp11,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->hp12,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->hp13,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->hp14,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->hp15,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->hp16,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->hp17,SIGNAL(clicked()),this,SLOT(streetEdit()));

    connect(ui->by1,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->by2,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->by3,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->by4,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->by5,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->by6,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->by7,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->by8,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->by9,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->by10,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->by11,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->by12,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->by13,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->by14,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->by15,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->by16,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->by17,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->by18,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->by19,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->by20,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->by21,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->by22,SIGNAL(clicked()),this,SLOT(streetEdit()));

    connect(ui->hd1,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->hd2,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->hd3,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->hd4,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->hd5,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->hd6,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->hd7,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->hd8,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->hd9,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->hd10,SIGNAL(clicked()),this,SLOT(streetEdit()));

    connect(ui->zc1,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->zc2,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->zc3,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->zc4,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->zc5,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->zc6,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->zc7,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->zc8,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->zc9,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->zc10,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->zc11,SIGNAL(clicked()),this,SLOT(streetEdit()));
    
    connect(ui->ch1,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->ch2,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->ch3,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->ch4,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->ch5,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->ch6,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->ch7,SIGNAL(clicked()),this,SLOT(streetEdit()));
    connect(ui->ch8,SIGNAL(clicked()),this,SLOT(streetEdit()));
}

QString GuangZhouMapInterface::m_ConfirmedCases = "0",GuangZhouMapInterface::m_AboardConfirmedCases = "0",
        GuangZhouMapInterface::m_InternalConfirmedCases = "0",GuangZhouMapInterface::m_LocalConfirmedCases = "0",
        GuangZhouMapInterface::weather = "晴",GuangZhouMapInterface::tempture = "25",
        GuangZhouMapInterface::line = "noline",GuangZhouMapInterface::level = "nolevel";

GuangZhouMapInterface::~GuangZhouMapInterface()
{
    delete ui;
}

//标记当前页面
void GuangZhouMapInterface::markThis()
{
    this->displayPage->on_placeName_linkActivated("gz");
}

//进入街道：打开小窗口，编辑用
void GuangZhouMapInterface::streetEdit()
{
    QPushButton *tmpButtonS = qobject_cast<QPushButton*>(sender());
    this->streetPage = new gzmapchangeperson(this);
    this->streetPage->on_placeName_linkActivated(tmpButtonS->objectName());
    this->streetPage->displayNum();
    this->streetPage->show();

    //当小窗口按下保存，更新区级数据
    connect(this->streetPage->ui->saveButton,SIGNAL(clicked()),this,SLOT(mergeDataStreet()));
}

//进入地区：切换页面
void GuangZhouMapInterface::switchPage()
{
    QPushButton *tmpButton = qobject_cast<QPushButton*>(sender());

    if (tmpButton == ui->NanShaButton){
        ui->stack->setCurrentIndex(1);
        ui->UI_map_region_bg->setText("<html><head/><body><p><img src=\":/GUI/UI_map_NanSha.png\"/></p></body></html>");

        ui->regionName_3->setText("南 沙 区");
        ui->regionName_4->setText("南 沙 区");
        ui->fatherName_2->setText("广 州 市");

        hideAllStreet();
        ui->street_NanSha->show();

        this->displayPage->on_placeName_linkActivated("ns");
    }
    if (tmpButton == ui->PanYuButton){
        ui->stack->setCurrentIndex(1);
        ui->UI_map_region_bg->setText("<html><head/><body><p><img src=\":/GUI/UI_map_PanYu.png\"/></p></body></html>");

        ui->regionName_3->setText("番 禺 区");
        ui->regionName_4->setText("番 禺 区");
        ui->fatherName_2->setText("广 州 市");

        hideAllStreet();
        ui->street_PanYu->show();

        this->displayPage->on_placeName_linkActivated("py");
    }
    if (tmpButton == ui->HaiZhuButton){
        ui->stack->setCurrentIndex(1);
        ui->UI_map_region_bg->setText("<html><head/><body><p><img src=\":/GUI/UI_map_HaiZhu.png\"/></p></body></html>");

        ui->regionName_3->setText("海 珠 区");
        ui->regionName_4->setText("海 珠 区");
        ui->fatherName_2->setText("广 州 市");

        hideAllStreet();
        ui->street_HaiZhu->show();

        this->displayPage->on_placeName_linkActivated("hz");
    }
    if (tmpButton == ui->LiWanButton){
        ui->stack->setCurrentIndex(1);
        ui->UI_map_region_bg->setText("<html><head/><body><p><img src=\":/GUI/UI_map_LiWan.png\"/></p></body></html>");

        ui->regionName_3->setText("荔 湾 区");
        ui->regionName_4->setText("荔 湾 区");
        ui->fatherName_2->setText("广 州 市");

        hideAllStreet();
        ui->street_LiWan->show();

        this->displayPage->on_placeName_linkActivated("lw");
    }
    if (tmpButton == ui->YueXiuButton){
        ui->stack->setCurrentIndex(1);
        ui->UI_map_region_bg->setText("<html><head/><body><p><img src=\":/GUI/UI_map_YueXiu.png\"/></p></body></html>");

        ui->regionName_3->setText("越 秀 区");
        ui->regionName_4->setText("越 秀 区");
        ui->fatherName_2->setText("广 州 市");

        hideAllStreet();
        ui->street_YueXiu->show();

        this->displayPage->on_placeName_linkActivated("yx");
    }
    if (tmpButton == ui->TianHeButton){
        ui->stack->setCurrentIndex(1);
        ui->UI_map_region_bg->setText("<html><head/><body><p><img src=\":/GUI/UI_map_TianHe.png\"/></p></body></html>");

        ui->regionName_3->setText("天 河 区");
        ui->regionName_4->setText("天 河 区");
        ui->fatherName_2->setText("广 州 市");

        hideAllStreet();
        ui->street_TianHe->show();

        this->displayPage->on_placeName_linkActivated("th");
    }
    if (tmpButton == ui->HuangPuButton){
        ui->stack->setCurrentIndex(1);
        ui->UI_map_region_bg->setText("<html><head/><body><p><img src=\":/GUI/UI_map_HuangPu.png\"/></p></body></html>");

        ui->regionName_3->setText("黄 浦 区");
        ui->regionName_4->setText("黄 浦 区");
        ui->fatherName_2->setText("广 州 市");

        hideAllStreet();
        ui->street_HuangPu->show();

        this->displayPage->on_placeName_linkActivated("hp");
    }
    if (tmpButton == ui->BaiYunButton){
        ui->stack->setCurrentIndex(1);
        ui->UI_map_region_bg->setText("<html><head/><body><p><img src=\":/GUI/UI_map_BaiYun.png\"/></p></body></html>");

        ui->regionName_3->setText("白 云 区");
        ui->regionName_4->setText("白 云 区");
        ui->fatherName_2->setText("广 州 市");

        hideAllStreet();
        ui->street_BaiYun->show();

        this->displayPage->on_placeName_linkActivated("by");
    }
    if (tmpButton == ui->HuaDuButton){
        ui->stack->setCurrentIndex(1);
        ui->UI_map_region_bg->setText("<html><head/><body><p><img src=\":/GUI/UI_map_HuaDu.png\"/></p></body></html>");

        ui->regionName_3->setText("花 都 区");
        ui->regionName_4->setText("花 都 区");
        ui->fatherName_2->setText("广 州 市");

        hideAllStreet();
        ui->street_HuaDu->show();

        this->displayPage->on_placeName_linkActivated("hd");
    }
    if (tmpButton == ui->ZengChengButton){
        ui->stack->setCurrentIndex(1);
        ui->UI_map_region_bg->setText("<html><head/><body><p><img src=\":/GUI/UI_map_ZengCheng.png\"/></p></body></html>");

        ui->regionName_3->setText("增 城 区");
        ui->regionName_4->setText("增 城 区");
        ui->fatherName_2->setText("广 州 市");

        hideAllStreet();
        ui->street_ZengCheng->show();

        this->displayPage->on_placeName_linkActivated("zc");
    }
    if (tmpButton == ui->CongHuaButton){
        ui->stack->setCurrentIndex(1);
        ui->UI_map_region_bg->setText("<html><head/><body><p><img src=\":/GUI/UI_map_CongHua.png\"/></p></body></html>");

        ui->regionName_3->setText("从 化 区");
        ui->regionName_4->setText("从 化 区");
        ui->fatherName_2->setText("广 州 市");

        hideAllStreet();
        ui->street_CongHua->show();

        this->displayPage->on_placeName_linkActivated("ch");
    }
    mergeDataStreet();
}

void GuangZhouMapInterface::switchPageBack()
{
    ui->stack->setCurrentIndex(0);
    markThis();
    mergeData();
}

//显示确诊人数按钮
void GuangZhouMapInterface::count_0_edit()
{
    markThis();
    this->displayPage->on_nameLabel_linkActivated("确诊人数");
    this->displayPage->show();
    this->displayPage->readData();
}
void GuangZhouMapInterface::count_0_edit_back()
{
    this->displayPage->hide();
    this->on_count_0_linkActivated(this->m_ConfirmedCases);
}
void GuangZhouMapInterface::count_4_edit()
{
    this->displayPage->on_nameLabel_linkActivated("确诊人数");
    this->displayPage->show();
    this->displayPage->readData();
}
void GuangZhouMapInterface::count_4_edit_back()
{
    this->displayPage->hide();
    this->on_count_4_linkActivated(this->m_ConfirmedCases);
}

//显示境外输入人数按钮
void GuangZhouMapInterface::count_1_edit()
{
    markThis();
    this->displayPage->on_nameLabel_linkActivated("境外输入人数");
    this->displayPage->show();
    this->displayPage->readData();
}
void GuangZhouMapInterface::count_1_edit_back()
{
    this->displayPage->hide();
}
void GuangZhouMapInterface::count_5_edit()
{
    this->displayPage->on_nameLabel_linkActivated("境外输入人数");
    this->displayPage->show();
    this->displayPage->readData();
}
void GuangZhouMapInterface::count_5_edit_back()
{
    this->displayPage->hide();
}

//显示境内输入人数按钮
void GuangZhouMapInterface::count_2_edit()
{
    markThis();
    this->displayPage->on_nameLabel_linkActivated("境内输入人数");
    this->displayPage->show();
    this->displayPage->readData();
}
void GuangZhouMapInterface::count_2_edit_back()
{
    this->displayPage->hide();
}
void GuangZhouMapInterface::count_6_edit()
{
    this->displayPage->on_nameLabel_linkActivated("境内输入人数");
    this->displayPage->show();
    this->displayPage->readData();
}
void GuangZhouMapInterface::count_6_edit_back()
{
    this->displayPage->hide();
}

//显示本地输入人数按钮
void GuangZhouMapInterface::count_3_edit()
{
    markThis();
    this->displayPage->on_nameLabel_linkActivated("本地输入人数");
    this->displayPage->show();
    this->displayPage->readData();
}
void GuangZhouMapInterface::count_3_edit_back()
{
    this->displayPage->hide();
}
void GuangZhouMapInterface::count_7_edit()
{
    this->displayPage->on_nameLabel_linkActivated("本地输入人数");
    this->displayPage->show();
    this->displayPage->readData();
}
void GuangZhouMapInterface::count_7_edit_back()
{
    this->displayPage->hide();
}

//显示天气按钮
void GuangZhouMapInterface::weather_edit()
{
    markThis();
    this->displayPage->on_nameLabel_linkActivated("天气");
    this->displayPage->show();
}
void GuangZhouMapInterface::weather_edit_back()
{
    this->displayPage->hide();
}

//显示温度按钮
void GuangZhouMapInterface::temperature_edit()
{
    markThis();
    this->displayPage->on_nameLabel_linkActivated("温度");
    this->displayPage->show();
}
void GuangZhouMapInterface::temperature_edit_back()
{
    this->displayPage->hide();
}

//整合街道数据到广州市
//会在以下情况执行：1.第一次进入广州市地图; 2.从区地图切回广州市地图
void GuangZhouMapInterface::readData_gz(QFile &fileDataC, int &gzCount_n1, int &gzCount_n2, int &gzCount_n3, int &gzCount_n4)
{
    QTextStream ifsDC(&fileDataC);
    fileDataC.open(QIODevice::ReadOnly|QIODevice::Text);

    QString n1, n2, n3, n4;
    ifsDC >> n1 >> n2 >> n3 >> n4;

    gzCount_n1 += n1.toInt();
    gzCount_n2 += n2.toInt();
    gzCount_n3 += n3.toInt();
    gzCount_n4 += n4.toInt();
}
void GuangZhouMapInterface::mergeData()
{
    int gzCount_n1 = 0, gzCount_n2 = 0, gzCount_n3 = 0, gzCount_n4 = 0;

    QFile fileDataC1("nanshaareafile.txt");
    readData_gz(fileDataC1, gzCount_n1, gzCount_n2, gzCount_n3, gzCount_n4);

    QFile fileDataC2("panyuareafile.txt");
    readData_gz(fileDataC2, gzCount_n1, gzCount_n2, gzCount_n3, gzCount_n4);

    QFile fileDataC3("haizhuareafile.txt");
    readData_gz(fileDataC3, gzCount_n1, gzCount_n2, gzCount_n3, gzCount_n4);

    QFile fileDataC4("liwanareafile.txt");
    readData_gz(fileDataC4, gzCount_n1, gzCount_n2, gzCount_n3, gzCount_n4);

    QFile fileDataC5("yuexiuareafile.txt");
    readData_gz(fileDataC5, gzCount_n1, gzCount_n2, gzCount_n3, gzCount_n4);

    QFile fileDataC6("tianheareafile.txt");
    readData_gz(fileDataC6, gzCount_n1, gzCount_n2, gzCount_n3, gzCount_n4);

    QFile fileDataC7("huangpuareafile.txt");
    readData_gz(fileDataC7, gzCount_n1, gzCount_n2, gzCount_n3, gzCount_n4);

    QFile fileDataC8("baiyunareafile.txt");
    readData_gz(fileDataC8, gzCount_n1, gzCount_n2, gzCount_n3, gzCount_n4);

    QFile fileDataC9("huaduareafile.txt");
    readData_gz(fileDataC9, gzCount_n1, gzCount_n2, gzCount_n3, gzCount_n4);

    QFile fileDataC10("conghuaareafile.txt");
    readData_gz(fileDataC10, gzCount_n1, gzCount_n2, gzCount_n3, gzCount_n4);

    QFile fileDataC11("zengchengareafile.txt");
    readData_gz(fileDataC11, gzCount_n1, gzCount_n2, gzCount_n3, gzCount_n4);

    //显示到 UI
    ui->count_0->setText(QString::number(gzCount_n1));
    ui->count_1->setText(QString::number(gzCount_n2));
    ui->count_2->setText(QString::number(gzCount_n3));
    ui->count_3->setText(QString::number(gzCount_n4));

    //保存到文件
    QFile fileTmp("guangzhoumapfile.txt");
    QTextStream ofsD(&fileTmp);
    fileTmp.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate);
    ofsD << gzCount_n1 << " " << gzCount_n2 << " "  << gzCount_n3 << " "  << gzCount_n4 << endl;

    fileTmp.flush();
    fileTmp.close();
}

//整合街道数据到区
//会在以下情况执行：1.修改数据后点击确认按钮; 2.点开区地图
void GuangZhouMapInterface::mergeDataStreet()
{
    QString streetCode;
    int streetCount_n1 = 0, streetCount_n2 = 0, streetCount_n3 = 0, streetCount_n4 = 0;
    QString streetCount_wr = 0;
    QString streetCount_te = 0;
    int fileCount = 1;

    if (ui->regionName_3->text() == "南 沙 区"){ fileCount = 9; streetCode = "ns"; }
    if (ui->regionName_3->text() == "番 禺 区"){ fileCount = 16; streetCode = "py"; }
    if (ui->regionName_3->text() == "海 珠 区"){ fileCount = 17; streetCode = "hz"; }
    if (ui->regionName_3->text() == "荔 湾 区"){ fileCount = 22; streetCode = "lw"; }
    if (ui->regionName_3->text() == "越 秀 区"){ fileCount = 18; streetCode = "yx"; }
    if (ui->regionName_3->text() == "天 河 区"){ fileCount = 21; streetCode = "th"; }
    if (ui->regionName_3->text() == "黄 浦 区"){ fileCount = 17; streetCode = "hp"; }
    if (ui->regionName_3->text() == "白 云 区"){ fileCount = 22; streetCode = "by"; }
    if (ui->regionName_3->text() == "花 都 区"){ fileCount = 10; streetCode = "hd"; }
    if (ui->regionName_3->text() == "增 城 区"){ fileCount = 11; streetCode = "zc"; }
    if (ui->regionName_3->text() == "从 化 区"){ fileCount = 8; streetCode = "ch"; }

    for (int i=1; i<=fileCount; i++)
    {
        QString dIndex = QString::number(i);

        QFile fileData(streetCode + dIndex + ".txt");
        QTextStream ifsD(&fileData);
        fileData.open(QIODevice::ReadOnly|QIODevice::Text);

        QString n1, n2, n3, n4, wr, te;
        ifsD >> n1 >> n2 >> n3 >> n4 >> wr >> te;

        streetCount_n1 += n1.toInt();
        streetCount_n2 += n2.toInt();
        streetCount_n3 += n3.toInt();
        streetCount_n4 += n4.toInt();

        streetCount_wr = wr;
        streetCount_te = te;
    }

    //显示到 UI
    ui->count_4->setText(QString::number(streetCount_n1));
    ui->count_5->setText(QString::number(streetCount_n2));
    ui->count_6->setText(QString::number(streetCount_n3));
    ui->count_7->setText(QString::number(streetCount_n4));

    ui->weather_2->setText(streetCount_wr);
    ui->temperature_2->setText(streetCount_te);

    //保存到文件
    if (streetCode == "ns")
    {
        QFile fileTmp("nanshaareafile.txt");
        QTextStream ofsD(&fileTmp);
        fileTmp.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate);
        ofsD << streetCount_n1 << " " << streetCount_n2 << " "  << streetCount_n3 << " "  << streetCount_n4 << " "  << streetCount_wr << " "  << streetCount_te << endl;

        fileTmp.flush();
        fileTmp.close();
    }
    if (streetCode == "py")
    {
        QFile fileTmp("panyuareafile.txt");
        QTextStream ofsD(&fileTmp);
        fileTmp.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate);
        ofsD << streetCount_n1 << " " << streetCount_n2 << " "  << streetCount_n3 << " "  << streetCount_n4 << " "  << streetCount_wr << " "  << streetCount_te << endl;

        fileTmp.flush();
        fileTmp.close();
    }
    if (streetCode == "hz")
    {
        QFile fileTmp("haizhuareafile.txt");
        QTextStream ofsD(&fileTmp);
        fileTmp.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate);
        ofsD << streetCount_n1 << " " << streetCount_n2 << " "  << streetCount_n3 << " "  << streetCount_n4 << " "  << streetCount_wr << " "  << streetCount_te << endl;

        fileTmp.flush();
        fileTmp.close();
    }
    if (streetCode == "lw")
    {
        QFile fileTmp("liwanareafile.txt");
        QTextStream ofsD(&fileTmp);
        fileTmp.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate);
        ofsD << streetCount_n1 << " " << streetCount_n2 << " "  << streetCount_n3 << " "  << streetCount_n4 << " "  << streetCount_wr << " "  << streetCount_te << endl;

        fileTmp.flush();
        fileTmp.close();
    }
    if (streetCode == "yx")
    {
        QFile fileTmp("yuexiuareafile.txt");
        QTextStream ofsD(&fileTmp);
        fileTmp.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate);
        ofsD << streetCount_n1 << " " << streetCount_n2 << " "  << streetCount_n3 << " "  << streetCount_n4 << " "  << streetCount_wr << " "  << streetCount_te << endl;

        fileTmp.flush();
        fileTmp.close();
    }
    if (streetCode == "th")
    {
        QFile fileTmp("tianheareafile.txt");
        QTextStream ofsD(&fileTmp);
        fileTmp.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate);
        ofsD << streetCount_n1 << " " << streetCount_n2 << " "  << streetCount_n3 << " "  << streetCount_n4 << " "  << streetCount_wr << " "  << streetCount_te << endl;

        fileTmp.flush();
        fileTmp.close();
    }
    if (streetCode == "hp")
    {
        QFile fileTmp("huangpuareafile.txt");
        QTextStream ofsD(&fileTmp);
        fileTmp.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate);
        ofsD << streetCount_n1 << " " << streetCount_n2 << " "  << streetCount_n3 << " "  << streetCount_n4 << " "  << streetCount_wr << " "  << streetCount_te << endl;

        fileTmp.flush();
        fileTmp.close();
    }
    if (streetCode == "by")
    {
        QFile fileTmp("baiyunareafile.txt");
        QTextStream ofsD(&fileTmp);
        fileTmp.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate);
        ofsD << streetCount_n1 << " " << streetCount_n2 << " "  << streetCount_n3 << " "  << streetCount_n4 << " "  << streetCount_wr << " "  << streetCount_te << endl;

        fileTmp.flush();
        fileTmp.close();
    }
    if (streetCode == "hd")
    {
        QFile fileTmp("huaduareafile.txt");
        QTextStream ofsD(&fileTmp);
        fileTmp.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate);
        ofsD << streetCount_n1 << " " << streetCount_n2 << " "  << streetCount_n3 << " "  << streetCount_n4 << " "  << streetCount_wr << " "  << streetCount_te << endl;

        fileTmp.flush();
        fileTmp.close();
    }
    if (streetCode == "zc")
    {
        QFile fileTmp("zengchengareafile.txt");
        QTextStream ofsD(&fileTmp);
        fileTmp.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate);
        ofsD << streetCount_n1 << " " << streetCount_n2 << " "  << streetCount_n3 << " "  << streetCount_n4 << " "  << streetCount_wr << " "  << streetCount_te << endl;

        fileTmp.flush();
        fileTmp.close();
    }
    if (streetCode == "ch")
    {
        QFile fileTmp("conghuaareafile.txt");
        QTextStream ofsD(&fileTmp);
        fileTmp.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate);
        ofsD << streetCount_n1 << " " << streetCount_n2 << " "  << streetCount_n3 << " "  << streetCount_n4 << " "  << streetCount_wr << " "  << streetCount_te << endl;

        fileTmp.flush();
        fileTmp.close();
    }
}

//确诊人数修改
void GuangZhouMapInterface::on_count_0_linkActivated(const QString &link)
{
    ui->count_0->setText(link);
}
void GuangZhouMapInterface::on_count_4_linkActivated(const QString &link)
{
    ui->count_4->setText(link);
}
//境外输入人数修改
void GuangZhouMapInterface::on_count_1_linkActivated(const QString &link)
{
    ui->count_1->setText(link);
}
void GuangZhouMapInterface::on_count_5_linkActivated(const QString &link)
{
    ui->count_5->setText(link);
}
//境内输入人数修改
void GuangZhouMapInterface::on_count_2_linkActivated(const QString &link)
{
    ui->count_2->setText(link);
}
void GuangZhouMapInterface::on_count_6_linkActivated(const QString &link)
{
    ui->count_6->setText(link);
}
//本地输入人数修改
void GuangZhouMapInterface::on_count_3_linkActivated(const QString &link)
{
    ui->count_3->setText(link);
}
void GuangZhouMapInterface::on_count_7_linkActivated(const QString &link)
{
    ui->count_7->setText(link);
}
//天气修改
void GuangZhouMapInterface::on_weather_linkActivated(const QString &link)
{
    ui->weather->setText(link);
}
void GuangZhouMapInterface::on_weather_2_linkActivated(const QString &link)
{
    ui->weather_2->setText(link);
}
//温度修改
void GuangZhouMapInterface::on_temperature_linkActivated(const QString &link)
{
    ui->temperature->setText(link);
}
void GuangZhouMapInterface::on_temperature_2_linkActivated(const QString &link)
{
    ui->temperature_2->setText(link);
}
//风险等级修改
void GuangZhouMapInterface::on_riskLvl_linkActivated(const QString &link)
{
    ui->riskLvl->setText(link);
}
void GuangZhouMapInterface::on_riskLvl_2_linkActivated(const QString &link)
{
    ui->riskLvl_2->setText(link);
}

//隐藏所有街道
void GuangZhouMapInterface::hideAllStreet()
{
    ui->street_NanSha->hide();
    ui->street_PanYu->hide();
    ui->street_HaiZhu->hide();
    ui->street_LiWan->hide();
    ui->street_YueXiu->hide();
    ui->street_TianHe->hide();
    ui->street_HuangPu->hide();
    ui->street_ZengCheng->hide();
    ui->street_BaiYun->hide();
    ui->street_HuaDu->hide();
    ui->street_CongHua->hide();
}

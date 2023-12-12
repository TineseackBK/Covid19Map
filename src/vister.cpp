#include "vister.h"
#include "ui_vister.h"
#include "covidmapmanagersystem.h"

Vister::Vister(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Vister)
{
    ui->setupUi(this);

    //确认
    this->gzPage = new GuangZhouMapInterface(this);
    connect(ui->loginButton,SIGNAL(clicked()),this,SLOT(hide()));
    connect(ui->loginButton,SIGNAL(clicked()),this->gzPage,SLOT(show()));
    connect(ui->loginButton,SIGNAL(clicked()),this->gzPage,SLOT(mergeData()));
    connect(this->gzPage,SIGNAL(back()),this->gzPage,SLOT(hide()));
    connect(this->gzPage,SIGNAL(back()),this,SLOT(show()));

    //返回
    connect(ui->exitButton,SIGNAL(clicked()),this,SIGNAL(back()));

    //退出系统
    connect(ui->QuitButton,SIGNAL(clicked()),this,SLOT(close()));
}

Vister::~Vister()
{
    delete ui;
}

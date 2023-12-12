#include "userselect.h"
#include "ui_userselect.h"


userselect::userselect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userselect)
{
    ui->setupUi(this);

    //修改账号按钮
    this->changePage = new change(this);
    connect(ui->changeUserButton,SIGNAL(clicked()),this,SLOT(hide()));
    connect(ui->changeUserButton,SIGNAL(clicked()),this->changePage,SLOT(on_nameLabel_linkActivated("用户")));
    connect(ui->changeUserButton,SIGNAL(clicked()),this->changePage,SLOT(show()));

    connect(this->changePage,SIGNAL(back()),this->changePage,SLOT(hide()));
    connect(this->changePage,SIGNAL(back()),this,SLOT(show()));

    //进入广州市地图按钮
    this->gzPage = new GuangZhouMapInterface(this);
    connect(ui->enterGzmapButton,SIGNAL(clicked()),this,SLOT(hide()));
    connect(ui->enterGzmapButton,SIGNAL(clicked()),this->gzPage,SLOT(show()));

    connect(this->gzPage,SIGNAL(back()),this->gzPage,SLOT(hide()));
    connect(this->gzPage,SIGNAL(back()),this,SLOT(show()));

    //退出账号按钮
    connect(ui->exitButton,SIGNAL(clicked()),this,SIGNAL(back()));
}

userselect::~userselect()
{
    delete ui;
}

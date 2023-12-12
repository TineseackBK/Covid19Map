#include "covidmapmanagersystem.h"
#include "ui_covidmapmanagersystem.h"


CovidMapManagerSystem::CovidMapManagerSystem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CovidMapManagerSystem)
{
    ui->setupUi(this);

//    setWindowFlags(Qt::FramelessWindowHint); //隐藏窗口标题

    //按钮样式
    ui->AdminButton->setStyleSheet("QPushButton{border-image: url(:/GUI/UI_login_btn_admin_1.png);}"
                                   "QPushButton:pressed{border-image: url(:/GUI/UI_login_btn_admin_2.png);}");
    ui->UserButton->setStyleSheet("QPushButton{border-image: url(:/GUI/UI_login_btn_user_1.png);}"
                                   "QPushButton:pressed{border-image: url(:/GUI/UI_login_btn_user_2.png);}");
    ui->GuestButton->setStyleSheet("QPushButton{border-image: url(:/GUI/UI_login_btn_guest_1.png);}"
                                   "QPushButton:pressed{border-image: url(:/GUI/UI_login_btn_guest_2.png);}");
    ui->QuitButton->setStyleSheet("QPushButton{border-image: url(:/GUI/UI_login_btn_quit_1.png);}"
                                   "QPushButton:pressed{border-image: url(:/GUI/UI_login_btn_quit_2.png);}");

    //用户登录
    this->userPage = new User(this);
    connect(ui->UserButton,SIGNAL(clicked()),this,SLOT(hide()));
    connect(ui->UserButton,SIGNAL(clicked()),this->userPage,SLOT(show()));
    connect(this->userPage,SIGNAL(back()),this->userPage,SLOT(hide()));
    connect(this->userPage,SIGNAL(back()),this,SLOT(show()));

    //管理员登录
    this->managerPage = new Manager(this);
    connect(ui->AdminButton,SIGNAL(clicked()),this,SLOT(hide()));
    connect(ui->AdminButton,SIGNAL(clicked()),this->managerPage,SLOT(show()));
    connect(this->managerPage,SIGNAL(back()),this->managerPage,SLOT(hide()));
    connect(this->managerPage,SIGNAL(back()),this,SLOT(show()));

    //游客登录
    this->visterPage = new Vister(this);
    connect(ui->GuestButton,SIGNAL(clicked()),this,SLOT(hide()));
    connect(ui->GuestButton,SIGNAL(clicked()),this->visterPage,SLOT(show()));
    connect(this->visterPage,SIGNAL(back()),this->visterPage,SLOT(hide()));
    connect(this->visterPage,SIGNAL(back()),this,SLOT(show()));

    //退出系统
    connect(ui->QuitButton,SIGNAL(clicked()),this,SLOT(close()));

}

CovidMapManagerSystem::~CovidMapManagerSystem()
{
    delete ui;
}

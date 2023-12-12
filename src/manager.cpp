#include "manager.h"
#include "ui_manager.h"
#include "covidmapmanagersystem.h"

Manager::Manager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Manager)
{
    ui->setupUi(this);

//    setWindowFlags(Qt::FramelessWindowHint); //隐藏窗口标题

    //按钮样式
    ui->ManagerBookButton->setStyleSheet("QPushButton{border-image: url(:/GUI/UI_login_admin_create_1.png);}"
                                   "QPushButton:pressed{border-image: url(:/GUI/UI_login_admin_create_2.png);}");
    ui->ManagerLoginButton->setStyleSheet("QPushButton{border-image: url(:/GUI/UI_login_admin_login_1.png);}"
                                   "QPushButton:pressed{border-image: url(:/GUI/UI_login_admin_login_2.png);}");
    ui->ManagerExitButton->setStyleSheet("QPushButton{border-image: url(:/GUI/UI_login_admin_back_1.png);}"
                                   "QPushButton:pressed{border-image: url(:/GUI/UI_login_admin_back_2.png);}");
    ui->QuitButton->setStyleSheet("QPushButton{border-image: url(:/GUI/UI_login_btn_quit_1.png);}"
                                   "QPushButton:pressed{border-image: url(:/GUI/UI_login_btn_quit_2.png);}");

    //管理员注册
    this->scPage = new secertcode(this);
    connect(ui->ManagerBookButton,SIGNAL(clicked()),this,SLOT(hide()));
    connect(ui->ManagerBookButton,SIGNAL(clicked()),this->scPage,SLOT(show()));
    connect(this->scPage,SIGNAL(back()),this->scPage,SLOT(hide()));
    connect(this->scPage,SIGNAL(back()),this,SLOT(show()));

    //管理员登录
    this->loginPage = new login(this);
    this->loginPage->on_nameLabel_linkActivated("管理员");
    connect(ui->ManagerLoginButton,SIGNAL(clicked()),this,SLOT(hide()));
    connect(ui->ManagerLoginButton,SIGNAL(clicked()),this->loginPage,SLOT(show()));
    connect(this->loginPage,SIGNAL(back()),this->loginPage,SLOT(hide()));
    connect(this->loginPage,SIGNAL(back()),this,SLOT(show()));

    //管理员返回
    connect(ui->ManagerExitButton,SIGNAL(clicked()),this,SIGNAL(back()));

    //退出系统
    connect(ui->QuitButton,SIGNAL(clicked()),this,SLOT(close()));

}

Manager::~Manager()
{
    delete ui;
}


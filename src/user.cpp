#include "user.h"
#include "ui_user.h"
#include "covidmapmanagersystem.h"

User::User(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::User)
{
    ui->setupUi(this);

    //用户注册
    this->bookPage = new book(this);
    this->bookPage->on_nameLabel_linkActivated("用户");
    connect(ui->UserBookButton,SIGNAL(clicked()),this,SLOT(hide()));
    connect(ui->UserBookButton,SIGNAL(clicked()),this->bookPage,SLOT(show()));
    connect(this->bookPage,SIGNAL(back()),this->bookPage,SLOT(hide()));
    connect(this->bookPage,SIGNAL(back()),this,SLOT(show()));

    //用户登录
    this->loginPage = new login(this);
    this->loginPage->on_nameLabel_linkActivated("用户");
    connect(ui->UserLoginButton,SIGNAL(clicked()),this,SLOT(hide()));
    connect(ui->UserLoginButton,SIGNAL(clicked()),this->loginPage,SLOT(show()));
    connect(this->loginPage,SIGNAL(back()),this->loginPage,SLOT(hide()));
    connect(this->loginPage,SIGNAL(back()),this,SLOT(show()));

    //用户返回
    connect(ui->UserExitButton,SIGNAL(clicked()),this,SIGNAL(back()));

    //退出系统
    connect(ui->QuitButton,SIGNAL(clicked()),this,SLOT(close()));

}

User::~User()
{
    delete ui;
}

//用户登录槽函数
//void User::on_UserLoginButton_clicked()
//{
//    this->loginPage = new login(this);
//    this->loginPage->on_nameLabel_linkActivated("用户");
//    connect(ui->UserLoginButton,&QPushButton::clicked,[=](){
//        this->hide();
//        this->loginPage->show();
//    });
//    connect(this->loginPage,&login::back,[=](){
//        this->loginPage->hide();
//        this->show();
//    });
//}
//用户退出槽函数
//void User::on_UserExitButton_clicked()
//{
//    connect(ui->UserExitButton,&QPushButton::clicked,[=](){
//        emit this->back();
//    });

//}
//用户注册槽函数
//void User::on_UserBookButton_clicked()
//{
//    this->bookPage = new book(this);
//    this->bookPage->on_nameLabel_linkActivated("用户");
//    connect(ui->UserBookButton,&QPushButton::clicked,[=](){
//        this->hide();
//        this->bookPage->show();
//    });

//    connect(this->bookPage,&book::back,[=](){
//        this->bookPage->hide();
//        this->show();
//    });
//}

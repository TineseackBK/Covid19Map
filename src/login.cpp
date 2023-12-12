#include "login.h"
#include "ui_login.h"
#include "manager.h"
#include "user.h"
#include "managerselect.h"
#include "userselect.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    //按钮样式
    ui->saveButton->setStyleSheet("QPushButton{border-image: url(:/GUI/UI_btn_confirm_1.png);}"
                                   "QPushButton:pressed{border-image: url(:/GUI/UI_btn_confirm_2.png);}");
    ui->exitButton->setStyleSheet("QPushButton{border-image: url(:/GUI/UI_btn_cancel_1.png);}"
                                   "QPushButton:pressed{border-image: url(:/GUI/UI_btn_cancel_2.png);}");
    ui->QuitButton->setStyleSheet("QPushButton{border-image: url(:/GUI/UI_login_btn_quit_1.png);}"
                                   "QPushButton:pressed{border-image: url(:/GUI/UI_login_btn_quit_2.png);}");

    //确认
    connect(ui->saveButton,SIGNAL(clicked()),this,SLOT(saveButton()));

    //返回
    connect(ui->exitButton,SIGNAL(clicked()),this,SIGNAL(back()));

    //退出系统
    connect(ui->QuitButton,SIGNAL(clicked()),this,SLOT(close()));

    this->userName = ui->userNameText->text();
    this->userCode = ui->userCodeText->text();

}

QString login::userName = "noname";
QString login::userCode = "000000";

login::~login()
{
    delete ui;
}

//改变标签名
void login::on_nameLabel_linkActivated(const QString &link)
{
    ui->nameLabel->setText(link);
        //更改背景
        if (ui->nameLabel->text() == "管理员")
            ui->UI_login_key_bg->setText("<html><head/><body><p><img src=\":/GUI/UI_login_admin_key.png\"/></p></body></html>");
        if (ui->nameLabel->text() == "用户")
            ui->UI_login_key_bg->setText("<html><head/><body><p><img src=\":/GUI/UI_login_user_key.png\"/></p></body></html>");
}

//确认按钮
void login::saveButton()
{
    QString filename;
    QString name = ui->nameLabel->text();
    if(name == "管理员")
    {
        filename = ManagerFile;
    }
    else if(name == "用户")
    {
        filename = OrdinaryFile;
    }
    QFile file(filename);
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream ifs(&file);
    QString fname,fcode;
    bool isfind = 0;
    while(!ifs.atEnd())
    {
        ifs>>fname>>fcode;
        if(fname == this->userName && fcode == this->userCode)
        {
            isfind = 1;
            break;
        }
    }
    file.flush();
    file.close();
    if(isfind == 1)
    {
        QApplication::setQuitOnLastWindowClosed(false);//防止点击信息栏后程序直接终止
//        QMessageBox msgBox;
//        msgBox.setWindowTitle("疫情地图管理系统");
//          msgBox.setText(name+"认证登陆成功！");
//          QPushButton * sbtn = msgBox.addButton("确认",QMessageBox::AcceptRole);
//          msgBox.setDefaultButton(sbtn);
//          msgBox.exec();
          if(name == "管理员")
          {
              this->msPage = new managerselect(this);
              this->hide();
              this->msPage->show();

              connect(this->msPage,SIGNAL(back()),this->msPage,SLOT(hide()));
              connect(this->msPage,SIGNAL(back()),ui->userNameText,SLOT(clear()));
              connect(this->msPage,SIGNAL(back()),ui->userCodeText,SLOT(clear()));
              connect(this->msPage,SIGNAL(back()),this,SLOT(show()));
          }
          else if(name == "用户")
          {
              this->usPage = new userselect(this);
              this->hide();
              this->usPage->show();

              connect(this->usPage,SIGNAL(back()),this->usPage,SLOT(hide()));
              connect(this->usPage,SIGNAL(back()),ui->userNameText,SLOT(clear()));
              connect(this->usPage,SIGNAL(back()),ui->userCodeText,SLOT(clear()));
              connect(this->usPage,SIGNAL(back()),this,SLOT(show()));
          }

    }
    else if (isfind == 0)
    {
        QApplication::setQuitOnLastWindowClosed(false);//防止点击信息栏后程序直接终止
        QMessageBox msgBox;
        msgBox.setWindowTitle("疫情地图管理系统");
          msgBox.setText(name+"认证登陆失败！\n用户名或密码错误！\n请重新输入！");
          QPushButton * sbtn = msgBox.addButton("确认",QMessageBox::AcceptRole);
          msgBox.setDefaultButton(sbtn);
          msgBox.exec();
//          ui->userNameText->clear();
          ui->userCodeText->clear();
    }
}

//登录用户名
void login::on_userNameText_editingFinished()
{
    this->userName = ui->userNameText->text();
}
//登录密码
void login::on_userCodeText_editingFinished()
{
    this->userCode = ui->userCodeText->text();
}

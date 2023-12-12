#include "secertcode.h"
#include "ui_secertcode.h"
#include "manager.h"
#include "guangzhoumapinterface.h"

secertcode::secertcode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secertcode)
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

}

QString secertcode::secertCode = "000000";

secertcode::~secertcode()
{
    delete ui;
}
//密钥获取
void secertcode::on_userCodeText_editingFinished()
{
    this->secertCode = ui->userCodeText->text();
}
//确认按钮
void secertcode::saveButton()
{
    QFile file(SecertCodeFile);
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream ifs(&file);
    QString fsecertcode;
    bool isfind = 0;
    while(!ifs.atEnd())
    {
        ifs>>fsecertcode;
        if(fsecertcode == this->secertCode && !(ui->userCodeText->text().isEmpty()))
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
        QMessageBox msgBox;
        msgBox.setWindowTitle("疫情地图管理系统");
          msgBox.setText("管理员注册密钥验证成功");
          QPushButton * sbtn = msgBox.addButton("确认",QMessageBox::AcceptRole);
          msgBox.setDefaultButton(sbtn);
          msgBox.exec();
          this->bookPage = new book(this);
          this->hide();
          this->bookPage->on_nameLabel_linkActivated("管理员");
//          this->bookPage->on_titleLabel_linkActivated("注册");
          this->bookPage->show();
          ui->userCodeText->clear();
//          connect(this->bookPage,&book::back,[=](){
//              this->bookPage->hide();
//              this->show();
//          });
          connect(this->bookPage,SIGNAL(back()),this->bookPage,SLOT(hide()));
          connect(this->bookPage,SIGNAL(back()),this,SLOT(show()));

    }
    else if (isfind == 0)
    {
        QApplication::setQuitOnLastWindowClosed(false);//防止点击信息栏后程序直接终止
        QMessageBox msgBox;
        msgBox.setWindowTitle("疫情地图管理系统");
          msgBox.setText("管理员注册密钥验证失败\n请重新输入");
          QPushButton * sbtn = msgBox.addButton("确认",QMessageBox::AcceptRole);
          msgBox.setDefaultButton(sbtn);
          msgBox.exec();
          ui->userCodeText->clear();
    }
}

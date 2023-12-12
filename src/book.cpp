#include "book.h"
#include "ui_book.h"
#include "manager.h"
#include "user.h"
#include "guangzhoumapinterface.h"
#include "secertcode.h"

book::book(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::book)
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

QString book::userName = "noname";
QString book::userCode = "000000";

book::~book()
{
    delete ui;
}

//改变标签名
void book::on_nameLabel_linkActivated(const QString &link)
{
    ui->nameLabel->setText(link);
}

//确认按钮
void book::saveButton()
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
        if(fname == this->userName&&fcode == this->userCode)
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
          msgBox.setText("该账号已存在！");
          QPushButton * sbtn = msgBox.addButton("确认",QMessageBox::AcceptRole);
          msgBox.setDefaultButton(sbtn);
          msgBox.exec();
          ui->userNameText->clear();
          ui->userCodeText->clear();
    }
    else if(isfind == 0)
    {
        file.open(QIODevice::Append|QIODevice::WriteOnly|QIODevice::Text);
        QTextStream ofs(&file);
        if(!ui->userNameText->text().isEmpty()&&!ui->userCodeText->text().isEmpty())
        {
            ofs<<ui->userNameText->text()<<" "<<ui->userCodeText->text()<<endl;
            QApplication::setQuitOnLastWindowClosed(false);//防止点击信息栏后程序直接终止
            QMessageBox msgBox;
            msgBox.setWindowTitle("疫情地图管理系统");
              msgBox.setText(name+"注册成功！");
              QPushButton * sbtn = msgBox.addButton("确认",QMessageBox::AcceptRole);
              msgBox.setDefaultButton(sbtn);
              msgBox.exec();
              ui->userNameText->clear();
              ui->userCodeText->clear();
              file.flush();
              file.close();
        }
        else if (ui->userNameText->text().isEmpty()||ui->userCodeText->text().isEmpty())
        {
            QApplication::setQuitOnLastWindowClosed(false);//防止点击信息栏后程序直接终止
            QMessageBox msgBox;
            msgBox.setWindowTitle("疫情地图管理系统");
              msgBox.setText(name+"注册失败！\n用户名或密码为空！\n请重新输入！");
              QPushButton * sbtn = msgBox.addButton("确认",QMessageBox::AcceptRole);
              msgBox.setDefaultButton(sbtn);
              msgBox.exec();
//              ui->userNameText->clear();
              ui->userCodeText->clear();
        }
    }
}

//登录用户名
void book::on_userNameText_editingFinished()
{
    this->userName = ui->userNameText->text();
}
//登录密码
void book::on_userCodeText_editingFinished()
{
    this->userCode = ui->userCodeText->text();
}

#include "change.h"
#include "ui_change.h"
#include "managerselect.h"
#include "userselect.h"

#include <QDebug>

change::change(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::change)
{
    ui->setupUi(this);

    //确认
    connect(ui->saveButton,SIGNAL(clicked()),this,SLOT(saveButton()));

    //返回
    connect(ui->exitButton,SIGNAL(clicked()),this,SIGNAL(back()));

    //退出系统
    connect(ui->QuitButton,SIGNAL(clicked()),this,SLOT(close()));
}

QString change::userName = "noname";
QString change::userCode = "000000";
QString change::userNameBehind = "noname";
QString change::userCodeBehind = "000000";

change::~change()
{
    delete ui;
}
//修改用户名
void change::on_userNameText_editingFinished()
{
    this->userName = ui->userNameText->text();
}
//修改密码
void change::on_userCodeText_editingFinished()
{
    this->userCode = ui->userCodeText->text();
}
//确认按钮
void change::saveButton()
{
    QString filename,filename1;
    QString name = ui->nameLabel->text();
    if(name == "管理员")
    {
        filename = ManagerFile;
        filename1 = ManagerChangeFile;
    }
    else if(name == "用户")
    {
        filename = OrdinaryFile;
        filename1 = OrdinaryChangeFile;
    }
    QFile file(filename);
    QFile file1(filename1);
    QTextStream ifs(&file);
    QTextStream ofs(&file);
    file.open(QIODevice::ReadWrite|QIODevice::Text);
    QTextStream ofss(&file1);
    file1.open(QIODevice::WriteOnly|QIODevice::Text);
    QString fname,fcode;
    bool isfind = 0;
    if(!ui->userNameText->text().isEmpty()&&!ui->userCodeText->text().isEmpty()&&
            !ui->userNameText_2->text().isEmpty()&&!ui->userCodeText_2->text().isEmpty())
    {
        while(!ifs.atEnd())
        {
            ifs>>fname>>fcode;
            int a = fname.compare(this->userName);
            int b = fcode.compare(this->userCode);
            if (fabs(a) || fabs(b))
            {
                ofss << fname << " " << fcode << " " << endl;
            }
            else
            {
                isfind = 1;
            }
        }
        file.flush();
        file.close();
        file1.flush();
        file1.close();
        if (isfind == 1)
        {

            QTextStream ifss(&file1);
            file1.open(QIODevice::ReadOnly|QIODevice::Text);
            file.open(QIODevice::WriteOnly|QIODevice::Truncate|QIODevice::Text);
            while (!ifss.atEnd())
            {
                ifss >> fname >> fcode;
                ofs << fname << " " << fcode << " " << endl;
            }
            file.flush();
            file.close();
            file1.flush();
            file1.close();
            file.open(QIODevice::WriteOnly|QIODevice::Append|QIODevice::Text);
            ofs << this->userNameBehind << " " << this->userCodeBehind << " " << endl;
            file.flush();
            file.close();
            QApplication::setQuitOnLastWindowClosed(false);//防止点击信息栏后程序直接终止
            QMessageBox msgBox;
            msgBox.setWindowTitle("疫情地图管理系统");
              msgBox.setText("修改成功！");
              QPushButton * sbtn = msgBox.addButton("确认",QMessageBox::AcceptRole);
              msgBox.setDefaultButton(sbtn);
              msgBox.exec();
              ui->userNameText->clear();
              ui->userCodeText->clear();
              ui->userNameText_2->clear();
              ui->userCodeText_2->clear();
        }
        else
        {
            QApplication::setQuitOnLastWindowClosed(false);//防止点击信息栏后程序直接终止
            QMessageBox msgBox;
            msgBox.setWindowTitle("疫情地图管理系统");
              msgBox.setText("修改失败！\n用户不存在！");
              QPushButton * sbtn = msgBox.addButton("确认",QMessageBox::AcceptRole);
              msgBox.setDefaultButton(sbtn);
              msgBox.exec();
              ui->userNameText->clear();
              ui->userCodeText->clear();
              ui->userNameText_2->clear();
              ui->userCodeText_2->clear();
        }
    }
    else
    {
        QApplication::setQuitOnLastWindowClosed(false);//防止点击信息栏后程序直接终止
        QMessageBox msgBox;
        msgBox.setWindowTitle("疫情地图管理系统");
          msgBox.setText("修改失败！\n修改前后用户名或密码为空！\n请重新输入！");
          QPushButton * sbtn = msgBox.addButton("确认",QMessageBox::AcceptRole);
          msgBox.setDefaultButton(sbtn);
          msgBox.exec();
          ui->userNameText->clear();
          ui->userCodeText->clear();
          ui->userNameText_2->clear();
          ui->userCodeText_2->clear();
    }
}

//修改标签名
void change::on_nameLabel_linkActivated(const QString &link)
{
    ui->nameLabel->setText(link);
    qDebug() << "cnm";
}
//修改后用户
void change::on_userNameText_2_editingFinished()
{
    this->userNameBehind = ui->userNameText_2->text();
}
//修改后密码
void change::on_userCodeText_2_editingFinished()
{
    this->userCodeBehind = ui->userCodeText_2->text();
}

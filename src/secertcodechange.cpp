#include "secertcodechange.h"
#include "ui_secertcodechange.h"
#include "managerselect.h"

secertcodechange::secertcodechange(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secertcodechange)
{
    ui->setupUi(this);

    //确认
    connect(ui->saveButton,SIGNAL(clicked()),this,SLOT(saveButton()));

    //返回
    connect(ui->exitButton,SIGNAL(clicked()),this,SIGNAL(back()));

    //退出系统
    connect(ui->QuitButton,SIGNAL(clicked()),this,SLOT(close()));
}

QString secertcodechange::code = "000000";
QString secertcodechange::codeBehind = "000000";

secertcodechange::~secertcodechange()
{
    delete ui;
}
//修改前密钥
void secertcodechange::on_userCodeText_editingFinished()
{
    this->code = ui->userCodeText->text();
}
//修改后密钥
void secertcodechange::on_userCodeText_2_editingFinished()
{
    this->codeBehind = ui->userCodeText_2->text();
}
//确认按钮
void secertcodechange::saveButton()
{
    QFile file(SecertCodeFile);
    QFile file1(SecertchangeFile);
    QTextStream ifs(&file);
    QTextStream ofs(&file);
    file.open(QIODevice::ReadWrite|QIODevice::Text);
    QTextStream ofss(&file1);
    file1.open(QIODevice::WriteOnly|QIODevice::Text);
    QString fcode;
    bool isfind = 0;
    if(!ui->userCodeText->text().isEmpty()&&!ui->userCodeText_2->text().isEmpty())
    {
        while(!ifs.atEnd())
        {
            ifs>>fcode;
            int a = fcode.compare(this->code);
            if (fabs(a))
            {
                ofss << fcode << endl;
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
                ifss >> fcode;
                ofs << fcode << endl;
            }
            file.flush();
            file.close();
            file1.flush();
            file1.close();
            file.open(QIODevice::WriteOnly|QIODevice::Append|QIODevice::Text);
            ofs << this->codeBehind << endl;
            file.flush();
            file.close();
            QApplication::setQuitOnLastWindowClosed(false);//防止点击信息栏后程序直接终止
            QMessageBox msgBox;
            msgBox.setWindowTitle("疫情地图管理系统");
              msgBox.setText("修改成功");
              QPushButton * sbtn = msgBox.addButton("确认",QMessageBox::AcceptRole);
              msgBox.setDefaultButton(sbtn);
              msgBox.exec();
              ui->userCodeText->clear();
              ui->userCodeText_2->clear();
        }
        else
        {
            QApplication::setQuitOnLastWindowClosed(false);//防止点击信息栏后程序直接终止
            QMessageBox msgBox;
            msgBox.setWindowTitle("疫情地图管理系统");
              msgBox.setText("修改失败！\n密钥不存在");
              QPushButton * sbtn = msgBox.addButton("确认",QMessageBox::AcceptRole);
              msgBox.setDefaultButton(sbtn);
              msgBox.exec();
              ui->userCodeText->clear();
              ui->userCodeText_2->clear();
        }
    }
    else
    {
        QApplication::setQuitOnLastWindowClosed(false);//防止点击信息栏后程序直接终止
        QMessageBox msgBox;
        msgBox.setWindowTitle("疫情地图管理系统");
          msgBox.setText("修改失败\n修改前后密钥为空\n请重新输入");
          QPushButton * sbtn = msgBox.addButton("确认",QMessageBox::AcceptRole);
          msgBox.setDefaultButton(sbtn);
          msgBox.exec();
          ui->userCodeText->clear();
          ui->userCodeText_2->clear();
    }
}

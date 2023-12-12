#include "secertcodechoose.h"
#include "ui_secertcodechoose.h"
#include "managerselect.h"

secertcodechoose::secertcodechoose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secertcodechoose)
{
    ui->setupUi(this);

    //确认
    connect(ui->saveButton,SIGNAL(clicked()),this,SLOT(saveButton()));

    //返回
    connect(ui->exitButton,SIGNAL(clicked()),this,SIGNAL(back()));

    //退出系统
    connect(ui->QuitButton,SIGNAL(clicked()),this,SLOT(close()));
}

QString secertcodechoose::secertcode = "000000";

secertcodechoose::~secertcodechoose()
{
    delete ui;
}
//标签修改
void secertcodechoose::on_titleLabel_linkActivated(const QString &link)
{
    ui->titleLabel->setText(link);
}
//确认按钮
void secertcodechoose::saveButton()
{
    QString name = ui->titleLabel->text();
    QFile file(SecertCodeFile);
    QTextStream ofs(&file);
    if(name == "添加")
    {
        QTextStream ifs(&file);
        file.open(QIODevice::ReadOnly|QIODevice::Text);
        QString fcode;
        bool isfind = 0;
        if(!ui->userCodeText->text().isEmpty())
        {
            while(!ifs.atEnd())
            {
                ifs>>fcode;
                int a = fcode.compare(this->secertcode);
                if (fabs(a)){}
                else
                {
                    isfind = 1;
                }
            }
            file.flush();
            file.close();
            if (isfind == 1)
            {
                QApplication::setQuitOnLastWindowClosed(false);//防止点击信息栏后程序直接终止
                QMessageBox msgBox;
                msgBox.setWindowTitle("疫情地图管理系统");
                  msgBox.setText("添加失败！\n密钥已存在！");
                  QPushButton * sbtn = msgBox.addButton("确认",QMessageBox::AcceptRole);
                  msgBox.setDefaultButton(sbtn);
                  msgBox.exec();
                  ui->userCodeText->clear();
            }
            else
            {
                file.open(QIODevice::Append|QIODevice::WriteOnly|QIODevice::Text);
                ofs<<this->secertcode<<endl;
                QApplication::setQuitOnLastWindowClosed(false);//防止点击信息栏后程序直接终止
                QMessageBox msgBox;
                msgBox.setWindowTitle("疫情地图管理系统");
                  msgBox.setText("添加成功！");
                  QPushButton * sbtn = msgBox.addButton("确认",QMessageBox::AcceptRole);
                  msgBox.setDefaultButton(sbtn);
                  msgBox.exec();
                  ui->userCodeText->clear();
                  file.flush();
                  file.close();
            }
        }
        else
        {
            QApplication::setQuitOnLastWindowClosed(false);//防止点击信息栏后程序直接终止
            QMessageBox msgBox;
            msgBox.setWindowTitle("疫情地图管理系统");
              msgBox.setText("添加失败！\n密钥为空！\n请重新输入！");
              QPushButton * sbtn = msgBox.addButton("确认",QMessageBox::AcceptRole);
              msgBox.setDefaultButton(sbtn);
              msgBox.exec();
              ui->userCodeText->clear();
        }
    }
    else if(name == "删除")
    {
        QFile file1(SecertchangeFile);
        QTextStream ifs(&file);
        QTextStream ofs(&file);
        file.open(QIODevice::ReadWrite|QIODevice::Text);
        QTextStream ofss(&file1);
        file1.open(QIODevice::WriteOnly|QIODevice::Text);
        QString fcode;
        bool isfind = 0;
        if(!ui->userCodeText->text().isEmpty())
        {
            while(!ifs.atEnd())
            {
                ifs>>fcode;
                int a = fcode.compare(this->secertcode);
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
                while (ifss.atEnd())
                {
                    ifss >> fcode;
                    ofs << fcode << endl;

                }
                file.flush();
                file.close();
                file1.flush();
                file1.close();
                QApplication::setQuitOnLastWindowClosed(false);//防止点击信息栏后程序直接终止
                QMessageBox msgBox;
                msgBox.setWindowTitle("疫情地图管理系统");
                  msgBox.setText("删除成功！");
                  QPushButton * sbtn = msgBox.addButton("确认",QMessageBox::AcceptRole);
                  msgBox.setDefaultButton(sbtn);
                  msgBox.exec();
                  ui->userCodeText->clear();
            }
            else
            {
                QApplication::setQuitOnLastWindowClosed(false);//防止点击信息栏后程序直接终止
                QMessageBox msgBox;
                msgBox.setWindowTitle("疫情地图管理系统");
                  msgBox.setText("删除失败！\n密钥不存在！");
                  QPushButton * sbtn = msgBox.addButton("确认",QMessageBox::AcceptRole);
                  msgBox.setDefaultButton(sbtn);
                  msgBox.exec();
                  ui->userCodeText->clear();
            }
        }
        else
        {
            QApplication::setQuitOnLastWindowClosed(false);//防止点击信息栏后程序直接终止
            QMessageBox msgBox;
            msgBox.setWindowTitle("疫情地图管理系统");
              msgBox.setText("删除失败！\n密钥为空！\n请重新输入！");
              QPushButton * sbtn = msgBox.addButton("确认",QMessageBox::AcceptRole);
              msgBox.setDefaultButton(sbtn);
              msgBox.exec();
              ui->userCodeText->clear();
        }
    }
    file.flush();
    file.close();
}
//密钥名称
void secertcodechoose::on_userCodeText_editingFinished()
{
    this->secertcode = ui->userCodeText->text();
}

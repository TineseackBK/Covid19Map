#include "managerselect.h"
#include "ui_managerselect.h"
#include <QFileDialog>
#include <QDebug>

managerselect::managerselect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::managerselect)
{
    ui->setupUi(this);

    //修改用户账号按钮
    this->changePage = new change(this);
    connect(ui->changeUserButton,SIGNAL(clicked()),this,SLOT(hide()));
    connect(ui->changeUserButton,SIGNAL(clicked()),this->changePage,SLOT(on_nameLabel_linkActivated("用户")));
    connect(ui->changeUserButton,SIGNAL(clicked()),this->changePage,SLOT(show()));

    connect(this->changePage,SIGNAL(back()),this->changePage,SLOT(hide()));
    connect(this->changePage,SIGNAL(back()),this,SLOT(show()));


    //修改管理员账号按钮
    this->changePage = new change(this);
    connect(ui->changeManagerButton,SIGNAL(clicked()),this,SLOT(hide()));
    connect(ui->changeManagerButton,SIGNAL(clicked()),this->changePage,SLOT(on_nameLabel_linkActivated("管理员")));
    connect(ui->changeManagerButton,SIGNAL(clicked()),this->changePage,SLOT(show()));

    connect(this->changePage,SIGNAL(back()),this->changePage,SLOT(hide()));
    connect(this->changePage,SIGNAL(back()),this,SLOT(show()));


    //修改密钥按钮
    this->sccPage = new secertcodechange(this);
    connect(ui->changeCodeButton,SIGNAL(clicked()),this,SLOT(hide()));
    connect(ui->changeCodeButton,SIGNAL(clicked()),this->sccPage,SLOT(show()));

    connect(this->sccPage,SIGNAL(back()),this->sccPage,SLOT(hide()));
    connect(this->sccPage,SIGNAL(back()),this,SLOT(show()));


    //添加用户账号按钮
    this->bookPage = new book(this);
    connect(ui->addUserButton,SIGNAL(clicked()),this,SLOT(hide()));
    connect(ui->addUserButton,SIGNAL(clicked()),this->bookPage,SLOT(on_nameLabel_linkActivated("用户")));
    connect(ui->addUserButton,SIGNAL(clicked()),this->bookPage,SLOT(show()));

    connect(this->bookPage,SIGNAL(back()),this->bookPage,SLOT(hide()));
    connect(this->bookPage,SIGNAL(back()),this,SLOT(show()));


    //添加管理员账号按钮
    this->bookPage = new book(this);
    connect(ui->addManagerButton,SIGNAL(clicked()),this,SLOT(hide()));
    connect(ui->addManagerButton,SIGNAL(clicked()),this->bookPage,SLOT(on_nameLabel_linkActivated("管理员")));
    connect(ui->addManagerButton,SIGNAL(clicked()),this->bookPage,SLOT(show()));

    connect(this->bookPage,SIGNAL(back()),this->bookPage,SLOT(hide()));
    connect(this->bookPage,SIGNAL(back()),this,SLOT(show()));


    //添加密钥按钮
    this->scPage = new secertcodechoose(this);
    connect(ui->addCodeButton,SIGNAL(clicked()),this,SLOT(hide()));
    connect(ui->addCodeButton,SIGNAL(clicked()),this->scPage,SLOT(on_titleLabel_linkActivated("添加")));
    connect(ui->addCodeButton,SIGNAL(clicked()),this->scPage,SLOT(show()));

    connect(this->scPage,SIGNAL(back()),this->scPage,SLOT(hide()));
    connect(this->scPage,SIGNAL(back()),this,SLOT(show()));


    //删除用户账号按钮
    this->duPage = new deleteUser(this);
    connect(ui->deleteUserButton,SIGNAL(clicked()),this,SLOT(hide()));
    connect(ui->deleteUserButton,SIGNAL(clicked()),this->duPage,SLOT(on_nameLabel_linkActivated("用户")));
    connect(ui->deleteUserButton,SIGNAL(clicked()),this->duPage,SLOT(show()));

    connect(this->duPage,SIGNAL(back()),this->duPage,SLOT(hide()));
    connect(this->duPage,SIGNAL(back()),this,SLOT(show()));


    //删除管理员账号按钮
    this->duPage = new deleteUser(this);
    connect(ui->deleteManagerButton,SIGNAL(clicked()),this,SLOT(hide()));
    connect(ui->deleteManagerButton,SIGNAL(clicked()),this->duPage,SLOT(on_nameLabel_linkActivated("管理员")));
    connect(ui->deleteManagerButton,SIGNAL(clicked()),this->duPage,SLOT(show()));

    connect(this->duPage,SIGNAL(back()),this->duPage,SLOT(hide()));
    connect(this->duPage,SIGNAL(back()),this,SLOT(show()));


    //删除密钥按钮
    this->scPage = new secertcodechoose(this);
    connect(ui->deleteCodeButton,SIGNAL(clicked()),this,SLOT(hide()));
    connect(ui->deleteCodeButton,SIGNAL(clicked()),this->scPage,SLOT(on_titleLabel_linkActivated("删除")));
    connect(ui->deleteCodeButton,SIGNAL(clicked()),this->scPage,SLOT(show()));

    connect(this->scPage,SIGNAL(back()),this->scPage,SLOT(hide()));
    connect(this->scPage,SIGNAL(back()),this,SLOT(show()));


    //进入广州市地图按钮
    this->gzPage = new GuangZhouMapInterface(this);
    connect(ui->enterGzmapButton,SIGNAL(clicked()),this,SLOT(hide()));
    connect(ui->enterGzmapButton,SIGNAL(clicked()),this->gzPage,SLOT(show()));
    connect(ui->enterGzmapButton,SIGNAL(clicked()),this->gzPage,SLOT(mergeData()));

    connect(this->gzPage,SIGNAL(back()),this->gzPage,SLOT(hide()));
    connect(this->gzPage,SIGNAL(back()),this,SLOT(show()));

    //退出账号按钮
    connect(ui->exitButton,SIGNAL(clicked()),this,SIGNAL(back()));

    //显示用户账号按钮
    connect(ui->showUserButton_2,SIGNAL(clicked()),this,SLOT(showUser()));

    //显示管理员帐号按钮
    connect(ui->showManagerButton_2,SIGNAL(clicked()),this,SLOT(showAdmin()));

    //显示密钥按钮
    connect(ui->showCodeButton_2,SIGNAL(clicked()),this,SLOT(showCode()));

    //恢复出厂设置按钮
    connect(ui->deleteAllButton,SIGNAL(clicked()),this,SLOT(resetAll()));
}

QString managerselect::showname = "noname";

managerselect::~managerselect()
{
    delete ui;
}

//显示用户账号按钮
void managerselect::showUser()
{
    ui->showInfoText->clear();
    QFile file(OrdinaryFile);
    QString fname,fpassword,line;
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream ifs(&file);
    while(!ifs.atEnd())
    {
        ifs>>fname>>fpassword;
        line += fname;
        line.append(" ");
        line+=fpassword;
        line+='\n';
        ui->showInfoText->setPlainText(line);
    }
    file.flush();
    file.close();
}

//显示管理员帐号按钮
void managerselect::showAdmin()
{
    ui->showInfoText->clear();
    QFile file(ManagerFile);
    QString fname,fpassword,line;
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream ifs(&file);
    while(!ifs.atEnd())
    {
        ifs>>fname>>fpassword;
        line += fname;
        line.append(" ");
        line+=fpassword;
        line+='\n';
        ui->showInfoText->setPlainText(line);
    }
    file.flush();
    file.close();
}

//显示密钥按钮
void managerselect::showCode()
{
    ui->showInfoText->clear();
    QFile file(SecertCodeFile);
    QString fcode,line;
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream ifs(&file);
    while(!ifs.atEnd())
    {
        ifs>>fcode;
        line += fcode;
        line+='\n';
        ui->showInfoText->setPlainText(line);
    }
    file.flush();
    file.close();
}

//恢复出厂设置按钮
void managerselect::resetAll()
{
    QString text;
    text+="你确定要恢复出厂设置吗？";
    text+='\n';
    text+="这个操作将不可恢复！！";
    int ret = QMessageBox::warning(this,"疫情地图管理系统",text,QMessageBox::Cancel | QMessageBox::Save);
    QFile file(OrdinaryFile),file1(ManagerFile),file2(SecertCodeFile);
    QTextStream ofs(&file),ofs1(&file1),ofs2(&file2);
    switch (ret)
    {
        case QMessageBox::Save:
            file.open(QIODevice::Truncate|QIODevice::WriteOnly|QIODevice::Text);
            file1.open(QIODevice::Truncate|QIODevice::WriteOnly|QIODevice::Text);
            file2.open(QIODevice::Truncate|QIODevice::WriteOnly|QIODevice::Text);
            ofs<<"ordinaryuser 000000"<<endl;
            ofs1<<"manageruser 000000"<<endl;
            ofs2<<"000000"<<endl;
            file.flush();
            file.close();
            file1.flush();
            file1.close();
            file2.flush();
            file2.close();
            break;
        case QMessageBox::Cancel:
            break;
        default:
            break;
    }
}

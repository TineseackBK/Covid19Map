#include "gzmapchangeperson.h"
#include "ui_gzmapchangeperson.h"
#include "guangzhoumapinterface.h"
#include "regionalareainterface.h"

gzmapchangeperson::gzmapchangeperson(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gzmapchangeperson)
{
    ui->setupUi(this);

    //确认
    connect(ui->saveButton,SIGNAL(clicked()),this,SLOT(saveButton()));

    ui->saveButton->setStyleSheet("QPushButton{border-image: url(:/GUI/UI_btn_confirm_round.png);}"
                                   "QPushButton:pressed{border-image: url(:/GUI/UI_btn_confirm_round_1.png);}");

    //返回
    connect(ui->exitButton,SIGNAL(clicked()),this,SLOT(close()));

    ui->exitButton->setStyleSheet("QPushButton{border-image: url(:/GUI/UI_btn_cancel_round.png);}"
                                   "QPushButton:pressed{border-image: url(:/GUI/UI_btn_cancel_round_1.png);}");

    //变更信息栏后刷新显示
    connect(ui->nameLabel,SIGNAL(currentIndexChanged(int)),this,SLOT(displayNum()));
}

QString gzmapchangeperson::person = "0";

gzmapchangeperson::~gzmapchangeperson()
{
    delete ui;
}


//地区名标签
void gzmapchangeperson::on_placeName_linkActivated(const QString &link)
{
    ui->placeName->setText(link);
}

//修改标签
void gzmapchangeperson::on_nameLabel_linkActivated(const QString &link)
{
    ui->nameLabel->setCurrentText(link);
}

//修改后人数
void gzmapchangeperson::on_afterPerson_editingFinished()
{
    this->person = ui->afterPerson->text();
}

//显示数字
void gzmapchangeperson::displayNum()
{
    QFile fileD(ui->placeName->text() + ".txt");
    QTextStream ifsD(&fileD);
    fileD.open(QIODevice::ReadOnly|QIODevice::Text);

    QString n1, n2, n3, n4, wr, te;
    ifsD >> n1 >> n2 >> n3 >> n4 >> wr >> te;

    QString dNum;
    if (ui->nameLabel->currentText() == "确诊人数") dNum = n1;
    if (ui->nameLabel->currentText() == "境外输入人数") dNum = n2;
    if (ui->nameLabel->currentText() == "境内输入人数") dNum = n3;
    if (ui->nameLabel->currentText() == "本地输入人数") dNum = n4;
    if (ui->nameLabel->currentText() == "天气") dNum = wr;
    if (ui->nameLabel->currentText() == "温度") dNum = te;

    ui->currentNum->setText(dNum);
}

//确认按钮
void gzmapchangeperson::saveButton()
{
    ui->currentNum->setText(this->person);

    QFile file(ui->placeName->text() + ".txt");
    QTextStream ifs(&file);
    QTextStream ofs(&file);
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    if(!ui->afterPerson->text().isEmpty())
    {
        QString n1, n2, n3, n4, wr, te;
        ifs >> n1 >> n2 >> n3 >> n4 >> wr >> te;

        if(ui->nameLabel->currentText()=="确诊人数")
        {
            n1 = this->person;
        }
        else if(ui->nameLabel->currentText()=="境外输入人数")
        {
            n2 = this->person;
        }
        else if(ui->nameLabel->currentText()=="境内输入人数")
        {
            n3 = this->person;
        }
        else if(ui->nameLabel->currentText()=="本地输入人数")
        {
            n4 = this->person;
        }
        else if(ui->nameLabel->currentText()=="天气")
        {
            wr = this->person;
        }
        else if(ui->nameLabel->currentText()=="温度")
        {
            te = this->person;
        }

        file.flush();
        file.close();

        file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate);
        ofs << n1 << " " << n2 << " "  << n3 << " "  << n4 << " "  << wr << " "  << te << endl;

        file.flush();
        file.close();
        ui->afterPerson->clear();

        //若选择了为 14 天内新增
//        connect(ui->checkNew,SIGNAL(toggled(true)),);
    }
    else
    {
        QApplication::setQuitOnLastWindowClosed(false);//防止点击信息栏后程序直接终止
        QMessageBox msgBox;
        msgBox.setWindowTitle("疫情地图管理系统");
          msgBox.setText("修改失败\n修改信息为空\n请重新输入");
          QPushButton * sbtn = msgBox.addButton("确认",QMessageBox::AcceptRole);
          msgBox.setDefaultButton(sbtn);
          msgBox.exec();
          ui->afterPerson->clear();
    }
}


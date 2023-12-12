#ifndef MANAGER_H
#define MANAGER_H

#include <QDialog>
#include <QPushButton>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include "login.h"
#include "book.h"
#include "secertcode.h"
class CovidMapManagerSystem;
namespace Ui {
class Manager;
}

class Manager : public QDialog
{
    Q_OBJECT

public:
    explicit Manager(QWidget *parent = nullptr);
    ~Manager();
    login*loginPage = NULL;//登录界面
    secertcode*scPage  =NULL;//密钥界面

private slots:

signals:
    void back();//返回上一级信号

private:
    Ui::Manager *ui;
};

#endif // MANAGER_H

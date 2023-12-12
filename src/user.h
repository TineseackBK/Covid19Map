#ifndef USER_H
#define USER_H

#include <QDialog>
#include <QPushButton>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include "guangzhoumapinterface.h"
#include "login.h"
#include "book.h"
class CovidMapManagerSystem;
namespace Ui {
class User;
}

class User : public QDialog
{
    Q_OBJECT

public:
    explicit User(QWidget *parent = nullptr);
    ~User();
    login*loginPage = NULL;//登录界面
    book*bookPage = NULL;//注册界面

private slots:

signals:
    void back();//返回上一级信号

private:
    Ui::User *ui;
};

#endif // USER_H

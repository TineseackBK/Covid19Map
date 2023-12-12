#ifndef MANAGERSELECT_H
#define MANAGERSELECT_H

#include <QDialog>
#include <QPushButton>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include "guangzhoumapinterface.h"
#include "login.h"
#include "GlobalFile.h"
#include "change.h"
#include "deleteuser.h"
#include "secertcodechoose.h"
#include "secertcodechange.h"

namespace Ui {
class managerselect;
}

class managerselect : public QDialog
{
    Q_OBJECT

public:
    explicit managerselect(QWidget *parent = nullptr);
    ~managerselect();

    static QString showname;

    GuangZhouMapInterface*gzPage = NULL;//广州界面
    book*bookPage = NULL;//添加账号界面
    change*changePage = NULL;//修改账号界面
    deleteUser*duPage = NULL;//删除账号界面
    secertcodechoose*scPage = NULL;//添加、删除密钥界面
    secertcodechange*sccPage = NULL;//修改密钥界面

public slots:
    void resetAll();
    void showUser();
    void showAdmin();
    void showCode();

signals:
    void back();//返回上一级信号

private:
    Ui::managerselect *ui;
};

#endif // MANAGERSELECT_H

#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QPushButton>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include "GlobalFile.h"



class Manager;
class User;
class GuangZhouMapInterface;
class managerselect;
class userselect;
namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
    managerselect*msPage = NULL;//管理员界面
    userselect*usPage = NULL;//用户界面
    static QString userName;
    static QString userCode;

private slots:

public slots:
    void on_nameLabel_linkActivated(const QString &link);

    void saveButton();

    void on_userNameText_editingFinished();

    void on_userCodeText_editingFinished();

signals:
    void back();//返回上一级信号

private:
    Ui::login *ui;
};

#endif // LOGIN_H

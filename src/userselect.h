#ifndef USERSELECT_H
#define USERSELECT_H

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

namespace Ui {
class userselect;
}

class userselect : public QDialog
{
    Q_OBJECT

public:
    explicit userselect(QWidget *parent = nullptr);
    ~userselect();
    GuangZhouMapInterface*gzPage = NULL;//广州界面
    change*changePage = NULL;//修改账号界面

signals:
    void back();//返回上一级信号

private slots:

private:
    Ui::userselect *ui;
};

#endif // USERSELECT_H

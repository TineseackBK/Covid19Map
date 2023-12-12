#ifndef VISTER_H
#define VISTER_H

#include <QDialog>
#include <QPushButton>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include "guangzhoumapinterface.h"
class CovidMapManagerSystem;
namespace Ui {
class Vister;
}

class Vister : public QDialog
{
    Q_OBJECT

public:
    explicit Vister(QWidget *parent = nullptr);
    ~Vister();
    GuangZhouMapInterface*gzPage = NULL;//广州界面

private slots:

signals:
    void back();//返回上一级信号

private:
    Ui::Vister *ui;
};

#endif // VISTER_H

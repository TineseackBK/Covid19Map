#ifndef REGIONALAREASELECT_H
#define REGIONALAREASELECT_H

#include <QDialog>
#include <QPushButton>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include "regionalareainterface.h"

class GuangZhouMapInterface;
namespace Ui {
class RegionalAreaSelect;
}

class RegionalAreaSelect : public QDialog
{
    Q_OBJECT

public:
    explicit RegionalAreaSelect(QWidget *parent = nullptr);
    ~RegionalAreaSelect();
    RegionalAreaInterface*raPage = NULL;

public slots:
    void on_placeName_linkActivated(const QString &link);

    void on_nameLabel_linkActivated(const QString &link);

    //读入文件
    void readData_gz(QFile &, QString &);
    void readData();

signals:
    void back();//返回上一级信号

private:
    Ui::RegionalAreaSelect *ui;
};

#endif // REGIONALAREASELECT_H

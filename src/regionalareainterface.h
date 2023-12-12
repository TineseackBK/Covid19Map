#ifndef REGIONALAREAINTERFACE_H
#define REGIONALAREAINTERFACE_H

#include <QDialog>
#include <QPushButton>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include "gzmapchangeperson.h"
class RegionalAreaSelect;
namespace Ui {
class RegionalAreaInterface;
}

class RegionalAreaInterface : public QDialog
{
    Q_OBJECT

public:
    explicit RegionalAreaInterface(QWidget *parent = nullptr);
    ~RegionalAreaInterface();
    gzmapchangeperson*gzchangePage = NULL;//修改人数界面

private slots:
    void on_EnterStreetButton_clicked();

    void on_ccButton_clicked();

    void on_accButton_clicked();

    void on_iccButton_clicked();

    void on_lccButton_clicked();

    void on_wButton_clicked();

    void on_exitButton_clicked();

    void on_tempButton_clicked();



    void on_ccShowLabel_linkActivated(const QString &link);

    void on_accShowLabel_linkActivated(const QString &link);

    void on_iccShowLabel_linkActivated(const QString &link);

    void on_lccShowLabel_linkActivated(const QString &link);

    void on_weatherShowLabel_linkActivated(const QString &link);

    void on_tempShowLabel_linkActivated(const QString &link);

public slots:
    void on_palceNameLabel_linkActivated(const QString &link);

    void on_covidLabel_linkActivated(const QString &link);

signals:
    void back();//返回上一级信号

private:
    Ui::RegionalAreaInterface *ui;
};

#endif // REGIONALAREAINTERFACE_H

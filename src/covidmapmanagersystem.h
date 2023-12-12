#ifndef COVIDMAPMANAGERSYSTEM_H
#define COVIDMAPMANAGERSYSTEM_H

#include <QDialog>
#include <QPushButton>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include <manager.h>
#include <user.h>
#include <vister.h>
#include <guangzhoumapinterface.h>

QT_BEGIN_NAMESPACE
namespace Ui { class CovidMapManagerSystem; }
QT_END_NAMESPACE

class CovidMapManagerSystem : public QDialog
{
    Q_OBJECT

public:
    CovidMapManagerSystem(QWidget *parent = nullptr);
    ~CovidMapManagerSystem();
    User*userPage = NULL;//用户界面
    Manager*managerPage = NULL;//管理员界面
    Vister*visterPage = NULL;//游客界面



private:
    Ui::CovidMapManagerSystem *ui;

signals:

private slots:

};
#endif // COVIDMAPMANAGERSYSTEM_H

#ifndef GZMAPCHANGEPERSON_H
#define GZMAPCHANGEPERSON_H

#include <QDialog>
#include <QPushButton>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include "GlobalFile.h"
class RegionalAreaInterface;
class GuangZhouMapInterface;
namespace Ui {
class gzmapchangeperson;
}

class gzmapchangeperson : public QDialog
{
    Q_OBJECT

public:
    explicit gzmapchangeperson(QWidget *parent = nullptr);
    ~gzmapchangeperson();
    static QString person;

    Ui::gzmapchangeperson *ui;

private slots:

    void on_afterPerson_editingFinished();

public slots:
    void on_placeName_linkActivated(const QString &link);

    void on_nameLabel_linkActivated(const QString &link);

    void saveButton();

    void displayNum();

signals:
    void back();//返回上一级信号

private:

};

#endif // GZMAPCHANGEPERSON_H

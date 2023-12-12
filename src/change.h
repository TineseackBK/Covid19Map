#ifndef CHANGE_H
#define CHANGE_H

#include <QDialog>
#include <QPushButton>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include "GlobalFile.h"
#include <cmath>

class Manager;
class userselect;
namespace Ui {
class change;
}

class change : public QDialog
{
    Q_OBJECT

public:
    explicit change(QWidget *parent = nullptr);
    ~change();

    static QString userName;
    static QString userCode;
    static QString userNameBehind;
    static QString userCodeBehind;

private slots:
    void on_userNameText_editingFinished();

    void on_userCodeText_editingFinished();

    void saveButton();

    void on_userNameText_2_editingFinished();

    void on_userCodeText_2_editingFinished();

public slots:
    void on_nameLabel_linkActivated(const QString &link);

signals:
    void back();//返回上一级信号

private:
    Ui::change *ui;
};

#endif // CHANGE_H

#ifndef SECERTCODECHANGE_H
#define SECERTCODECHANGE_H

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

namespace Ui {
class secertcodechange;
}

class secertcodechange : public QDialog
{
    Q_OBJECT

public:
    explicit secertcodechange(QWidget *parent = nullptr);
    ~secertcodechange();
    static QString code;
    static QString codeBehind;

private slots:
    void on_userCodeText_editingFinished();
    void on_userCodeText_2_editingFinished();
    void saveButton();

signals:
    void back();//返回上一级信号

private:
    Ui::secertcodechange *ui;
};

#endif // SECERTCODECHANGE_H

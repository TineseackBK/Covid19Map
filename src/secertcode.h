#ifndef SECERTCODE_H
#define SECERTCODE_H

#include <QDialog>
#include <QPushButton>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include "GlobalFile.h"
#include "book.h"

class Manager;
class GuangZhouMapInterface;

namespace Ui {
class secertcode;
}

class secertcode : public QDialog
{
    Q_OBJECT

public:
    explicit secertcode(QWidget *parent = nullptr);
    ~secertcode();
    book*bookPage = NULL;//注册界面
    static QString secertCode;

signals:
    void back();//返回上一级信号

private slots:
    void on_userCodeText_editingFinished();

    void saveButton();

private:
    Ui::secertcode *ui;
};

#endif // SECERTCODE_H

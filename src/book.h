#ifndef BOOK_H
#define BOOK_H

#include <QDialog>
#include <QPushButton>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include "GlobalFile.h"

class secertcode;
class Manager;
class User;
class GuangZhouMapInterface;
namespace Ui {
class book;
}

class book : public QDialog
{
    Q_OBJECT

public:
    explicit book(QWidget *parent = nullptr);
    ~book();
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
    Ui::book *ui;
};

#endif // BOOK_H

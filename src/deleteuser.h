#ifndef DELETEUSER_H
#define DELETEUSER_H

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
class deleteUser;
}

class deleteUser : public QDialog
{
    Q_OBJECT

public:
    explicit deleteUser(QWidget *parent = nullptr);
    ~deleteUser();
    static QString userName;
    static QString userCode;

private slots:
    void on_userNameText_editingFinished();
    void on_userCodeText_editingFinished();
    void saveButton();

public slots:
    void on_nameLabel_linkActivated(const QString &link);

signals:
    void back();//返回上一级信号

private:
    Ui::deleteUser *ui;
};

#endif // DELETEUSER_H

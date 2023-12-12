#ifndef SECERTCODECHOOSE_H
#define SECERTCODECHOOSE_H

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
class secertcodechoose;
}

class secertcodechoose : public QDialog
{
    Q_OBJECT

public:
    explicit secertcodechoose(QWidget *parent = nullptr);
    ~secertcodechoose();
    static QString secertcode;

private slots:
    void saveButton();
    void on_userCodeText_editingFinished();

public slots:
    void on_titleLabel_linkActivated(const QString &link);

signals:
    void back();//返回上一级信号

private:
    Ui::secertcodechoose *ui;
};

#endif // SECERTCODECHOOSE_H

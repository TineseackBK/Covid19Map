#include "ordinary.h"
#include "ui_ordinary.h"

Ordinary::Ordinary(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ordinary)
{
    ui->setupUi(this);
}

Ordinary::~Ordinary()
{
    delete ui;
}

#ifndef ORDINARY_H
#define ORDINARY_H

#include <QDialog>

namespace Ui {
class Ordinary;
}

class Ordinary : public QDialog
{
    Q_OBJECT

public:
    explicit Ordinary(QWidget *parent = nullptr);
    ~Ordinary();

private:
    Ui::Ordinary *ui;
};

#endif // ORDINARY_H

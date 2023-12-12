//#include "mainwindow.h"
//#include "ui_mainwindow.h"

//#include <QDebug>

//MainWindow::MainWindow(QWidget *parent)
//    : QMainWindow(parent)
//    , ui(new Ui::MainWindow)
//{
//    ui->setupUi(this);

//    setWindowFlags(Qt::FramelessWindowHint); //隐藏窗口标题

//    connect(ui->btn_quit, SIGNAL(clicked()), this, SLOT(close()));

//    ui->btn_quit->setStyleSheet("QPushButton{border-image: url(:/GUI/button/icontest1.png);}"
//                                "QPushButton:hover{border-image: url(:/GUI/button/icontest2.png);}"
//                                "QPushButton:pressed{border-image: url(:/GUI/button/icontest3.png);}");

//    connect(ui->btn_open, SIGNAL(clicked()), this, SLOT(txt()));

////    extern void txt();
////    txt();

//}

//void MainWindow::txt(){
//    qDebug() << "123\n456";
//}

//MainWindow::~MainWindow()
//{
//    delete ui;
//}


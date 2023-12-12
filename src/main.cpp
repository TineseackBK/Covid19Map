#include "covidmapmanagersystem.h"

#include <QApplication>
#include <iostream>
#include <fstream>
#include <cmath>
#include <QTextStream>
#include <QFile>
#include <QString>
#include <QDebug>
using namespace std;

void InitUsers();

int main(int argc, char *argv[])
{

    InitUsers();

    QApplication a(argc, argv);
    CovidMapManagerSystem w;
    w.show();
    return a.exec();
}

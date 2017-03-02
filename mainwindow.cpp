#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QComboBox>

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent),ui(new Ui::MainWindow),scheme(true),score(0),exam3(0)
{
    setFixedSize(400, 400);
    ui->setupUi(this);
    QObject::connect(ui->horizontalSlider,SIGNAL(valueChanged(int)), this, SLOT (setchange1(int)));
    QObject::connect(ui->horizontalSlider_2,SIGNAL(valueChanged(int)), this, SLOT (setchange2(int)));
    QObject::connect(ui->horizontalSlider_3,SIGNAL(valueChanged(int)), this, SLOT (setchange3(int)));
    QObject::connect(ui->horizontalSlider_4,SIGNAL(valueChanged(int)), this, SLOT (setchange4(int)));
    QObject::connect(ui->horizontalSlider_5,SIGNAL(valueChanged(int)), this, SLOT (setchange5(int)));
    QObject::connect(ui->horizontalSlider_6,SIGNAL(valueChanged(int)), this, SLOT (setchange6(int)));
    QObject::connect(ui->horizontalSlider_7,SIGNAL(valueChanged(int)), this, SLOT (setchange7(int)));
    QObject::connect(ui->horizontalSlider_8,SIGNAL(valueChanged(int)), this, SLOT (setchange8(int)));
    QObject::connect(ui->horizontalSlider_9,SIGNAL(valueChanged(int)), this, SLOT (setchangeexam1(int)));
    QObject::connect(ui->horizontalSlider_10,SIGNAL(valueChanged(int)), this, SLOT (setchangeexam2(int)));
    QObject::connect(ui->horizontalSlider_11,SIGNAL(valueChanged(int)), this, SLOT (setchangefinal(int)));
    QObject::connect(ui->schemeAButton,SIGNAL(clicked(bool)), this, SLOT (setSchemeA()));
    QObject::connect(ui->schemeBButton,SIGNAL(clicked(bool)), this, SLOT (setSchemeB()));
    QObject::connect(this,SIGNAL(value_changed()), this, SLOT (setChange()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setchange1(int value)
{
    hw1 = value;
    emit value_changed();
}
void MainWindow::setchange2(int value)
{
    hw2 = value;
    emit value_changed();
}
void MainWindow::setchange3(int value)
{
    hw3 = value;
    emit value_changed();
}
void MainWindow::setchange4(int value)
{
    hw4 = value;
    emit value_changed();
}
void MainWindow::setchange5(int value)
{
    hw5 = value;
    emit value_changed();
}
void MainWindow::setchange6(int value)
{
    hw6 = value;
    emit value_changed();
}
void MainWindow::setchange7(int value)
{
    hw7 = value;
    emit value_changed();
}
void MainWindow::setchange8(int value)
{
    hw8 = value;
    emit value_changed();
}
void MainWindow::setchangeexam1(int value)
{
    exam1 = value;
    emit value_changed();
}
void MainWindow::setchangeexam2(int value)
{
    exam2 = value;
    emit value_changed();
}
void MainWindow::setchangefinal(int value)
{
    exam3 = value;
    emit value_changed();
}

void MainWindow::setSchemeA()
{
    scheme = true;
    emit value_changed();
}
void MainWindow::setSchemeB()
{
    scheme = false;
    emit value_changed();
}
void MainWindow::setChange()
{
    if(scheme)
        score = 0.0015625*(hw1+hw2+hw3+hw4+hw5+hw6+hw7+hw8)+0.0020*exam1+0.0020*exam2+0.0035*exam3;
    else
    {
        exam = exam2;
        if (exam1>exam2)
            exam = exam1;
        score = 0.0015625*(hw1+hw2+hw3+hw4+hw5+hw6+hw7+hw8)+0.0030*exam+0.0044*exam3;
        score = hw1;
    }
    ui->outputLabel->setText(QString::number(score*100)+"%");
}








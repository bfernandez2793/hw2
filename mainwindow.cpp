#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedWidget>

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent),ui(new Ui::MainWindow),scheme(true),score(0),
    hw1(0),hw2(0),hw3(0),hw4(0),hw5(0),hw6(0),hw7(0),hw8(0),exam1(0),exam2(0),exam3(0),
    hw1C(0),hw2C(0),exam1C(0),finalC(0),finalproject(0)
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

    QObject::connect(ui->comboBox,SIGNAL(activated(int)), this, SLOT (class_changed(int)));

    QObject::connect(ui->horizontalSlider_12,SIGNAL(valueChanged(int)), this, SLOT (setchange1C(int)));
    QObject::connect(ui->horizontalSlider_13,SIGNAL(valueChanged(int)), this, SLOT (setchange2C(int)));
    QObject::connect(ui->horizontalSlider_14,SIGNAL(valueChanged(int)), this, SLOT (setchangeexam1C(int)));
    QObject::connect(ui->horizontalSlider_15,SIGNAL(valueChanged(int)), this, SLOT (setchangefinalC(int)));
    QObject::connect(ui->horizontalSlider_16,SIGNAL(valueChanged(int)), this, SLOT (setchangefinalproject(int)));
    QObject::connect(ui->schemeAButton_2,SIGNAL(clicked(bool)), this, SLOT (setSchemeA()));
    QObject::connect(ui->schemeBButton_2,SIGNAL(clicked(bool)), this, SLOT (setSchemeB()));
    QObject::connect(this,SIGNAL(value_changed1()), this, SLOT (setChange1()));




    ui->widget->setVisible(false);
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
    emit value_changed1();
}
void MainWindow::setSchemeB()
{
    scheme = false;
    emit value_changed();
    emit value_changed1();
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
    }
    ui->outputLabel->setText(QString::number(score*100)+"%");
}
void MainWindow::class_changed(int index)
{
    if(index == 1)
    {
        ui->widget->setVisible(true);
        ui->widget1->setVisible(false);
    }
    else
    {
        ui->widget->setVisible(false);
        ui->widget1->setVisible(true);
    }

}

void MainWindow::setchange1C(int value)
{
    hw1C = value;
    emit value_changed1();
}
void MainWindow::setchange2C(int value)
{
    hw2C = value;
    emit value_changed1();
}
void MainWindow::setchangeexam1C(int value)
{
    exam1C = value;
    emit value_changed1();
}
void MainWindow::setchangefinalC(int value)
{
    finalC = value;
    emit value_changed1();
}
void MainWindow::setchangefinalproject(int value)
{
    finalproject = value;
    emit value_changed1();
}
void MainWindow::setChange1()
{
    if(scheme)
        score = 0.00375*(hw1C+hw2C)+0.0025*exam1C+0.0030*finalC+0.0035*finalproject;
    else
    {
        score = 0.00375*(hw1C+hw2C)+0.0050*finalC+0.0035*finalproject;
    }
    ui->outputLabel_2->setText(QString::number(score*100)+"%");
}





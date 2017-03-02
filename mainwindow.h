#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLCDNumber>
#include <QTextEdit>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
    void value_changed();
private slots:
    void setchange1(int value);
    void setchange2(int value);
    void setchange3(int value);
    void setchange4(int value);
    void setchange5(int value);
    void setchange6(int value);
    void setchange7(int value);
    void setchange8(int value);
    void setchangeexam1(int value);
    void setchangeexam2(int value);
    void setchangefinal(int value);
    void setSchemeA();
    void setSchemeB();
    void setChange();

private:
    int hw1,hw2,hw3,hw4,hw5,hw6,hw7,hw8,exam1,exam2,exam3;
    double score;
    int exam;
    bool scheme;
    Ui::MainWindow *ui;
    QLCDNumber *mnumberer;
    QTextEdit *text;
};

#endif // MAINWINDOW_H

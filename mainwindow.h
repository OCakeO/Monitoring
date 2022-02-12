#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "exampleobject.h"

#include <QThread>
#include <QMainWindow>
#include <QFile>
#include <QDir>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void slotGetNumber();

private:
    Ui::MainWindow *ui;
    ExampleObject example;
    QThread thread_1;       // Первый поток
    ExampleObject exampleObject_1;  // первый объект, который будет работать в первом потоке
};
#endif // MAINWINDOW_H

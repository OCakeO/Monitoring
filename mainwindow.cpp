#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDir dir = QDir::currentPath();     // путь: Папка с исполняемым файлом
    ui->textEdit->setText(dir.path()); // записываем с text_Edit путь к папке
    exampleObject_1.setRunning(true); // Запуск потока
    thread_1.start();                // Запуск потока

    connect(&example, &ExampleObject::valueFull, this, &MainWindow::slotGetNumber); //&MainWindow::slotGetNumber); // Принимаем сгнал из ExampleObject и открываем метод slotGetNumber()

    // Запуск выполнения метода run будет осуществляться по сигналу запуска от соответствующего потока
        connect(&thread_1, &QThread::started, &exampleObject_1, &ExampleObject::run);
    // Остановка потока же будет выполняться по сигналу finished от соответствующего объекта в потоке
        connect(&exampleObject_1, &ExampleObject::finished, &thread_1, &QThread::terminate);
        exampleObject_1.moveToThread(&thread_1);    // Передаём объекты в соответствующие потоки
}
void MainWindow::slotGetNumber(){
    ui->label_2->setText("Содержимое изменено");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    exampleObject_1.setRunning(false); // Остановка потока
    exampleObject_1.setRunning(true);

    ui->label_2->setText("Содержимое не изменилось");
    // Остановка потоков через завершение выполнения методов run в объектах
}


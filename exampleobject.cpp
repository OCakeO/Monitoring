#include "exampleobject.h"

#include <QDebug>

ExampleObject::ExampleObject(QObject *parent) : QObject(parent){}


bool ExampleObject::running() const
{
    return m_running;
}

// Самый важный метод, в котором будет выполняться "полезная" работа объекта
void ExampleObject::run()
{
    if (firstchek == false){
        firstValue = chek(); // запоминаем сколько файлов в папке изначально
        firstchek = true;
    }
    // Переменная m_running отвечает за работу объекта в потоке.
    // При значении false работа завершается
    while (m_running)
    {
        chekAll();
        qDebug()<< chek() << firstValue;
    }

    emit finished();
}

int ExampleObject::chek()
{
    QDir dir = QDir::currentPath(); // Папка с исполняемым файлом
    dir.setFilter(QDir::Files | QDir::AllDirs| QDir::Dirs | QDir::NoDotAndDotDot | QDir::NoDot | QDir::NoDotDot );   ///устанавливаем фильтр выводимых файлов/папок (см ниже)
    dir.setSorting(QDir::Size | QDir::Reversed);
    QFileInfoList list = dir.entryInfoList(); // Узнаем сколько файлов
    return list.size();
}

void ExampleObject::chekAll(){
    if(firstValue != chek()){ // Если перовое кол-во файлов не равно нынешнему
        emit valueFull();
    }
    return;
}

void ExampleObject::setRunning(bool running)
{
    if (running == false)
        firstValue = chek(); // Если нажата кнопка "Сброс" обнуляем значения первой проверки файлов
    if (m_running == running)
        return;

    m_running = running;
    emit runningChanged(running);
}

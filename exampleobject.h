#ifndef EXAMPLEOBJECT_H
#define EXAMPLEOBJECT_H

#include <QDir>

using namespace std;

class ExampleObject : public QObject
{
    Q_OBJECT
    // Свойство, управляющее работой потока
    Q_PROPERTY(bool running READ running WRITE setRunning NOTIFY runningChanged)

    bool m_running;
    bool firstchek = 0;
    int firstValue = 0;
    int valueFiles;

public:
    explicit ExampleObject(QObject *parent = 0);
    bool running() const;
    int chek();

private:
    void chekAll();

signals:
    void finished();    // Сигнал, по которому будем завершать поток, после завершения метода run
    void runningChanged(bool running);
    void valueFull();

public slots:
    void run(); // Метод с полезной нагрузкой, который может выполняться в цикле
    void setRunning(bool running);

};

#endif // EXAMPLEOBJECT_H

#include "mainwindow.h"
#include <QApplication>
#include <QThreadPool>
#include <QDebug>
#include <QRunnable>
class Task:public QRunnable
{
    int id_;
public:
    Task(int id):id_(id)
    {
        // QThread::sleep(1);
        qDebug() << "ctor" << id_;
    }
    void run()
    {
        qDebug() << "run" << id_;
    }
    ~Task()
    {
        qDebug() << "dtor" << id_;
    }
};
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QThreadPool pool;
    pool.setMaxThreadCount(2);
    pool.setMaxThreadCount(0);

    for(int i=0 ; i < 100; ++i)
    {
        Task* pTask = new Task(i);
        pTask->setAutoDelete(true);

        pool.start(pTask);
    }
    pool.setMaxThreadCount(2);
    return a.exec();
}

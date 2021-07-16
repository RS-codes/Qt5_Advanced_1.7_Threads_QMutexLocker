#include "worker.h"

Worker::Worker(QObject *parent, Counter *counter, QMutex *mutex) : QObject(parent), QRunnable ()
{
    this->counter = counter;
    this->mutex = mutex;
}

void Worker::run()
{
    if(!counter) return;

    qInfo() << this << " Starting";

    for (int i = 0; i < 100; i++)
    {
        //Without our mutex, the count is wildy out of control
        //Only lock for short term durations!

        QMutexLocker locker(mutex);
        counter->increment();
        qInfo() << this << " Count: " << counter->count();
        counter->decrement();
    }

    qInfo() << this << " Finished";
}

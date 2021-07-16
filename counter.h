#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>
#include <QDebug>

class Counter : public QObject
{
    Q_OBJECT
public:
    explicit Counter(QObject *parent = nullptr);

    void increment();
    void decrement();
    int count();

signals:

public slots:

private:
    int value = 0;
};

#endif // COUNTER_H

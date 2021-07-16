#include "counter.h"

Counter::Counter(QObject *parent) : QObject(parent)
{

}

void Counter::increment()
{
    value++;
}

void Counter::decrement()
{
    value--;
}

int Counter::count()
{
    return value;
}

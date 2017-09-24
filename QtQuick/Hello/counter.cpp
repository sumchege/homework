#include "counter.h"
#include <QObject>
#include <QTimer>

Counter::Counter(QObject *parent) : QObject(parent),
    m_pTimer(new QTimer(this)),
    m_nValue(0),
    m_nDirection(Ascending)
{
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(stepValue()));
    m_pTimer->setInterval(1000);
    m_pTimer->setSingleShot(false);
    m_pTimer->start();

}

int Counter::value() const
{
    return m_nValue;

}

void Counter::setValue(int nValue)
{
    if(nValue != m_nValue)
    {
        m_nValue = nValue;
        emit valueChanged(nValue);
    }

}

void Counter::setDirection(Counter::Direction nDirection)
{
    m_nDirection = nDirection;
}

void Counter::stepValue()
{
    switch(m_nDirection)
    {
    case Ascending:
        setValue(m_nValue + 1);
        break;
    case Descending:
        setValue(m_nValue - 1);
        break;

    }
}

#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>
class QTimer;


class Counter : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)
public:
Counter(QObject *parent = Q_NULLPTR);
enum Direction{
    Ascending,
    Descending
};

Q_ENUM(Direction)

int value() const;
void setValue();

signals:
void valueChanged(int nValue);

public slots:
void stepValue();

private:
QTimer *m_mTimer;

int m_nValue;
Direction m_nDirection;
};

#endif // COUNTER_H

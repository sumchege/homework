#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>
class QTimer;

class Counter : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)
public:
    enum Direction
    {
        Ascending,
        Descending
    };

    Q_ENUM(Direction)

    explicit Counter(QObject *parent = Q_NULLPTR);

    int value() const;
    void setValue(int nValue);
    Q_INVOKABLE void setDirection(Direction nDirection);


signals:
    void valueChanged(int nValue);

public slots:
    void stepValue();

private:
    QTimer *m_pTimer;
    int m_nValue;
    Direction m_nDirection;

};

#endif // COUNTER_H

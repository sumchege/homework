#ifndef LEVELGAUGE_H
#define LEVELGAUGE_H

#include <QQuickPaintedItem>
#include <QPainter>

class LevelGauge : public QQuickPaintedItem
{
    Q_OBJECT
public:
    LevelGauge(QQuickItem *parent = 0);
    void paint(QPainter *painter);

signals:

public slots:
};

#endif // LEVELGAUGE_H

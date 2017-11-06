#include "levelgauge.h"


LevelGauge::LevelGauge(QQuickItem *parent) : QQuickPaintedItem(parent)
{

}

void LevelGauge::paint(QPainter *painter)
{

    const qreal halfPenWidth = qMax(painter->pen().width()/2.0, 1.0);

    QRectF rect = boundingRect();
    rect.adjust(halfPenWidth, halfPenWidth, -halfPenWidth, -halfPenWidth);
    painter->drawRect(rect);
    painter->drawEllipse(rect);

}

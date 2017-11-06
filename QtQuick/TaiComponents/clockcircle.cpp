#include "clockcircle.h"

clockCircle::clockCircle(QQuickItem *parent): QQuickPaintedItem(parent),
    m_bgColor(Qt::white),
    m_borderActiveColor(Qt::blue),
    m_borderNactiveColor(Qt::gray),
    m_angle(0),
    m_circleTime(QTime(0, 0, 0, 0))
{
    // init timer
    // and connect to timer signal from lambda function
    internalTimer = new QTimer(this);


    connect(internalTimer, &QTimer::timeout, [=](){
        setAngle(angle() - 0.3);
        setCircleTime(circleTime().addMSecs(20));
        update();
    });


}

void clockCircle::paint(QPainter *painter)
{
    QBrush brush(m_bgColor);
    QBrush brushActive(m_borderActiveColor);
    QBrush brushNonActive(m_borderActiveColor);

    painter->setPen(Qt::NoPen);
    painter->setRenderHints(QPainter::Antialiasing);
    painter->drawEllipse(boundingRect().adjusted(1, 1, -1, -1));

    painter->setBrush(brushActive);
    painter->drawPie(boundingRect().adjusted(1, 1, -1, -1),
                     90*16,
                     m_angle*16);

    painter->setBrush(brush);
    painter->drawEllipse(boundingRect().adjusted(20, 20, -20, -20));

}

void clockCircle::clear()
{
    setCircleTime(QTime(0, 0, 0, 0));
    setAngle(0);
    update();
    emit cleared();


}

void clockCircle::stop()
{
    internalTimer->stop();
}

void clockCircle::start()
{
    internalTimer->start(50);
}

QString clockCircle::name()
{
    return m_name;
}

QColor clockCircle::bgColor() const
{
    return m_bgColor;
}

QColor clockCircle::borderActiveColor() const
{
    return m_borderActiveColor;
}

QColor clockCircle::borderNactiveColor() const
{
    return m_borderNactiveColor;
}

qreal clockCircle::angle() const
{
    return m_angle;
}

QTime clockCircle::circleTime() const
{
    return m_circleTime;
}

void clockCircle::setName(const QString name)
{
    if(m_name == name)
        return;

    m_name = name;
    emit nameChanged(name);
}

void clockCircle::setBgColor(const QColor bgColor)
{
    if(m_bgColor == bgColor)
        return;

    m_bgColor = bgColor;
    emit bgColorChanged(bgColor);
}

void clockCircle::setBorderActiveColor(const QColor borderActiveColor)
{
    if(m_borderActiveColor == borderActiveColor)
        return;

    m_borderActiveColor = borderActiveColor;
    emit borderActiveColorChanged(borderActiveColor);

}

void clockCircle::setBorderNactiveColor(const QColor borderNactiveColor)
{
    if(m_borderNactiveColor == borderNactiveColor)
        return ;

    m_borderNactiveColor == borderNactiveColor;
    emit borderNactiveColorChanged(borderNactiveColor);
}

void clockCircle::setAngle(const qreal angle)
{
    if(m_angle == angle)
        return;

    m_angle = angle;
    if(m_angle <= -360) m_angle = 0;
    emit angleChanged(angle);

}

void clockCircle::setCircleTime(const QTime circleTime)
{
    if(m_circleTime == circleTime)
        return;

    m_circleTime = circleTime;
    emit circleTimeChanged(circleTime);
}





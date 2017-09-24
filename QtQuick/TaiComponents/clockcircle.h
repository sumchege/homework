#ifndef CLOCKCIRCLE_H
#define CLOCKCIRCLE_H

#include <QtQuick/QQuickPaintedItem>
#include <QColor>
#include <QBrush>
#include <QPen>
#include <QPainter>
#include <QTime>
#include <QTimer>

class clockCircle : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QColor bgColor READ bgColor WRITE setBgColor NOTIFY bgColorChanged)
    Q_PROPERTY(QColor borderActiveColor READ borderActiveColor WRITE setBorderActiveColor NOTIFY borderActiveColorChanged)
    Q_PROPERTY(QColor borderNactiveColor READ borderNactiveColor WRITE setBorderNactiveColor NOTIFY borderNactiveColorChanged)
    Q_PROPERTY(qreal angle READ angle WRITE setAngle NOTIFY angleChanged)
    Q_PROPERTY(QTime circleTime READ circleTime WRITE setCircleTime NOTIFY circleTimeChanged)

public:
    explicit clockCircle(QQuickItem *parent = 0);
    void paint(QPainter *painter); // Overide the method which will be rendered to our
    // methods
    // start, stop, clear
    Q_INVOKABLE void clear();
    Q_INVOKABLE void stop();
    Q_INVOKABLE void start();

    QString name();
    QColor bgColor() const;
    QColor borderActiveColor() const;
    QColor borderNactiveColor() const;
    qreal angle() const;
    QTime circleTime() const;




signals:
    void cleared();

    void nameChanged(const QString name);
    void bgColorChanged(const QColor bgColor);
    void borderActiveColorChanged(const QColor borderActiveColor);
    void borderNactiveColorChanged(const QColor borderNactiveColor);
    void angleChanged(const qreal angle);
    void circleTimeChanged(const QTime circleTime);

public slots:
    void setName(const QString name);
    void setBgColor(const QColor bgColor);
    void setBorderActiveColor(const QColor borderActiveColor);
    void setBorderNactiveColor(const QColor borderNactiveColor);
    void setAngle(const qreal angle);
    void setCircleTime(const QTime circleTime);

private:
    QString m_name;
    QColor m_bgColor, m_borderActiveColor, m_borderNactiveColor;
    qreal m_angle;
    QTime m_circleTime;
    QTimer *internalTimer;

};



#endif // CLOCKCIRCLE_H

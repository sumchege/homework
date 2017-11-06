#ifndef QCHANNEL_SERIAL_H
#define QCHANNEL_SERIAL_H


#include <QObject>
#include <QString>
#include <QStringList>
#include <QList>
#include <QVariant>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>


class QChannel_Serial : public QObject
{
    Q_OBJECT
public:
    explicit QChannel_Serial(QObject *parent = nullptr);
    Q_INVOKABLE QStringList channels();
    Q_INVOKABLE bool open(const QString &name);
    Q_INVOKABLE void close();
    Q_INVOKABLE bool isOpen();
    Q_INVOKABLE QString name();

    Q_INVOKABLE QStringList params();
    Q_INVOKABLE QString param(const QString &name);
    Q_INVOKABLE bool paramSet(const QString &name, const QString &value);

    Q_INVOKABLE QList<int> readBytes();
    Q_INVOKABLE bool writeBytes(const QList<int> &b);
    Q_INVOKABLE bool writeString(const QString &s);

protected:
    QSerialPort *port_;
    bool open_;
    QString name_;
    QStringList params_;
    QByteArray *out_;

signals:

public slots:
};

#endif // QCHANNEL_SERIAL_H

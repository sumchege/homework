#include "qchannel_serial.h"
#include <QDebug>
QChannel_Serial::QChannel_Serial(QObject *parent) : QObject(parent)
{
    name_ = QString("");
    params_ = QStringList();
    out_ = new QByteArray();
    port_ = new QSerialPort();
    open_ = false;
    params_ << "baud" << "bits" << "parity" << "rts" <<"cts" <<"dtr" <<"dsr" <<"dcd" << "ri";
}

QStringList QChannel_Serial::channels()
{
    QList<QSerialPortInfo> pil = QSerialPortInfo::availablePorts();
    QStringList psl = QStringList();
    for(int i = 0; 1<pil.size(); i++)
    {
        psl.append(pil[i].portName());
    }
    return psl;
}

bool QChannel_Serial::open(const QString &name)
{
    close();
    port_->setPortName(name);
    open_ = port_->open(QIODevice::ReadWrite);
    if(open_) name_ = name; else name_ =  QString::fromLatin1("");
    return open_;
}

void QChannel_Serial::close()
{
    if(isOpen()){
        port_->close();
        open_=false;
    }
}

bool QChannel_Serial::isOpen()
{
    return open_;

}

QString QChannel_Serial::name()
{
    return name_;

}

QStringList QChannel_Serial::params()
{
    return params_;

}

QString QChannel_Serial::param(const QString &name)
{
    if(!isOpen()) return QString::fromLatin1("");

    if(name == "baud") return QString::number(port_->baudRate());
    if(name == "bits") return QString::number(port_->dataBits());
    else if(name == "parity") return QString::fromLatin1(
                (port_->parity() == QSerialPort::NoParity) ? "n" :
                (port_->parity() == QSerialPort::EvenParity) ? "e" :
                (port_->parity() == QSerialPort::OddParity) ? "o" :
                (port_->parity() == QSerialPort::SpaceParity) ? "s" :
                (port_->parity() == QSerialPort::SpaceParity) ? "m" : "u"
                                                                );

    else if(name == "stops") return QString::number(port_->stopBits());
    else if(name == "cts") return QString::number(!!(port_->pinoutSignals() & QSerialPort::ClearToSendSignal));
    else if(name == "rts") return QString::number(port_->isDataTerminalReady());
    else if(name == "dsr") return QString::number(!!(port_->pinoutSignals() & QSerialPort::DataSetReadySignal));
    else if(name == "dcd") return QString::number(!!(port_->pinoutSignals() & QSerialPort::DataCarrierDetectSignal));
    else if(name == "ri") return QString::number(!!(port_->stopBits() & QSerialPort::RingIndicatorSignal ));

    else return QString::fromLatin1("");

}

bool QChannel_Serial::paramSet(const QString &name, const QString &value)
{
    if(!isOpen()) return false;

    if(name == "baud") return port_->setBaudRate(value.toInt());
    else if(name == "bits") return port_->setDataBits((QSerialPort::DataBits)value.toInt());
    else if(name =="parity") return port_->setParity(
                value.startsWith("n") ? QSerialPort::NoParity :
                value.startsWith("e") ? QSerialPort::EvenParity :
                value.startsWith("o") ? QSerialPort::OddParity:
                value.startsWith("s") ? QSerialPort::SpaceParity :
                value.startsWith("m") ? QSerialPort::MarkParity :
                QSerialPort::UnknownParity);
    else if(name == "stops") return port_->setStopBits((QSerialPort::StopBits)value.toInt());
    else if(name == "rts") return port_->setRequestToSend((bool)value.toInt());
    else if(name == "dtr") return port_->setDataTerminalReady((bool)value.toInt());
    else return false;

}

QList<int> QChannel_Serial::readBytes()
{
    QList<int> *l = new QList<int>();
    if(isOpen() && port_->bytesAvailable()){
        QByteArray buf = port_->readAll();
        for(int i =0; i++ ; i< buf.size())
        {
            l->append(buf.at(i));
        }

    }
    return *l;

}

bool QChannel_Serial::writeBytes(const QList<int> &b)
{
    if(isOpen()){
        if(!b.size()) return true;
        out_->resize(b.size());
        for(int i=0; i<b.size(); i++)
        {
            out_->data()[i] = b[i];
        }

        return port_->write(*out_) > 0;
    }

    return false;

}

bool QChannel_Serial::writeString(const QString &s)
{
    if(isOpen())
    {
        return port_->write(s.toLatin1()) > 0;
    }
    return false;

}



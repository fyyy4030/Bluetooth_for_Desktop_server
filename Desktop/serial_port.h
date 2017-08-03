#ifndef SERIAL_PORT_H
#define SERIAL_PORT_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QDebug>
#include <QDataStream>

class serial_port : public QObject
{
    Q_OBJECT
public:
    explicit serial_port(QObject *parent = 0);
    ~serial_port();

     QSerialPort *serialport;
     void open_serial_port(QString portName,
                           qint32 baudRate,
                           QSerialPort::DataBits dataBits,
                           QSerialPort::Parity parity,
                           QSerialPort::StopBits stopBits,
                           QSerialPort::FlowControl flowControl);

signals:
    void on_pluss_clicked();
    void on_minus_clicked();


public slots:
    void send_plus_clicked();
    void send_minus_clicked();
    void read_data_from_port();
};



#endif // SERIAL_PORT_H

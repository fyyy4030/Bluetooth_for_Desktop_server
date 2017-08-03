#include "serial_port.h"

serial_port::serial_port(QObject *parent) : QObject(parent)
{
    serialport = new QSerialPort(parent);
    //теперь всегда при изменении данных через порта будет вызывается функция считывающая их

  //  connect(serialport,SIGNAL(readyRead()),this,SLOT(read_data_from_port()));
    connect( serialport,&QSerialPort::readyRead,this,&serial_port::read_data_from_port);

    /*
     * открыть Serial Port!
     */

}

serial_port::~serial_port()
{
    //удалить объект класса QSerialPort и закрыть порт
    serialport->close();
    delete serialport;
}

void serial_port::open_serial_port(QString portName, qint32 baudRate, QSerialPort::DataBits dataBits, QSerialPort::Parity parity, QSerialPort::StopBits stopBits, QSerialPort::FlowControl flowControl)
{
    serialport->setPortName(portName);
    serialport->setBaudRate(baudRate);
    serialport->setDataBits(dataBits);
    serialport->setParity(parity);
    serialport->setStopBits(stopBits);
    serialport->setFlowControl(flowControl);
    if (serialport->open(QIODevice::ReadWrite))
      //   emit connected(portName);
    qDebug()<<"Connected to SerialPort in function void serial_port::open_serial_port(QString portName, qint32 baudRate, QSerialPort::DataBits dataBits, QSerialPort::Parity parity, QSerialPort::StopBits stopBits, QSerialPort::FlowControl flowControl)";
    else
        qDebug()<<"Disconnect to SerialPort in function void serial_port::open_serial_port(QString portName, qint32 baudRate, QSerialPort::DataBits dataBits, QSerialPort::Parity parity, QSerialPort::StopBits stopBits, QSerialPort::FlowControl flowControl)";

 //       emit error(serial->errorString());
}

/*
 * инициилизировать конструктор
 * добавить деструктор
 * реализовать считывание и отправку данных в Последовательный порт
*/

void serial_port::send_plus_clicked(){
    qDebug()<<"slot send plus serial port"<<endl;
    // body of the function
    //Send data to Serial Port
}

void serial_port::send_minus_clicked()
{
     qDebug()<<"slot send minus serial port"<<endl;
    // body of the function
    // Send data to Serial Port using QByteArray and out stream
    // and by this way we let remote device understands that
     // Desktop has been changed and Android has to change the picture too
}

void serial_port::read_data_from_port()
{
    qDebug()<<"read data from port!!!!!!!"<<endl;
    QByteArray byteArr = serialport->readLine();
    QDataStream in(&byteArr, QIODevice::ReadOnly);
    int number_Actiion=0;// 1 - plus, 2 -minus, в number_Action считываем из Последовательного порта
      in >> number_Actiion;
    while(1){
        // принимаем данные из ком порта и в зависимости от данных вызываем тот или иной слот
        if(number_Actiion==1){
            emit send_plus_clicked();
            emit on_pluss_clicked();
            break;
        }

        if(number_Actiion==2){
            emit send_minus_clicked();
            emit on_minus_clicked();
            break;
        }
        if(number_Actiion==0){
            qDebug()<<"Doesnt work read_data_from_port()"<<endl;
            break;
        }
    }
}

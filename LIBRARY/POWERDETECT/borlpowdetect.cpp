#include <QtGlobal>
#include <QByteArray>
#include <cmath>
#include <string>
#include <windows.h>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QString>
#include <QtDebug>
#include <QThread>
#include "serialcom.h"
#include "borlpowdetect.h"

using namespace std;

BORLPOWDETECT::BORLPOWDETECT()
{
    AutoSetComPort();
}

/*
 * THIS FUNCTION IS DESIGNED BY USZ BORL GROUP
 * IN ORDER TO CONTROL A "LASER COMPONENTS"
 * OPTICAL SW USING SERIAL COMUNICATION
 */

void BORLPOWDETECT::SetCOMPort(QString portName)
{
    ComPort=portName;
    qDebug()<<ComPort;
}

void BORLPOWDETECT::ReadWritePOW()
{

    QSerialPort serial;

    serial.setPortName(ComPort);
    serial.setBaudRate(19200);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);

    if(serial.open(QIODevice::ReadWrite))
    {
        serial.clear();
        serial.write("d"); // r NL n CR
        serial.flush();
        serial.waitForBytesWritten(1000);
        QThread::msleep(200);
        serial.waitForReadyRead(1000);
        QByteArray data=serial.readAll();
        quint8 str_len = data.size();
         data.remove(str_len - 2,2);
         voltage = data;
//         qDebug()<<voltage;

//         qDebug()<<QString::number(voltage);

    }
    else
     {
     qDebug()<<"ERROR";
    }
     serial.close();

}

void BORLPOWDETECT::ObtainPOW()
{
    ReadWritePOW();
}

void BORLPOWDETECT::AutoSetComPort()
{
    serialcom = new SerialCom();
    serialcom->SerialFind();
    bool IsArduino = 0;
    quint8 count =  serialcom->Portcount + 1;
    for (int i =1; i<count;i++)
    {
        if(productIDArduino == serialcom->productID[i])
        {
            IsArduino = 1;
            ComPort = serialcom->portName[i];
             qDebug()<<"";
             qDebug()<< "DEVICE " + QString::number(i)+ " is power meter";
//             qDebug()<<"DEVICE "+QString::number(i);
             qDebug()<<serialcom->portName[i];
             qDebug()<<serialcom->description[i];
             qDebug()<<serialcom->manufacturer[i];
             qDebug()<<serialcom->serialNumber[i];
             qDebug()<<serialcom->productID[i];
        }

    }
    if (IsArduino == 0)
        qDebug() << "no arduino found, please check com port connection";
}

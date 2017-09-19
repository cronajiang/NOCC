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
         qDebug()<<data;

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


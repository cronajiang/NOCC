#include <QtGlobal>
#include <cmath>
#include <string>
#include <windows.h>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QString>
#include <QtDebug>
#include <QThread>
#include "serialcom.h"
#include "borlsw.h"

using namespace std;

BORLSW::BORLSW()
{
}

/*
 * THIS FUNCTION IS DESIGNED BY USZ BORL GROUP
 * IN ORDER TO CONTROL A "LASER COMPONENTS"
 * OPTICAL SW USING SERIAL COMUNICATION
 */

BORLSW::SetCOMPort(QString portName)
{
    ComPort=portName;
    qDebug()<<ComPort;
}

BORLSW::ReadWriteSC(char cCommand[15])
{

    QSerialPort serial;

    serial.setPortName(ComPort);
    serial.setBaudRate(57600);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);

    if(serial.open(QIODevice::ReadWrite))
    {
        serial.write(cCommand); // r NL n CR
        serial.flush();
        serial.waitForBytesWritten(1000);
        serial.waitForReadyRead(1000);
        qDebug()<<serial.readAll();
    }
     serial.close();

}

BORLSW::WriteSC(char cCommand[15])
{
    QSerialPort serial;

    serial.setPortName(ComPort);
    serial.setBaudRate(57600);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);

    if(serial.open(QIODevice::ReadWrite))
    {
        serial.write(cCommand); // r NL n CR
        serial.flush();
        serial.waitForBytesWritten(1000);
    }
     serial.close();
}

BORLSW::SwType()
{
    QThread::msleep(100);
    string StrComand="type\?\r\n";
    char cCommand[15];
    strncpy(cCommand,StrComand.c_str(),sizeof(cCommand));
    cCommand[sizeof(cCommand)-1]=0;
    qDebug()<<cCommand;
    ReadWriteSC(cCommand);
}

BORLSW::SwFirmware()
{
    QThread::msleep(100);
    string StrComand="firmware\?\r\n";
    char cCommand[15];
    strncpy(cCommand,StrComand.c_str(),sizeof(cCommand));
    cCommand[sizeof(cCommand)-1]=0;
    qDebug()<<cCommand;
    ReadWriteSC(cCommand);
}

BORLSW::CurrentChannel()
{
    QThread::msleep(100);
    string StrComand="ch\?\r\n";
    char cCommand[15];
    strncpy(cCommand,StrComand.c_str(),sizeof(cCommand));
    cCommand[sizeof(cCommand)-1]=0;
    qDebug()<<cCommand;
    ReadWriteSC(cCommand);
}

BORLSW::SetChannel(qint8 ChannelNumb)
{
    QThread::msleep(100);
    ChannelNum=ChannelNumb;
    string StrComand="ch" + to_string(ChannelNum) + "\r\n";
    char cCommand[15];
    strncpy(cCommand,StrComand.c_str(),sizeof(cCommand));
    cCommand[sizeof(cCommand)-1]=0;
    qDebug()<<cCommand;
    WriteSC(cCommand);
}








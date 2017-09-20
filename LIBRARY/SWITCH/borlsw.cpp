#include "borlsw.h"

using namespace std;

BORLSW::BORLSW()
{

    AutoSetComPort();

}

/*
 * THIS FUNCTION IS DESIGNED BY USZ BORL GROUP
 * IN ORDER TO CONTROL A "LASER COMPONENTS"
 * OPTICAL SW USING SERIAL COMUNICATION
 */

void BORLSW::SetCOMPort(QString portName)
{

    ComPort=portName;
    qDebug()<<ComPort;
}



void BORLSW::ReadWriteSC(char cCommand[15])
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

void BORLSW::WriteSC(char cCommand[15])
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

void BORLSW::SwType()
{
    QThread::msleep(100);
    string StrComand="type\?\r\n";
    char cCommand[15];
    strncpy(cCommand,StrComand.c_str(),sizeof(cCommand));
    cCommand[sizeof(cCommand)-1]=0;
    qDebug()<<cCommand;
    ReadWriteSC(cCommand);
}

void BORLSW::SwFirmware()
{
    QThread::msleep(100);
    string StrComand="firmware\?\r\n";
    char cCommand[15];
    strncpy(cCommand,StrComand.c_str(),sizeof(cCommand));
    cCommand[sizeof(cCommand)-1]=0;
    qDebug()<<cCommand;
    ReadWriteSC(cCommand);
}

void BORLSW::CurrentChannel()
{
    QThread::msleep(100);
    string StrComand="ch\?\r\n";
    char cCommand[15];
    strncpy(cCommand,StrComand.c_str(),sizeof(cCommand));
    cCommand[sizeof(cCommand)-1]=0;
    qDebug()<<cCommand;
    ReadWriteSC(cCommand);
}

void BORLSW::SetChannel(qint8 ChannelNumb)
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

//quint16 BORLSW::getID()
//{
//    return productIDswitch;
//}

void BORLSW::AutoSetComPort()
{
    serialcom = new SerialCom();
    serialcom->SerialFind();
    bool IsSwitch = 0;
    for (int i =1; i<serialcom->Portcount;i++)
    {
        if(productIDswitch == serialcom->productID[i])
        {
            IsSwitch = 1;
            ComPort = serialcom->portName[i];
             qDebug()<<"";
             qDebug()<< "DEVICE " + QString::number(i)+ " is SWITCH";
//             qDebug()<<"DEVICE "+QString::number(i);
             qDebug()<<serialcom->portName[i];
             qDebug()<<serialcom->description[i];
             qDebug()<<serialcom->manufacturer[i];
             qDebug()<<serialcom->serialNumber[i];
             qDebug()<<serialcom->productID[i];
        }

    }
    if (IsSwitch == 0)
        qDebug() << "no swtich found, please check com port connection";
}






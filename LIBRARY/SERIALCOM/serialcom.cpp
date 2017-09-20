#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QtDebug>
#include "serialcom.h"

SerialCom::SerialCom()
{

}

void SerialCom::SerialFind()
{
    Portcount=0;
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos)
    {
        Portcount++;
        description[Portcount] = info.description();
        manufacturer[Portcount] = info.manufacturer();
        serialNumber[Portcount] = info.serialNumber();
        portName[Portcount] = info.portName();
        productID[Portcount] = info.productIdentifier();
    }

//    for(int i=1;i<Portcount+1;i++)
//    {
//    qDebug()<<"";
//    qDebug()<<"DEVICE "+QString::number(i);
//    qDebug()<<portName[i];
//    qDebug()<<description[i];
//    qDebug()<<manufacturer[i];
//    qDebug()<<serialNumber[i];
//    qDebug()<<productID[i];
//    }
}


QString SerialCom::SerialSet(qint8 iSet)
{
    qint8 Portcount=0;
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos)
    {
        Portcount++;
        description[Portcount] = info.description();
        manufacturer[Portcount] = info.manufacturer();
        serialNumber[Portcount] = info.serialNumber();
        portName[Portcount] = info.portName();
    }

    /*
    qDebug()<<"";
    qDebug()<<"SELECTED DEVICE";
    qDebug()<<"DEVICE "+QString::number(iSet);
    qDebug()<<portName[iSet];
    qDebug()<<description[iSet];
    qDebug()<<manufacturer[iSet];
    qDebug()<<serialNumber[iSet];
*/
    return portName[iSet];
}


void SerialCom::SerialFindDebug()
{
    Portcount=0;
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos)
    {
        Portcount++;
        description[Portcount] = info.description();
        manufacturer[Portcount] = info.manufacturer();
        serialNumber[Portcount] = info.serialNumber();
        portName[Portcount] = info.portName();
        productID[Portcount] = info.productIdentifier();
    }

    for(int i=1;i<Portcount+1;i++)
    {
    qDebug()<<"";
    qDebug()<<"DEVICE "+QString::number(i);
    qDebug()<<portName[i];
    qDebug()<<description[i];
    qDebug()<<manufacturer[i];
    qDebug()<<serialNumber[i];
    qDebug()<<productID[i];
    }
}


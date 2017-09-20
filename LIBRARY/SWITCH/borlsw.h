#ifndef BORLSW_H
#define BORLSW_H

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
//#include "borlsw_global.h"

class BORLSW
{

public:

    BORLSW();
    void SwType();
    void SwFirmware();
    void CurrentChannel();
    void SetChannel(qint8);
    void SetCOMPort(QString);
    //quint16 getID();
    const quint16 productIDswitch = 24577;
    void AutoSetComPort();


    SerialCom *serialcom;

private:
    qint8 ChannelNum;
    void ReadWriteSC(char[]);
    void WriteSC(char[]);
    QString ComPort;

};

#endif // BORLSW_H

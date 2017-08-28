#ifndef BORLSW_H
#define BORLSW_H

//#include "borlsw_global.h"

class BORLSW
{

public:

    BORLSW();
    SwType();
    SwFirmware();
    CurrentChannel();
    SetChannel(qint8);
    SetCOMPort(QString);

private:
    qint8 ChannelNum;
    ReadWriteSC(char[]);
    WriteSC(char[]);
    QString ComPort;
};

#endif // BORLSW_H

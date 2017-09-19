#ifndef BORLSW_H
#define BORLSW_H

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

private:
    qint8 ChannelNum;
    void ReadWriteSC(char[]);
    void WriteSC(char[]);
    QString ComPort;
};

#endif // BORLSW_H

#ifndef BORLPOWDETECT_H
#define BORLPOWDETECT_H

#include "serialcom.h"

class BORLPOWDETECT
{
public:
    BORLPOWDETECT();
    void ObtainPOW();
    void SetCOMPort(QString);

    const quint16 productIDArduino = 67;
    void AutoSetComPort();


    SerialCom *serialcom;


    QString ComPort;

    QByteArray voltage;
private:
    void ReadWritePOW();
};

#endif // BORLPOWDETECT_H

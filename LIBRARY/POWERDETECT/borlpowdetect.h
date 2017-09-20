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

    void ReadWritePOW();
    QString ComPort;

private:

};

#endif // BORLPOWDETECT_H

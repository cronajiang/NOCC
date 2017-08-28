#ifndef BORLPOWDETECT_H
#define BORLPOWDETECT_H


class BORLPOWDETECT
{
public:
    BORLPOWDETECT();
    ObtainPOW();
    SetCOMPort(QString);

private:
    ReadWritePOW();
    QString ComPort;
};

#endif // BORLPOWDETECT_H

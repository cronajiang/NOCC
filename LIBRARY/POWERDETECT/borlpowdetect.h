#ifndef BORLPOWDETECT_H
#define BORLPOWDETECT_H


class BORLPOWDETECT
{
public:
    BORLPOWDETECT();
    void ObtainPOW();
    void SetCOMPort(QString);

private:
    void ReadWritePOW();
    QString ComPort;
};

#endif // BORLPOWDETECT_H

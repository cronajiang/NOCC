#ifndef SERIALCOM_H
#define SERIALCOM_H

#include <QString>
class SerialCom
{
public:

    SerialCom();
    void SerialFind();
    QString SerialSet(qint8 iSet);

    quint16 productID[5];
    qint8 Portcount;
    QString description[5];
    QString manufacturer[5];
    QString serialNumber[5];
    QString portName[5];
//private:




};

#endif // SERIALCOM_H

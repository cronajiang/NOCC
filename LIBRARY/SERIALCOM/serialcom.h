#ifndef SERIALCOM_H
#define SERIALCOM_H


class SerialCom
{
public:

    SerialCom();
    SerialFind();
    QString SerialSet(qint8 iSet);

private:

    QString description[5];
    QString manufacturer[5];
    QString serialNumber[5];
    QString portName[5];

};

#endif // SERIALCOM_H
